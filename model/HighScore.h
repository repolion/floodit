#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QJsonObject>
#include <sstream>

class HighScore
{
private:
    //QList<int> _listScore;
    int _height;
    int _width;
    int _best;
    int _nbColors;
    QString static format(int nb);
public:
    HighScore();
    HighScore(int,int,int,int);
    void setWidth(int);
    void setHeight(int);
    void setBest(int);
    void setNbColors(int);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

};

#endif // HIGHSCORE_H
