#include "game.h"

Game::Game(std::string fileName1, std::string fileName2, int l, bool isTextOnly): hiScore{0}, playerTurn{0} {
    init(fileName1, fileName2, l, isTextOnly);
}

void Game::init(std::string fileName1, std::string fileName2, int l, bool isTextOnly){
    playerTurn = 0;
    display = std::make_shared<TextDisplay>(2, 18, 11);
    if(!isTextOnly){
        window = std::make_shared<GraphicsDisplay>(590, 520);
    }
    board1 = std::make_shared<ConcreteBoard>(0, fileName1, l);
    board1->attach(display.get());
    if(!isTextOnly){
        board1->attach(window.get());
    }
    board2 = std::make_shared<ConcreteBoard>(1, fileName2, l);
    board2->attach(display.get());
    if(!isTextOnly){
        board2->attach(window.get());
    }
    board1->notifyObservers();
    board2->notifyObservers();

    // start from player 1
    board1->setNext(board1->genNext());
}

void Game::heavy() {
    if (playerTurn == 1) {
        board1 = std::make_shared<HeavyDecorator>(board1);
    }
    else if (playerTurn == 0) {
        board2 = std::make_shared<HeavyDecorator>(board2);
    }
}

void Game::blind() {
    if (playerTurn == 1) {
        board1 = std::make_shared<BlindDecorator>(board1);
        board1->notifyObservers();
    }
    else if (playerTurn == 0) {
        board2 = std::make_shared<BlindDecorator>(board2);
        board2->notifyObservers();
    }
}

void Game::force(CellType type) {
    if (playerTurn == 1) {
        board1 = std::make_shared<ForceDecorator>(board1, type);
	board1->notifyObservers();
    }
    else if (playerTurn == 0) {
        board2 = std::make_shared<ForceDecorator>(board2, type);
	board2->notifyObservers();
    }
}

void Game::recover() {
    if (playerTurn == 0) {
        board1 = board1->getBoard();
    }
    else if (playerTurn == 1) {
        board2 = board2->getBoard();
    }
}

void Game::left(std::istream & in, int n) {
    int numberOfRowsRemoved = 0;
    if (playerTurn == 0) {
        numberOfRowsRemoved = board1->left(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            execAction(in);
        }

        if (board1->isTurnOver()) {
            board1->setTurnOver();
            recover();
            switchTurn();
        }
    }
    else if (playerTurn == 1) {
        numberOfRowsRemoved = board2->left(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            execAction(in);
        }

        if (board2->isTurnOver()) {
            board2->setTurnOver();
            recover();
            switchTurn();
        }
    }
}

void Game::right(std::istream & in, int n) {
    int numberOfRowsRemoved = 0;
    if (playerTurn == 0) {
        numberOfRowsRemoved = board1->right(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            execAction(in);
        }

        if (board1->isTurnOver()) {
            board1->setTurnOver();
            recover();
            switchTurn();
        }
    }
    else if (playerTurn == 1) {
        numberOfRowsRemoved = board2->right(n);

        // special actions
        if (numberOfRowsRemoved >= 2) {
            execAction(in);
        }

        if (board2->isTurnOver()) {
            board2->setTurnOver();
            recover();
            switchTurn();
        }
    }
}

void Game::down(int n) {
    if (playerTurn == 0) {
        board1->down(n);
    }
    else if (playerTurn == 1) {
        board2->down(n);
    }
}

void Game::rotate(bool isClockwise, int n) {
    if (playerTurn == 0) {
        board1->rotate(isClockwise, n);
    }
    else if (playerTurn == 1) {
        board2->rotate(isClockwise, n);
    }
}

void Game::drop(std::istream & in, int n) {
    int numberOfRowsRemoved = 0;
    if (playerTurn == 0) {
        if(n > 1){
            board1->setCountD(n - 1);
        } else if (board1->getCountD() > 0) {
            board1->setCountD(board1->getCountD() - 1);
        }

        numberOfRowsRemoved = board1->drop();

        // special actions
        if (numberOfRowsRemoved >= 2) {
            execAction(in);
        }

        if (board1->isTurnOver()) {
            board1->setTurnOver();
            recover();
            switchTurn();
        }
    }
    else if (playerTurn == 1) {
        if(n > 1){
            board2->setCountD(n - 1);
        } else if (board2->getCountD() > 0){
            board2->setCountD(board2->getCountD() - 1);
        }

        numberOfRowsRemoved = board2->drop();

        // special actions
        if (numberOfRowsRemoved >= 2) {
            execAction(in);
        }

        if (board2->isTurnOver()) {
            board2->setTurnOver();
            recover();
            switchTurn();
        }
    }
}

void Game::levelup(int n) {
    if (playerTurn == 0) {
        for (int i = 0; i < n; ++i) {
            board1->levelUp();
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            board2->levelUp();
        }
    }
}

void Game::leveldown(int n) {
    if (playerTurn == 0) {
        for (int i = 0; i < n; ++i) {
            board1->levelDown();
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            board2->levelDown();
        }
    }
}

void Game::norandom(std::string file) {
    if (playerTurn == 0) {
        board1->noRandom(file);
    }
    else if (playerTurn == 1) {
        board2->noRandom(file);
    }
}

void Game::random() {
    if (playerTurn == 0) {
        board1->random();
    }
    else if (playerTurn == 1) {
        board2->random();
    }
}

void Game::replaceBlock(std::string cmd) {
    CellType type = CellType::E;

    if (cmd == "I") {
        type = CellType::I;
    }
    else if (cmd == "J") {
        type = CellType::J;
    }
    else if (cmd == "L") {
        type = CellType::L;
    }
    else if (cmd == "O") {
        type = CellType::O;
    }
    else if (cmd == "S") {
        type = CellType::S;
    }
    else if (cmd == "Z") {
        type = CellType::Z;
    }
    else if (cmd == "T") {
        type = CellType::T;
    }

    if (playerTurn == 0) {
        board1->replaceBlock(type);
    } else {
        board2->replaceBlock(type);
    }
}

bool Game::isAutoDrop() const {
    if (playerTurn == 0) {
        return board1->getCountD() > 0;
    } else if (playerTurn == 1) {
        return board2->getCountD() > 0;
    }
    return false;
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

// Read one special action from istream in and execute the action
void Game::execAction(std::istream & in) {
    std::cout << "Please unleash your special powers: ";
    std::string cmd;
    in >> cmd;
    if (cmd == "blind") {
        blind();
    }
    else if (cmd == "heavy") {
        heavy();
    }
    else if (cmd == "force") {
        std::string t;
        in >> t;

        CellType type = CellType::E;

        if (t == "I") {
            type = CellType::I;
        }
        else if (t == "J") {
            type = CellType::J;
        }
        else if (t == "L") {
            type = CellType::L;
        }
        else if (t == "O") {
            type = CellType::O;
        }
        else if (t == "S") {
            type = CellType::S;
        }
        else if (t == "Z") {
            type = CellType::Z;
        }
        else if (t == "T") {
            type = CellType::T;
        }

        force(type);
    } else {
        std::cout << "What are you talking about?" << std::endl;
        execAction(in);
    }
}
