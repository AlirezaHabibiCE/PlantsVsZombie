#ifndef SUNFLOWERBOARD_H
#define SUNFLOWERBOARD_H

#include <QObject>
#include <Plantboard.h>
#include <QGraphicsSceneMouseEvent>

class SunflowerBoard : public QObject, public PlantBoard
{
    Q_OBJECT
public:
    explicit SunflowerBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:

public slots:
    void slotPlayerScore(int playerScore);

};

#endif // SUNFLOWERBOARD_H
