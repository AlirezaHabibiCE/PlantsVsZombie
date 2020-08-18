#ifndef OAKBOARD_H
#define OAKBOARD_H

#include <QObject>
#include <Plantboard.h>
#include <QGraphicsSceneMouseEvent>
#include <Oak.h>

class OakBoard : public QObject ,public PlantBoard
{
    Q_OBJECT
public:
    explicit OakBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    Oak* OakSellected();
    void UnselectOak();

public slots:
    void slotPlayerScore(int playerScore);

};

#endif // OAKBOARD_H
