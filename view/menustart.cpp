#include "menustart.h"

MenuStart::MenuStart(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *qvb = new QVBoxLayout();
    QPushButton *quick = new QPushButton("Quick Game");
    QPushButton *newGame = new QPushButton("New Game");

    connect(quick,SIGNAL(clicked()),parent,SLOT(quickGame()));
    connect(newGame,SIGNAL(clicked()),parent,SLOT(newGame()));

    quick->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    newGame->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    qvb->addWidget(quick);
    qvb->addWidget(newGame);
    qvb->setMargin(250);
    qvb->setAlignment(quick,Qt::AlignCenter);
    qvb->setAlignment(newGame,Qt::AlignCenter);

    setLayout(qvb);
}

MenuStart::~MenuStart(){}
