#ifndef CONSTS_H
#define CONSTS_H

#include <QString>
#include <QEvent>

namespace consts {
    const QString configFileName = "config/configdatabase.ini";
    const QString sostavTableName = "sostav";
    const QString stadyTableName = "stady";
    const QString raskTableName = "rasc";
    const QString koeffTableName = "koeff";

    const QEvent::Type receiveProjectEventType = QEvent::Type::User;
    const QEvent::Type databseErrorEventType = static_cast<QEvent::Type>(QEvent::Type::User + 1);
}
#endif // CONSTS_H
