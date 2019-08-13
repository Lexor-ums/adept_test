/**************************************************************************
**  File: RaskEntity.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef RASKENTITY_H
#define RASKENTITY_H

#include <qstring.h>

class RaskEntity
{
public:
    RaskEntity();
    RaskEntity(const RaskEntity& other );

    int getId() const;
    void setId(int value);

    QString getSubID() const;
    void setSubID(const QString &value);

    QString getSubIDName() const;
    void setSubIDName(const QString &value);

    QString getCode() const;
    void setCode(const QString &value);

    QString getCPred() const;
    void setCPred(const QString &value);

    QString getXMax() const;
    void setXMax(const QString &value);

    QString getPPred() const;
    void setPPred(const QString &value);

    QString getUnit() const;
    void setUnit(const QString &value);

    QString getXMin() const;
    void setXMin(const QString &value);

    QString getYear() const;
    void setYear(const QString &value);

    QString getTyp() const;
    void setTyp(const QString &value);

    QString getXZad() const;
    void setXZad(const QString &value);

    QString getKoeffTek() const;
    void setKoeffTek(const QString &value);

    QString getCsled() const;
    void setCsled(const QString &value);

    QString getA() const;
    void setA(const QString &value);

    QString getB() const;
    void setB(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getMnogitel() const;
    void setMnogitel(const QString &value);

    QString getPSled() const;
    void setPSled(const QString &value);

    QString getRazdel() const;
    void setRazdel(const QString &value);

private:
    int id {0};
    QString subID { "" };
    QString subIDName { "" };
    QString code { "" };
    QString cPred { "" };
    QString xMax { "" };
    QString pPred { "" };
    QString unit { "" };
    QString xMin { "" };
    QString year { "" };
    QString typ{ "" };
    QString xZad{ "" };
    QString koeffTek{ "" };
    QString csled { "" };
    QString A { "" };
    QString B { "" };
    QString name{ "" };
    QString mnogitel{ "" };
    QString pSled{ "" };
    QString razdel{ "" };

};

#endif // RASKENTITY_H
