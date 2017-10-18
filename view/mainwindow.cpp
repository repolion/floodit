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
    _reset = new Reset(this);
    _myStack->addWidget(_intro);
    _myStack->addWidget(_menuStart);
    _myStack->addWidget(_options);
    _myStack->addWidget(_reset);

    this->setCentralWidget(_myStack);
    _myStack->setCurrentIndex(0);

    QTimer::singleShot(4000, [=](){
        _myStack->setCurrentIndex(1);
        setBackground(":/images/choice.jpg");
    });

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::quickGame(){
    _wg = new WidgetGame(15,15,4,this);
    _myStack->insertWidget(4,_wg);
    _myStack->setCurrentIndex(4);
    setBackground(":/images/bluedark.jpg");
}

void MainWindow::newGame(){
    _myStack->setCurrentIndex(2);
    setBackground(":/images/options.jpg");
}

void MainWindow::newGame(int height,int width,int nbCol){

    _wg = new WidgetGame(height,width,nbCol,this);
    _myStack->insertWidget(4,_wg);
    _myStack->setCurrentIndex(4);
    setBackground(":/images/bluedark.jpg");
}

void MainWindow::cancel(){
    _myStack->setCurrentIndex(1);
    setBackground(":/images/choice.jpg");
}

void MainWindow::setBackground(QString image){
    QPixmap bkgnd(image);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(720,660);
}

void MainWindow::resetOrNot(){
    _myStack->setCurrentIndex(3);
    setBackground(":/images/reset.jpg");
}

void MainWindow::delScores(){
    _myStack->setCurrentIndex(1);
    setBackground(":/images/choice.jpg");
    if( remove( "save.json" ) != 0 )
        perror( "Error deleting file" );
      else
        puts( "File successfully deleted" );
}
