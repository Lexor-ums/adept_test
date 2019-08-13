#include "projectsRequestEvent.h"

#include <qapplication.h>

ProjectsRequestEvent::ProjectsRequestEvent() : QEvent (ProjectsRequestEvent::type())
{

}
QEvent::Type ProjectsRequestEvent::type()
{    
    return consts::receiveProjectEventType;
}

QList<ProjectModel> ProjectsRequestEvent::getData() const
{
    return data;
}

void ProjectsRequestEvent::setData(const QList<ProjectModel> &value)
{
    data = value;
}
