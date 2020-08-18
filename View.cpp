#include "View.h"


View::View()
{
    //create viewController
    viewController = new Controller();

    // create scene
    setScene(viewController->scene);

    // set background image
    setBackgroundBrush(QBrush(QImage(":/images/bgstepthree.png")));

    // set fixed size
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // set background music
    viewPlayer = new QMediaPlayer();
    viewPlayer->setMedia(QUrl("qrc:/musics/GrasswalkPvZ1.mp3"));
    viewPlayer->play();

    // initialize seconds to zero
    seconds = 0;

    // start timer
    viewTimer = new QTimer();
    viewTimer->start(1000);
    connect(viewTimer , SIGNAL(timeout()) , this , SLOT(schedule()));

}

View::~View() {
    delete viewTimer;
    delete viewController;
    delete viewPlayer;
}

void View::schedule(){
   ++seconds;
    if (viewController->getRound() == 1)
    {
        if(seconds == 10 || seconds == 15){
            viewController->addZombie(5 , 10);
        }
    }
     else if (viewController->getRound() == 2)
    {
        if(seconds == 45 || seconds == 48 ||seconds == 50 ||seconds == 51
                ||seconds == 54 ||seconds == 52 ||seconds == 60
                ||seconds == 58||seconds == 62 ||seconds == 61){
            viewController->addZombie(5 , 10);
        }
    }
     else if (viewController->getRound() == 3)
    {
        if(seconds == 50 || seconds == 54){
            viewController->addZombie(5 , 10);
        }
    }

    if(seconds % 2 == 0){
        viewController->addSun();
    }
}
