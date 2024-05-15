#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "../model/TetrisModel.h"
#include "GameBoardWidget.h"
#include "../model/TetrisGame.h"

class GameWindow : public QMainWindow, Observer
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr, TetrisModel *model = nullptr, bool usePrefilled = false, int level = 1);
    ~GameWindow();

private slots:
    void quitGame();
    void pauseGame();
    void update(Observable* observable) override;

private:
    TetrisModel *model; // Instance of TetrisModel class
    GameBoardWidget *gameBoardWidget; // Widget to contain game board
    QLabel *scoreLabel; // Label to display current score
    QLabel *levelLabel; // Label to display current level
};

#endif // GAMEWINDOW_H
