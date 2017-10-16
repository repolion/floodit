#ifndef FLOODGAME_H
#define FLOODGAME_H


#include <list>
#include <model/color.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <iostream>
#include <QFile>
#include "HighScore.h"
#include "model/board.h"
#include "observer/observable.h"

namespace oli {

class Floodgame: public Observable
{
private:
    bool _started;
    bool _isGameOver;
    HighScore _highScore;
    Color _lastColor;
    Color _newColor;
    Board _board;
    int _nbColors;
    std::list<Position> _listCaptured;

    int _nbClick;
    QJsonObject loadSavedScores()const ;
    bool checkScores() const;
    bool _newRecord;

public:
    Floodgame(int height,int width,int nbCol);
    ~Floodgame();
    Board& getBoard();
    void addCaptured(Position position);
    int getNbColors();
    void init(int height,int width,int nbCol);
    void floodFill(int x,int y,Color newColor,Color oldColor,int cpt);
    void setNewColor(Color color);
    void changeCurrentColor(Color color,int count);
    void printColor(int x,int y);
    bool getIsGameOver();
    void setNbClick();
    Color getLastColor();
    bool isGameOver();
    bool isNewRecord();
    int getNbClick();
    int getRecord();

};

}

#endif // FLOODGAME_H
