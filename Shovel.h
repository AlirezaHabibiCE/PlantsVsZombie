#ifndef SHOVEL_H
#define SHOVEL_H

#include <QObject>

class Shovel : public QObject
{
    Q_OBJECT
public:
    explicit Shovel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SHOVEL_H