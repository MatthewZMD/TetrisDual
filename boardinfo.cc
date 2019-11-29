#include "boardinfo.h"

<<<<<<< Updated upstream
=======
BoardInfo::BoardInfo() : player{0}, level{0}, score{0}, boardData{std::vector<std::vector<char>>{}}, nextType{CellType::E} {}

>>>>>>> Stashed changes
BoardInfo::BoardInfo(int player, int level, int score, std::vector<std::vector<char>> boardData, CellType nextType) : player{player}, level{level}, score{score}, boardData{boardData}, nextType{nextType} {}

BoardInfo::~BoardInfo() {}
