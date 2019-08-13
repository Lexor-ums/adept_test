#include <QSettings>
#include <iostream>
#include "connectortodatabase.h"
#include <QSqlDriver>
#include <QDebug>

static int connectId = 0;

/*!
 * \class ConnectorToDatabase
 * \brief Класс ConnectorToDatabase описывает соединение с базой данных.
 *
 * Может использовать параметры из конфигурационного файла или непрсредственно
 * установленные в исходном коде.
 */

/*!
 * Создаёт объект ConnectorToDatabase по умолчанию. Устанавливает:
 * \li тип драйвера - QPSQL;
 * \li имя хоста - 127.0.0.1;
 * \li имя базы данных - imitator;
 * \li имя пользователя - imitator.
 */
ConnectorToDatabase::ConnectorToDatabase() {
	m_type = QString("QPSQL");
    m_hostName = QString("127.0.0.1");
	m_databaseName = QString("imitator");
	m_userName = QString("imitator");
}

/*!
 * Уничтожает объект ConnectorToDatabase при этом разрывает соединение с БД.
 */
ConnectorToDatabase::~ConnectorToDatabase() {
    {
        dataBase.close();
    }
}

/*!
 * Соединяется с базой данных. Возвращает \a true если соединение прошло
 * успешно и \a false в противном случае.
 */
bool ConnectorToDatabase::connectToDatabase() {
//    if(!dataBase.isOpen()) {
//        if(!dataBase.open()) {
//			return false;
//		}
//	}
//    if(dataBase.isOpen()) {
//		return true;
//	}
//    if(!dataBase.open()) {
//		return false;
//	}
//    m_isConnected = true;
//	return true;
    if(!QSqlDatabase::database(m_connectName).isOpen()) {
        if(!QSqlDatabase::database(m_connectName).open()) {
            return false;
        }
    }
    if(QSqlDatabase::database(m_connectName).isOpen()) {
        return true;
    }
    if(!QSqlDatabase::database(m_connectName).open()) {
        return false;
    }
    return true;
}

/*!
 * Возвращает имя соединения.
 */
QString ConnectorToDatabase::connectName() const {
    return m_connectName;
}

void ConnectorToDatabase::notify(const QString &mess)
{
    qDebug()<<dataBase.driver()->subscribeToNotification(mess);
}

/*!
 * Возвращает имя хоста.
 */
QString ConnectorToDatabase::hostName() const {
	return m_hostName;
}

/*!
 * Возвращает имя базы данных.
 */
QString ConnectorToDatabase::databaseName() const {
	return m_databaseName;
}

/*!
 * Устанавливает имя конфигурационного файла равным \a configFilename.
 * Считывает из него параметры соединения.
 */
void ConnectorToDatabase::setConfigFileName(const QString &configFilename) {
	QSettings settings(configFilename, QSettings::IniFormat);
	settings.beginGroup("configdatabase");
	m_type = settings.value("type", m_type).toString();
	m_hostName = settings.value("hostname", m_hostName).toString();
	m_databaseName = settings.value("databasename", m_databaseName).toString();
	m_userName = settings.value("username", m_userName).toString();
	settings.endGroup();
	do {
		m_connectName = QString::number(connectId++);
	} while(QSqlDatabase::contains(m_connectName));	
    dataBase = QSqlDatabase::addDatabase(m_type, m_connectName);
    dataBase.setHostName(m_hostName);
    dataBase.setDatabaseName(m_databaseName);
    dataBase.setUserName(m_userName);
    dataBase.setConnectOptions("connect_timeout=3");
}

/*!
 * Возвращает тип драйвера соединения.
 */
QString ConnectorToDatabase::type() const {
	return m_type;
}

/*!
 * Возвращает имя пользователя.
 */
QString ConnectorToDatabase::userName() const {
    return m_userName;
}

QSqlDatabase &ConnectorToDatabase::getDataBase()
{
    return dataBase;
}
