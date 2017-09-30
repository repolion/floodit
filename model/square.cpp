#include "square.h"

namespace oli {

Square::Square(){

}
Square::Square(Position position, int nbCol){
    //erreur si nbCol > 9 !!!
    _position = position;
    //    _color = static_cast<Color>(rand()%6);
//        srand((int)time(0));
        int randomNumber = (random(0,nbCol));
       // RED,GREEN,YELLOW,BLUE,PURPLE,DEEPPINK,CYAN,ORANGE,GREY
   // std::cout<<randomNumber<<std::endl;
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
    //std::cout<<"set color"<<std::endl;
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

QColor Square::getQColor(){
    QColor color;
    switch(this->_color){
    case Color::RED:
        color = Qt::red;
        break;
    case Color::GREEN:
        color = QColor(50,205, 50, 255);
        break;
    case Color::ORANGE:
        color = QColor(238, 154, 0, 255);
        break;
    case Color::BLUE:
        color = QColor(72, 118, 255, 255);
        break;
    case Color::PURPLE:
        color =  QColor(89, 51, 204, 255);
        break;
    case Color::DEEPPINK:
        color = QColor(255, 52, 179, 255);
        break;
    case Color::CYAN:
        color = Qt::cyan;
        break;
    case Color::YELLOW:
        color = Qt::yellow;
        break;
    case Color::GREY:
        color = QColor(204,204,204,255);
        break;

    }
    return color;
}


//a partir de combien + combien
int Square::random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if ( first )
   {
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max - min);
}

}
