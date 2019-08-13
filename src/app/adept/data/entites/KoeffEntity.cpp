/**************************************************************************
**  File: KoeffEntity.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "KoeffEntity.h"

KoeffEntity::KoeffEntity()
{

}

KoeffEntity::KoeffEntity(const KoeffEntity &other)
{
    id = other.id;
    subID = other.subID;
    subIDName = other.subIDName;
    dolya = other.dolya;
    hard = other.hard;
    name = other.name;
    A_B_normal = other.A_B_normal;
    status = other.status;
}

int KoeffEntity::getId() const
{
    return id;
}

void KoeffEntity::setId(int value)
{
    id = value;
}

QString KoeffEntity::getSubID() const
{
    return subID;
}

void KoeffEntity::setSubID(const QString &value)
{
    subID = value;
}

QString KoeffEntity::getSubIDName() const
{
    return subIDName;
}

void KoeffEntity::setSubIDName(const QString &value)
{
    subIDName = value;
}

QString KoeffEntity::getDolya() const
{
    return dolya;
}

void KoeffEntity::setDolya(const QString &value)
{
    dolya = value;
}

QString KoeffEntity::getHard() const
{
    return hard;
}

void KoeffEntity::setHard(const QString &value)
{
    hard = value;
}

QString KoeffEntity::getName() const
{
    return name;
}

void KoeffEntity::setName(const QString &value)
{
    name = value;
}

QString KoeffEntity::getA_B_normal() const
{
    return A_B_normal;
}

void KoeffEntity::setA_B_normal(const QString &value)
{
    A_B_normal = value;
}

QString KoeffEntity::getStatus() const
{
    return status;
}

void KoeffEntity::setStatus(const QString &value)
{
    status = value;
}
