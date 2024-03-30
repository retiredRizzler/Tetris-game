#ifndef SPIECE_H
#define SPIECE_H


#include "Piece.h"

class SPiece : public Piece {
public:
    SPiece();
    bool operator==(const Piece& other) const override;

};

#endif // SPIECE_H
