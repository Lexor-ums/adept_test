#ifndef DATAADAPTER_H
#define DATAADAPTER_H

#include <qsqlrecord.h>
#include <data/entites/KoeffEntity.h>
#include <data/entites/RaskEntity.h>
#include <data/entites/SostavEntity.h>
#include <data/entites/StadyEntity.h>
#include <data/models/TreeModelItem.h>


/*!
 * \brief The DataAdapter class
 * класс преобразовывает результат sql запроса во внутренний формат
 */
class DataAdapter
{
public:
    DataAdapter();
    QList<TreeModelItemData> raskFromSQLToApp(const QList<QSqlRecord>& record);
    QList<TreeModelItemData> sostavFromSQLToApp(const QList<QSqlRecord>& record);
    QList<TreeModelItemData> stadyFromSQLToApp(const QList<QSqlRecord>& record);
    QList<TreeModelItemData> koeffFromSQLToApp(const QList<QSqlRecord>& record);
};

#endif // DATAADAPTER_H
