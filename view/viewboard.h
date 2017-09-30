#ifndef VIEWBOARD_H
#define VIEWBOARD_H

#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>
#include "observer/observer.h"
#include "model/floodgame.h"
#include "mybutton.h"
#include "buttonwidget.h"

namespace oli {

class ViewBoard: public Observer
      {
private:
    Floodgame *_game;
    int _width;
    int _height;
    QVBoxLayout *_vBox;
//    QPixmap _pixmap;
    QLabel * _ql;
    Color _myColor;
    ButtonWidget *_buttonWidget;
    QHBoxLayout * _hboxBoutons;

   // void addColors(QStringList &texts,int nbColors);
private slots:


signals:
    void test();

public:
    ViewBoard();
    ViewBoard(QWidget &fenetre, Floodgame * game,int nbCol);
    void setDisplay();
    void Update();
  //  std::string getColor(Color _myColor);
};

}

#endif // VIEWBOARD_H
