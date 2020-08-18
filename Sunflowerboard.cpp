#include "Sunflowerboard.h"

SunflowerBoard::SunflowerBoard(QGraphicsItem* parent) : QObject(), PlantBoard (50, false, false, parent)
{
    setPixmap(QPixmap(":/images/sunflowerUnSelected.jpg"));
    setPos(60,10);
}

void SunflowerBoard::slotPlayerScore(int playerScore)
{
    if (price <= playerScore){
        isSelectable = true;
        setPixmap(QPixmap(":/images/sunflowerSelectable.jpg"));
    }
    else{
        isSelectable = false;
        setPixmap(QPixmap(":/images/sunflowerUnSelected.jpg"));
    }
}

void SunflowerBoard::isPlaced()
{
    isSelected = false;
    setPixmap(QPixmap(":/images/sunflowerSelectable.jpg"));
}

void SunflowerBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //first we check that plant is selectable
    if(isSelectable){
       isSelected = true;

       //set selected picture
       setPixmap(QPixmap(":/images/sunflowerSelected.jpg"));

       emit sunflowerSellected();
    }
    else if ( isSelected ){
        isSelected = false;
        setPixmap(QPixmap(":/images/sunflowerSelectable.jpg"));
        emit UnselectSunflower();
    }
}

