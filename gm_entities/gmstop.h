#ifndef GMSTOP_H
#define GMSTOP_H

#include <QtCore>

class GMRoute;
class GMOrder;
class GMLocation;
class GMStopType;
class GMUdfs;

class GMStop
{
public:
    GMStop();
    ~GMStop();

    int *getId() const;
    void setId(int id);

    //BEGIN COMPUTATION FUNCTIONS
    void importJson(const QJsonObject &json);
    void appendJson(const QJsonObject &json);
    QJsonObject exportJson();
    void setMembersNull();

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
    //void setMembersNull();
    void setImportedMembersFalse();

    QJsonObject exportEngine();
    void importEngine(const QJsonObject &json);

    //Memeber subsection
    bool *objBoolInit                       = Q_NULLPTR;
    int *objIntInit                         = Q_NULLPTR;
    double *objDoubleInit                   = Q_NULLPTR;
    QString *objQStringInit                 = Q_NULLPTR;
    QDate *objQDateInit                     = Q_NULLPTR;
    QDateTime *objQDateTimeInit             = Q_NULLPTR;



    //NEW OBJECTS HERE
    float *objFloatInit                     = Q_NULLPTR;
    GMRoute *objGMRouteInit                 = Q_NULLPTR;
    GMOrder *objGMOrderInit                 = Q_NULLPTR;
    GMLocation *objGMLocationInit           = Q_NULLPTR;
    GMStopType *objGMStopTypeInit           = Q_NULLPTR;
    GMUdfs *objGMUdfsInit                   = Q_NULLPTR;


    QStringList memberList;

    QMap<QString, int*>              objInt;
    QMap<QString, double*>           objDouble;
    QMap<QString, bool*>             objBool;
    QMap<QString, QString*>          objQString;
    QMap<QString, QDate*>            objQDate;
    QMap<QString, QDateTime*>        objQDateTime;

    //Members which will need new loops written for them.
    QMap<QString, float*>            objFloat;
    QMap<QString, GMRoute*>          objGMRoute;
    //Members which are new and also need thier class written...
    QMap<QString, GMOrder*>          objGMOrder;
    QMap<QString, GMLocation*>       objGMLocation;
    QMap<QString, GMStopType*>       objGMStopType;
    QMap<QString, GMUdfs*>           objGMUdfs;


    //Meta member to track which members are imported
    QMap<QString, bool>             importedMember;

    //This is needed so that I can turn objects into strings.
    QJsonDocument                   catalyst;
};

#endif // GMSTOP_H
