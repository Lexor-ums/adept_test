/**************************************************************************
**  File: TreeViewModel.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "TreeViewModel.h"
#include <QDebug>
#include <data/database/DatabaseWacther.h>

TreeViewModel::TreeViewModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = QSharedPointer<TreeItem>(new TreeItem({tr("Title"), tr("Summary")}));
}

TreeViewModel::~TreeViewModel()
{

}

QVariant TreeViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags TreeViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant TreeViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TreeViewModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem.data();
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

bool TreeViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) return false;
    TreeItem *item = getItem(index);    
    bool result = item->setData(index.column(), value);
    if (result) {
     emit dataChanged(index, index);
    }
    return result;
}

QModelIndex TreeViewModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

QModelIndex TreeViewModel::createRow(const QModelIndex &index, int role)
{
    Q_UNUSED(role);
    TreeModelItemData sqlData;

    sqlData.setName("новая запись");
    sqlData.setType(getItem(index)->getSqlData().type());
    sqlData.setSubID(getItem(index)->getSqlData().ID());
    if(getItem(index)->getSqlData().isServiceBranch()){
        sqlData.setSubIDName("rasc");
        sqlData.setSubID(getItem(index)->getSqlData().subID());
    }
    else
        sqlData.setSubIDName(getItem(index)->getSqlData().type());
    if(sqlData.type() == "stady"
            && !getItem(index)->getSqlData().isServiceBranch() ){
        sqlData.setSubIDName("stady");
        sqlData.setType("sostav");
    }
    sqlData.setValue("");

    TreeItem* parent = getItem(index);
    beginInsertRows(index, 0, 0);
    bool success = parent->insertChildren(0, 1, rootItem->columnCount(), sqlData);
    endInsertRows();
    auto childIndex = this->index(0, 0, index);
    if(success){
        emit TreeViewModel::itemInserted(sqlData, childIndex);
        return childIndex;
    }
    return QModelIndex();
}

int TreeViewModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem.data();
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int TreeViewModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}

void TreeViewModel::extractStady(TreeItem* parent, const QList<TreeModelItem>& list){
    for(auto item : list){
        QVector<QVariant> v;
        v<<item.getData().name()<<item.getData().value();
        TreeItem* child = new TreeItem(v, parent);
        child->setSqlData(item.getData());
        parent->appendChild(child);
        if( item.childsList().count() != 0){
            TreeItem* nextRoot = parent->child(parent->childCount() - 1);
            extractStady(nextRoot, item.childsList());
        }
    }
}

void TreeViewModel::setupModelData(const QList<ProjectModel> &projectList)
{
    QList<TreeItem*> parents;
    parents<<rootItem.data();
    for(auto project : projectList){
        QVector<QVariant> v;
        v<<project.getData().name()<<project.getData().value();
        TreeItem* projectItem = new TreeItem(v, parents.last());
        projectItem->setSqlData(project.getData());
        parents.last()->appendChild(projectItem);
        v.clear();
        v<<QObject::trUtf8("Стадии")<<"";
        auto sqlData = projectItem->getSqlData();
        sqlData.setIsServiceBranch(true);
        sqlData.setType("stady");
        sqlData.setSubID(sqlData.ID());
        sqlData.setSubIDName("rasc");
        TreeItem* stageItem = new TreeItem(v, projectItem);
        stageItem->setSqlData(sqlData);
        projectItem->appendChild(stageItem);

        extractStady(stageItem, project.stadyList());
        v.clear();
        v<<QObject::trUtf8("Коэффициенты")<<"";
        TreeItem* koeffItem = new TreeItem(v, projectItem);
        sqlData.setType("koeff");
        koeffItem->setSqlData(sqlData);
        projectItem->appendChild(koeffItem);
        for(auto koeff :  project.koefficientsList()){
            QVector<QVariant> v;
            v<<koeff.name()<<koeff.value();
            TreeItem* child = new TreeItem(v, koeffItem);
            child->setSqlData(koeff);
            koeffItem->appendChild(child);
        }
    }
}

bool TreeViewModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    bool success;
    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, rootItem->columnCount(),
                                         TreeModelItemData());
    endInsertRows();
    return success;
}

bool TreeViewModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    TreeModelItemData sqlData = parentItem->child(position)->getSqlData();
    bool success = true;
    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();
    if(success)
        emit TreeViewModel::itemRemoved(sqlData);
    return success;
}

TreeItem *TreeViewModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
     TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
     if (item) return item;
    }
    return rootItem.data();
}

void TreeViewModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, rootItem->childCount());
    rootItem->removeChildren(0, rootItem->childCount());
    endRemoveRows();}
