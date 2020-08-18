#include "OakBoard.h"

OakBoard::OakBoard(QGraphicsItem* parent) : QObject(), PlantBoard (150, false, false, parent)
{
    setPixmap(QPixmap(":/images/OakUnSelected.jpg"));
    setPos(275,8);
}

void OakBoard::slotPlayerScore(int playerScore)
{
    if (price <= playerScore){
        isSelectable = true;
    }
}

void OakBoard::isPlaced()
{
    isSelected = false;
    emit UnselectOak();
}

void OakBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //first we check that plant is selectable
    if(isSelectable){
       isSelected = true;

       //set selected picture
       setPixmap(QPixmap(":/images/OakSelected.jpg"));

       emit OakSellected();
    }
    else if ( isSelected && !(isSelected)){
        isSelected = false;
        setPixmap(QPixmap(":/images/OakSelectable.jpg"));
        emit UnselectOak();
    }
}
