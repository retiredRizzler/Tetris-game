#ifndef PIECE_H
#define PIECE_H

#include "../Position.hpp"
#include <vector>

class Piece {
public:
    Piece(const std::vector<Position>& shape);

    virtual void setPosition(int r, int c);
    virtual std::vector<Position> getAbsolutePositions() const;
    virtual void rotateClockwise();
    virtual void rotateCounterClockwise();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual int getRow();
    virtual int getCol();
    std::vector<Position>& getShape();
    virtual bool operator==(const Piece& other) const;

protected:
    std::vector<Position> shape;

private:
    int row;
    int col;
    std::vector<std::vector<int>> getRotationMatrix();
};

#endif // PIECE_H
