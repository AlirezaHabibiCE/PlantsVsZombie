#include "Block.h"
#include "Controller.h"

Block::Block(QGraphicsItem* parent, Score* blockScore):
    blockScore{blockScore}, QGraphicsRectItem (parent)
{
    plant = nullptr;//at first this is null

    //initialize all plants flags
    sunflower = false;
    shooter = false;
    oak = false;
    cherry = false;
}


void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   
    if (plant == nullptr)
    {
        if (shooter){
            plant = new Shooter(bTimer, parentItem());
            scene()->addItem(plant);
            plant->setPos(x()+10 , y()+10);
            emit signalIsPlacedToScore(100);
            emit signalIsPlacedToBoard();
        }
        if (sunflower){
            plant = new SunFlower(bTimer, blockScore, parentItem());
            scene()->addItem(plant);
            plant->setPos(x()+10 , y()+10);
            emit signalIsPlacedToScore(50);
            emit signalIsPlacedToBoard();

        }
        if (cherry){
//            plant = new Cherry(bTimer, parentItem());
//            scene()->addItem(plant);
//            plant->setPos(x()+10 , y()+10);
            emit signalIsPlacedToScore(150);
            emit signalIsPlacedToBoard();

        }
        if (oak){
//            plant = new Shooter(bTimer, parentItem());
//            scene()->addItem(plant);
//            plant->setPos(x()+10 , y()+10);
            emit signalIsPlacedToScore(150);
            emit signalIsPlacedToBoard();

        }
    }
}

Shooter *Block::ShooterSellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        shooter = true;
    }
}

SunFlower *Block::SunFlowerSellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        sunflower = true;
    }
}

Oak *Block::OakSellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        oak = true;
    }
}

Cherry* Block::CherrySellected()
{
    if (!(shooter||sunflower||cherry||oak))
    {
        cherry = true;
    }
}

void Block::UnSelect()
{
    sunflower = false;
    shooter = false;
    oak = false;
    cherry = false;
}

