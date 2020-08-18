#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "Zombie.h"
#include "Score.h"
#include "Sun.h"

class Controller : public QObject
{
    Q_OBJECT
    friend class View;friend class Block;
private:
    QGraphicsScene * scene;
    QTimer * cTimer;
    QGraphicsRectItem * holder;
    QList<Zombie *> zombieList;
    QList<Sun *> sunList;
    Score * controllerScore;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void addZombie(const int& velocity , const int& lives);
    void addSun();

signals:

};

#endif // CONTROLLER_H
