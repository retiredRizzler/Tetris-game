#ifndef TETRISGAME_H
#define TETRISGAME_H

#include "TetrisModel.h"

class TetrisGame {
private:
    TetrisModel model;

public:
    TetrisGame(int boardRow, int boardCol);

    void start();

    void end();

    bool isGameOver();

    void movePieceDown();

    void movePieceLeft();

    void movePieceRight();

    void dropPiece();

    void rotatePiece(char dir);

    void updateGame();

    GameBoard& getGameBoard();
};

#endif // TETRISGAME_H
