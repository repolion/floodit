#include "board.h"
#include "square.h"

namespace oli {

Board::Board(){}

Board::Board(int height, int width,int nbCol){
    _width = width;
    _height = height ;

   // _squares.resize(_width,std::vector<Square>(_height));

    for (int y=0; y<_height; y++){
         _squares.resize(height,std::vector<Square>(width));
    }

//    for (int i=0; i<x; i++){
//        _squares.resize(i,std::vector<Square>(y));
//    }

    for (int y = 0; y<_height; y++){
        for (int x = 0; x<_width; x++){
            _squares[y][x]=Square(Position(x,y),nbCol);

        }
    }
    _squares[0][0].setCaptured();
}
Board::~Board(){}

int Board::getWidth(){
    return _width;
}

int Board::getHeight(){
    return _height;
}

 Square& Board::getSquare(int x,int y){
     return _squares[x][y];
 }

 void Board::changeColorBoard(int x,int y,Color color){
     _squares[x][y].setColor(color);
 }

}
