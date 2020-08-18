#include "OakBoard.h"

OakBoard::OakBoard(QGraphicsItem* parent) : QObject(), PlantBoard (150, false, false, parent)
{
    setPixmap(QPixmap(":/images/OakUnSelected.jpg"));
    setPos(80,10);
}

void OakBoard::slotPlayerScore(int playerScore)
{
    if (price <= playerScore){
        isSelectable = true;
    }
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
    else if ( isSelected ){
        isSelected = false;
        setPixmap(QPixmap(":/images/OakSelectable.jpg"));
        emit UnselectOak();
    }
}
