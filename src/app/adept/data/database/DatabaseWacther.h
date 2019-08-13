#ifndef DATABASEWACTHER_H
#define DATABASEWACTHER_H

#include "connectortodatabase.h"

#include <QEvent>
#include <QMultiMap>
#include <QWidget>
#include <QDebug>
#include <QThread>
/*!
 * \brief The DataBaseWatcher class
 * класс, отвечающий за взаимодействие БД и интерфейса
 */
class DataBaseWatcher : public QObject
{
    Q_OBJECT
public:
    static DataBaseWatcher* instance(){
        if(p_databaseWatcher == nullptr){
            p_databaseWatcher = new DataBaseWatcher();
            return p_databaseWatcher;
        }
        else
            return p_databaseWatcher;
    }
    static void release(){
        delete p_databaseWatcher;
    }
    /*!
     * \brief subscribeToDBEvents подписка на события изменения в БД
     * \param event - тип события
     */
    void subscribeToDBEvents(const QString& event);
    /*!
     * \brief subscribe подписка на события выполнения запросов к БД
     * \param event тип события
     * \param window владелец события
     */
    void subscribe(const QEvent::Type &event, QObject *window);
    /*!
     * \brief riseEvent вызывает событие после выполнения запросов к БД
     * \param event класс события
     */
    void riseEvent(QEvent* event);
    QStringList getListNotifications();
    /*!
     * \brief getConnection возвращает экземпляр класса соединения с БД
     * \return экземпляр класса соединения с БД
     */
    ConnectorToDatabase* getConnection();

signals:
    /*!
     * \brief dbChanged оповещение об изменениях в бд
     * \param event тип события
     */
    void dbChanged(QString event);
public slots:
private:
    DataBaseWatcher(QObject* parent = nullptr);
    ~DataBaseWatcher(){}
    static DataBaseWatcher* p_databaseWatcher;
    ConnectorToDatabase * connector;
    QMultiMap<QEvent::Type, QObject*> m_eventsmap;
};

#endif // DATABASEWACTHER_H
