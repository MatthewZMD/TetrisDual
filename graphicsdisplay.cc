#include "graphicsdisplay.h"
#include "window.h"

GraphicsDisplay::GraphicsDisplay(int length, int width): length{length}, width{width}, xw{Xwindow(width, length)} {
	xw.fillRectangle(0, 0, width, length, Xwindow::Orange);
	xw.fillRectangle(250, 0, 20, 590, Xwindow::Black);
}

void GraphicsDisplay::GraphicsDisplay::notify(Subject& s) {
	Board & b = dynamic_cast<Board&>(s);
	BoardInfo &bi = dynamic_cast<BoardInfo&>(b.getInfo());
	int player = bi.player;
	std::string level = std::to_string(bi.level);
	std::string score = std::to_string(bi.score);
	if (player == 0) {
		xw.fillRectangle(0, 13, 250, 27, Xwindow::Orange);
		xw.drawBigString(15, 40, "Level: " + level, Xwindow::Black);
		xw.fillRectangle(0, 58, 250, 27, Xwindow::Orange);
		xw.drawBigString(15 ,85, "Score: " + score, Xwindow::Black);
		for (int i = 0; i < 18; ++i) {
			for (int j = 0; j < 11; ++j) {
				char current = bi.boardData[i][j];
				xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::White);
				if (current == 'I') {
					xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Brown);
				} else if (current == 'J') {
					xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Red);
				} else if (current == 'L') {
					xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Cyan);
				} else if (current == 'O') {
                                        xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::DarkGreen);
				} else if (current == 'S') {
					xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Magenta);
				} else if (current == 'Z') {
					xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Blue);
				} else if (current == 'T') {
                    xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Green);
				} else if (current == '*') {
                    xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Brown);
					xw.drawString(24 + 20 * j, 115 + 20 * i, "*", Xwindow::White);
				} else if (current == '?') {
                    xw.fillRectangle(15 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Black);
					xw.drawString(24 + 20 * j, 115 + 20 * i, "?", Xwindow::White);
				}
				xw.fillRectangle(15 + 20 * j + 11, 100 + 20 * i + 1, 7, 7, Xwindow::White);
				//xw.fillRectangle(15 + 20 * j + 3, 100 + 20 * i + 15, 3, 3, Xwindow::White);
			    

			}
		}
		xw.drawBigString(15, 500, "Next:", Xwindow::Black);
		CellType type = bi.nextType;
		for (int i = 0; i < 2; ++i) {
                   for (int j = 0; j < 4; ++j) {
                        xw.fillRectangle(65 + 30 * j, 510 + 30 * i, 30, 30, Xwindow::Orange);
                   }
                }

		switch(type) {
			case CellType::I:
				xw.fillRectangle(65, 540, 30, 30, Xwindow::Brown);
				xw.fillRectangle(95, 540, 30, 30, Xwindow::Brown);
                xw.fillRectangle(125, 540, 30, 30, Xwindow::Brown);
                xw.fillRectangle(155, 540, 30, 30, Xwindow::Brown);
                break;
			case CellType::J:
				xw.fillRectangle(65, 510, 30, 30, Xwindow::Red);
                xw.fillRectangle(65, 540, 30, 30, Xwindow::Red);
                xw.fillRectangle(95, 540, 30, 30, Xwindow::Red);
                xw.fillRectangle(125, 540, 30, 30, Xwindow::Red);
                break;
			case CellType::L:
				xw.fillRectangle(125, 510, 30, 30, Xwindow::Cyan);
                xw.fillRectangle(125, 540, 30, 30, Xwindow::Cyan);
                xw.fillRectangle(65, 540, 30, 30, Xwindow::Cyan);
                xw.fillRectangle(95, 540, 30, 30, Xwindow::Cyan);
                break;
			case CellType::O:
				xw.fillRectangle(65, 510, 30, 30, Xwindow::DarkGreen);
                xw.fillRectangle(95, 510, 30, 30, Xwindow::DarkGreen);
                xw.fillRectangle(65, 540, 30, 30, Xwindow::DarkGreen);
                xw.fillRectangle(95, 540, 30, 30, Xwindow::DarkGreen);
                break;
			case CellType::S:
				xw.fillRectangle(65, 540, 30, 30, Xwindow::Magenta);
                xw.fillRectangle(95, 510, 30, 30, Xwindow::Magenta);
                xw.fillRectangle(95, 540, 30, 30, Xwindow::Magenta);
                xw.fillRectangle(125, 510, 30, 30, Xwindow::Magenta);
                break;
			case CellType::Z:
				xw.fillRectangle(65, 510, 30, 30, Xwindow::Blue);
                xw.fillRectangle(95, 510, 30, 30, Xwindow::Blue);
                xw.fillRectangle(95, 540, 30, 30, Xwindow::Blue);
                xw.fillRectangle(125, 540, 30, 30, Xwindow::Blue);
                break;
			case CellType::T:
				xw.fillRectangle(65, 510, 30, 30, Xwindow::Green);
                xw.fillRectangle(95, 510, 30, 30, Xwindow::Green);
                xw.fillRectangle(125, 510, 30, 30, Xwindow::Green);
                xw.fillRectangle(95, 540, 30, 30, Xwindow::Green);
                break;
            case CellType::E:
                break;
            case CellType::Star:
                break;
		}
		for (int i = 0; i < 19; ++i) {
			xw.drawLine(15, 100 + 20 * i, 235, 100 + 20 * i);
                                                xw.drawLine(15, 100 + 20 * i - 1, 235, 100 + 20 * i - 1);

		}
		for (int j = 0; j < 12; ++j) {
			xw.drawLine(15 + 20 * j, 100, 15 + 20 * j, 460);
			 xw.drawLine(15 + 20 * j - 1, 100, 15 + 20 * j - 1, 460);
            

		}
	} else {
		xw.fillRectangle(270, 13, 250, 27, Xwindow::Orange);
		xw.drawBigString(285, 40, "Level: " + level, Xwindow::Black);
			xw.fillRectangle(270, 58, 250, 27, Xwindow::Orange);
		xw.drawBigString(285 ,85, "Score: " + score, Xwindow::Black);
        for (int i = 0; i < 18; ++i) {
            for (int j = 0; j < 11; ++j) {
                char current = bi.boardData[i][j];
		xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::White);
                if (current == 'I') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Brown);
                } else if (current == 'J') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Red);
                } else if (current == 'L') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Cyan);
                } else if (current == 'O') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::DarkGreen);
                } else if (current == 'S') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Magenta);
                } else if (current == 'Z') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Blue);
                } else if (current == 'T') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Green);
                } else if (current == '*') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Brown);
                    xw.drawString(294 + 20 * j, 115 + 20 * i, "*", Xwindow::White);
                } else if (current == '?') {
                    xw.fillRectangle(285 + 20 * j, 100 + 20 * i, 20, 20, Xwindow::Black);
                    xw.drawString(294 + 20 * j, 115 + 20 * i, "?", Xwindow::White);
                }
		xw.fillRectangle(285 + 20 * j + 11, 100 + 20 * i + 1, 7, 7, Xwindow::White);
		//xw.fillRectangle(285 + 20 * j + 3, 100 + 20 * i + 15, 3, 3, Xwindow::White);



            }
        }
        xw.drawBigString(285, 500, "Next:", Xwindow::Black);
        CellType type = bi.nextType;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 4; ++j) {
			xw.fillRectangle(335 + 30 * j, 510 + 30 * i, 30, 30, Xwindow::Orange);
		}
	}
        switch(type) {
            case CellType::I:
                xw.fillRectangle(335, 540, 30, 30, Xwindow::Brown);
                xw.fillRectangle(365, 540, 30, 30, Xwindow::Brown);
                xw.fillRectangle(395, 540, 30, 30, Xwindow::Brown);
                xw.fillRectangle(425, 540, 30, 30, Xwindow::Brown);
		break;
            case CellType::J:
                xw.fillRectangle(335, 510, 30, 30, Xwindow::Red);
                xw.fillRectangle(335, 540, 30, 30, Xwindow::Red);
                xw.fillRectangle(365, 540, 30, 30, Xwindow::Red);
                xw.fillRectangle(395, 540, 30, 30, Xwindow::Red);
		break;
            case CellType::L:
                xw.fillRectangle(395, 510, 30, 30, Xwindow::Cyan);
                xw.fillRectangle(395, 540, 30, 30, Xwindow::Cyan);
                xw.fillRectangle(335, 540, 30, 30, Xwindow::Cyan);
                xw.fillRectangle(365, 540, 30, 30, Xwindow::Cyan);
		break;
            case CellType::O:
                xw.fillRectangle(335, 510, 30, 30, Xwindow::DarkGreen);
                xw.fillRectangle(365, 510, 30, 30, Xwindow::DarkGreen);
                xw.fillRectangle(335, 540, 30, 30, Xwindow::DarkGreen);
                xw.fillRectangle(365, 540, 30, 30, Xwindow::DarkGreen);
		break;
            case CellType::S:
                xw.fillRectangle(335, 540, 30, 30, Xwindow::Magenta);
                xw.fillRectangle(365, 510, 30, 30, Xwindow::Magenta);
                xw.fillRectangle(365, 540, 30, 30, Xwindow::Magenta);
                xw.fillRectangle(395, 510, 30, 30, Xwindow::Magenta);
		break;
            case CellType::Z:
                xw.fillRectangle(335, 510, 30, 30, Xwindow::Blue);
                xw.fillRectangle(365, 510, 30, 30, Xwindow::Blue);
                xw.fillRectangle(365, 540, 30, 30, Xwindow::Blue);
                xw.fillRectangle(395, 540, 30, 30, Xwindow::Blue);
                break;
	    case CellType::T:
                xw.fillRectangle(335, 510, 30, 30, Xwindow::Green);
                xw.fillRectangle(365, 510, 30, 30, Xwindow::Green);
                xw.fillRectangle(395, 510, 30, 30, Xwindow::Green);
                xw.fillRectangle(365, 540, 30, 30, Xwindow::Green);
		break;
            case CellType::E:
                break;
            case CellType::Star:
                break;
        }
        for (int i = 0; i < 19; ++i) {
            xw.drawLine(285, 100 + 20 * i, 505, 100 + 20 * i);
	     xw.drawLine(285, 100 + 20 * i - 1, 505, 100 + 20 * i - 1);


        }       

        for (int j = 0; j < 12; ++j) {
            xw.drawLine(285 + 20 * j, 100, 285 + 20 * j, 460);
	     xw.drawLine(285 + 20 * j - 1, 100, 285 + 20 * j - 1, 460);

 
        }
	}
}

GraphicsDisplay::~GraphicsDisplay() {}
