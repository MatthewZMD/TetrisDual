#include "forcedecorator.h"

using namespace std;

ForceDecorator::~ForceDecorator() {
    delete board;
}

ForceDecorator::(Board* board, CellType giventype): giventype{giventype} {}

Block genBlock() {}