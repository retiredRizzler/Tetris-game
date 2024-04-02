#ifndef SQUAREPIECE_H
#define SQUAREPIECE_H

#include "Piece.h"

class SquarePiece : public Piece {
public:
    SquarePiece();
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
    bool operator==(const Piece& other) const override;

};

#endif // SQUAREPIECE_H
