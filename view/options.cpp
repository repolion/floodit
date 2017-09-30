#include "options.h"

Options::Options(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *boxAll = new QVBoxLayout();
    QHBoxLayout *boxSize = new QHBoxLayout();
    QHBoxLayout *boxWidth = new QHBoxLayout();
    QLabel *width = new QLabel("width");
    _spinWidth = new QSpinBox();
    QHBoxLayout *boxHeight = new QHBoxLayout();
    QLabel *height = new QLabel("height");
    _spinHeight = new QSpinBox();
    QHBoxLayout *boxColors = new QHBoxLayout();
    QLabel *nbColors = new QLabel("Number of colors");
    _spinColors = new QSpinBox();
    QPushButton *start = new QPushButton("Start");
    QPushButton *cancel = new QPushButton("Cancel");
    start->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    cancel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    _spinColors->setRange(2,8);
    _spinColors->setValue(4);

    _spinHeight->setRange(5,35);
    _spinHeight->setValue(10);

    _spinWidth->setRange(5,35);
    _spinWidth->setValue(10);

    connect(cancel,SIGNAL(clicked()),parent,SLOT(cancel()));

    connect(start,SIGNAL(clicked()),this,SLOT(reemitOptions()));

    boxWidth->addWidget(width);
    boxWidth->addWidget(_spinWidth);

    boxWidth->addWidget(height);
    boxWidth->addWidget(_spinHeight);

    boxSize->addLayout(boxWidth);
    boxSize->addLayout(boxHeight);

    boxColors->addWidget(nbColors);
    boxColors->addWidget(_spinColors);

    boxAll->addLayout(boxSize);
    boxAll->addLayout(boxColors);
    boxAll->addWidget(start);
    boxAll->addWidget(cancel);

    boxAll->setAlignment(start,Qt::AlignCenter);
    boxAll->setAlignment(cancel,Qt::AlignCenter);
   // boxAll->setAlignment(start,Qt::AlignBottom);
   // boxAll->setAlignment(cancel,Qt::AlignTop);
    boxAll->setAlignment(Qt::AlignCenter);
    boxAll->setMargin(240);



    setLayout(boxAll);

//    QPushButton *start = new QPushButton("Start",this);
    connect(this,(SIGNAL(options(int,int,int))),parent,SLOT(newGame(int,int,int)));
}

Options::~Options(){}

  void Options::reemitOptions(){
      emit options(_spinHeight->value(),_spinWidth->value(),_spinColors->value());
  }
