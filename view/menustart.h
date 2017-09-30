#ifndef MENUSTART_H
#define MENUSTART_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class Widget;
}

class MenuStart :public QWidget{
    Q_OBJECT

public:
    explicit MenuStart(QWidget *parent = 0);
    ~MenuStart();

};

#endif // MENUSTART_H
