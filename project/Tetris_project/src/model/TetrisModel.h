#ifndef TETRISMODEL_H
#define TETRISMODEL_H
#include "GameBoard.h"
#include "PieceBag.h"
#include "GameSate.h"
#include <iostream>


class TetrisModel
{
public:
    TetrisModel(GameBoard& board);
    void startGame();
    void movePieceRight();
    void movePieceLeft();
    void movePieceDown();
    void dropPiece();
    void rotatePiece(char dir);

private:
    GameBoard board;
    PieceBag bag;
    GameState state;
    bool isColliding(const std::shared_ptr<Piece>& piece, int row, int col) const;
};



#endif // TETRISMODEL_H
