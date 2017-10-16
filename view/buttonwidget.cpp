#include "buttonwidget.h"

namespace oli {

ButtonWidget::ButtonWidget(int nbCol, QWidget *parent)
    : QWidget(parent)
{
    signalMapper = new QSignalMapper(this);
    QGridLayout *gridLayout = new QGridLayout;

    for (int i = 1; i <= nbCol; ++i) {

        QPushButton *button = new QPushButton("");
        QColor col =ColorConvert::getQColor(static_cast<Color>(i-1));
        QString qss = QString("background-color: %1").arg(col.name());
        button->setStyleSheet(qss);
        button->setFocusPolicy(Qt::NoFocus);
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button,i);
        gridLayout->addWidget(button, (i-1) / 8, (i-1) % 8);
    }

    connect(signalMapper, SIGNAL(mapped(int)),parent, SLOT(play(int)));
    setLayout(gridLayout);
}

}
