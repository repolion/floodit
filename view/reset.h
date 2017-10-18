#ifndef RESET_H
#define RESET_H

#include <QPushButton>
#include <QHBoxLayout>

namespace Ui {
class Widget;
}
/*!
 * \brief The Reset class
 * To confirm reseting of the scores record
 */
class Reset :public QWidget{
    Q_OBJECT

public:
    explicit Reset(QWidget *parent = 0);
    ~Reset();

signals:


private slots:

private:

};
#endif // RESET_H
