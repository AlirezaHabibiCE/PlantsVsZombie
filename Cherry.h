#ifndef CHERRY_H
#define CHERRY_H

#include <QObject>

class Cherry : public QObject
{
    Q_OBJECT
public:
    explicit Cherry(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CHERRY_H