#ifndef PIECEBAG_H
#define PIECEBAG_H
#include <vector>
#include "Piece.hpp"
#include "LPiece.h"

class PiecesBag {
private:
    std::vector<Piece> bag;
    int currentIndex;

public:
    // Constructor to initialize the bag with given size
    PiecesBag(int size);

    // Method to get the bag
    std::vector<Piece> getBag() const;

    // Method to refill the bag if it's empty
    void refill();

    // Method to get the next piece from the bag
    Piece getNextPiece();
};
/*private:
    std::vector<Piece*> bag;
    int currentIndex;

public:
    PiecesBag(int size);
    ~PiecesBag(); // Destructor to free memory

    Piece* getNextPiece();
};*/
#endif // PIECEBAG_H
