#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include "widgetGame.h"
#include "intro.h"
#include "menustart.h"
#include "options.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    QStackedWidget getStack();

private:
    Ui::MainWindow *ui;
    QStackedWidget *_myStack;
    Intro *_intro;
    MenuStart *_menuStart;
    Options *_options;
    WidgetGame *_wg;

public slots:

    void cancel();
    void quickGame();
    void newGame();
    void newGame(int height,int width,int nbCol);

};

#endif // MAINWINDOW_H
