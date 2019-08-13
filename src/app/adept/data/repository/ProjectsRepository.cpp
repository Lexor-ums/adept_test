/**************************************************************************
**  File: ProjectsRepository.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "ProjectsRepository.h"

#include <QtConcurrent/QtConcurrent>
#include <data/database/DatabaseWacther.h>
#include <data/adapters/dataadapter.h>
#include <utils/events/ErrorEvent.h>
#include <utils/events/projectsRequestEvent.h>

ProjectsRepository::ProjectsRepository()
{

}

void ProjectsRepository::loadProjects()
{
    QFuture <void> future = QtConcurrent::run(this, &ProjectsRepository::startLoadProjects);
}

int ProjectsRepository::getMaxId(const QString &table)
{
    auto res = dao.getMaxId(table);
    if(!res.first){
    }
    return res.second;
}

void ProjectsRepository::insertData(TreeModelItemData data)
{
    QFuture <void> future =
            QtConcurrent::run(this, &ProjectsRepository::startInsertData, data);
}

void ProjectsRepository::updateData(TreeModelItemData data)
{
    QFuture <void> future =
            QtConcurrent::run(this, &ProjectsRepository::startUpdateData, data);
}

void ProjectsRepository::removeData(TreeModelItemData data)
{
    QFuture <void> future =
            QtConcurrent::run(this, &ProjectsRepository::startRemoveData, data);
}

void ProjectsRepository::startInsertData(TreeModelItemData data)
{
    if(!dao.insertData(data))
        DataBaseWatcher::instance()->riseEvent(new ErrorEvent());
}

void ProjectsRepository::startUpdateData(TreeModelItemData data)
{
    if(!dao.updateData(data))
        DataBaseWatcher::instance()->riseEvent(new ErrorEvent());
}

void ProjectsRepository::startRemoveData(TreeModelItemData data)
{
    if(!dao.remove(data))
        DataBaseWatcher::instance()->riseEvent(new ErrorEvent());
}

QList<TreeModelItem> ProjectsRepository::addChilds(const QList<TreeModelItemData>& list, QString id,
                               const QString& parentName){
    QList<TreeModelItem> childsList;
    for(auto data : list){
        if(data.subIDName()  != parentName)
            continue;
        if(data.subID() == id){
            TreeModelItem it;
            it.setData(data);
            it.addChild(addChilds(list, data.ID(), parentName));
            childsList.push_back(it);
        }
    }
    return childsList;
}

void ProjectsRepository::startLoadProjects()
{
    DataAdapter adapter;
    QList<TreeModelItemData> sostavListData;
    QList<TreeModelItemData> stadiesListData;;
    QList<TreeModelItemData> koeffsListData;
    QList<TreeModelItemData> raskListData;

    QList<TreeModelItem> sostavList;
    QList<TreeModelItem> stadiesList;;
    QList<TreeModelItem> koeffsList;
    QList<TreeModelItem> raskList;

    QList<ProjectModel> projectsList;

    auto res = dao.getSostavList();
    if(res.first)
        sostavListData = adapter.sostavFromSQLToApp(res.second);
    else {
        DataBaseWatcher::instance()->riseEvent(new ErrorEvent());
        return;
    }
    res = dao.getStadyList();
    if(res.first)
        stadiesListData = adapter.stadyFromSQLToApp(res.second);
    else {
        DataBaseWatcher::instance()->riseEvent(new ErrorEvent());
        return;
    }
    res = dao.getKoeffList();
    if(res.first)
        koeffsListData = adapter.koeffFromSQLToApp(res.second);
    else {
        DataBaseWatcher::instance()->riseEvent(new ErrorEvent());
        return;
    }
    res = dao.getRaskList();
    if(res.first)
        raskListData = adapter.raskFromSQLToApp(res.second);
    else {
        DataBaseWatcher::instance()->riseEvent(new ErrorEvent());
        return;
    }

    for (auto it : sostavListData) {
        TreeModelItem item;
        item.setData(it);
        if(it.subIDName() == "stady"){
            sostavList.push_back(item);
        }
        if(it.subIDName() == "sostav"){
            item.setData(it);
            item.addChild(addChilds(sostavListData, it.ID(), "sostav"));
            for (auto& master_it : sostavList) {
                if(master_it.getData().ID() == it.subID()){
                    master_it.addChild(item);
                }
            }
        }
    }

    for (auto it : stadiesListData) {
        TreeModelItem item;
        item.setData(it);
        if(it.subIDName() == "rasc"){
            for (auto master_it : sostavList) {
                if(master_it.getData().subID() == it.ID()){
                    item.addChild(master_it);
                }
            }
            stadiesList.push_back(item);
        }
        if(it.subIDName() == "stady"){
            item.setData(it);
            item.addChild(addChilds(sostavListData, it.ID(), "stady"));
            for (auto& master_it : stadiesList) {
                if(master_it.getData().ID() == it.subID()){
                    master_it.addChild(item);
                }
            }
        }
    }
    for (auto rask : raskListData) {
        ProjectModel project;
        project.setData(rask);
        for(auto stady : stadiesList){
            if(stady.getData().subID() == rask.ID())
                project.addStady(stady);
        }
        for(auto koeff : koeffsListData){
            if(koeff.subID() == rask.ID())
                project.addKoefficient(koeff);
        }
        projectsList.push_back(project);
    }
    ProjectsRequestEvent* ev = new ProjectsRequestEvent();
    ev->setData(projectsList);
    DataBaseWatcher::instance()->riseEvent(ev);
}
