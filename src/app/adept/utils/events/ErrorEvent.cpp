#include "ErrorEvent.h"
#include <utils/consts/Consts.h>

ErrorEvent::ErrorEvent(): QEvent (ErrorEvent::type())
{

}

QEvent::Type ErrorEvent::type()
{
    return consts::receiveProjectEventType;
}
