#include "boardinfo.h"

BoardInfo::BoardInfo(int player, int level, int score, std::vector<std::vector<char>> boardData) : player{player}, level{level}, score{score}, boardData{boardData}, nextType{nextType} {}

BoardInfo::~BoardInfo() {}
