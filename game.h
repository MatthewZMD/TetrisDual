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
    std::vector<std::shared_ptr<Board>> boards;
    std::vector<std::shared_ptr<TextDisplay>> displays;
    int hiScore;
    int playerTurn;
    const int playerNum = 2;
    Game();
    void heavy(std::shared_ptr<Board> givenBoard);
    void blind(std::shared_ptr<Board> givenBoard);
    void force(std::shared_ptr<Board> givenBoard, CellType giventype);
    void recover(std::shared_ptr<Board> givenBoard);
};

#endif
