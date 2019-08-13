/**************************************************************************
**  File: ProjectsRepository.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef PROJECTSREPOSITORY_H
#define PROJECTSREPOSITORY_H

#include <data/entites/KoeffEntity.h>
#include <data/entites/RaskEntity.h>
#include <data/entites/SostavEntity.h>
#include <qlist.h>
#include <data/models/ProjectModel.h>
#include <data/dao/ProjectsDAO.h>

/*!
 * \brief The ProjectsRepository class класс предоставляет API взаимождействия с БД
 */
class ProjectsRepository
{
public:
    ProjectsRepository();
    /*!
     * \brief loadProjects загрузка списка проектов
     */
    void loadProjects();
    /*!
     * \brief getMaxId запрос максимального интекса в БД
     * \param table имя БД
     * \return максимальный индекс
     */
    int getMaxId(const QString& table);
    /*!
     * \brief insertData добавление данных в структуру
     * \param data класс с описанием данных
     */
    void insertData(TreeModelItemData data);
    /*!
     * \brief insertData обновление данных в структуре
     * \param data класс с описанием данных
     */
    void updateData(TreeModelItemData data);
    /*!
     * \brief insertData удаление данных из структуры
     * \param data класс с описанием данных
     */
    void removeData(TreeModelItemData data);    
private:
    void startLoadProjects();
    void startInsertData(TreeModelItemData data);
    void startUpdateData(TreeModelItemData data);
    void startRemoveData(TreeModelItemData data);
    QList<TreeModelItem> addChilds(const QList<TreeModelItemData>& list, QString id,
                                   const QString& parentName);
    ProjectsDAO dao;
};

#endif // PROJECTSREPOSITORY_H
