#include "Position.hpp"
#include <iostream>
#include <vector>
#include <utility>

class Piece {
protected:
    std::vector<Position> piece_pos;

public:
    // Constructeur prenant la position initiale de la pièce
    Piece(const std::vector<Position>& pos) : piece_pos(pos) {}

    // Méthode pour faire pivoter la pièce
    virtual void rotate(int rotation){
        if(rotation == 1){
            for(auto& posi : piece_pos){
                int val = posi.getX();
                posi.setX(posi.getY());
                posi.setY(-val);
            }
        } else {
            for(auto& posi : piece_pos){
                int val = posi.getX();
                posi.setX(-posi.getY());
                posi.setY(val);
            }
        }
    };

    // Méthodes pour déplacer la pièce
    virtual void moveLeft(){
        // Parcourir toutes les positions de la pièce et déplacer chaque position d'une unité vers la gauche
        for (auto& pos : piece_pos) {
            pos.setX(pos.getX() - 1);
        }
    };
    virtual void moveRight(){
        // Parcourir toutes les positions de la pièce et déplacer chaque position d'une unité vers la gauche
        for (auto& pos : piece_pos) {
            pos.setX(pos.getX() + 1);
        }
    };
    virtual void moveDown(){
        // Parcourir toutes les positions de la pièce et déplacer chaque position d'une unité vers la gauche
        for (auto& pos : piece_pos) {
            pos.setX(pos.getY() - 1);
        }
    };

    // Méthode pour obtenir la position de la pièce
    std::vector<Position> getPos() const {
        return piece_pos;
    }
};
