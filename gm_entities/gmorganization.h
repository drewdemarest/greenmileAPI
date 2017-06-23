#ifndef GMORGANIZATION_H
#define GMORGANIZATION_H

#include <QtCore>

class GMOrganization
{
public:
    GMOrganization();

    //BEGIN COMPUTATION FUNCTIONS
    void importJson(const QJsonObject &json);
    void appendJson(const QJsonObject &json);
    QJsonObject exportJson();

private:
    //GM_Organization org
    //GM_Location orgin;
    //GM_Location destination;
    //GM_Stop stops;
    //GM_DriverAssignment driverAssignments;
    //GM_EquipmentAssignment equipmentAssignments;
    //GM_RouteHelperAssignment routeHelperAssignments;

    //Computation subsection.
    void compareJson(const QJsonObject &json);
    void setMembersToDefaults();
    void setImportedMembersFalse();

    QJsonObject exportEngine();
    void importEngine(const QJsonObject &json);


    //Memeber subsection
    bool objBoolInit                      = false;
    int objIntInit                        = 0;
    double objDoubleInit                  = 0;
    QString objQStringInit                = QString();
    QDate objQDateInit                    = QDate::currentDate();
    QDateTime objQDateTimeInit            = QDateTime::currentDateTime();

    QStringList memberList;

    QMap<QString, int>              objInt;
    QMap<QString, double>           objDouble;
    QMap<QString, bool>             objBool;
    QMap<QString, QString>          objQString;
    QMap<QString, QDate>            objQDate;
    QMap<QString, QDateTime>        objQDateTime;
    QMap<QString, GMOrganization>   objGMOrganization;
    //Meta member to track which members are imported
    QMap<QString, bool>         importedMember;
};

#endif // GMORGANIZATION_H
