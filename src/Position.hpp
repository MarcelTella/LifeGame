#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int row;
    int col;
    Position(int rowInit, int colInit) :
        row(rowInit),
        col(colInit)
    {}
};

#endif
