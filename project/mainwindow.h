#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model/TetrisModel.h"
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QKeyEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(TetrisModel& game, QWidget *parent = nullptr);
    void initialize();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene;
    TetrisModel& game;

    void displayBoard();
    void displayCurrentBrick();
    int computeRectSize();
};

#endif // MAINWINDOW_H

