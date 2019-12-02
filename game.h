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
#include "graphicsdisplay.h"

class Game {
    public:
    std::shared_ptr<Board> board1;
    std::shared_ptr<Board> board2;
    std::shared_ptr<TextDisplay> display;
    std::shared_ptr<GraphicsDisplay> window;
    int hiScore;
    int playerTurn;
    Game(std::string fileName1, std::string fileName2, int l, bool isTextOnly);
    void init(std::string fileName1, std::string fileName2, int l, bool isTextOnly);

    void heavy();
    void blind();
    void force(CellType type);
    void recover();

    bool left(int n);
    bool right(int n);
    void down(int n);
    void rotate(bool isClockwise, int n);
    bool drop(int n);
    void levelup(int n);
    void leveldown(int n);
    void norandom(std::string file);
    void random();
    void replaceBlock(std::string cmd);

    bool isAutoDrop() const;

    private:
    void switchTurn();
};

#endif
