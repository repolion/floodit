#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include "widgetGame.h"
#include "intro.h"
#include "menustart.h"
#include "options.h"
#include "reset.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class
 * The application's controller
 * This class manage the different view of the application
 * and the has the game object
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStackedWidget *_myStack;
    Intro *_intro;
    MenuStart *_menuStart;
    Options *_options;
    Reset * _reset;
    WidgetGame *_wg;
    void setBackground(QString image);

public slots:
    void delScores();
    void resetOrNot();
    void cancel();
    void quickGame();
    void newGame();
    void newGame(int height,int width,int nbCol);

};

#endif // MAINWINDOW_H
