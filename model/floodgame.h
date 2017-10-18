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

class Floodgame: public Observable{

public:
    /*!
     * \brief Floodgame
     * the game's constructor with parameters
     * \param height the board's height
     * \param width the board's width
     * \param nbCol the number of color possible for the squares
     */
    Floodgame(int height,int width,int nbCol);

    ~Floodgame();

    /*!
     * \brief getBoard
     * \return the board
     */
    Board& getBoard();

    /*!
     * \brief addCaptured
     * add a Position to the list of position captured
     * \param position the position of the new position captured
     */
    void addCaptured(Position position);

    /*!
     * \brief getNbColors
     * \return the number of color possible for a square
     */
    int getNbColors();

    /*!
     * \brief init
     * to initialise a new game
     * \param height the board's height
     * \param width the board's width
     * \param nbCol the number of different color possible for the squares
     */
    void init(int height,int width,int nbCol);

    /*!
     * \brief floodFill
     * The algorithm to check the board for new position to capture
     * \param x the x axis position
     * \param y the y axis position
     * \param newColor the new color
     * \param oldColor the old color
     * \param cpt a counter
     */
    void floodFill(int x,int y,Color newColor,Color oldColor,int cpt);

    /*!
     * \brief setNewColor
     * \param color the new color to set
     */
    void setNewColor(Color color);

    /*!
     * \brief changeCurrentColor
     * \param color the new color to set
     * \param count a counter initialised
     */
    void changeCurrentColor(Color color,int count);

    /*!
     * \brief getIsGameOver
     * to get the gameover status
     * \return if the game is over or not
     */
    bool getIsGameOver();

    /*!
     * \brief setNbClick
     * to set the number of click made
     */
    void setNbClick();

    /*!
     * \brief getLastColor
     * \return the last color choosed
     */
    Color getLastColor();

    /*!
     * \brief isGameOver
     * \return if the game is over or not
     */
    bool isGameOver();

    /*!
     * \brief isNewRecord
     * \return if the actual score is a new record or not
     */
    bool isNewRecord();

    /*!
     * \brief getNbClick
     * \return the number of click
     */
    int getNbClick();

    /*!
     * \brief getRecord
     * \return the record
     */
    int getRecord();

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

};

}

#endif // FLOODGAME_H
