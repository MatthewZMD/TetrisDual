#include "textdisplay.h"

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

/*
void TextDisplay::notify(Subject & s) {
	Board & b = dynamic_cast<Board&>(s);
	BoardInfo & info = b.getInfo();
	
	int player = info.player;
	level.at(player) = info.level;
	score.at(player) = info.score;
	boardData.at(player) = info.boardData;
	nextType.at(player) = info.nextType;
}*/

std::ostream& operator<<(std::ostream &out, const TextDisplay &td) {
	std::string sp = "      ";

	// level
	for (unsigned i = 0; i < td.boardData.size(); ++i) {
		if (i > 0) {
			out << sp;
		}
		out << "Level:" << std::setw(5) << td.level.at(i);
	}
	out << std::endl;

	// score
	for (unsigned i = 0; i < td.boardData.size(); ++i) {
		if (i > 0) {
			out << sp;
		}
		out << "Score:" << std::setw(5) << td.score.at(i);
	}
	out << std::endl;

	// separator
	for (unsigned i = 0; i < td.boardData.size(); ++i) {
		if (i > 0) {
			out << sp;
		}
		for (unsigned j = 0; j < td.boardData.at(i).at(0).size(); ++j) {
			out << "-";
		}
	}
	out << std::endl;

	// board data
	for (unsigned r = 0; r < td.boardData.at(0).size(); ++r) {
		for (unsigned i = 0; i < td.boardData.size(); ++i) {
			if (i > 0) {
				out << sp;
			}
			for (unsigned c = 0; c < td.boardData.at(i).at(r).size(); ++c) {
				out << td.boardData.at(i).at(r).at(c);
			}
		}
		out << std::endl;
	}

	// separator
	for (unsigned i = 0; i < td.boardData.size(); ++i) {
		if (i > 0) {
			out << sp;
		}
		for (unsigned j = 0; j < td.boardData.at(i).at(0).size(); ++j) {
			out << "-";
		}
	}
	out << std::endl;

	// next block
	for (unsigned i = 0; i < td.boardData.size(); ++i) {
		if (i > 0) {
			out << sp;
		}
		out << std::left << std::setw(td.boardData.at(0).at(0).size()) << "Next:";
	}
	out << std::endl;

	// next type
	for (unsigned i = 0; i < td.boardData.size(); ++i) {
		if (i > 0) {
			out << sp;
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

		out << std::left << std::setw(td.boardData.at(0).at(0).size()) << str;
	}
	out << std::endl;

	for (unsigned i = 0; i < td.boardData.size(); ++i) {
		if (i > 0) {
			out << sp;
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

		out << std::left << std::setw(td.boardData.at(0).at(0).size()) << str;
	}
	out << std::endl;

	return out;
}
