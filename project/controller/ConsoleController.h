#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../model/TetrisGame.h"

class ConsoleController {

private:
    TetrisGame game;

    void askBoardSize(int& rows, int& cols);
    void handleInput();

public:
    ConsoleController();
    void run();
};


#endif // CONTROLLER_H
