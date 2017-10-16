#include "mybutton.h"

namespace oli {

MyButton::MyButton(){

}

MyButton::MyButton(int num,Color color){

    QColor col =ColorConvert::getQColor(color);
    QString qss = QString("background-color: %1").arg(col.name());

    _color = color;
    _button = new QPushButton("");
    _button->setGeometry(QRect(QPoint((45*num),350),QSize(45,45)));
    _button->setStyleSheet(qss);
    _button->setFocusPolicy(Qt::NoFocus);
}

void MyButton::setVisibility(bool visibility){
    _button->setVisible(visibility);
}

QPushButton *MyButton::getButton(){
    return _button;
}

Color MyButton::getColor(){
    return _color;
}

}
