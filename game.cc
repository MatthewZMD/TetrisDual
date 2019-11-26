#include "game.h"

Game::Game(): hiScore{0}, playerTurn{0} {
    for(int i = 0; i < playerNum; ++i){
        boards.emplace_back(std::shared_ptr<Board>(new ConcreteBoard()));
        displays.emplace_back(std::shared_ptr<TextDisplay>(new TextDisplay()));
        boards.at(i)->attach(displays.at(i));
    }
}

void Game::heavy(std::shared_ptr<Board> givenBoard) {
    givenBoard = std::shared_ptr<Board>(new HeavyDecorator(givenBoard));
}

void Game::blind(std::shared_ptr<Board> givenBoard) {
    givenBoard = std::shared_ptr<Board>(new BlindDecorator(givenBoard));
}

void Game::force(std::shared_ptr<Board> givenBoard, CellType giventype) {
    givenBoard = std::shared_ptr<Board>(new ForceDecorator(givenBoard, giventype));
}

void Game::recover(std::shared_ptr<Board> givenBoard) {
    givenBoard = givenBoard->getBoard();
}
