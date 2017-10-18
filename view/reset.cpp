#include "reset.h"

Reset::Reset(QWidget *parent) :
    QWidget(parent)
{

    QHBoxLayout *qvb = new QHBoxLayout();
    QPushButton *yes = new QPushButton("Yes");
    QPushButton *no = new QPushButton("No");

    connect(yes,SIGNAL(clicked()),parent,SLOT(delScores()));
    connect(no,SIGNAL(clicked()),parent,SLOT(cancel()));

    yes->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    no->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    qvb->addWidget(yes);
    qvb->addWidget(no);
    qvb->setMargin(250);
    qvb->setAlignment(yes,Qt::AlignCenter);
    qvb->setAlignment(no,Qt::AlignCenter);
    setLayout(qvb);


}
Reset::~Reset(){}
