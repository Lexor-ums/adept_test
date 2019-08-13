/**************************************************************************
**  File: ProjectsDAO.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef PROJECTSDAO_H
#define PROJECTSDAO_H

#include <data/entites/SostavEntity.h>

#include <QSqlRecord>
#include <qlist.h>

#include <connectortodatabase.h>

#include <data/models/TreeModelItemData.h>


/*!
 * \brief The ProjectsDAO class
 * класс ,предоставляющий доступ к данным
 */
class ProjectsDAO
{
public:
    ProjectsDAO();
    QPair<bool, QList<QSqlRecord>> getSostavList();
    QPair<bool, QList<QSqlRecord>> getRaskList();
    QPair<bool, QList<QSqlRecord>> getKoeffList();
    QPair<bool, QList<QSqlRecord> > getStadyList();
    bool insertData(TreeModelItemData data);
    bool updateData(TreeModelItemData data);
    bool remove(TreeModelItemData data);
    QPair<bool, int> getMaxId(const QString& table);
private:
    QPair<bool, QList<QSqlRecord>> selectAll(const QString& tableName);
};

#endif // PROJECTSDAO_H
