#ifndef DISCOVERMOD_H
#define DISCOVERMOD_H

#include <QQueue>
#include <QUdpSocket>

class discoverMod
{
public:
    discoverMod();
    ~discoverMod();

    QUdpSocket & socket();
    QQueue<QByteArray> message();
private:
    QUdpSocket _socket;
    QQueue<QByteArray> _messageQue;
};

#endif // DISCOVERMOD_H
