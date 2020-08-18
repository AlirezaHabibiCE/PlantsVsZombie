#include "Controller.h"
#include "Shooter.h"
#include "SunFlower.h"
#include "Oak.h"
#include <cstdlib>



Controller::Controller(QObject *parent, int level)
    : QObject(parent), level{level} {
    // create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    // create holder
    holder = new QGraphicsRectItem();
    holder->setRect(0,0,800,600);

    // create and start ctimer
    cTimer = new QTimer();
    cTimer->start(50);

    // add score board
    controllerScore = new Score(holder);
    scene->addItem(controllerScore);
    controllerScore->setPos(30,57);

    // add a test shooter
    auto myShooter = new Shooter(cTimer , holder);
    scene->addItem(myShooter);
    myShooter->setPos(40+300,375);

    // add a test SunFlower
    auto mySunFlower = new SunFlower(cTimer, controllerScore , holder);
    scene->addItem(mySunFlower);
    mySunFlower->setPos(40,375);

    //set boards
    shooterBoard = new ShooterBoard(holder);
    scene->addItem(shooterBoard);

    sunflowerBoard = new SunflowerBoard(holder);
    scene->addItem(sunflowerBoard);

    oakboard = new OakBoard(holder);

    if ( level >= 2)
    {
        scene->addItem(oakboard);
    }

    cherryBoard = new CherryBoard(holder);
    if (level >= 3)
    {
        scene->addItem(cherryBoard);
    }



    for (int i{0}; i < level ; ++i){
        for(int j{0}; j < 8 ; ++j){
            controllerBlocks.push_back( new Block(holder, controllerScore));

            //setting size of block
            controllerBlocks.last()->setRect( 0, 0 , 80 , 107 );
            controllerBlocks.last()->setPos(34 + ( j*80 ), 382 - ( i*108 ));

            QPen pen{"green"};
            pen.setStyle(Qt::NoPen);
            controllerBlocks.last()->setPen(pen);

            //add to scene
            scene->addItem(controllerBlocks.last());

            //connect block to score
            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToScore(int )),
                                                  controllerScore, SLOT(isPlaced(int )));

            //send signal that plants is placed
            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  shooterBoard , SLOT(isPlaced()));

            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  sunflowerBoard , SLOT(isPlaced()));

            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  oakboard , SLOT(isPlaced()));

            connect(controllerBlocks.last(), SIGNAL(signalIsPlacedToBoard()),
                                                  cherryBoard , SLOT(isPlaced()));

            //select from board and send signal to block to change true its related flag
            connect(shooterBoard , SIGNAL(ShooterSellected()),
                                      controllerBlocks.last() , SLOT(ShooterSellected()));

            connect(sunflowerBoard , SIGNAL(sunflowerSellected()),
                                      controllerBlocks.last() , SLOT(SunFlowerSellected()));

            connect(oakboard , SIGNAL(OakSellected()),
                                      controllerBlocks.last() , SLOT(OakSellected()));

            connect(cherryBoard , SIGNAL(CherrySelected()),
                                      controllerBlocks.last() , SLOT(CherrySellected()));

            //Unselect signal
            connect(shooterBoard , SIGNAL(UnselectShooter()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(sunflowerBoard , SIGNAL(UnselectSunflower()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(oakboard , SIGNAL(UnSelectCherry()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(cherryBoard , SIGNAL(UnselectOak()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            //connect score to board(send amount of score)
            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      shooterBoard , SLOT(slotPlayerScore(int )));

            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      sunflowerBoard , SLOT(slotPlayerScore(int )));

            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      oakboard , SLOT(slotPlayerScore(int )));

            connect(controllerScore , SIGNAL(signalChangeAmount(int )),
                                      cherryBoard , SLOT(slotPlayerScore(int )));

            //change flag to false in blocks
            connect(shooterBoard , SIGNAL(isPlaced()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

            connect(sunflowerBoard , SIGNAL(isPlaced()),
                                      controllerBlocks.last() , SLOT(UnSelect()));

        }
    }


    // add a test Oak
//    auto myOak = new Oak(cTimer , 10 , holder);
//    scene->addItem(myOak);
//    myOak->setPos(40,375);

}

Controller::~Controller() {
    delete holder;
    delete cTimer;
    delete scene;
}

void Controller::addZombie(const int& velocity , const int& lives) {
    zombieList.push_back(new Zombie(velocity , cTimer , lives ,holder));
    // add to the scene
    scene->addItem(zombieList.last());

    zombieList.last()->setPos(800 ,390 - 100*(rand()%level) );
}

//void Controller::addMasterZombie(const int &velocity, const int &lives)
//{
//    masterZombieList.push_back(new MasterZombie(velocity , cTimer , lives ,holder));
//    // add to the scene
//    scene->addItem(masterZombieList.last());
//    masterZombieList.last()->setPos(800,370);
//}

void Controller::addSun() {
    sunList.push_back(new Sun(scene , controllerScore , holder , cTimer));
    sunList.last()->setPos( rand() % 800 , 0);
}

int Controller::getRound()
{
    return level;
}

// test
//void Controller::addOak() {
//    auto myOak = new Oak(cTimer , 10 , holder);
//    scene->addItem(myOak);
//    myOak->setPos(40,375);
//}
