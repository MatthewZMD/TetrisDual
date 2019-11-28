#include "game.h"

Game::Game(std::string fileName1, std::string fileName2, int l): hiScore{0}, playerTurn{0} {
    std::shared_ptr<TextDisplay> display = std::make_shared<TextDisplay>(2, 18, 11);	
    board1 = std::shared_ptr<Board>(new ConcreteBoard(1, fileName1, l));
    board1->attach(display.get());
    board2 = std::shared_ptr<Board>(new ConcreteBoard(2, fileName2, l));
    board2->attach(display.get());
}

void Game::heavy(std::shared_ptr<Board> givenBoard) {
    givenBoard = std::make_shared<HeavyDecorator>(givenBoard);
}

void Game::blind(std::shared_ptr<Board> givenBoard) {
    givenBoard = std::make_shared<BlindDecorator>(givenBoard);
}

void Game::force(std::shared_ptr<Board> givenBoard, CellType giventype) {
    givenBoard = std::make_shared<ForceDecorator>(givenBoard, giventype);
}

void Game::recover(std::shared_ptr<Board> givenBoard) {
    givenBoard = givenBoard->getBoard();
}
