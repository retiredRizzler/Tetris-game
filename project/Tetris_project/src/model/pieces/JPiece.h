#ifndef JPIECE_H
#define JPIECE_H

#include "Piece.h"

class JPiece : public Piece {
public:
    JPiece();
    bool operator==(const Piece& other) const override;

};

#endif // JPIECE_H
