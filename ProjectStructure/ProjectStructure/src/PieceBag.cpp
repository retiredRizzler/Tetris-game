#include "Piece.h"
#include "IPiece.h"
#include "JPiece.h"
#include "LPiece.h"
#include "SPiece.h"
#include "SquarePiece.h"
#include "ZPiece.h"
#include "TPiece.h"
#include <cstdlib> // In order to use rand() function


class PieceBag {
public:
    PieceBag(size_t size) : bagSize(size) {
        refill();
    }

    std::vector<Piece> getBag() const {
        return bag;
    }

    void refill() {
        bag.clear();
        for (size_t i = 0; i < bagSize; ++i) {
            addRandomPiece();
        }
    }

    Piece getNextPiece() {
        if (bag.empty()) {
            refill();
        }
        Piece nextPiece = bag.front();
        // Remove the first piece from the bag
        bag.erase(bag.begin());
        return nextPiece;
    }

private:
    std::vector<Piece> bag;
    size_t bagSize;

    void addRandomPiece() {
        int randomIndex = rand() % 7;

        switch (randomIndex) {
        case 0:
            bag.push_back(IPiece());
            break;
        case 1:
            bag.push_back(JPiece());
            break;
        case 2:
            bag.push_back(LPiece());
            break;
        case 3:
            bag.push_back(SquarePiece());
            break;
        case 4:
            bag.push_back(SPiece());
            break;
        case 5:
            bag.push_back(ZPiece());
            break;
        case 6:
            bag.push_back(TPiece());
            break;
        default:
            break;
        }
    }
};
