#ifndef IPIECE_H
#define IPIECE_H

#include "Piece.h"

class IPiece : public Piece {
public:
    IPiece();
    bool operator==(const Piece& other) const override;

};
#endif // IPIECE_H
