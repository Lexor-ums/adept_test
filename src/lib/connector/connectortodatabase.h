#ifndef __CONNECTORTODATABASE_H_
#define __CONNECTORTODATABASE_H_

#include <QtSql/QSqlDatabase>
#include <QObject>
#include <QSqlDriver>
#include "database_global.h"

class DATABASE_EXPORT ConnectorToDatabase {
	public:
		ConnectorToDatabase();
		~ConnectorToDatabase();
		QString connectName() const;
        void notify(const QString& mess);
		bool connectToDatabase();
		QString hostName() const;
		QString databaseName() const;
		void setConfigFileName(const QString& configFilename);
		QString type() const;
		QString userName() const;
        QStringList getNotifications(){
            return dataBase.driver()->subscribedToNotifications();
        }
        QSqlDriver* driver(){return dataBase.driver();}

        QSqlDatabase& getDataBase();

private:
        QString m_hostName;
        QString m_databaseName;
		QString m_userName;
		QString m_connectName;
		QString m_type;
        bool m_isConnected { false };
        QSqlDatabase dataBase;
};

#endif //__CONNECTORTODATABASE_H_
