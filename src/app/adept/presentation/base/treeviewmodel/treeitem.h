#ifndef TREEITEM_H
#define TREEITEM_H

#include <QVariant>
#include <QVector>

#include <data/models/TreeModelItemData.h>

/*!
 * \brief The TreeItem class класс описывает элемент представления в модели
 */
class TreeItem
{
public:
    explicit TreeItem(const QVector<QVariant> &data, TreeItem *parentItem = nullptr);
    ~TreeItem();
    /*!
     * \brief appendChild добавление потомка
     * \param child потомок
     */
    void appendChild(TreeItem *child);
    bool insertChildren(int position, int count, int columns, const TreeModelItemData &sqlData);
    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool setData(int column, const QVariant &value);
    int row() const;
    TreeItem *parentItem();
    bool removeChildren(int position, int count);
    TreeModelItemData getSqlData() const;
    void setSqlData(const TreeModelItemData &value);

private:
    QVector<TreeItem*> m_childItems;
    QVector<QVariant> m_itemData;
    TreeModelItemData sqlData;
    TreeItem *m_parentItem;
};

#endif // TREEITEM_H
