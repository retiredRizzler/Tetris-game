#include "Piece.h"
#include "IPiece.h"
class PieceBag {
public:
    PieceBag(size_t size) : bagSize(size) {
        refill();
    }

    // Get the current bag of pieces
    std::vector<Piece> getBag() const {
        return bag;
    }

    // Refill the bag with new pieces
    void refill() {
        bag.clear();
        for (size_t i = 0; i < bagSize; ++i) {
            // Add random pieces to the bag
            // You can customize this to add specific pieces or a sequence of pieces if needed
            // For now, let's add a random piece to the bag
            addRandomPiece();
        }
    }

    // Get the next piece from the bag
    Piece getNextPiece() {
        // If bag is empty, refill it
        if (bag.empty()) {
            refill();
        }
        // Get the first piece from the bag
        Piece nextPiece = bag.front();
        // Remove the first piece from the bag
        bag.erase(bag.begin());
        return nextPiece;
    }

private:
    std::vector<Piece> bag; // Vector to store pieces in the bag
    size_t bagSize; // Size of the bag

    // Add a random piece to the bag
    void addRandomPiece() {
        // Create a random piece (you can customize this to add specific pieces)
        // For now, let's add a ZPiece as an example
        IPiece randomPiece;
        bag.push_back(randomPiece);
    }
};
