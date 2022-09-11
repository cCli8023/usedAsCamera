#include "timeMod.h"

#include <QTimeZone>

timeMod::timeMod()
{

}

QList<QByteArray> timeMod::timeZoneList()
{
    QList<QByteArray> src = {
        "Asia/Shanghai",
        "America/New_York",
        "Europe/Berlin"
    };

    QList<QByteArray> dst;

    for (auto & tz : src) {
        if (QTimeZone::isTimeZoneIdAvailable(tz)){
            dst.append(tz);
        }
    }

    return dst;
}

QDateTime timeMod::timeById(QByteArray tz)
{
    _curId = tz;
    return QDateTime::currentDateTime().toTimeZone(QTimeZone(tz));
}

QDateTime timeMod::time()
{
    return timeById(_curId);
}
