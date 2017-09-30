#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _myStack = new QStackedWidget(this);
    _intro = new Intro(this);
    _menuStart = new MenuStart(this);
    _options = new Options(this);
    _myStack->addWidget(_intro);
    _myStack->addWidget(_menuStart);
    _myStack->addWidget(_options);

    //_wg = new WidgetGame(15,15,4,this);

    this->setCentralWidget(_myStack);
    _myStack->setCurrentIndex(0);

    QTimer::singleShot(3000, [=](){
        _myStack->setCurrentIndex(1);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quickGame(){
    _wg = new WidgetGame(15,15,4,this);
    _myStack->insertWidget(3,_wg);
    _myStack->setCurrentIndex(3);

}

void MainWindow::newGame(){
    _myStack->setCurrentIndex(2);
}

void MainWindow::newGame(int height,int width,int nbCol){

    _wg = new WidgetGame(height,width,nbCol,this);
    _myStack->insertWidget(3,_wg);
    _myStack->setCurrentIndex(3);

}

void MainWindow::cancel(){
    _myStack->setCurrentIndex(1);
}

