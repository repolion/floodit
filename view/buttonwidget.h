#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H


#include <iostream>
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QMap>
#include <model/color.h>
#include "view/mybutton.h"

namespace oli {

class ButtonWidget : public QWidget
{
    Q_OBJECT

public:
    ButtonWidget(int nbCol, QWidget *parent = 0);

signals:
    void clicked(const QString &text);
private slots:

private:
    QSignalMapper *signalMapper;
    QColor getQColor(Color col);
};

}

#endif // BUTTONWIDGET_H
