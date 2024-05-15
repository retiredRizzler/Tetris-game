#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "ui_startwindow.h"
#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::StartWindow *ui;
    QGraphicsScene scene;

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    int getWidthSpinBox() const;
    int getHeightSpinBox() const;
    bool getPrefilledChoice() const;
    Ui::StartWindow& getUi() const;
    void cleanRestart();
};

#endif // STARTWINDOW_H
