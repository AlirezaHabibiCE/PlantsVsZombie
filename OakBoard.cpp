#include "OakBoard.h"

OakBoard::OakBoard(QGraphicsItem* parent) : QObject(), PlantBoard (100, false, false, parent)
{
    setPixmap(QPixmap(":/images/OakUnSelected.jpg"));
    setPos(80,10);
}

void OakBoard::slotPlayerScore(int playerScore)
{
    if (price < playerScore){
        isSelectable = true;
    }
}

void OakBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
