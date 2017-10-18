#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <iostream>

namespace Ui {
class Widget;
}
/*!
 * \brief The Options class
 * the class that make possible to change new game's options
 */
class Options :public QWidget{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

signals:
    void options(int height,int width,int nbCol);

private slots:
    void reemitOptions();
private:
    QSpinBox *_spinWidth;
    QSpinBox *_spinHeight;
    QSpinBox *_spinColors;

};

#endif // OPTIONS_H
