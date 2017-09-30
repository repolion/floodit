#include "position.h"

namespace oli {

//  constructeur par défaut
Position::Position():Position(0,0){}

//  constructeur avec paramètres
Position::Position(int x, int y):_x{x}, _y{y}{}

//  destructeur
Position::~Position(){}


// Getters
int Position::getX(){
    return _x;
}

int Position::getY(){
    return _y;
}

}
