#ifndef SQUARE_H
#define SQUARE_H

#include <QColor>
#include <random>
#include <iostream>
#include <time.h>
#include "color.h"
#include "position.h"

namespace oli {

class Square{

public:
    /*!
     * \brief Square
     * Square's default constructor
     */
    Square();
    /*!
     * \brief Square
     * square's constructor with parameters
     * \param position the position of the square
     * \param nbCol the square's color
     */
    Square(Position position,int nbCol);

    /*!
     * \brief Square
     * \param position
     * \param color
     */
    Square(Position position,Color color);
    //destructor
    ~Square();

    /*!
     * \brief setColor
     * to set the square's color
     * \param color the color to set
     */
    void setColor(Color color);

    /*!
     * \brief getColor
     * \return the Square's color
     */
    Color getColor();

    /*!
     * \brief getQColor
     * \return the square's Qcolor
     */
    QColor getQColor();

    /*!
     * \brief setCaptured
     * set if the square is captured or not
     */
    void setCaptured();

    /*!
     * \brief getCaptured
     * \return if the square is captured or not
     */
    bool getCaptured();

private:
    Position _position;
    Color _color;
    bool _captured;
    int random(int min, int max);
};

}

#endif // SQUARE_H
