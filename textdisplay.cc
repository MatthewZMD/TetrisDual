#include "textdisplay.h"
#include "board.h"
#include "boardinfo.h"
TextDisplay::TextDisplay(int numberOfPlayers, int numberOfRows, int numberOfColumns){
	for (int i = 0; i < numberOfPlayers; ++i) {
		level.emplace_back(0);
		score.emplace_back(0);

		boardData.emplace_back(std::vector<std::vector<char>>{});
		for (int r = 0; r < numberOfRows; ++r) {
			boardData.at(i).emplace_back(std::vector<char>{});
			for (int c = 0; c < numberOfColumns; ++c) {
				boardData.at(i).at(r).emplace_back(' ');
			}
		}

		nextType.emplace_back(CellType::T);
	}
}

void TextDisplay::notify(Subject & s) {
	Board & b = dynamic_cast<Board&>(s);
	BoardInfo &bi = dynamic_cast<BoardInfo&>(b.getInfo());

	int player = bi.player;
	level.at(player) = bi.level;
	score.at(player) = bi.score;
	boardData.at(player) = bi.boardData;
	nextType.at(player) = bi.nextType;
}

std::ostream& operator<<(std::ostream &out, const TextDisplay &td) {
	int cSpace = 6;
	int numberOfPlayers = (int)td.boardData.size();
	int numberOfRows = (int)td.boardData.at(0).size();
	int numberOfColumns = (int)td.boardData.at(0).at(0).size();

	// level
	for (int i = 0; i < numberOfPlayers; ++i) {
		if (i > 0) {
			out << std::setw(cSpace) << "";
		}
		out << "Level:" << std::setw(numberOfColumns - 6) << td.level.at(i);
	}
	out << std::endl;

	// score
	for (int i = 0; i < numberOfPlayers; ++i) {
		if (i > 0) {
			out << std::setw(cSpace) << "";
		}
		out << "Score:" << std::setw(numberOfColumns - 6) << td.score.at(i);
	}
	out << std::endl;

	// separator
	for (int i = 0; i < numberOfPlayers; ++i) {
		if (i > 0) {
			out << std::setw(cSpace) << "";
		}
		for (int j = 0; j < numberOfColumns; ++j) {
			out << "-";
		}
	}
	out << std::endl;

	// board data
	for (int r = 0; r < numberOfRows; ++r) {
		for (int i = 0; i < numberOfPlayers; ++i) {
			if (i > 0) {
				out << std::setw(cSpace) << "";
			}
			for (int c = 0; c < numberOfColumns; ++c) {
				out << td.boardData.at(i).at(r).at(c);
			}
		}
		out << std::endl;
	}

	// separator
	for (int i = 0; i < numberOfPlayers; ++i) {
		if (i > 0) {
			out << std::setw(cSpace) << "";
		}
		for (int j = 0; j < numberOfColumns; ++j) {
			out << "-";
		}
	}
	out << std::endl;

	// next block
	for (int i = 0; i < numberOfPlayers; ++i) {
		if (i > 0) {
			out << std::setw(cSpace) << "";
		}
		out << std::left << std::setw(numberOfColumns) << "Next:";
	}
	out << std::endl;

	// next type
	for (int i = 0; i < numberOfPlayers; ++i) {
		if (i > 0) {
			out << std::setw(cSpace) << "";
		}

		std::string str;
		if (td.nextType.at(i) == CellType::I) {
			str = "";
		}
		else if (td.nextType.at(i) == CellType::J) {
			str = "J";;
		}
		else if (td.nextType.at(i) == CellType::L) {
			str = "  L";
		}
		else if (td.nextType.at(i) == CellType::O) {
			str = "OO";
		}
		else if (td.nextType.at(i) == CellType::S) {
			str = " SS";
		}
		else if (td.nextType.at(i) == CellType::Z) {
			str = "ZZ";
		}
		else if (td.nextType.at(i) == CellType::T) {
			str = "TTT";
		}
		else if (td.nextType.at(i) == CellType::E) {
			str = "";
		}

		out << std::left << std::setw(numberOfColumns) << str;
	}
	out << std::endl;

	for (int i = 0; i < numberOfPlayers; ++i) {
		if (i > 0) {
			out << std::setw(cSpace) << "";
		}

		std::string str;
		if (td.nextType.at(i) == CellType::I) {
			str = "IIII";
		}
		else if (td.nextType.at(i) == CellType::J) {
			str = "JJJ";;
		}
		else if (td.nextType.at(i) == CellType::L) {
			str = "LLL";
		}
		else if (td.nextType.at(i) == CellType::O) {
			str = "OO";
		}
		else if (td.nextType.at(i) == CellType::S) {
			str = "SS";
		}
		else if (td.nextType.at(i) == CellType::Z) {
			str = " ZZ";
		}
		else if (td.nextType.at(i) == CellType::T) {
			str = " T";
		}
		else if (td.nextType.at(i) == CellType::E) {
			str = "";
		}

		out << std::left << std::setw(numberOfColumns) << str;
	}
	out << std::endl;

	return out;
}
