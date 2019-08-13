#ifndef PROJECTSREQUESTEVENT_H
#define PROJECTSREQUESTEVENT_H

#include <QEvent>
#include <utils/consts/Consts.h>
#include <data/models/ProjectModel.h>

/*!
 * \brief The ProjectsRequestEvent class оповешении об успешной выборке проектов из БД
 */
class ProjectsRequestEvent : public QEvent
{
public:
    explicit ProjectsRequestEvent();
    virtual ~ProjectsRequestEvent() {}

    static QEvent::Type type();
    QList<ProjectModel> getData() const;
    void setData(const QList<ProjectModel> &value);

private:
    QList<ProjectModel> data;
};


#endif // PROJECTSREQUESTEVENT_H
