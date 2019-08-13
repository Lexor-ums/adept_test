/**************************************************************************
**  File: SostavEntity.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "SostavEntity.h"

SostavEntity::SostavEntity()
{

}

SostavEntity::SostavEntity(const SostavEntity &other)
{
    id = other.id;
    subID = other.subID;
    subIDName = other.subIDName;
    dolya = other.dolya;
    name = other.name;
    status = other.status;
}

int SostavEntity::getId() const
{
    return id;
}

void SostavEntity::setId(int value)
{
    id = value;
}

QString SostavEntity::getSubID() const
{
    return subID;
}

void SostavEntity::setSubID(const QString &value)
{
    subID = value;
}

QString SostavEntity::getSubIDName() const
{
    return subIDName;
}

void SostavEntity::setSubIDName(const QString &value)
{
    subIDName = value;
}

QString SostavEntity::getDolya() const
{
    return dolya;
}

void SostavEntity::setDolya(const QString &value)
{
    dolya = value;
}

QString SostavEntity::getName() const
{
    return name;
}

void SostavEntity::setName(const QString &value)
{
    name = value;
}

QString SostavEntity::getStatus() const
{
    return status;
}

void SostavEntity::setStatus(const QString &value)
{
    status = value;
}
