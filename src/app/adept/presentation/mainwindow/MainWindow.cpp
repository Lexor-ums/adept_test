/**************************************************************************
**  File: MainWindow.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "MainWindow.h"
#include <utils/events/projectsRequestEvent.h>
#include <utils/events/ErrorEvent.h>
#include <QMessageBox>
#include <qdebug.h>
#include <data/repository/ProjectsRepository.h>
#include <data/database/DatabaseWacther.h>
#include <utils/consts/Consts.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle(QObject::trUtf8("Управление базой данных"));
    p_model = QSharedPointer<TreeViewModel> ( new TreeViewModel());
    treeView->setModel(p_model.data());
    treeView->installEventFilter(this);
    DataBaseWatcher::instance()->subscribe(consts::receiveProjectEventType, this);
    DataBaseWatcher::instance()->subscribe(consts::databseErrorEventType, this);
    DataBaseWatcher::instance()->subscribeToDBEvents("notify");
    qDebug()<<DataBaseWatcher::instance()->getListNotifications();
    connect(DataBaseWatcher::instance(), &DataBaseWatcher::dbChanged, this,
            [=](QString event){
       m_projectsRepository.data()->loadProjects();
    });
    m_projectsRepository.data()->loadProjects();
    connect(pushButtonAdd, &QPushButton::clicked, this, &MainWindow::onAddClick);
    connect(pushButtonRemove, &QPushButton::clicked, this, &MainWindow::onRemoveClick);
    connect(p_model.data(), &TreeViewModel::itemInserted, this,
            [=](TreeModelItemData data, const QModelIndex& index){
        data.setID(QString::number(m_projectsRepository.data()->getMaxId(data.type())));
        p_model->getItem(index)->setSqlData(data);
        m_projectsRepository->insertData(data);
    });
    connect(p_model.data(), &TreeViewModel::itemRemoved, this, [=](TreeModelItemData data){
        m_projectsRepository->removeData(data);
    });
    connect(p_valueChangigWindow.data(), &ChangeValueWindow::changesAccepted, this,
            &MainWindow::onValueChanged);
    connect(treeView, &QTreeView::doubleClicked, p_valueChangigWindow.data(),
            &ChangeValueWindow::showWindow);

}

void MainWindow::onRemoveClick()
{
    QModelIndex index = treeView->selectionModel()->currentIndex();
    if(!index.isValid()){
        QMessageBox msgBox;
        msgBox.setText(QObject::trUtf8("Ничего не выбрано "));
        msgBox.exec();
        return;
    }
    auto item = p_model->getItem(index);
    if(item->getSqlData().isServiceBranch()){
        QMessageBox msgBox;
        msgBox.setText(QObject::trUtf8("Невозможно удалить данную ветвь"));
        msgBox.exec();
        return;
    }
    p_model->removeRows(index.row(), 1, index.parent());
}

void MainWindow::onValueChanged(const QModelIndex &index, const QString &value)
{
    QModelIndex child = p_model->index(0, index.column(), index.parent());
    p_model->setData(child, value);
    TreeItem* item = p_model->getItem(child);
    auto data = item->getSqlData();
    if(child.column() == 0)
        data.setName(value);
    if(child.column() == 1)
        data.setValue(value);
    item->setSqlData(data);
    m_projectsRepository->updateData(data);
}

void MainWindow::onAddClick()
{
    QModelIndex index = treeView->selectionModel()->currentIndex();
    if(!index.isValid()){
        QMessageBox msgBox;
        msgBox.setText(QObject::trUtf8("Ничего не выбрано"));
        msgBox.exec();
        return;
    }
    if(p_model->getItem(index)->getSqlData().type() == "koeff" &&
            !p_model->getItem(index)->getSqlData().isServiceBranch()){
        QMessageBox msgBox;
        msgBox.setText(QObject::trUtf8("Невозможно добавление в данную ветвь"));
        msgBox.exec();
        return;
    }
    if (p_model->columnCount(index) == 0) {
        if (!p_model->insertColumn(0, index)) return;
    }
    auto childIndex = p_model->createRow(index, Qt::EditRole);
    treeView->selectionModel()->setCurrentIndex(childIndex,
                                                QItemSelectionModel::ClearAndSelect);
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == consts::receiveProjectEventType) {
        qDebug()<<"load proj";
        p_model.data()->clear();
        p_model->setupModelData(static_cast<ProjectsRequestEvent*>(event)->getData());        
        treeView->setColumnWidth(0, treeView->width() * 0.8);
        return true;
    }
    else if (event->type() == consts::databseErrorEventType) {
        QMessageBox msgBox;
        msgBox.setText(QObject::trUtf8("Проблемы с доступом к БД "));
        msgBox.exec();
        return true;
    }
    else {
        return QMainWindow::event(event);
    }
}
