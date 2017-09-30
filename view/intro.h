#ifndef INTRO_H
#define INTRO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class Widget;
}

class Intro :public QWidget{
    Q_OBJECT

public:
    explicit Intro(QWidget *parent = 0);
    ~Intro();
};

#endif // INTRO_H
