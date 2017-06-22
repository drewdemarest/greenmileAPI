#ifndef GMENTITY_H
#define GMENTITY_H

#include <QtCore>

class GMEntity
{
public:
    GMEntity();

    virtual void read(const QJsonObject &json);
    virtual void append(const QJsonObject &json);
    virtual QJsonObject write();

protected:
    //Computation subsection.
    void compareJson(const QJsonObject &json);
    void setMembersToDefaults();
    void setImportedMembersFalse();

    //Memeber subsection
    bool objBoolInit                      = false;
    int objIntInit                        = 0;
    double objDoubleInit                  = 0;
    QString objQStringInit                = QString();
    QDate objQDateInit                    = QDate::currentDate();
    QDateTime objQDateTimeInit            = QDateTime::currentDateTime();

    QStringList memberList;

    QMap<QString, int>          objInt;
    QMap<QString, double>       objDouble;
    QMap<QString, bool>         objBool;
    QMap<QString, QString>      objQString;
    QMap<QString, QDate>        objQDate;
    QMap<QString, QDateTime>    objQDateTime;
    //Meta member to track which members are imported
    QMap<QString, bool>         importedMember;

    //Custom Member maps...
    //GM_Organization org
    //GM_Location orgin;
    //GM_Location destination;
    //GM_Stop stops;
    //GM_DriverAssignment driverAssignments;
    //GM_EquipmentAssignment equipmentAssignments;
    //GM_RouteHelperAssignment routeHelperAssignments;
};

#endif // GMENTITY_H

