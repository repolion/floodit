#ifndef INTRO_H
#define INTRO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPalette>

namespace Ui {
class Widget;
}
/*!
 * \brief The Intro class
 * The class launched during a few seconds at the begining of the program launch
 */
class Intro :public QWidget{
    Q_OBJECT

public:
    explicit Intro(QWidget *parent = 0);
    ~Intro();
};

#endif // INTRO_H
