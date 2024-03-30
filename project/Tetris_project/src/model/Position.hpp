#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
private:
    int x;
    int y;

public:
    Position(int xVal, int yVal) : x(xVal), y(yVal) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int xVal) {
        x = xVal;
    }

    void setY(int yVal) {
        y = yVal;
    }

    void moveBy(int dx, int dy) {
        x += dx;
        y += dy;
    }
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

#endif // POSITION_HPP
