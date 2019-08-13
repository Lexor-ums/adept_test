/**************************************************************************
**  File: MainWindow.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"
#include <data/repository/ProjectsRepository.h>
#include <presentation/base/treeviewmodel/TreeViewModel.h>
#include <presentation/changevaluewindow/ChangeValuewindow.h>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    // MainWindowView interface
private:
    QSharedPointer<ProjectsRepository> m_projectsRepository { new ProjectsRepository () };
    QSharedPointer<TreeViewModel> p_model;
    QSharedPointer<ChangeValueWindow> p_valueChangigWindow { new ChangeValueWindow()};
    // QObject interface
private slots:
    /*!
     * \brief onAddClick событие добавление ноовго элемента
     */
    void onAddClick();
    /*!
     * \brief onRemoveClick событие удаления элемента
     */
    void onRemoveClick();
    /*!
     * \brief onValueChanged обновления данных
     * \param index индекс изменямого элемента
     * \param value новое значение
     */
    void onValueChanged(const QModelIndex& index, const QString& value);
public:
    bool event(QEvent *event);
};

#endif // MAINWINDOW_H
