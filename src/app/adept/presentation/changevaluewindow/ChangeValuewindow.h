#ifndef CHANGEVALUEWINDOW_H
#define CHANGEVALUEWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <ui_ChangeValuewindow.h>

/*!
 * \brief The ChangeValueWindow class окно редактрования параетров
 */
class ChangeValueWindow : public QMainWindow, Ui::ChangeValueWindow
{
    Q_OBJECT

public:
    explicit ChangeValueWindow(QWidget *parent = nullptr);
    ~ChangeValueWindow();
public slots:
    /*!
     * \brief showWindow отобразить окно
     * \param index индекс изменяемого элемента
     */
    void showWindow(const QModelIndex& index);
signals:
    void changesAccepted(const QModelIndex& index, const QString& value);
private:
    QModelIndex m_index;
};

#endif // CHANGEVALUEWINDOW_H
