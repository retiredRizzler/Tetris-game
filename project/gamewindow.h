#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "./ui_gamewindow.h"
#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
