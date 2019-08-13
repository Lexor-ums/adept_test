/**************************************************************************
**  File: KoeffEntity.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef KOEFFENTITY_H
#define KOEFFENTITY_H

#include <qstring.h>



class KoeffEntity
{
public:
    KoeffEntity();
    KoeffEntity(const KoeffEntity& other);
    int getId() const;
    void setId(int value);

    QString getSubID() const;
    void setSubID(const QString &value);

    QString getSubIDName() const;
    void setSubIDName(const QString &value);

    QString getDolya() const;
    void setDolya(const QString &value);

    QString getHard() const;
    void setHard(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getA_B_normal() const;
    void setA_B_normal(const QString &value);

    QString getStatus() const;
    void setStatus(const QString &value);

private:
    int id {0};
    QString subID { "" };
    QString subIDName { "" };
    QString dolya { "" };
    QString hard { "" };
    QString name { "" };
    QString A_B_normal { "" };
    QString status { "" };
};

#endif // KOEFFENTITY_H
