#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include <memory>
#include <string>
#include "board.h"
#include "celltype.h"
#include "concreteboard.h"
#include "textdisplay.h"
#include "heavydecorator.h"
#include "blinddecorator.h"
#include "forcedecorator.h"

class Game {
    public:
    std::shared_ptr<Board> board1;
    std::shared_ptr<Board> board2;
    std::shared_ptr<TextDisplay> display;
    int hiScore;
    int playerTurn;
    Game(std::string fileName1, std::string fileName2, int l);

    void heavy(std::shared_ptr<Board> givenBoard);
    void blind(std::shared_ptr<Board> givenBoard);
    void force(std::shared_ptr<Board> givenBoard, CellType giventype);
    void recover(std::shared_ptr<Board> givenBoard);

    void left(int n);
    void right(int n);
    void down(int n);
    void rotate(bool isClockwise);
    void drop();
    void levelup(int n);
    void leveldown(int n);
    void norandom();
    void random();
    void replaceBlock(std::string cmd);

    private:
    void switchTurn();
};

#endif
