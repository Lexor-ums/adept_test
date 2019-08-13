/**************************************************************************
**  File: TreeViewModel.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H

#include "treeitem.h"

#include <qstandarditemmodel.h>

#include <data/models/ProjectModel.h>


/*!
 * \brief The TreeViewModel class класс описывает модель данных treeview
 */
class TreeViewModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeViewModel(QObject *parent = nullptr);
    ~TreeViewModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    /*!
     * \brief createRow создание новой записи
     * \param index  родительский индекс
     * \param role роль
     * \return индекс нового элемента
     */
    QModelIndex createRow(const QModelIndex &index, int role = Qt::EditRole);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    /*!
     * \brief setupModelData иницилизация модели
     * \param lines список проектов
     */
    void setupModelData(const QList<ProjectModel> &lines);
    bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &parent = QModelIndex()) override;
    TreeItem *getItem(const QModelIndex &index) const;
    void clear();

signals:
    /*!
     * \brief itemInserted оповещение о добавлении нового элемена
     * \param data структура данных
     * \param index  индек созданного элемента
     */
    void itemInserted(const TreeModelItemData& data,  const QModelIndex& index);
    /*!
     * \brief itemUpdated оповещение об обновлении элемена
     * \param data структура данных
     */
    void itemUpdated(const TreeModelItemData& data);
    /*!
     * \brief itemRemoved оповещение об удалении элемена
     * \param data структура данных
     */
    void itemRemoved(const TreeModelItemData& data);

private:
    void extractStady(TreeItem* parent, const QList<TreeModelItem>& list);
    QSharedPointer<TreeItem> rootItem;
};

#endif // TREEVIEWMODEL_H
