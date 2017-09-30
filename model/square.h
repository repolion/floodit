#ifndef SQUARE_H
#define SQUARE_H

#include "color.h"
#include "position.h"
#include <QColor>
#include <random>
#include <iostream>
#include <time.h>


namespace oli {

class Square{

private:
    Position _position;
    Color _color;
    bool _captured;
    int random(int min, int max);
public:
    Square();
    Square(Position position,int nbCol);
    Square(Position position,Color color);
    ~Square();
    void setColor(Color color);
    Color getColor();
    QColor getQColor();
    void setCaptured();
    bool getCaptured();

};

}

#endif // SQUARE_H
