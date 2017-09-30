#include "mybutton.h"

namespace oli {

MyButton::MyButton(){

}

MyButton::MyButton(int num,Color color/*,QWidget & fenetre*/){
    _color = color;
//    _button = new QPushButton("",&fenetre);
     _button = new QPushButton("");
    _button->setGeometry(QRect(QPoint((45*num),350),QSize(45,45)));
    QColor col =getQColor(color);
    QString qss = QString("background-color: %1").arg(col.name());
    _button->setStyleSheet(qss);
    _button->setFocusPolicy(Qt::NoFocus);
}

void MyButton::setVisibility(bool visibility){
    _button->setVisible(visibility);
}

QPushButton *MyButton::getButton(){
    return _button;
}

QColor MyButton::getQColor(Color col){
    QColor color;
    switch(col){
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

Color MyButton::getColor(){
    return _color;
}

}
