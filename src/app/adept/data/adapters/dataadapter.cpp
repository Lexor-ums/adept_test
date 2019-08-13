#include "dataadapter.h"
#include <QtDebug>
#include <QList>

DataAdapter::DataAdapter()
{

}

QList<TreeModelItemData> DataAdapter::raskFromSQLToApp(const QList<QSqlRecord> &record)
{
    QList<TreeModelItemData> list;
    for(auto rec : record){
        TreeModelItemData entity;
        entity.setID(rec.value("ID").toString());
        entity.setName(rec.value("Razdel").toString());
        entity.setValue(rec.value("KoeffTek").toString());
        entity.setSubID(rec.value("subID").toString());
        entity.setSubIDName(rec.value("subIDName").toString());
        entity.setType("rasc");
        list.push_back(entity);
    }
    return list;
}

QList<TreeModelItemData> DataAdapter::sostavFromSQLToApp(const QList<QSqlRecord> &record)
{
    QList<TreeModelItemData> list;
    for(auto rec : record){
        TreeModelItemData entity;
        entity.setID(rec.value("ID").toString());
        entity.setName(rec.value("Name").toString());
        entity.setValue(rec.value("Dolya").toString());
        entity.setSubID(rec.value("subID").toString());
        entity.setSubIDName(rec.value("subIDName").toString());
        entity.setType("sostav");
        list.push_back(entity);
    }
    return list;
}

QList<TreeModelItemData
> DataAdapter::stadyFromSQLToApp(const QList<QSqlRecord> &record)
{
    QList<TreeModelItemData> list;
    for(auto rec : record){
        TreeModelItemData entity;
        entity.setID(rec.value("ID").toString());
        entity.setName(rec.value("Name").toString());
        entity.setValue(rec.value("Dolya").toString());
        entity.setSubID(rec.value("subID").toString());
        entity.setSubIDName(rec.value("subIDName").toString());
        entity.setType("stady");
        list.push_back(entity);
    }
    return list;
}

QList<TreeModelItemData> DataAdapter::koeffFromSQLToApp(const QList<QSqlRecord> &record)
{
    QList<TreeModelItemData> list;
    for(auto rec : record){
        TreeModelItemData entity;
        entity.setID(rec.value("ID").toString());
        entity.setName(rec.value("Name").toString());
        entity.setValue(rec.value("Dolya").toString());
        entity.setSubID(rec.value("subID").toString());
        entity.setSubIDName(rec.value("subIDName").toString());
        entity.setType("koeff");
        list.push_back(entity);
    }
    return list;
}
