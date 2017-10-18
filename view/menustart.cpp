#include "menustart.h"

MenuStart::MenuStart(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *qvb = new QVBoxLayout();
    QPushButton *quick = new QPushButton("Quick Game");
    QPushButton *newGame = new QPushButton("New Game");
    QPushButton *reset = new QPushButton("Reset scores");

    connect(quick,SIGNAL(clicked()),parent,SLOT(quickGame()));
    connect(newGame,SIGNAL(clicked()),parent,SLOT(newGame()));
    connect(reset,SIGNAL(clicked()),parent,SLOT(resetOrNot()));

    quick->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    newGame->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    reset->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    qvb->addWidget(quick);
    qvb->addWidget(newGame);
    qvb->addWidget(reset);
    qvb->setMargin(250);
    qvb->setAlignment(quick,Qt::AlignCenter);
    qvb->setAlignment(newGame,Qt::AlignCenter);
    qvb->setAlignment(reset,Qt::AlignCenter);
    setLayout(qvb);
}

MenuStart::~MenuStart(){}
