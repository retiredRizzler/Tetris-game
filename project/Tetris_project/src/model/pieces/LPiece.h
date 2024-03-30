#ifndef LPIECE_H
#define LPIECE_H

#include "Piece.h"

class LPiece : public Piece {
public:
    LPiece();
    bool operator==(const Piece& other) const override;

};

#endif // LPIECE_H
