/**************************************************************************
**  File: ProjectModel.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include "TreeModelItem.h"
#include <data/entites/KoeffEntity.h>
#include <data/entites/RaskEntity.h>
#include <qlist.h>


/*!
 * \brief The ProjectModel class класс описывающий роект
 */
class ProjectModel
{
public:
    ProjectModel();
    /*!
     * \brief stadyList запрос списка этапов реализации проекта
     * \return список данных
     */
    QList<TreeModelItem> stadyList() const;
    /*!
     * \brief koefficientsList запрос списка коэффициентов
     * \return список коэффициетов
     */
    QList<TreeModelItemData> koefficientsList() const;

    void addKoefficient(const TreeModelItemData& koefficient);
    void addStady(const TreeModelItem& stady);

    TreeModelItemData getData() const;
    void setData(const TreeModelItemData &value);
    ProjectModel& operator=(const ProjectModel other);
private:
    QList<TreeModelItem> m_stadyList;
    QList<TreeModelItemData> m_koefficientsList;
    TreeModelItemData data;
};

#endif // PROJECTMODEL_H
