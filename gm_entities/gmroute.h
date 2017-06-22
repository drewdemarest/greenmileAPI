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

    void setMembersToDefaults();

    void read(const QJsonObject &json);
    void append(const QJsonObject &json);

    QJsonObject write();



private:
    bool routeBoolInit                      = false;
    int routeIntInit                        = 0;
    double routeDoubleInit                  = 0;
    QString routeQStringInit                = QString();
    QDate routeQDateInit                    = QDate::currentDate();
    QDateTime routeQDateTimeInit            = QDateTime::currentDateTime();

    QStringList memberList;

    QMap<QString, int> routeInt;
    QMap<QString, double> routeDouble;
    QMap<QString, bool> routeBool;
    QMap<QString, QString> routeQString;
    QMap<QString, QDate> routeQDate;
    QMap<QString, QDateTime> routeQDateTime;

    QMap<QString, bool> importedMember;

    //GM_Organization org
    //GM_Location orgin;
    //GM_Location destination;
    //GM_Stop stops;
    //GM_DriverAssignment driverAssignments;
    //GM_EquipmentAssignment equipmentAssignments;
    //GM_RouteHelperAssignment routeHelperAssignments;

    void compareJson(const QJsonObject &json);
    void setImportedMembersFalse();
};

#endif // GMROUTE_H
