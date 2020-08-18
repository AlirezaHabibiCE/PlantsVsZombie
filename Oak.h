#ifndef OAK_H
#define OAK_H

#include <QObject>

class Oak : public QObject
{
    Q_OBJECT
public:
    explicit Oak(QObject *parent = nullptr);

signals:
    Oak* OakSellected();

public slots:

};

#endif // OAK_H
