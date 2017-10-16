#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "square.h"
#include "floodexception.h"

namespace oli {

class Board
{
private:
    int _width;
    int _height;
    std::vector<std::vector<Square> > _squares;

public:
    Board();
    ~Board();
    Board(int x,int y,int nbCol);

    int getWidth();
    int getHeight();
    Square& getSquare(int x, int y);
    void changeColorBoard(int x,int y,Color color);
};

}

#endif // BOARD_H
