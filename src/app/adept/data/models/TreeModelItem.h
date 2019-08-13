/**************************************************************************
**  File: TreeModelItem.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 12.08.2019
**************************************************************************/
#ifndef TREEMODELITEM_H
#define TREEMODELITEM_H

#include "TreeModelItemData.h"

#include <QList>
#include <QString>

/*!
 * \brief The TreeModelItem class описывает струкруту корневых элементов древа
 */
class TreeModelItem
{
public:
    TreeModelItem();    
    TreeModelItem(const TreeModelItem &other);

    QList<TreeModelItem> childsList() const;
    void addChild(const TreeModelItem &child);
    void addChild(const QList<TreeModelItem> &childList);

    TreeModelItemData getData() const;
    void setData(const TreeModelItemData &value);

    TreeModelItem& operator=(const TreeModelItem& other);
private:
    TreeModelItemData data;
    QList<TreeModelItem> m_childsList;
};

#endif // TREEMODELITEM_H

