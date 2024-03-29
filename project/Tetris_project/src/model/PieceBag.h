#ifndef PIECEBAG_H
#define PIECEBAG_H

#include <vector>
#include <memory>
#include "pieces/Piece.h" // Assuming Piece.h is implemented

class PieceBag {
public:
    PieceBag(size_t size);

    // Get a const reference to the current bag contents (avoid modification)
    const std::vector<std::shared_ptr<Piece>>& getBag() const;

    // Refill the bag with new pieces
    void refill();

    // Get the next piece from the bag
    std::shared_ptr<Piece> getNextPiece();

private:
    std::vector<std::shared_ptr<Piece>> bag;
    size_t bagSize;
    void addRandomPiece();
};

#endif // PIECEBAG_H
