#ifndef MENUSTART_H
#define MENUSTART_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>

namespace Ui {
class Widget;
}
/*!
 * \brief The MenuStart class
 * To let the choice between a new game or a quickgame
 */
class MenuStart :public QWidget{
    Q_OBJECT

public:
    explicit MenuStart(QWidget *parent = 0);
    ~MenuStart();
};

#endif // MENUSTART_H
