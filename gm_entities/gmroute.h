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

    double getBaslineDistance() const;
    void setBaslineDistance(double baslineDistance);

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

    QDateTime getBaselineComplete() const;
    void setBaselineComplete(const QDateTime &baselineComplete);

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

    double getBaselineCost() const;
    void setBaselineCost(double baselineCost);

    double getPlannedCost() const;
    void setPlannedCost(double plannedCost);

    double getActualCost() const;
    void setActualCost(double actualCost);

    QDateTime getBaselineStart() const;
    void setBaselineStart(const QDateTime &baselineStart);

    QDateTime getPlannedStart() const;
    void setPlannedStart(const QDateTime &plannedStart);

    QDateTime getProjectedStart() const;
    void setProjectedStart(const QDateTime &projectedStart);

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

    int getTravelTimeMinutes() const;
    void setTravelTimeMinutes(int travelTimeMinutes);

    int getPlannedTravelTimeMinites() const;
    void setPlannedTravelTimeMinites(int plannedTravelTimeMinites);

    int getBaselineTravelTimeMinutes() const;
    void setBaselineTravelTimeMinutes(int baselineTravelTimeMinutes);

    bool getHasPicture() const;
    void setHasPicture(bool hasPicture);

    void read(const QJsonObject &json);
    QJsonObject write();
    void setMembersToDefaults();

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
    QDateTime plannedDeparture;
    QDateTime baselineDeparture;
    QDateTime projectedArrival;
    QDateTime projectedDeparture;
    QDateTime actualArrival;
    QDateTime actualDeparture;
    double baslineDistance;
    double plannedDistance;
    double projectedDistance;
    double actualDistance;
    int delayTypeID;
    int delayMinutes;
    QDateTime lastContactTime;
    QDateTime baselineComplete;
    QDateTime plannedComplete;
    QDateTime projectedComplete;
    QDateTime actualComplete;
    QString actualStartDataQuality;
    QString actualDistanceQuality;
    QString actualDepartDataQuality;
    double baselineCost;
    double plannedCost;
    double actualCost;
    QDateTime baselineStart;
    QDateTime plannedStart;
    QDateTime projectedStart;
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
    int travelTimeMinutes;
    int plannedTravelTimeMinutes;
    int baselineTravelTimeMinutes;
    bool hasPicture;
    //GM_RouteHelperAssignment routeHelperAssignments;

    void compareJson(const QJsonObject &json);
    void setImportedMembersFalse();
};

#endif // GMROUTE_H
