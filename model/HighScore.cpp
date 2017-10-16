#include "HighScore.h"

namespace oli {

HighScore::HighScore(){}
HighScore::HighScore(int width,int height,int nbColors){
    _width = width;
    _height = height;
    _nbColors = nbColors;
}
HighScore::HighScore(int width,int height,int best,int nbColors){
    _width = width;
    _height = height;
    _nbColors = nbColors;
    _best = best; 
}
void HighScore::setWidth(int width){
    _width = width;
}
void HighScore::setHeight(int height){
    _height = height;
}
void HighScore::setBest(int best){
    _best = best;
}
void HighScore::setNbColors(int nbColors){
    _nbColors = nbColors;
}

void HighScore::write(QJsonObject &json) const{
    QString id;
    id = format(_width) + format(_height) + format(_nbColors);
    json[id] = _best;
}

QString HighScore::format(int nb){
    std::ostringstream oss;
    if(nb<10) oss << 0 <<nb;
    else oss<<nb;
    QString test = QString::fromStdString(oss.str());
    return test;
}

QString HighScore::getId() const{
   return format(_width) + format(_height) + format(_nbColors);
}

int HighScore::getBest() const{
    return _best;
}

}
