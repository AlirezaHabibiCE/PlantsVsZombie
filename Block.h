#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <Plant.h>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <Plantboard.h>
#include <Cherry.h>
#include <Shooter.h>
#include <Oak.h>
#include <SunFlower.h>
#include <QGraphicsScene>
#include <Controller.h>

class Block : public QObject , public QGraphicsRectItem, public Controller
{
    Q_OBJECT

private:
    Plant* plant;
    bool sunflower;
    bool shooter;
    bool Oak;
    bool cherry;

public:
    explicit Block(QGraphicsItem* parent);
    void isPlaced();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void signalIsPlaced();

public slots:
    Cherry* CherrySellected();
};

#endif // BLOCK_H
