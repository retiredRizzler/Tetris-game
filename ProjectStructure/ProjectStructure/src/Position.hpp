#ifndef POSITION_HPP
#define POSITION_HPP

#include <utility>

class Position {
private:
    int x;
    int y;

public:
    // Constructeur prenant les coordonnées x et y
    Position(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Accesseurs pour obtenir les coordonnées x et y
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    // Méthode pour définir les coordonnées x et y
    void setX(int x_val) {
        x = x_val;
    }

    void setY(int y_val) {
        y = y_val;
    }

    // Méthode pour déplacer la position par un décalage donné
    void moveBy(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

#endif // POSITION_HPP
