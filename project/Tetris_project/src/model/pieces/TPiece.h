#ifndef TPIECE_H
#define TPIECE_H

#include "Piece.h"

class TPiece : public Piece {
public:
    TPiece();
    bool operator==(const Piece& other) const override;
};

#endif // TPIECE_H
