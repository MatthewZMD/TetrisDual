#include "boardinfo.h"

BoardInfo::BoardInfo(int playerNum, int boardLevel, int boardScore, std::vector<std::vector<char>> boardDisplay):playerNum{playerNum}, boardLevel{boardLevel}, boardScore{boardScore}, boardDisplay{boardDisplay} {}

~BoardInfo::BoardInfo() {}
