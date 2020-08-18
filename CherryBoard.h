#ifndef CHERRYBOARD_H
#define CHERRYBOARD_H

#include <QObject>
#include <Plantboard.h>
#include <QGraphicsSceneMouseEvent>
#include <Cherry.h>

class CherryBoard : public QObject, public PlantBoard
{
    Q_OBJECT
public:
    explicit CherryBoard(QGraphicsItem* parent);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
        Cherry* CherrySelected();
        bool UnSelectCherry(){return false;}

public slots:
    void slotPlayerScore(int playerScore);


};

#endif // CHERRYBOARD_H
