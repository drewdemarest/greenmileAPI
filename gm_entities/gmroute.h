#ifndef GMROUTE_H
#define GMROUTE_H

#include <QtCore>
#include <gm_entities/gmorganization.h>

class GMRoute
{
public:
    GMRoute();

    //BEGIN GETTERS/SETTERS

    int getId() const;
    void setId(int id);

    QString getKey() const;
    void setKey(const QString &key);

    QString getDescription() const;
    void setDescription(const QString &description);

    QDate getDate() const;
    void setDate(const QDate &date);

    bool getLastStopIsDestination() const;
    void setLastStopIsDestination(bool lastStopIsDestination);

    QDateTime getPlannedArrival() const;
    void setPlannedArrival(const QDateTime &plannedArrival);

    QDateTime getBaseLineArrival() const;
    void setBaseLineArrival(const QDateTime &baseLineArrival);

    QDateTime getBaseLineDeparture() const;
    void setBaseLineDeparture(const QDateTime &baseLineDeparture);

    QDateTime getPlannedDeparture() const;
    void setPlannedDeparture(const QDateTime &plannedDeparture);

    QDateTime getBaselineDeparture() const;
    void setBaselineDeparture(const QDateTime &baselineDeparture);

    QDateTime getProjectedArrival() const;
    void setProjectedArrival(const QDateTime &projectedArrival);

    QDateTime getProjectedDeparture() const;
    void setProjectedDeparture(const QDateTime &projectedDeparture);

    QDateTime getActualArrival() const;
    void setActualArrival(const QDateTime &actualArrival);

    QDateTime getActualDeparture() const;
    void setActualDeparture(const QDateTime &actualDeparture);

    double getbaseLineDistance() const;
    void setbaseLineDistance(double baseLineDistance);

    double getPlannedDistance() const;
    void setPlannedDistance(double plannedDistance);

    double getProjectedDistance() const;
    void setProjectedDistance(double projectedDistance);

    double getActualDistance() const;
    void setActualDistance(double actualDistance);

    int getDelayTypeID() const;
    void setDelayTypeID(int delayTypeID);

    int getDelayMinutes() const;
    void setDelayMinutes(int delayMinutes);

    QDateTime getLastContactTime() const;
    void setLastContactTime(const QDateTime &lastContactTime);

    QDateTime getBaseLineComplete() const;
    void setBaseLineComplete(const QDateTime &baseLineComplete);

    QDateTime getPlannedComplete() const;
    void setPlannedComplete(const QDateTime &plannedComplete);

    QDateTime getProjectedComplete() const;
    void setProjectedComplete(const QDateTime &projectedComplete);

    QDateTime getActualComplete() const;
    void setActualComplete(const QDateTime &actualComplete);

    QString getActualStartDataQuality() const;
    void setActualStartDataQuality(const QString &actualStartDataQuality);

    QString getActualDistanceDataQuality() const;
    void setActualDistanceDataQuality(const QString &actualDistanceDataQuality);

    QString getActualDepartDataQuality() const;
    void setActualDepartDataQuality(const QString &actualDepartureDataQuality);

    double getbaseLineCost() const;
    void setbaseLineCost(double baseLineCost);

    double getPlannedCost() const;
    void setPlannedCost(double plannedCost);

    double getActualCost() const;
    void setActualCost(double actualCost);

    QDateTime getBaseLineStart() const;
    void setBaseLineStart(const QDateTime &baseLineStart);

    QDateTime getPlannedStart() const;
    void setPlannedStart(const QDateTime &plannedStart);

    QDateTime getProjectedStart() const;
    void setProjectedStart(const QDateTime &projectedStart);

    QDateTime getActualStart() const;
    void setActualStart(const QDateTime &actualStart);

    bool getHasHelper() const;
    void setHasHelper(bool hasHelper);

    QString getDriversName() const;
    void setDriversName(const QString &driversName);

    int getTotalStops() const;
    void setTotalStops(int totalStops);

    int getCanceledStops() const;
    void setCanceledStops(int canceledStops);

    int getUndeliveredStops() const;
    void setUndeliveredStops(int undeliveredStops);

    int getRedeliveredStops() const;
    void setRedeliveredStops(int redeliveredStops);

    int getActualDepartures() const;
    void setActualDepartures(int actualDepartures);

    QString getStatus() const;
    void setStatus(const QString &status);

    int getActualTravelTimeMinutes() const;
    void setACtualTravelTimeMinutes(int actualTravelTimeMinutes);

    int getPlannedTravelTimeMinutes() const;
    void setPlannedTravelTimeMinutes(int plannedTravelTimeMinutes);

    int getbaselineTravelTimeMinutes() const;
    void setbaselineTravelTimeMinutes(int baselineTravelTimeMinutes);

    bool getHasPicture() const;
    void setHasPicture(bool hasPicture);

    GMOrganization getOrganization() const;
    void setOrganization(const GMOrganization &organization);

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
    GMOrganization objGMOrganizationInit  = GMOrganization();

    QStringList memberList;

    QMap<QString, int>              objInt;
    QMap<QString, double>           objDouble;
    QMap<QString, bool>             objBool;
    QMap<QString, QString>          objQString;
    QMap<QString, QDate>            objQDate;
    QMap<QString, QDateTime>        objQDateTime;
    QMap<QString, GMOrganization>   objGMOrganization;
    //Meta member to track which members are imported
    QMap<QString, bool>             importedMember;

    //This is needed so that I can turn objects into strings.
    QJsonDocument                   catalyst;
};

#endif // GMROUTE_H
