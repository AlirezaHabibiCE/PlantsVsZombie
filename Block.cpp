#include "Block.h"
#include "Controller.h"

Block::Block(QGraphicsItem* parent):QGraphicsRectItem (parent)
{
    plant = nullptr;//at first this is null

    //initialize all plants flags
    sunflower = false;
    shooter = false;
    Oak = false;
    cherry = false;
}

void Block::isPlaced()
{
    emit signalIsPlaced();
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   
    if (plant == nullptr)
    {
        if (shooter){
            plant = new Shooter(cTimer, holder);
            Controller::scene->addItem(plant);
            plant;
        }
    }
}

Cherry* Block::CherrySellected()
{
    if (!(shooter||sunflower||cherry||Oak))
    {
        cherry = true;
    }
}

