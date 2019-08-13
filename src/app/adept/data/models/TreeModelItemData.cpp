/**************************************************************************
**  File: TreeModelItemData.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 12.08.2019
**************************************************************************/
#include "TreeModelItemData.h"

#include <QString>

TreeModelItemData::TreeModelItemData()
{

}

QString TreeModelItemData::type() const
{
    return m_type;
}

void TreeModelItemData::setType(const QString &type)
{
    m_type = type;
}

QString TreeModelItemData::ID() const
{
    return m_ID;
}

void TreeModelItemData::setID(const QString &ID)
{
    m_ID = ID;
}

QString TreeModelItemData::subID() const
{
    return m_subID;
}

void TreeModelItemData::setSubID(const QString &subID)
{
    m_subID = subID;
}

QString TreeModelItemData::subIDName() const
{
    return m_subIDName;
}

void TreeModelItemData::setSubIDName(const QString &subIDName)
{
    m_subIDName = subIDName;
}

QString TreeModelItemData::name() const
{
    return m_name;
}

void TreeModelItemData::setName(const QString &name)
{
    m_name = name;
}

QString TreeModelItemData::value() const
{
    return m_value;
}

void TreeModelItemData::setValue(const QString &value)
{
    m_value = value;
}

bool TreeModelItemData::isServiceBranch() const
{
    return m_isServiceBranch;
}

void TreeModelItemData::setIsServiceBranch(bool isServiceBranch)
{
    m_isServiceBranch = isServiceBranch;
}
