#ifndef BOARDINFO_H
#define BOARDINFO_H
#include <vector>
#include "info.h"
#include "celltype.h"

struct BoardInfo : public Info {
	int player;
	int level;
	int score;
	std::vector<std::vector<char>> boardData;
	CellType nextType;
	BoardInfo();
	BoardInfo(int player, int level, int score, std::vector<std::vector<char>> boardData, CellType nextType);
	~BoardInfo();
};

#endif
