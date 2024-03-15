#include "PieceBag.h"
#include "LPiece.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
// Constructor
PiecesBag::PiecesBag(int size) : currentIndex(0) {
    // Initialize random seed
    srand(time(nullptr));

    // Fill the bag with pieces
    /*for (int i = 0; i < size; ++i) {
        // Randomly generate the type of piece and create it
        // Here, you would add your logic to create pieces according to your game's rules
        // For example, you might have different types of pieces (e.g., LPiece, TPiece, etc.)
        // and you would randomly choose one of these types to create a new piece.
        // For simplicity, let's assume a generic Piece for now.

        //Piece newPiece;
        std::vector<Piece> listePiece = {LPiece l,}
        bag.push_back(newPiece);
    }*/
    for (int i = 0; i < size; ++i) {
        // Generate a random type of piece (for simplicity, let's assume LPiece and JPiece)
        // You can extend this to support more types of pieces
        int pieceType = rand() % 2; // Generating a random number between 0 and 1 for simplicity
        std::vector<Position> positions; // Vector to hold positions for the piece
        // Generate positions for the piece
        // Add your logic here to generate positions as per your requirements
        // For simplicity, let's assume the positions are generated randomly here
            // Generate random positions (replace with your logic)
            Position newPos(0,0);
            positions.push_back(newPos);

        // Create the piece based on its type
        if (pieceType == 0) {
            LPiece newLPiece(positions);
            bag.push_back(newLPiece);
        } else {
            JPiece newJPiece(positions);
            bag.push_back(newJPiece);
        }
    }
}


// Method to get the bag
std::vector<Piece> PiecesBag::getBag() const {
    return bag;
}

// Method to refill the bag if it's empty
void PiecesBag::refill() {
    // Refill the bag with new pieces
    // For simplicity, we'll just clear the bag and refill it with new pieces
    // You might want to implement a more sophisticated logic for refilling based on your game's rules
    bag.clear();
    // Assuming the bag has a fixed size (as specified in the constructor)
    for (size_t i = 0; i < bag.size(); ++i) {
        Piece newPiece;
        bag.push_back(newPiece);
    }
}

// Method to get the next piece from the bag
Piece PiecesBag::getNextPiece() {
    // Check if the bag is empty
    if (currentIndex >= bag.size()) {
        // Refill the bag if it's empty
        refill();
        // Reset the current index
        currentIndex = 0;
    }

    // Get the next piece from the bag
    Piece nextPiece = bag[currentIndex];
    // Increment the current index for the next call
    ++currentIndex;

    return nextPiece;
}
