#ifndef PIECEBAG_H
#define PIECEBAG_H

#include <vector>
#include "Piece.h"

class PieceBag {
public:
    PieceBag(size_t size);

    // Get the current bag of pieces
    std::vector<Piece> getBag() const;

    // Refill the bag with new pieces
    void refill();

    // Get the next piece from the bag
    Piece getNextPiece();

private:
    std::vector<Piece> bag; // Vector to store pieces in the bag
    size_t bagSize; // Size of the bag

    // Add a random piece to the bag
    void addRandomPiece();
};

#endif // PIECEBAG_H
