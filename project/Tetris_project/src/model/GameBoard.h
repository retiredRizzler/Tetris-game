#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <memory>
#include "pieces/Piece.h"

class GameBoard {
private:
    int rows;
    int cols;
    std::vector<std::vector<std::shared_ptr<Piece>>> board;

public:
    GameBoard(int rows, int cols);

    int getRows() const;
    int getCols() const;

    std::shared_ptr<Piece> getPieceAt(int row, int col) const;
    void setPieceAt(int row, int col, const std::shared_ptr<Piece>& piece);

    bool isInsideBoard(int row, int col) const; // Helper function
    bool isColliding(const std::shared_ptr<Piece>& piece, int row, int col) const;
    std::vector<int> clearCompletedLines();
};

#endif // GAMEBOARD_H
