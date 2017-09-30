#ifndef WIDGETGAME_H
#define WIDGETGAME_H

#include "view/viewboard.h"
#include "model/floodgame.h"
#include <QWidget>
#include <QKeyEvent>
#include <QStackedWidget>

using namespace oli;

class WidgetGame : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetGame(int height,int width,int nbCol,QWidget *parent = 0);
    ~WidgetGame();


private slots:
    void reemit();
    void restart();
    void play(int i);
signals:
    void reemitMain();
private:
    Floodgame *_game;
    ViewBoard _viewboard;
};

#endif // WIDGETGAME_H
