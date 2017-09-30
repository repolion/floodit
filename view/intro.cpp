#include "intro.h"

Intro::Intro(QWidget *parent) :
    QWidget(parent)
{
    QLabel *label = new QLabel(this);
    label->setText("Introduction");
}

Intro::~Intro(){}
