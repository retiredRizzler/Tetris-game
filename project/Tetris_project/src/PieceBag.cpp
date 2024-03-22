#include "PieceBag.h"
#include <memory>
#include <vector>
#include <cstdlib>
#include "Piece.h"
#include "IPiece.h"
#include "ZPiece.h"
#include "JPiece.h"
#include "LPiece.h"
#include "SquarePiece.h"
#include "SPiece.h"
#include "TPiece.h"

PieceBag::PieceBag(size_t size) : bagSize(size) {
    refill();
}

const std::vector<std::shared_ptr<Piece>>& PieceBag::getBag() const {
    return bag;
}

void PieceBag::refill() {
    bag.clear(); // Clear existing bag contents before refilling
    for (size_t i = 0; i < bagSize; ++i) {
        addRandomPiece(); // Add random piece types to the bag
    }
}

std::shared_ptr<Piece> PieceBag::getNextPiece() {
    if (bag.empty()) {
        refill(); // Refill if the bag is empty
    }
    std::shared_ptr<Piece> nextPiece = bag.front();
    bag.erase(bag.begin()); // Remove the used piece from the front
    return nextPiece;
}

void PieceBag::addRandomPiece() {
    int randomPiece = rand() % 7;

    switch (randomPiece) {
    case 0:
        bag.push_back(std::make_shared<IPiece>());
        break;
    case 1:
        bag.push_back(std::make_shared<SquarePiece>());
        break;
    case 2:
        bag.push_back(std::make_shared<ZPiece>());
        break;
    case 3:
        bag.push_back(std::make_shared<JPiece>());
        break;
    case 4:
        bag.push_back(std::make_shared<SPiece>());
        break;
    case 5:
        bag.push_back(std::make_shared<LPiece>());
        break;
    case 6:
        bag.push_back(std::make_shared<TPiece>());
        break;

    default:
        break;
    }
}
