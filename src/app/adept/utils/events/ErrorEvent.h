#ifndef ERROREVENT_H
#define ERROREVENT_H
#include <QEvent>

/*!
 * \brief The ErrorEvent class обработчик ошибок работы с БД
 */
class ErrorEvent : public QEvent
{
public:
    explicit ErrorEvent();
    virtual ~ErrorEvent() {}

    static QEvent::Type type();

private:
};

#endif // ERROREVENT_H
