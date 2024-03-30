#ifndef ZPIECE_H
#define ZPIECE_H

#include "Piece.h"

class ZPiece : public Piece {
public:
    ZPiece();
    bool operator==(const Piece& other) const override;

};

#endif // ZPIECE_H
