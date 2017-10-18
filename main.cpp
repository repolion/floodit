#include "view/mainwindow.h"
#include <QApplication>

#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(720,660);
    w.setWindowTitle("Flood it by Olivier.C");
    w.show();

    return a.exec();
}
