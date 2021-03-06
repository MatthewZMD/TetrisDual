#include <stdexcept>
#include "block.h"

void Block::recaliBtmLft(){
    Coordinate newBtmLft = Coordinate{0, 200};
    Coordinate cellPos;
    for(unsigned i = 0; i < cells.size(); ++i) {
        cellPos = cells.at(i)->pos;
        if(cellPos.col < newBtmLft.col) newBtmLft.col = cellPos.col;
        if(cellPos.row > newBtmLft.row) newBtmLft.row = cellPos.row;
    }
    btmLft = newBtmLft;
}

Block::Block(CellType t, int l, std::vector<Cell*> cells): cells { cells }, btmLft { Coordinate { 3, 0 } } {
    std::vector<Cell*> sq;
    for(auto &c : cells){
        if(!c->isEmpty()){
            throw "Game Over";
        }
        for(auto &ci : cells){
            if(ci != c){
                sq.emplace_back(ci);
            }
        }
        c->set(t, l, sq);
        sq.clear();
    }
}
