#include "buttonwidget.h"

namespace oli {

ButtonWidget::ButtonWidget(int nbCol, QWidget *parent)
    : QWidget(parent)
{
    signalMapper = new QSignalMapper(this);

    QGridLayout *gridLayout = new QGridLayout;
    for (int i = 1; i <= nbCol; ++i) {

        QPushButton *button = new QPushButton("");
        QColor col =getQColor(static_cast<Color>(i-1));
        QString qss = QString("background-color: %1").arg(col.name());
        button->setStyleSheet(qss);
        button->setFocusPolicy(Qt::NoFocus);
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button,i);
        gridLayout->addWidget(button, (i-1) / 8, (i-1) % 8);
       // button->setGeometry(QRect(QPoint((45*i),350),QSize(45,45)));
        //button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
       // button->setContentsMargins(100,0,100,0);
    }

    connect(signalMapper, SIGNAL(mapped(int)),
            parent, SLOT(play(int)));

    setLayout(gridLayout);

}

QColor ButtonWidget::getQColor(Color col){
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


}
