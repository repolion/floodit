#include "viewboard.h"

namespace oli {

ViewBoard::ViewBoard(){}

ViewBoard::ViewBoard(QWidget &fenetre, Floodgame * game,int nbCol){

    _game = game;
    _ql = new QLabel(&fenetre);
    _gameOver = new QLabel(&fenetre);
    _gameOver->setFixedHeight(525);
    _gameOver->setFixedWidth(720);
    _gameOver->setAlignment(Qt::AlignCenter);
    _ql->setFixedHeight(525);

    _buttonWidget = new ButtonWidget(nbCol,&fenetre);
    _vBox = new QVBoxLayout();
    _hboxBoutons = new QHBoxLayout;

    _nbClickLabel = new QLabel(&fenetre);
    QPushButton *restart = new QPushButton("Restart");
    restart->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QObject::connect(restart,SIGNAL(clicked()),&fenetre,SLOT(restart()));
    QPushButton *quit = new QPushButton("Quit");
    quit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QObject::connect(quit,SIGNAL(clicked()),&fenetre,SLOT(reemit()));
    _hboxBoutons->addWidget(restart);
    _hboxBoutons->addWidget(quit);
    _hboxBoutons->setAlignment(restart,Qt::AlignRight);
    _hboxBoutons->setAlignment(quit,Qt::AlignLeft);

    fenetre.setLayout(_vBox);
    setDisplay();

    _vBox->addWidget(_ql);
    _vBox->addWidget(_nbClickLabel);
    _vBox->addWidget(_buttonWidget);
    _vBox->setAlignment(_buttonWidget,Qt::AlignHCenter);

    _vBox->addLayout(_hboxBoutons);

}

void ViewBoard::setDisplay(){

    _nbClickLabel->setText("Clicked "+QVariant(_game->getNbClick()).toString() +" times");
    _nbClickLabel->setAlignment(Qt::AlignCenter);

    _width = _game->getBoard().getWidth();
    _height = _game->getBoard().getHeight();

    int brolWidth = _width;
    int brolHeight = _height;
    int block_width = 500 / [brolWidth, brolHeight](){
        int x;
        (brolWidth > brolHeight) ? x = brolWidth : x = brolHeight;
        return x;
    }();

    QPixmap _pixmap = QPixmap(_width*block_width+1,_height*block_width+1);
    _pixmap.fill(QColor("blue"));
    for(int i = 0; i < _height; i++){
        for (int j = 0; j < _width; j++){
            QPainter painter(&_pixmap);
            painter.setPen(QColor(81,81,81,255));
            painter.setBrush(_game->getBoard().getSquare(i,j).getQColor());
            if(_game->isGameOver())painter.setOpacity(0.1);
            QRect myQRect=(QRect(j*block_width,i*block_width,block_width,block_width));
            painter.drawRect(myQRect);
        }
    }
    if(_game->isGameOver() && _game->isNewRecord()){
        _gameOver->setPixmap(QPixmap(":/images/highScore.png").scaled(QSize(300,300),  Qt::KeepAspectRatio));
    }
    else if(_game->isGameOver()){
        _gameOver->setPixmap(QPixmap(":/images/gameOver2.png").scaled(QSize(300,300),  Qt::KeepAspectRatio));
    }
    else _gameOver->setPixmap(QPixmap(""));
    _ql->setAlignment(Qt::AlignCenter);

    _ql->setPixmap(_pixmap);

}

void ViewBoard::Update(){
    setDisplay();
}

}
