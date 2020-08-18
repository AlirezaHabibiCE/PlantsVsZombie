#ifndef OAKBOARD_H
#define OAKBOARD_H

#include <QObject>
#include <Plantboard.h>
#include <QGraphicsSceneMouseEvent>

class OakBoard : public QObject ,public PlantBoard
{
    Q_OBJECT
public:
    explicit OakBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:

public slots:
    void slotPlayerScore(int playerScore);

};

#endif // OAKBOARD_H
