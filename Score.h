#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QObject>


class Score : public QGraphicsTextItem{
    friend class Sun;

private:
    int playerScore;
    QMediaPlayer * scorePlayer;
public:
    Score(QGraphicsItem * parent = 0);
    ~Score();
    void addToScore(int s);

public slots:


signals:
    void signalChangeAmount(int playerScore);
};

#endif // SCORE_H
