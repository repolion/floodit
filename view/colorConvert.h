#ifndef COLORCONVERT_H
#define COLORCONVERT_H

#include <QColor>

namespace oli{
/*!
 * \brief The ColorConvert class
 * Class used by others class to convert a color to a QColor
 */
class ColorConvert{

public:
    static QColor getQColor(Color col){
        QColor color;
        switch(col){
        case Color::RED:
            color = Qt::red;
            break;
        case Color::GREEN:
            color = QColor(50,205, 50, 255);
            break;
        case Color::ORANGE:
            color = QColor(238, 154, 0, 255);
            break;
        case Color::BLUE:
            color = QColor(72, 118, 255, 255);
            break;
        case Color::PURPLE:
            color =  QColor(89, 51, 204, 255);
            break;
        case Color::DEEPPINK:
            color = QColor(255, 52, 179, 255);
            break;
        case Color::CYAN:
            color = Qt::cyan;
            break;
        case Color::YELLOW:
            color = Qt::yellow;
            break;
        case Color::GREY:
            color = QColor(204,204,204,255);
            break;
        }
        return color;
    }
};

}
#endif // COLORCONVERT_H
