#include "floodgame.h"

namespace oli {

Floodgame::Floodgame(int height,int width,int nbColors)
{
    init(height,width,nbColors);
}

void Floodgame::init(int height,int width,int nbCol){
    _nbClick = 0;
    _isGameOver = false;
    _nbColors = nbCol;
    _started = true;
    _isGameOver = false;
    _board = Board(height,width,_nbColors);
    _listCaptured.clear();
    _listCaptured.push_back(Position(0,0));
    _lastColor = _board.getSquare(0,0).getColor();
    _newColor = _board.getSquare(0,0).getColor();
    this->changeCurrentColor(_lastColor,0);
    _highScore = HighScore();
    _newRecord = false;
}

Floodgame::~Floodgame(){}

Board& Floodgame::getBoard(){
    return _board;
}

int Floodgame::getNbColors(){
    return _nbColors;
}

void Floodgame::addCaptured(Position position){
    _listCaptured.push_back(position);
}

void Floodgame::changeCurrentColor(Color color,int cpt){
    setNewColor(color);
    if (color == _lastColor && cpt!=0)return;
    for(Position pos: _listCaptured){
        floodFill(pos.getX(),pos.getY(),_newColor,_lastColor,cpt);
    }
    _isGameOver=isGameOver();
    if(_isGameOver){std::cout<<"finit en "<<_nbClick<<" clicks"<<std::endl;
        _highScore = HighScore(_board.getWidth(),_board.getHeight(),_nbClick,_nbColors);

        if (checkScores())_newRecord=true;
    }
    Notify();
}

void Floodgame::floodFill(int x,int y,Color newColor,Color oldColor,int cpt){

    if(x<0 || y<0 || x>=_board.getHeight() || y>=_board.getWidth())return;

    if(cpt==0) _board.changeColorBoard(x,y,newColor);
    else {
        if(_board.getSquare(x,y).getColor()==newColor){
            if(!_board.getSquare(x,y).getCaptured()){
                _board.getSquare(x,y).setCaptured();
                addCaptured(Position(x,y));
            }
        }
    }

    ++cpt;
    if(cpt==1){
        floodFill(x+1, y, newColor,oldColor,cpt);
        floodFill(x-1, y, newColor,oldColor,cpt);
        floodFill(x, y+1, newColor,oldColor,cpt);
        floodFill(x, y-1, newColor,oldColor,cpt);
    }

}

void Floodgame::setNewColor(Color color){
    _lastColor = _newColor;
    _newColor = color;
}

bool Floodgame::isGameOver(){
    return static_cast<int>(_listCaptured.size())==_board.getWidth()*_board.getHeight();
}

bool Floodgame::getIsGameOver(){
    return _isGameOver;
}

Color Floodgame::getLastColor(){
    return _newColor;
}

void Floodgame::setNbClick(){
    ++_nbClick;
    std::cout<<"click "<<_nbClick<<std::endl;
}

bool Floodgame::isNewRecord(){
    return _newRecord;
}

int Floodgame::getNbClick(){
    return _nbClick;
}

QJsonObject Floodgame::loadSavedScores()const{
    QFile loadFile(QStringLiteral("save.json"));

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Aucun fichier de sauvegarde trouvé, un nouveau fichier a été crée.");
        QJsonObject qjo;
        return qjo;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    loadFile.close();

    return loadDoc.object();
}

bool Floodgame::checkScores() const{

    QJsonObject gameObject;
    gameObject =loadSavedScores();
    QString id =_highScore.getId();

    if( (gameObject.contains(id) && gameObject.value(id).toInt()>_highScore.getBest())
            || (!gameObject.contains(id)) ) {
        _highScore.write(gameObject);
    }
    else{
        return false;
    }

    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Impossible d'ouvrir le fichier de sauvegarde pour inscrire nouveau record");
        return false;
    }
    QJsonDocument saveDoc(gameObject);
    saveFile.write(saveDoc.toJson());
    saveFile.close();
    return true;
}

}
