#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include "model/color.h"

namespace oli {

class MyButton
{

public:
    MyButton();
    MyButton(int num,Color color/*,QWidget & fenetre*/);
    void setVisibility(bool visibility);
    QPushButton *getButton();
    Color getColor();

signals:
    void sendColor();

private:
    QPushButton *_button;
    QColor getQColor(Color color);
    Color _color;
};

}

#endif // MYBUTTON_H
