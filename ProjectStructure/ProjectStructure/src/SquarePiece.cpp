#include "Piece.hpp"

class SquarePiece : public Piece {
public:
    // Implémentation de la rotation spécifique pour cette pièce
    virtual void rotate() override {
        return;
    }
};
