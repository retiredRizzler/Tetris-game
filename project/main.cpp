#include "mainwindow.h"
#include "GUIController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    TetrisModel model(10, 20);
    QApplication a(argc, argv);
    GUIController ctr;
    return a.exec();
}
