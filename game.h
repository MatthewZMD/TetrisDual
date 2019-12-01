#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
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
#include "graphicsdisplay.h"

class Game {
    public:
    std::shared_ptr<Board> board1;
    std::shared_ptr<Board> board2;
    std::shared_ptr<TextDisplay> display;
    std::shared_ptr<GraphicsDisplay> window;
    int hiScore;
    int playerTurn;
    Game(std::string fileName1, std::string fileName2, int l);
    void init(std::string fileName1, std::string fileName2, int l);

    void heavy();
    void blind();
    void force(CellType type);
    void recover();

    void left(std::istream & in, int n);
    void right(std::istream & in, int n);
    void down(int n);
    void rotate(bool isClockwise, int n);
    void drop(std::istream & in, int n);
    void levelup(int n);
    void leveldown(int n);
    void norandom(std::string file);
    void random();
    void replaceBlock(std::string cmd);

    bool isAutoDrop() const;

    private:
    void execAction(std::istream &in);
    void switchTurn();
};

#endif
