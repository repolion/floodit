#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "square.h"
#include "floodexception.h"

namespace oli {
/*!
 * \brief The Board class
 */
class Board
{
private:
    /*!
     * \brief _width the board's width
     */
    int _width;

    /*!
     * \brief _height the board's height
     */
    int _height;

    /*!
     * \brief _squares the board composed by squares
     */
    std::vector<std::vector<Square> > _squares;

public:
    /*!
     * \brief Board
     * the default constructor
     */
    Board();
    //destructor
    ~Board();

    /*!
     * \brief Board getters height
     * \param x the board's width
     * \param y the board's height
     * \param nbCol the number of color possible for the squares
     */
    Board(int x,int y,int nbCol);

    int getWidth();
    /*!
     * \brief getHeight getters width
     * \return the board's width
     */
    int getHeight();

    /*!
     * \brief getSquare
     * \return the board's height
     */
    Square& getSquare(int x, int y);

    /*!
     * \brief changeColorBoard
     * to change the color of a certain square on the board
     * \param x position on x axis
     * \param y position on y axis
     * \param color the new color
     */
    void changeColorBoard(int x,int y,Color color);
};

}

#endif // BOARD_H
