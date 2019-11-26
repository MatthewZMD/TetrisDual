#include "game.h"

Game::Game(): hiScore{0}, playerTurn{0} {}

void Game::heavy(std::shared_ptr<Board> givenboard) {
    givenboard = std::shared_ptr<Board>(new HeavyDecorator(givenboard)); 
}

void Game::blind(std::shared_ptr<Board> givenboard) {
    givenboard = std::shared_ptr<Board>(new BlindDecorator(givenboard));
}

void Game::force(std::shared_ptr<Board> givenboard, CellType giventype) {
    givenboard = std::shared_ptr<Board>(new ForceDecorator(givenboard, giventype));
}

void Game::recover(std::shared_ptr<Board> givenboard) {
    if (givenboard->isDecorator == 0) {
        return;
    } else {
        while (givenboard->isDecorator == 1) {
            givenboard = givenboard->
        }
    }
}