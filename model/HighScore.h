#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QJsonObject>
#include <sstream>

namespace oli {

/*!
 * \brief The HighScore class
 * Used to compare old results and the new score according to
 * the weight, the height and the number of colors
 * function
 */
class HighScore
{
public:
    /*!
     * \brief HighScore
     */
    HighScore();

    /*!
     * \brief HighScore
     * highscore's constructor with parameters
     */
    HighScore(int,int,int,int);

    /*!
     * \brief HighScore
     * highscore's constructor with parameters
     */
    HighScore(int, int, int);

    /*!
     * \brief setWidth
     * to set the width
     */
    void setWidth(int);

    /*!
     * \brief setHeight
     * to set the height
     */
    void setHeight(int);

    /*!
     * \brief setBest
     * to set the best score
     */
    void setBest(int);

    /*!
     * \brief setNbColors
     */
    void setNbColors(int);

    /*!
     * \brief getId
     * \return the id which defines the game record according to
     * the weight, the height and the number of colors
     */
    QString getId() const;

    /*!
     * \brief getBest
     * \return the best score
     */
    int getBest() const;

    /*!
     * \brief write
     * write into a Json object the id of a highscore and the score associated
     * \param json
     */
    void write(QJsonObject &json) const;

private:
    int _height;
    int _width;
    int _best;
    int _nbColors;
    QString static format(int nb);
};

}

#endif // HIGHSCORE_H
