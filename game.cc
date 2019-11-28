#include "game.h"

Game::Game(std::string fileName1, std::string fileName2): hiScore{0}, playerTurn{0} {
    board1 = std::shared_ptr<Board>(new ConcreteBoard(1, fileName1));
    display1 = std::shared_ptr<TextDisplay>(new TextDisplay(1));
    board1->attach(display1);

    board2 = std::shared_ptr<Board>(new ConcreteBoard(2, fileName2));
    display2 = std::shared_ptr<TextDisplay>(new TextDisplay(2));
    board2->attach(display2);
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
