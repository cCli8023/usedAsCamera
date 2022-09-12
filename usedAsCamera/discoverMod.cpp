#include "discoverMod.h"

discoverMod::discoverMod()
{
    _socket.bind(QHostAddress::AnyIPv4 , 8023);

    QHostAddress multiAddr;
    multiAddr.setAddress("239.255.255.254");

    _socket.joinMulticastGroup(multiAddr);
}

discoverMod::~discoverMod()
{
}

QUdpSocket &discoverMod::socket()
{
    return _socket;
}

QQueue<QByteArray> discoverMod::message()
{
    _messageQue.clear();

    while ( _socket.hasPendingDatagrams() ){
        QByteArray data;
        data.resize(_socket.pendingDatagramSize());
        QHostAddress host;
        quint16 port;
        _socket.readDatagram(data.data(), data.size(), &host, &port);
        qDebug() << host << " " << port;
        _messageQue.push_back(data);
    }
    return _messageQue;
}
