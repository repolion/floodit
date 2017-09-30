#include "widgetGame.h"


WidgetGame::WidgetGame(int height,int width,int nbCol,QWidget *parent) :
    QWidget(parent)
{
    _game = new Floodgame(height,width,nbCol);
    _viewboard = ViewBoard(*this,_game,nbCol);

    _game->AddObs(&_viewboard);

   // QPixmap bkgnd(":/images/galaxy.jpg");
  //  QPalette palette;
   // palette.setBrush(QPalette::Background, bkgnd);
   // this->setPalette(palette);
    //this->setFixedSize(700,660);

    connect(this,SIGNAL(reemitMain()),parent,SLOT(cancel()));
}

WidgetGame::~WidgetGame(){}

void WidgetGame::play(int i){
    Color col = static_cast<Color>(i-1);
    if(!_game->getIsGameOver()){
        if(_game->getLastColor()!=col)_game->setNbClick();
        _game->changeCurrentColor(col,0);
    }
}

void WidgetGame::reemit(){
    emit reemitMain();
}

void WidgetGame::restart(){
    _game->init(_game->getBoard().getHeight(),_game->getBoard().getWidth(),_game->getNbColors());
}


