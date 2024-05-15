/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *welcomeMessage;
    QPushButton *startButton;
    QPushButton *controlsButton;
    QPushButton *quitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(566, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        welcomeMessage = new QLabel(centralwidget);
        welcomeMessage->setObjectName("welcomeMessage");
        welcomeMessage->setGeometry(QRect(180, 40, 201, 41));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(210, 200, 93, 29));
        controlsButton = new QPushButton(centralwidget);
        controlsButton->setObjectName("controlsButton");
        controlsButton->setGeometry(QRect(210, 260, 93, 29));
        quitButton = new QPushButton(centralwidget);
        quitButton->setObjectName("quitButton");
        quitButton->setGeometry(QRect(210, 320, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 566, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        welcomeMessage->setText(QCoreApplication::translate("MainWindow", "Welcome to the Tetris game !", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        controlsButton->setText(QCoreApplication::translate("MainWindow", "How to Play", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
