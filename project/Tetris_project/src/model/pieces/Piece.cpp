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

// Helper function to create a rotation matrix for rotation
std::vector<std::vector<int>> getRotationMatrix() {
    return {{0, 1}, {-1, 0}};
}


void Piece::rotate() {
    std::vector<Position> rotatedShape;
    std::vector<std::vector<int>> rotationMatrix = getRotationMatrix();

    for (const auto& square : shape) {
        int newX = rotationMatrix[0][0] * square.getX() + rotationMatrix[0][1] * square.getY();
        int newY = rotationMatrix[1][0] * square.getX() + rotationMatrix[1][1] * square.getY();
        rotatedShape.push_back({newX, newY});
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

int Piece::getRow() {
    return row;
}

int Piece::getCol() {
    return col;
}

std::vector<Position>& Piece::getShape() {
    return shape;
}

bool Piece::operator==(const Piece& other) const {
    const Piece* otherPiece = dynamic_cast<const Piece*>(&other);
    return otherPiece != nullptr && shape == otherPiece->shape;
}


