#include "intro.h"

Intro::Intro(QWidget *parent) :
    QWidget(parent)
{
    QPixmap bkgnd(":/images/intro.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    parent->setPalette(palette);
    this->setFixedSize(720,660);
}

Intro::~Intro(){}
