#include "Piece.h"

Piece::Piece(const std::vector<Position>& shape) : shape(shape), row(0), col(0) {}

void Piece::setPosition(int r, int c) {
    row = r;
    col = c;
}

std::vector<Position> Piece::getAbsolutePositions() const {
    std::vector<Position> absolutePositions;
    for (const auto& relativePos : shape) {
        absolutePositions.push_back({row + relativePos.getX(), col + relativePos.getY()});
    }
    return absolutePositions;
}

void Piece::rotate() {
    std::vector<Position> rotatedShape;
    for (const auto& square : shape) {
        rotatedShape.push_back({-square.getY(), square.getX()});
    }
    shape = rotatedShape;
}

void Piece::moveDown() {
    row++;
}

void Piece::moveLeft() {
    col--;
}

void Piece::moveRight() {
    col++;
}
