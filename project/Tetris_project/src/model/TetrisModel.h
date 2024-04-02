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
    void updateGame();
    GameState& getState();
    GameBoard& getBoard();
    PieceBag& getBag();

private:
    GameBoard board;
    PieceBag bag;
    GameState state;
    int totalCompletedLine;
    int dropScore;
    bool canMoveDown();
    bool isColliding(const std::shared_ptr<Piece>& piece, int row, int col) const;
    void updateScore(int completedLine);
};



#endif // TETRISMODEL_H
