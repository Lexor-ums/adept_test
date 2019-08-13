/**************************************************************************
**  File: StadyEntity.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "StadyEntity.h"

StadyEntity::StadyEntity()
{

}

StadyEntity::StadyEntity(const StadyEntity &other)
{
    id = other.id;
    subID = other.subID;
    subIDName = other.subIDName;
    dolya = other.dolya;
    name = other.name;
    status = other.status;
}

int StadyEntity::getId() const
{
    return id;
}

void StadyEntity::setId(int value)
{
    id = value;
}

QString StadyEntity::getSubID() const
{
    return subID;
}

void StadyEntity::setSubID(const QString &value)
{
    subID = value;
}

QString StadyEntity::getSubIDName() const
{
    return subIDName;
}

void StadyEntity::setSubIDName(const QString &value)
{
    subIDName = value;
}

QString StadyEntity::getDolya() const
{
    return dolya;
}

void StadyEntity::setDolya(const QString &value)
{
    dolya = value;
}

QString StadyEntity::getName() const
{
    return name;
}

void StadyEntity::setName(const QString &value)
{
    name = value;
}

QString StadyEntity::getStatus() const
{
    return status;
}

void StadyEntity::setStatus(const QString &value)
{
    status = value;
}
