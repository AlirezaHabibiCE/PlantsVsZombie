#include "Shooterboard.h"

ShooterBoard::ShooterBoard(QGraphicsItem *parent) : QObject(), PlantBoard (100, false, false, parent)
{
    setPixmap(QPixmap(":/images/shooterUnSelected.jpg"));
    setPos(30,10);
}

void ShooterBoard::slotPlayerScore(int playerScore)
{
    if (price < playerScore){
        isSelectable = true;
    }
}

void ShooterBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
