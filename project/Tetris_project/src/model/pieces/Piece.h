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
    std::vector<std::vector<int>> getRotationMatrix();
    void negateMatrix(std::vector<std::vector<int>>& matrix);
    virtual bool operator==(const Piece& other) const;

protected:
    std::vector<Position> shape;

private:
    int row;
    int col;
    void rotate(const std::vector<std::vector<int>>& rotationMatrix);
};

#endif // PIECE_H
