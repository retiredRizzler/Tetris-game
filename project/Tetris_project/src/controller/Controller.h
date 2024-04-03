#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../model/TetrisGame.h"
#include "../view/ConsoleView.hpp"

class Controller {

private:
    TetrisGame tetrisGame;


    void askBoardSize(int& rows, int& cols);
    void handleInput();

public:
    Controller();
    void run();
};


#endif // CONTROLLER_H
