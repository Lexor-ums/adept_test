/**************************************************************************
**  File: SostavEntity.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/
#ifndef SOSTAVENTITY_H
#define SOSTAVENTITY_H

#include <qstring.h>



class SostavEntity
{
public:
    SostavEntity();
    SostavEntity(const SostavEntity& other);
    int getId() const;
    void setId(int value);

    QString getSubID() const;
    void setSubID(const QString &value);

    QString getSubIDName() const;
    void setSubIDName(const QString &value);

    QString getDolya() const;
    void setDolya(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getStatus() const;
    void setStatus(const QString &value);

private:
    int id {0};
    QString subID { "" };
    QString subIDName { "" };
    QString dolya { "" };
    QString name { "" };
    QString status { "" };
};

#endif // SOSTAVENTITY_H
