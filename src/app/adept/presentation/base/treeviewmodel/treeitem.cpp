#include "treeitem.h"

TreeItem::TreeItem(const QVector<QVariant> &data, TreeItem *parent)
    : m_itemData(data),
      m_parentItem(parent)
{

}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

void TreeItem::appendChild(TreeItem *item)
{
    m_childItems.append(item);
}

bool TreeItem::insertChildren(int position, int count, int columns,
                              const TreeModelItemData& sqlData)
{
    Q_UNUSED(columns);
    if (position < 0 || position > m_childItems.size()) return false;
    for (int row = 0; row < count; ++row) {
     QVector<QVariant> data;
     data<<sqlData.name()<<sqlData.value();
     TreeItem *item = new TreeItem(data, this);
     item->setSqlData(sqlData);
     m_childItems.insert(position, item);
    }
    return true;
}

TreeItem *TreeItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int TreeItem::childCount() const
{
    return m_childItems.count();
}

int TreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant TreeItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

bool TreeItem::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= m_itemData.size()) return false;
    m_itemData[column] = value;
    return true;
}

int TreeItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

TreeItem *TreeItem::parentItem()
{
    return m_parentItem;
}

bool TreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > m_childItems.size()) return false;
    for (int row = 0; row < count; ++row) delete m_childItems.takeAt(position);
    return true;
}

TreeModelItemData TreeItem::getSqlData() const
{
    return sqlData;
}

void TreeItem::setSqlData(const TreeModelItemData &value)
{
    sqlData = value;
}
