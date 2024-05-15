#include "gui/mainwindow.h"

#include <QApplication>
#include "controller/ConsoleController.h"

int main(int argc, char *argv[])
{
   // QApplication a(argc, argv);
   // MainWindow w;
   // w.show();
    //return a.exec();
    ConsoleController ctr;
    ctr.run();
}
