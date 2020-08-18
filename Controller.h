#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include "Zombie.h"
#include "Score.h"
#include "Sun.h"
#include "MasterZombie.h"
#include <Block.h>
#include <Shooterboard.h>
#include <Sunflowerboard.h>
#include <OakBoard.h>
#include <CherryBoard.h>
#include <Plantboard.h>
#include <Shovel.h>

class Controller : public QObject
{
    Q_OBJECT
    friend class View;
private:
    int level;
    int zombies;
    Shovel* shovel;
    CherryBoard* cherryBoard;
    SunflowerBoard* sunflowerBoard;
    OakBoard* oakboard;
    ShooterBoard* shooterBoard;
    QGraphicsScene * scene;
    QTimer * cTimer;
    QGraphicsRectItem * holder;
    QList<Zombie *> zombieList;
    QList<MasterZombie*> masterZombieList;
    QList<Sun *> sunList;
    QList<Block* > controllerBlocks;
    Score * controllerScore;

public:
    explicit Controller(QObject *parent = nullptr, int level=1);
    ~Controller();
    void addZombie(const int& velocity , const int& lives, int line);
    void addMasterZombie(const int& velocity , const int& lives, int line);
    void addSun();
    void addOak();
    void addCherry();
    int getRound();

signals:

public slots:
    void addBoard();
    void calculateZombie();
};

#endif // CONTROLLER_H
