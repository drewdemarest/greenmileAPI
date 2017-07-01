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

    QString *getKey() const;
    void setKey(QString &key);

    GMRoute *getRoute() const;
    void setRoute(GMRoute &route);

    GMOrder *getOrder() const;
    void setOrder(GMOrder &order);

    GMLocation *getLocation() const;
    void setLocation(GMLocation &location);

    int *getBaseLineSequenceNum() const;
    void setBaseLineSequenceNum(int baseLineSequenceNum);

    int *getPlannedSequenceNum() const;
    void setPlannedSequenceNum(int plannedSequenceNum);

    int *getActualSequenceNum() const;
    void setActualSequenceNum(int actualSequenceNum);

    GMStopType *getStopType() const;
    void setStopType(GMStopType &stopType);

    GMUdfs *getUdfs() const;
    void setUdfs(GMUdfs &udfs);

    QDateTime *getBaseLineArrival() const;
    void setBaseLineArrival(QDateTime &baseLineArrival);

    QDateTime *getPlannedArrival() const;
    void setPlannedArrival(QDateTime &plannedArrival);

    QDateTime *getPlannedDeparture() const;
    void setPlannedDeparture(QDateTime &plannedDeparture);

    QDateTime *getProjectedArrival() const;
    void setProjectedArrival(QDateTime &projectedArrival);

    QDateTime *getProjectedDeparture() const;
    void setProjectedDeparture(QDateTime &projectedDeparture);

    QDateTime *getActualArrival() const;
    void setActualArrival(QDateTime &actualArrival);

    double *getBaseLineDistance() const;
    void setBaseLineDistance(double baseLineDistance);

    double *getPlannedDistance() const;
    void setPlannedDistance(double plannedDistance);

    double *getProjectedDistance() const;
    void setProjectedDistance(double projectedDistance);

    double *getActualDistance() const;
    void setActualDistance(double actualDistance);

    QString *getActualArrivalDataQuality() const;
    void setActualArrivalDataQuality(QString &actualArrivalDataQuality);

    QString *getServiceDataQuality() const;
    void setServiceDataQuality(QString &serviceDataQuality);

    QString *getActualDepartureQuality() const;
    void setActualDepartureQuality(QString &actualDepartureQuality);

    QString *getActualDistanceQuality() const;
    void setActualDistanceQuality(QString &actualDistanceQuality);

    double *getBaseLineSize1() const;
    void setBaseLineSize1(double baseLineSize1);

    double *getBaseLineSize2() const;
    void setBaseLineSize2(double baseLineSize2);

    double *getBaseLineSize3() const;
    void setBaseLineSize3(double baseLineSize3);

    double *getPlannedSize1() const;
    void setPlannedSize1(double plannedLineSize1);

    double *getPlannedSize2() const;
    void setPlannedSize2(double baseLineSize2);

    double *getPlannedSize3() const;
    void setPlannedSize3(double baseLineSize3);

    double *getBaseLinePickupSize1() const;
    void setBaseLinePickupSize1(double baseLinePickupSize1);

    double *getBaseLinePickupSize2() const;
    void setBaseLinePickupSize2(double baseLinePickupSize2);

    double *getBaseLinePickupSize3() const;
    void setBaseLinePickupSize3(double baseLinePickupSize3);

    double *getActualPickupSize1() const;
    void setActualPickupSize(double actualPickupSize1);

    double *getActualPickupSize2() const;
    void setActualPickupSize2(double actualPickupSize2);

    double *getActualPickupSize3() const;
    void actualPickupSize3(double actualPickupSize3);

    double *getDamagedSize1() const;
    void setDamagedSize1(double damagedSize1);

    double *getDamagedSize2() const;
    void setDamagedSize2(double damagedSize2);

    double *getDamagedSize3() const;
    void setDamagedSize3(double damagedSize3);

    double *getBaselineServiceTime() const;
    void setBaselineServiceTime(double baselineServiceTime);

    double *getProjectedServiceTime() const;
    void setProjectedServiceTime(double projectedServiceTime);

    double *getPlannedServiceTime() const;
    void setPlannedServiceTime(double plannedServiceTime);

    double *getActualServiceTime() const;
    void setActualServiceTIme(double actualServiceTime);

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
