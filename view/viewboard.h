#ifndef VIEWBOARD_H
#define VIEWBOARD_H

#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>
#include <QVariant>
#include "observer/observer.h"
#include "model/floodgame.h"
#include "buttonwidget.h"
#include "colorConvert.h"

namespace oli {

/*!
 * \brief The ViewBoard class
 * the class that create and refresh the game's board view
 */
class ViewBoard: public Observer
      {
private:
    Floodgame *_game;
    int _width;
    int _height;
    QVBoxLayout *_vBox;
    QLabel * _ql;
    QLabel * _gameOver;
    QLabel *  _record;
    QLabel *  _nbClickLabel;
    Color _myColor;
    ButtonWidget *_buttonWidget;
    QHBoxLayout * _hboxBoutons;
    int _valueRecord;
private slots:

signals:
    void test();

public:
    ViewBoard();
    ViewBoard(QWidget &fenetre, Floodgame * game,int nbCol);
    void setDisplay();
    void Update();
};

}

#endif // VIEWBOARD_H
