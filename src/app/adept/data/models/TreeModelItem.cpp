/**************************************************************************
**  File: TreeModelItem.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 12.08.2019
**************************************************************************/
#include "TreeModelItem.h"
#include <QDebug>


TreeModelItem::TreeModelItem()
{
    m_childsList.clear();
}

TreeModelItem::TreeModelItem(const TreeModelItem &other)
{
    auto a = other.childsList();
    this->m_childsList = other.childsList();
    this->data = other.getData();

}

QList<TreeModelItem> TreeModelItem::childsList() const
{
    return m_childsList;
}

void TreeModelItem::addChild(const TreeModelItem &child)
{
    m_childsList.push_back(child);
}

void TreeModelItem::addChild(const QList<TreeModelItem> &childList)
{
    for(auto child : childList )
        m_childsList.push_back(child);
}


TreeModelItemData TreeModelItem::getData() const
{
    return data;
}

void TreeModelItem::setData(const TreeModelItemData &value)
{
    data = value;
}

TreeModelItem &TreeModelItem::operator=(const TreeModelItem &other)
{
    this->m_childsList = other.childsList();
    this->data = other.getData();
    return *this;
}


