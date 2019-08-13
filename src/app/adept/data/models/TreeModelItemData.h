/**************************************************************************
**  File: TreeModelItemData.h
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 12.08.2019
**************************************************************************/
#ifndef TREEMODELITEMDATA_H
#define TREEMODELITEMDATA_H

#include <QString>


/*!
 * \brief The TreeModelItemData class класс предоставляет внутреннюю
 * структуру данных ою этапах работ
 */
class TreeModelItemData
{
public:
    TreeModelItemData();
    QString type() const;
    void setType(const QString &type);

    QString ID() const;
    void setID(const QString &ID);

    QString subID() const;
    void setSubID(const QString &subID);

    QString subIDName() const;
    void setSubIDName(const QString &subIDName);

    QString name() const;
    void setName(const QString &name);

    QString value() const;
    void setValue(const QString &value);

    bool isServiceBranch() const;
    void setIsServiceBranch(bool isServiceBranch);

private:
    QString m_type;
    QString m_ID;
    QString m_subID;
    QString m_subIDName;
    QString m_name;
    QString m_value;
    bool m_isServiceBranch { false };
};

#endif // TREEMODELITEMDATA_H
