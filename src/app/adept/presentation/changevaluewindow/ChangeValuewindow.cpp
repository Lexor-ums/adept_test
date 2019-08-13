#include "ChangeValuewindow.h"
#include "ui_ChangeValuewindow.h"

ChangeValueWindow::ChangeValueWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle(QObject::trUtf8("Изменение параметров"));
    connect(pushButtonAccept, &QPushButton::clicked, this, [=](bool checked){
        Q_UNUSED(checked)
       emit ChangeValueWindow::changesAccepted(m_index, lineEdit->text());
       QMainWindow::hide();
    });
    connect(pushButtonReject, &QPushButton::clicked, this, &QMainWindow::hide);
}

ChangeValueWindow::~ChangeValueWindow()
{
}

void ChangeValueWindow::showWindow(const QModelIndex &index)
{
    m_index = index;
    if (m_index.column() == 0)
        label->setText(QObject::trUtf8("Новое название этапа"));
    if (m_index.column() == 1)
        label->setText(QObject::trUtf8("Новое название аттрибута"));
    lineEdit->setText(index.data().toString());
    show();
}
