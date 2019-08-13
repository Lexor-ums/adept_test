/**************************************************************************
**  File: RaskEntity.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#include "RaskEntity.h"

RaskEntity::RaskEntity()
{
}

RaskEntity::RaskEntity(const RaskEntity &other)
{
    id = other.id;
    subID = other.subID;
    subIDName = other.subIDName;
    code = other.code;
    cPred = other.cPred;
    xMax = other.xMax;
    pPred = other.pPred;
    unit = other.unit;
    xMin = other.xMin;
    year = other.year;
    typ = other.typ;
    xZad = other.xZad;
    koeffTek = other.koeffTek;
    csled = other.csled;
    A = other.A;
    B = other.B;
    name = other.name;
    mnogitel = other.mnogitel;
    pSled = other.pSled;
    razdel = other.razdel;
}

int RaskEntity::getId() const
{
    return id;
}

void RaskEntity::setId(int value)
{
    id = value;
}

QString RaskEntity::getSubID() const
{
    return subID;
}

void RaskEntity::setSubID(const QString &value)
{
    subID = value;
}

QString RaskEntity::getSubIDName() const
{
    return subIDName;
}

void RaskEntity::setSubIDName(const QString &value)
{
    subIDName = value;
}

QString RaskEntity::getCode() const
{
    return code;
}

void RaskEntity::setCode(const QString &value)
{
    code = value;
}

QString RaskEntity::getCPred() const
{
    return cPred;
}

void RaskEntity::setCPred(const QString &value)
{
    cPred = value;
}

QString RaskEntity::getXMax() const
{
    return xMax;
}

void RaskEntity::setXMax(const QString &value)
{
    xMax = value;
}

QString RaskEntity::getPPred() const
{
    return pPred;
}

void RaskEntity::setPPred(const QString &value)
{
    pPred = value;
}

QString RaskEntity::getUnit() const
{
    return unit;
}

void RaskEntity::setUnit(const QString &value)
{
    unit = value;
}

QString RaskEntity::getXMin() const
{
    return xMin;
}

void RaskEntity::setXMin(const QString &value)
{
    xMin = value;
}

QString RaskEntity::getYear() const
{
    return year;
}

void RaskEntity::setYear(const QString &value)
{
    year = value;
}

QString RaskEntity::getTyp() const
{
    return typ;
}

void RaskEntity::setTyp(const QString &value)
{
    typ = value;
}

QString RaskEntity::getXZad() const
{
    return xZad;
}

void RaskEntity::setXZad(const QString &value)
{
    xZad = value;
}

QString RaskEntity::getKoeffTek() const
{
    return koeffTek;
}

void RaskEntity::setKoeffTek(const QString &value)
{
    koeffTek = value;
}

QString RaskEntity::getCsled() const
{
    return csled;
}

void RaskEntity::setCsled(const QString &value)
{
    csled = value;
}

QString RaskEntity::getA() const
{
    return A;
}

void RaskEntity::setA(const QString &value)
{
    A = value;
}

QString RaskEntity::getB() const
{
    return B;
}

void RaskEntity::setB(const QString &value)
{
    B = value;
}

QString RaskEntity::getName() const
{
    return name;
}

void RaskEntity::setName(const QString &value)
{
    name = value;
}

QString RaskEntity::getMnogitel() const
{
    return mnogitel;
}

void RaskEntity::setMnogitel(const QString &value)
{
    mnogitel = value;
}

QString RaskEntity::getPSled() const
{
    return pSled;
}

void RaskEntity::setPSled(const QString &value)
{
    pSled = value;
}

QString RaskEntity::getRazdel() const
{
    return razdel;
}

void RaskEntity::setRazdel(const QString &value)
{
    razdel = value;
}
