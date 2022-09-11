#ifndef TIMEMOD_H
#define TIMEMOD_H

#include <QByteArray>
#include <QDateTime>

class timeMod
{
public:
    timeMod();

    //返回可用的时区ID
    QList<QByteArray> timeZoneList();

    //根据时区ID，返回当前时间
    QDateTime timeById(QByteArray);
    QDateTime time();
private:
    QByteArray _curId;
};

#endif // TIMEMOD_H
