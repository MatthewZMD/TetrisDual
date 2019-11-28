#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include <memory>
#include "board.h"
#include "concreteboard.h"
#include "textdisplay.h"
#include "heavydecorator.h"
#include "blinddecorator.h"
#include "forcedecorator.h"

class Game {
    std::shared_ptr<Board> board1;
    std::shared_ptr<Board> board2;
    std::shared_ptr<TextDisplay> display1;
    std::shared_ptr<TextDisplay> display2;
    int hiScore;
    int playerTurn;
    Game(std::string fileName1 = "sequence1.txt", std::string fileName2 = "sequence2.txt");
    void heavy(std::shared_ptr<Board> givenBoard);
    void blind(std::shared_ptr<Board> givenBoard);
    void force(std::shared_ptr<Board> givenBoard, CellType giventype);
    void recover(std::shared_ptr<Board> givenBoard);
};

#endif
