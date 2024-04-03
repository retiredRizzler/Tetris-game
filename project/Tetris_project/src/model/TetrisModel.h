#ifndef TETRISMODEL_H
#define TETRISMODEL_H
#include "GameBoard.h"
#include "PieceBag.h"
#include "GameState.h"
#include "Observable.h"
#include <iostream>
#include <chrono>


class TetrisModel : public Observable
{
public:
    TetrisModel(int boardRow, int boardCol);
    void startGame();
    void movePieceRight();
    void movePieceLeft();
    void movePieceDown();
    void dropPiece();
    void rotatePiece(char dir);
    void updateGame();
    bool isGameOver();
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

    const int MAX_SCORE = 50000;
    const int MAX_COMPLETED_LINES = 100;
    const int MAX_TIME_SECONDS = 300;
    std::chrono::steady_clock::time_point startTime;
};



#endif // TETRISMODEL_H
