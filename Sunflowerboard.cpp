#include "Sunflowerboard.h"

SunflowerBoard::SunflowerBoard(QGraphicsItem* parent) : QObject(), PlantBoard (100, false, false, parent)
{
    setPixmap(QPixmap(":/images/sunflowerUnSelected.jpg"));
    setPos(60,10);
}

void SunflowerBoard::slotPlayerScore(int playerScore)
{
    if (price < playerScore){
        isSelectable = true;
    }
}

void SunflowerBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
