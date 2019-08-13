/**************************************************************************
**  File: ProjectModel.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "ProjectModel.h"
#include <QDebug>

ProjectModel::ProjectModel()
{
    m_stadyList.clear();
}

QList<TreeModelItem> ProjectModel::stadyList() const
{
    return m_stadyList;
}

QList<TreeModelItemData> ProjectModel::koefficientsList() const
{
    return m_koefficientsList;
}

void ProjectModel::addKoefficient(const TreeModelItemData &koefficient)
{
    m_koefficientsList.push_back(koefficient);
}

void ProjectModel::addStady(const TreeModelItem &stady)
{
    m_stadyList.push_back(stady);
}

TreeModelItemData ProjectModel::getData() const
{
    return data;
}

void ProjectModel::setData(const TreeModelItemData &value)
{
    data = value;
}

ProjectModel &ProjectModel::operator=(const ProjectModel other)
{
    this->m_stadyList = other.stadyList();
    this->m_koefficientsList = other.koefficientsList();
    return *this;
}
