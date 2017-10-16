#include "viewboard.h"

namespace oli {

ViewBoard::ViewBoard(){}

ViewBoard::ViewBoard(QWidget &fenetre, Floodgame * game,int nbCol){

    _game = game;
    _ql = new QLabel(&fenetre);
    _ql->setFixedHeight(525);

    _gameOver = new QLabel(&fenetre);
    _gameOver->setFixedHeight(525);
    _gameOver->setFixedWidth(720);
    _gameOver->setAlignment(Qt::AlignCenter);

    _buttonWidget = new ButtonWidget(nbCol,&fenetre);
    _vBox = new QVBoxLayout();
    _hboxBoutons = new QHBoxLayout;
    _record = new QLabel(&fenetre);
    _nbClickLabel = new QLabel(&fenetre);

    QPushButton *restart = new QPushButton("Restart");
    QPushButton *quit = new QPushButton("Quit");

    QObject::connect(quit,SIGNAL(clicked()),&fenetre,SLOT(reemit()));
    QObject::connect(restart,SIGNAL(clicked()),&fenetre,SLOT(restart()));

    quit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    restart->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    _hboxBoutons->addWidget(restart);
    _hboxBoutons->addWidget(quit);
    _hboxBoutons->setAlignment(restart,Qt::AlignRight);
    _hboxBoutons->setAlignment(quit,Qt::AlignLeft);

    fenetre.setLayout(_vBox);
    setDisplay();

    _vBox->addWidget(_ql);
    _vBox->addWidget(_record);
    _vBox->addWidget(_nbClickLabel);
    _vBox->addWidget(_buttonWidget);
    _vBox->setAlignment(_buttonWidget,Qt::AlignHCenter);

    _vBox->addLayout(_hboxBoutons);

}

void ViewBoard::setDisplay(){

    if((_valueRecord =_game->getRecord())==0){
        _record->setText("");
    }else{
        _record->setText("Record: "+QVariant(_valueRecord).toString()+" clicks");
        _record->setAlignment(Qt::AlignCenter);
        _record->setStyleSheet("QLabel { background-color : transparent; color : orange; }");
    }

    _nbClickLabel->setText("Clicked "+QVariant(_game->getNbClick()).toString() +" times");
    _nbClickLabel->setAlignment(Qt::AlignCenter);
    _nbClickLabel->setStyleSheet("QLabel { background-color : transparent; color : white; }");

    _width = _game->getBoard().getWidth();
    _height = _game->getBoard().getHeight();

    int brolWidth = _width;
    int brolHeight = _height;
    int block_width = 500 / [brolWidth, brolHeight](){
        int x;
        (brolWidth > brolHeight) ? x = brolWidth : x = brolHeight;
        return x;
    }();
    QPixmap _pixmap;
    if(!_game->isGameOver()){
        _pixmap= QPixmap(_width*block_width+1,_height*block_width+1);
    }
    else _pixmap = QPixmap(490,490);
    _pixmap.fill(QColor("blue"));
    if(!_game->isGameOver()){
        for(int i = 0; i < _height; i++){
            for (int j = 0; j < _width; j++){
                QPainter painter(&_pixmap);
                painter.setPen(QColor(81,81,81,255));
                painter.setBrush(_game->getBoard().getSquare(i,j).getQColor());

                QRect myQRect=(QRect(j*block_width,i*block_width,block_width,block_width));
                painter.drawRect(myQRect);
            }
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
