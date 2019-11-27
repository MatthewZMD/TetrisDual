#include "coordinate.h"

bool Coordinate::operator==(const Coordinate o) const{
    return o.row == row && o.col == col;
}
