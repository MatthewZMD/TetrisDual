#ifndef _COORDINATE_H_
#define _COORDINATE_H_

struct Coordinate {
    int row, col;
    bool operator==(const Coordinate o) const;
};

#endif
