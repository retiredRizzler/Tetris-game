#ifndef PIECE_H
#define PIECE_H

#include "Position.hpp"
#include <vector>

class Piece {
public:
    Piece(const std::vector<Position>& shape);

    virtual void setPosition(int r, int c);
    virtual std::vector<Position> getAbsolutePositions() const;
    virtual void rotate();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();

private:
    std::vector<Position> shape;
    int row;
    int col;
};

#endif // PIECE_H
