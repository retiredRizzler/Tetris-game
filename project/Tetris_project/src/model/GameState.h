#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "pieces/Piece.h"
#include "PieceBag.h"

class GameState {
private:
    int score;
    std::shared_ptr<Piece> currentPiece;
    int currentLevel;
    std::shared_ptr<Piece> nextPiece;
    bool gameOver;

public:
    GameState(int score, std::shared_ptr<Piece> currentPiece, int currentLevel, PieceBag& pieceBag);

    // Getters
    int getScore() const;
    const std::shared_ptr<Piece>& getCurrentPiece() const;
    int getCurrentLevel() const;
    const std::shared_ptr<Piece>& getNextPiece() const;
    bool isGameOver() const;

    // Setters
    void setScore(int score);
    void updateCurrentPiece(PieceBag& pieceBag);
    void setCurrentLevel(int level);
    void setGameOver(bool isOver);
};

#endif // GAMESTATE_H
