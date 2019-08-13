/**************************************************************************
**  File: ProjectsDAO.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlError>
#include "ProjectsDAO.h"
#include <data/database/DatabaseWacther.h>
#include <connectortodatabase.h>
#include <utils/consts/Consts.h>

ProjectsDAO::ProjectsDAO()
{

}
QPair<bool, QList<QSqlRecord> > ProjectsDAO::getSostavList()
{
    return selectAll(consts::sostavTableName);
}

QPair<bool, QList<QSqlRecord>> ProjectsDAO::getRaskList()
{
    return selectAll(consts::raskTableName);
}

QPair<bool, QList<QSqlRecord>> ProjectsDAO::getKoeffList()
{
    return selectAll(consts::koeffTableName);
}

QPair<bool, QList<QSqlRecord>> ProjectsDAO::getStadyList()
{
    return selectAll(consts::stadyTableName);
}

bool ProjectsDAO::insertData(TreeModelItemData data)
{
    ConnectorToDatabase conn;
    bool request;
    conn.setConfigFileName(consts::configFileName);
    if(!conn.connectToDatabase())
        return false;
    QSqlQuery  query(conn.getDataBase());
    QString queryStr;
    if(data.type() != "rasc")
        queryStr = QString("insert into %1 (ID, subID, subIDName, Dolya, Name)"
                           "values(%2, '%3', '%4', '%5', '%6')")
                .arg(data.type()).arg(data.ID().toInt()).arg(data.subID()).arg(data.subIDName())
                .arg(data.value()).arg(data.name());
    else {
        queryStr = QString("insert into %1 (ID, subID, subIDName, KoeffTek, Razdel)"
                           "values(%2, '%3', '%4', '%5', '%6')")
                .arg(data.type()).arg(data.ID().toInt()).arg(data.subID()).arg(data.subIDName())
                .arg(data.value()).arg(data.name());
    }
        qDebug()<<"exec "<<queryStr;
    if(query.exec(queryStr)){
        request = true;
    }
    else {
        qDebug()<<query.lastError()<<queryStr;
        return false;
    }
    return request;
}

bool ProjectsDAO::updateData(TreeModelItemData data)
{
    ConnectorToDatabase conn;
    bool request;
    conn.setConfigFileName(consts::configFileName);
    if(!conn.connectToDatabase())
        return false;
    QSqlQuery  query(conn.getDataBase());
    QString queryStr;
    if(data.type() != "rasc")
        queryStr = QString("update %1 set subID = '%2', subIDName = '%3',"
                           "Dolya = '%4', Name = '%5' where ID = %6;")
                .arg(data.type()).arg(data.subID()).arg(data.subIDName())
                .arg(data.value()).arg(data.name()).arg(data.ID().toInt());
    else {
        queryStr = QString("update %1 set subID = '%2', subIDName = '%3',"
                           "KoeffTek = '%4', Razdel = '%5' where ID = %6;")
                .arg(data.type()).arg(data.subID()).arg(data.subIDName())
                .arg(data.value()).arg(data.name()).arg(data.ID().toInt());
    }
    if(query.exec(queryStr)){
        request = true;
        if(!query.exec("NOTIFY notify")){
            qDebug()<<query.lastError()<<queryStr;
        }
    }
    else {
        qDebug()<<query.lastError()<<queryStr;
        return false;
    }
    return request;
}

bool ProjectsDAO::remove(TreeModelItemData data)
{
    ConnectorToDatabase conn;
    bool request;
    conn.setConfigFileName(consts::configFileName);
    if(!conn.connectToDatabase())
        return false;
    QSqlQuery  query(conn.getDataBase());
    QString queryStr;
        queryStr = QString("delete from %1 where ID = %2;")
                .arg(data.type()).arg(data.ID().toInt());
    if(query.exec(queryStr)){
        request = true;
    }
    else {
        qDebug()<<query.lastError()<<queryStr;
        return false;
    }
    return request;
}

QPair<bool, int> ProjectsDAO::getMaxId(const QString &table)
{
    ConnectorToDatabase conn;
    int id = -1;
    QPair<bool, int> request;
    conn.setConfigFileName(consts::configFileName);
    if(!conn.connectToDatabase())
        return QPair<bool, int>(false, -1);
    QSqlQuery  query(conn.getDataBase());
    QString queryStr = QString("select MAX(ID) from %1;").arg(table);
    qDebug()<<"max id"<<queryStr;
    if(query.exec(queryStr)){
        while (query.next()) {
            id = query.record().value("max").toInt();            
        }
        request = { true, id + 1 };
    }
    else {
        qDebug()<<query.lastError();
        return QPair<bool, int>(false, -1);
    }
    return request;
}

QPair<bool, QList<QSqlRecord>> ProjectsDAO::selectAll(const QString &tableName)
{
    ConnectorToDatabase conn;
    QList<QSqlRecord> recordsList;
    QPair<bool, QList<QSqlRecord>> request;
    conn.setConfigFileName(consts::configFileName);
    if(!conn.connectToDatabase())
        return QPair<bool, QList<QSqlRecord>>(false, QList<QSqlRecord>());
    QSqlQuery  query(conn.getDataBase());
    if(query.exec(QString("select * from %1;").arg(tableName))){
        while (query.next()) {
            recordsList.push_back(query.record());

        }
        request = { true, recordsList };
    }
    else {
        qDebug()<<query.lastError();
        return QPair<bool, QList<QSqlRecord>>(false, QList<QSqlRecord>());
    }
    return request;
}

