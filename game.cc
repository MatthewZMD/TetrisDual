#include "game.h"

Game::Game(std::string fileName1, std::string fileName2, int l): hiScore{0}, playerTurn{0} {
    display = std::make_shared<TextDisplay>(2, 18, 11);
    board1 = std::make_shared<ConcreteBoard>(0, fileName1, l);
    board1->attach(display.get());
    board2 = std::make_shared<ConcreteBoard>(1, fileName2, l);
    board2->attach(display.get());
    board1->notifyObservers();
    board2->notifyObservers();

    // start from player 1
    board1->setNext(board1->genNext());
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

void Game::left(int n) {
    int numberOfRowsRemoved = 0;
    if (playerTurn == 0) {
        numberOfRowsRemoved = board1->left(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            //
        }

        if (board1->isTurnOver()) {
            board1->setTurnOver();
            switchTurn();
        }
    }
    else if (playerTurn == 1) {
        numberOfRowsRemoved = board2->left(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            //
        }

        if (board2->isTurnOver()) {
            board2->setTurnOver();
            switchTurn();
        }
    }
}

void Game::right(int n) {
    int numberOfRowsRemoved = 0;
    if (playerTurn == 0) {
        numberOfRowsRemoved = board1->right(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            //
        }

        if (board1->isTurnOver()) {
            board1->setTurnOver();
            switchTurn();
        }
    }
    else if (playerTurn == 1) {
        numberOfRowsRemoved = board2->right(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            //
        }

        if (board2->isTurnOver()) {
            board2->setTurnOver();
            switchTurn();
        }
    }
}

void Game::down(int n) {
    for(int i = 0; i < n; ++i){
        if (playerTurn == 0) {
            board1->down();
        }
        else if (playerTurn == 1) {
            board2->down();
        }
    }
}

void Game::rotate(bool isClockwise) {
    if (playerTurn == 0) {
        board1->rotate(isClockwise);
    }
    else if (playerTurn == 1) {
        board2->rotate(isClockwise);
    }
}

void Game::drop() {
    int numberOfRowsRemoved = 0;
    if (playerTurn == 0) {
        numberOfRowsRemoved = board1->drop();

        // special actions
        if (numberOfRowsRemoved >= 2) {
            //
        }

        if (board1->isTurnOver()) {
            board1->setTurnOver();
            switchTurn();
        }
    }
    else if (playerTurn == 1) {
        numberOfRowsRemoved = board2->drop();

        // special actions
        if (numberOfRowsRemoved >= 2) {
            //
        }

        if (board2->isTurnOver()) {
            board2->setTurnOver();
            switchTurn();
        }
    }
}

void Game::switchTurn() {
    if (playerTurn == 0) {
        board1->genThis();
        board2->setNext(board2->genNext());
        playerTurn = 1;
    }
    else if (playerTurn == 1) {
        board2->genThis();
        board1->setNext(board1->genNext());
        playerTurn = 0;
    }
}
