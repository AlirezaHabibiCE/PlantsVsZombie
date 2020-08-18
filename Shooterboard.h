#ifndef SHOOTERBOARD_H
#define SHOOTERBOARD_H

#include <QObject>
#include <Plantboard.h>
#include <QGraphicsSceneMouseEvent>

class ShooterBoard : public QObject, public PlantBoard
{
    Q_OBJECT
public:
    explicit ShooterBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:

public slots:
    void slotPlayerScore(int playerScore);

};

#endif // SHOOTERBOARD_H
