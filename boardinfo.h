#ifndef BOARDINFO_H
#define BOARDINFO_H
#include <vector>
#include "info.h"



struct BoardInfo : public Info {
	int boardLevel;
	int boardScore;
	int playerNum;
	std::vector<std::vector<char>> boardDisplay;
    BoardInfo(int playerNum, int boardLevel, int boardScore, std::vector<std::vector<char>> boardDisplay);
    ~BoardInfo() override;
};

#endif
