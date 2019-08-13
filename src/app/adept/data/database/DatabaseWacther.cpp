#include "DatabaseWacther.h"
#include <QDebug>
#include <QApplication>
#include <qsqldriver.h>
DataBaseWatcher* DataBaseWatcher::p_databaseWatcher;

void DataBaseWatcher::subscribeToDBEvents(const QString &event)
{
    qDebug()<<connector->connectToDatabase();
    connector->notify(event);
}

void DataBaseWatcher::subscribe(const QEvent::Type &event, QObject *window)
{
    m_eventsmap.insert(event, window);
}

void DataBaseWatcher::riseEvent(QEvent *event)
{
    for(auto widget : m_eventsmap.values(event->type())){
        QApplication::postEvent(widget, event);
    }
}

QStringList DataBaseWatcher::getListNotifications()
{
    return connector->getNotifications();
}

ConnectorToDatabase *DataBaseWatcher::getConnection()
{
    return connector;
}


DataBaseWatcher::DataBaseWatcher(QObject *parent) : QObject (parent)
{
    connector = new ConnectorToDatabase;
    connector->setConfigFileName("config/configdatabase.ini");
    connector->connectToDatabase();
    connect(connector->driver(),
            static_cast<void(QSqlDriver::*)(const QString &,
                                            QSqlDriver::NotificationSource,
                                            const QVariant &)>(&QSqlDriver::notification),
        [=](const QString &name, QSqlDriver::NotificationSource source, const QVariant &payload){
        if(source == QSqlDriver::OtherSource)
            emit DataBaseWatcher::dbChanged(name);
    });
}
