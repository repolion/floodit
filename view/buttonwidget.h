#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <iostream>
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include <QMap>
#include <model/color.h>
#include "colorConvert.h"

namespace oli {

/*!
 * \brief The ButtonWidget class
 */
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
};

}

#endif // BUTTONWIDGET_H
