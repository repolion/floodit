#include "square.h"

namespace oli {

Square::Square(){

}
Square::Square(Position position, int nbCol){
    _position = position;
        int randomNumber = (random(0,nbCol));
    _color = static_cast<Color>(randomNumber);
    _captured = false;
}

Square::Square(Position position,Color color){
    _position = position;
    _color = color;
}

//  destructeur
Square::~Square(){}

void Square::setColor(Color color){
    _color = color;
}

Color Square::getColor(){
    return _color;
}

void Square::setCaptured(){
    _captured = true;
}
bool Square::getCaptured(){
    return _captured;
}

int Square::random(int min, int max)
{
   static bool first = true;
   if ( first )
   {
      srand(time(NULL));
      first = false;
   }
   return min + rand() % (max - min);
}

}
