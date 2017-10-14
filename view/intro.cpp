#include "intro.h"

Intro::Intro(QWidget *parent) :
    QWidget(parent)
{
//    QLabel *label = new QLabel(this);
//    label->setText("Introduction");

 //   this->setStyleSheet("QWidget {background-image: url(:/images/test.jpg) }");

    QPixmap bkgnd(":/images/test.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    parent->setPalette(palette);
    this->setFixedSize(720,660);

}

Intro::~Intro(){}
