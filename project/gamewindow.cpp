#include "ui_gamewindow.h"
#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}
