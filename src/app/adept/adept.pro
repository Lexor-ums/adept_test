include(../../../common.pri)

include(../../../app.pri)

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = adept

CONFIG += c++17

SOURCES += \
    data/adapters/dataadapter.cpp \
    data/database/DatabaseWacther.cpp \
    main.cpp \
    presentation/base/treeviewmodel/treeitem.cpp \
    presentation/changevaluewindow/ChangeValuewindow.cpp \
    presentation/mainwindow/MainWindow.cpp \
    data/entites/RaskEntity.cpp \
    data/entites/StadyEntity.cpp \
    data/entites/SostavEntity.cpp \
    data/entites/KoeffEntity.cpp \
    presentation/base/treeviewmodel/TreeViewModel.cpp \
    data/models/ProjectModel.cpp \    
    data/dao/ProjectsDAO.cpp \
    data/repository/ProjectsRepository.cpp \    
    utils/events/ErrorEvent.cpp \
    utils/events/projectsRequestEvent.cpp \
    data/models/TreeModelItem.cpp \
    data/models/TreeModelItemData.cpp

FORMS += \
    presentation/changevaluewindow/ChangeValuewindow.ui \
    presentation/mainwindow/MainWindow.ui

HEADERS += \
    data/adapters/dataadapter.h \
    data/database/DatabaseWacther.h \
    presentation/base/treeviewmodel/treeitem.h \
    presentation/changevaluewindow/ChangeValuewindow.h \
    presentation/mainwindow/MainWindow.h \
    data/entites/RaskEntity.h \
    data/entites/StadyEntity.h \
    data/entites/SostavEntity.h \
    data/entites/KoeffEntity.h \
    data/database/database.h \
    data/database/database_global.h \
    presentation/base/treeviewmodel/TreeViewModel.h \
    data/models/ProjectModel.h \    
    data/dao/ProjectsDAO.h \
    data/repository/ProjectsRepository.h \    
    utils/events/ErrorEvent.h \
    utils/events/projectsRequestEvent.h \
    utils/consts/Consts.h \
    data/models/TreeModelItem.h \
    data/models/TreeModelItemData.h


INCLUDEPATH = ../../lib/connector

LIBS *= -lconnectortodatabase
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
