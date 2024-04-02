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

public:
    GameState(int score, std::shared_ptr<Piece> currentPiece, int currentLevel);

    // Getters
    int getScore() const;
    const std::shared_ptr<Piece>& getCurrentPiece() const;
    int getCurrentLevel() const;
    const std::shared_ptr<Piece>& getNextPiece() const;

    // Setters
    void incrementScore(int score);
    void updateCurrentPiece(PieceBag& pieceBag);
    void setCurrentLevel(int level);
};

#endif // GAMESTATE_H
