#ifndef FLOODGAME_H
#define FLOODGAME_H

#include "model/board.h"
#include "observer/observable.h"
#include <list>
#include <model/color.h>

namespace oli {

class Floodgame: public Observable
{
private:
    bool _started;
    bool _isGameOver;
    Color _lastColor;
    Color _newColor;
    Board _board;
    int _nbColors;
    std::list<Position> _listCaptured;
    bool isGameOver();
    int _nbClick;


public:
    Floodgame(int height,int width,int nbCol);
    ~Floodgame();
    Board& getBoard();
    void addCaptured(Position position);
    int getNbColors();
    void init(int height,int width,int nbCol);
    void floodFill(int x,int y,Color newColor,Color oldColor,int cpt);
    void setNewColor(Color color);
    static std::string getColor(Color color);
    void changeCurrentColor(Color color,int count);
    void printColor(int x,int y);
    bool getIsGameOver();
    void setNbClick();
    Color getLastColor();

};

}

#endif // FLOODGAME_H
