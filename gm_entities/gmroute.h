#ifndef GMROUTE_H
#define GMROUTE_H

#include <QtCore>

class GMRoute
{
public:
    GMRoute();

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

    QDateTime getbaseLineComplete() const;
    void setbaseLineComplete(const QDateTime &baseLineComplete);

    QDateTime getPlannedComplete() const;
    void setPlannedComplete(const QDateTime &plannedComplete);

    QDateTime getProjectedComplete() const;
    void setProjectedComplete(const QDateTime &projectedComplete);

    QDateTime getActualComplete() const;
    void setActualComplete(const QDateTime &actualComplete);

    QString getActualStartDataQuality() const;
    void setActualStartDataQuality(const QString &actualStartDataQuality);

    QString getActualDistanceQuality() const;
    void setActualDistanceQuality(const QString &actualDistanceQuality);

    QString getActualDepartDataQuality() const;
    void setActualDepartDataQuality(const QString &actualDepartDataQuality);

    double getbaseLineCost() const;
    void setbaseLineCost(double baseLineCost);

    double getPlannedCost() const;
    void setPlannedCost(double plannedCost);

    double getActualCost() const;
    void setActualCost(double actualCost);

    QDateTime getbaseLineStart() const;
    void setbaseLineStart(const QDateTime &baseLineStart);

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

    void read(const QJsonObject &json);
    QJsonObject write();
    void setMembersToDefaults();
    void append(const QJsonObject &json);

private:
    QStringList memberList ;
    QMap<QString, bool> importedMember;

    int id;
    QString key;
    QDate date;
    //GM_Organization org
    QString description;
    //GM_Location orgin;
    //GM_Location destination;
    bool lastStopIsDestination;
    //GM_Stop stops;
    QDateTime plannedArrival;
    QDateTime baseLineArrival;
    QDateTime plannedDeparture;
    QDateTime baseLineDeparture;
    QDateTime projectedArrival;
    QDateTime projectedDeparture;
    QDateTime actualArrival;
    QDateTime actualDeparture;
    double baseLineDistance;
    double plannedDistance;
    double projectedDistance;
    double actualDistance;
    int delayTypeID;
    int delayMinutes;
    QDateTime lastContactTime;
    QDateTime baseLineComplete;
    QDateTime plannedComplete;
    QDateTime projectedComplete;
    QDateTime actualComplete;
    QString actualStartDataQuality;
    QString actualDistanceQuality;
    QString actualDepartDataQuality;
    double baseLineCost;
    double plannedCost;
    double actualCost;
    QDateTime baseLineStart;
    QDateTime plannedStart;
    QDateTime projectedStart;
    QDateTime actualStart;
    bool hasHelper;
    QString driversName;
    //GM_DriverAssignment driverAssignments;
    //GM_EquipmentAssignment equipmentAssignments;
    int totalStops;
    int canceledStops;
    int undeliveredStops;
    int redeliveredStops;
    int actualDepartures;
    QString status;
    int actualTravelTimeMinutes;
    int plannedTravelTimeMinutes;
    int baselineTravelTimeMinutes;
    bool hasPicture;
    //GM_RouteHelperAssignment routeHelperAssignments;

    void compareJson(const QJsonObject &json);
    void setImportedMembersFalse();
};

#endif // GMROUTE_H
