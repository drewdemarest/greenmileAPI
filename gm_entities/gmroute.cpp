#include "gm_entities/gmroute.h"

GMRoute::GMRoute()
{
    id                          = 0;
    key                         = QString();
    date                        = QDate::currentDate();
    //GOrganization org
    description                 = QString();
    //GLocation orgin;
    //GLocation destination;
    lastStopIsDestination       = false;
    //GStop stops;
    plannedArrival              = QDateTime::currentDateTime();
    baseLineArrival             = QDateTime::currentDateTime();
    plannedDeparture            = QDateTime::currentDateTime();
    baseLineDeparture           = QDateTime::currentDateTime();
    projectedArrival            = QDateTime::currentDateTime();
    projectedDeparture          = QDateTime::currentDateTime();
    actualArrival               = QDateTime::currentDateTime();
    actualDeparture             = QDateTime::currentDateTime();
    baseLineDistance            = 0;
    plannedDistance             = 0;
    projectedDistance           = 0;
    actualDistance              = 0;
    delayTypeID                 = 0;
    delayMinutes                = 0;
    lastContactTime             = QDateTime::currentDateTime();
    baseLineComplete            = QDateTime::currentDateTime();
    plannedComplete             = QDateTime::currentDateTime();
    projectedComplete           = QDateTime::currentDateTime();
    actualComplete              = QDateTime::currentDateTime();
    actualStartDataQuality      = QString();
    actualDistanceQuality       = QString();
    actualDepartDataQuality     = QString();
    baseLineCost                = 0;
    plannedCost                 = 0;
    actualCost                  = 0;
    baseLineStart               = QDateTime::currentDateTime();
    plannedStart                = QDateTime::currentDateTime();
    projectedStart              = QDateTime::currentDateTime();
    actualStart                 = QDateTime::currentDateTime();
    hasHelper                   = false;
    driversName                 = QString();
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    totalStops                  = 0;
    canceledStops               = 0;
    undeliveredStops            = 0;
    redeliveredStops            = 0;
    actualDepartures            = 0;
    status                      = QString();
    actualTravelTimeMinutes     = 0;
    plannedTravelTimeMinutes    = 0;
    baselineTravelTimeMinutes   = 0;
    hasPicture                  = false;
    //GRouteHelperAssignment routeHelperAssignments;

    memberList  << "id"                         << "key"
                << "date"                       << "organization"
                << "description"                << "origin"
                << "destination"                << "lastStopIsDestination"
                << "stops"                      << "plannedArrival"
                << "plannedDeparture"           << "baseLineDeparture"
                << "projectedArrival"           << "projectedDeparture"
                << "actualArrival"              << "actualDeparture"
                << "baseLineDistance"           << "plannedDistance"
                << "projectedDistance"          << "actualDistance"
                << "delayTypeID"                << "delayMinutes"
                << "lastContactTime"            << "baseLineComplete"
                << "plannedComplete"            << "projectedComplete"
                << "actualComplete"             << "actualStartDataQuality"
                << "actualDistanceQuality"      << "actualDepartDataQuality"
                << "baseLineCost"               << "plannedCost"
                << "actualCost"                 << "baseLineStart"
                << "plannedStart"               << "projectedStart"
                << "hasHelper"                  << "driversName"
                << "driverAssignments"          << "equipmentAssignments"
                << "totalStops"                 << "canceledStops"
                << "underliveredStops"          << "redeliveredStops"
                << "actualDepartures"           << "status"
                << "actualTravelTimeMinutes"    << "plannedTravelTimeMinutes"
                << "baselineTravelTimeMinutes"  << "hasPicture"
                << "routeHelperAssignments"     << "baseLineArrival"
                << "actualStart"                << "actualTravelTimeMinutes";

    setImportedMembersFalse();
}

int GMRoute::getId() const
{
    return id;
}

void GMRoute::setId(int id)
{
    this->id = id;
}

QString GMRoute::getKey() const
{
    return key;
}

void GMRoute::setKey(const QString &key)
{
    this->key = key;
}

QString GMRoute::getDescription() const
{
    return description;
}

void GMRoute::setDescription(const QString &description)
{
    this->description = description;
}

QDate GMRoute::getDate() const
{
    return date;
}

void GMRoute::setDate(const QDate &date)
{
    this->date = date;
}

bool GMRoute::getLastStopIsDestination() const
{
    return lastStopIsDestination;
}

void GMRoute::setLastStopIsDestination(bool lastStopIsDestination)
{
    this->lastStopIsDestination = lastStopIsDestination;
}


QDateTime GMRoute::getPlannedArrival() const
{
    return plannedArrival;
}

void GMRoute::setPlannedArrival(const QDateTime &plannedArrival)
{
    this->plannedArrival = plannedArrival;
}

QDateTime GMRoute::getBaseLineArrival() const
{
    return baseLineArrival;
}

void GMRoute::setBaseLineArrival(const QDateTime &baseLineArrival)
{
    this->baseLineArrival = baseLineArrival;
}

QDateTime GMRoute::getPlannedDeparture() const
{
    return plannedDeparture;
}

void GMRoute::setPlannedDeparture(const QDateTime &plannedDeparture)
{
    this->plannedDeparture = plannedDeparture;
}

QDateTime GMRoute::getBaseLineDeparture() const
{
    return baseLineDeparture;
}

void GMRoute::setBaseLineDeparture(const QDateTime &baseLineDeparture)
{
    this->baseLineDeparture = baseLineDeparture;
}

QDateTime GMRoute::getProjectedArrival() const
{
    return projectedArrival;
}

void GMRoute::setProjectedArrival(const QDateTime &projectedArrival)
{
    this->projectedArrival = projectedArrival;
}

QDateTime GMRoute::getProjectedDeparture() const
{
    return projectedDeparture;
}

void GMRoute::setProjectedDeparture(const QDateTime &projectedDeparture)
{
    this->projectedDeparture = projectedDeparture;
}

QDateTime GMRoute::getActualArrival() const
{
    return actualArrival;
}

void GMRoute::setActualArrival(const QDateTime &actualArrival)
{
    this->actualArrival = actualArrival;
}

QDateTime GMRoute::getActualDeparture() const
{
    return actualDeparture;
}

void GMRoute::setActualDeparture(const QDateTime &actualDeparture)
{
    this->actualDeparture = actualDeparture;
}

double GMRoute::getbaseLineDistance() const
{
    return baseLineDistance;
}

void GMRoute::setbaseLineDistance(double baseLineDistance)
{
    this->baseLineDistance = baseLineDistance;
}

double GMRoute::getPlannedDistance() const
{
    return plannedDistance;
}

void GMRoute::setPlannedDistance(double plannedDistance)
{
    this->plannedDistance = plannedDistance;
}

double GMRoute::getProjectedDistance() const
{
    return projectedDistance;
}

void GMRoute::setProjectedDistance(double projectedDistance)
{
    this->projectedDistance = projectedDistance;
}

double GMRoute::getActualDistance() const
{
    return actualDistance;
}

void GMRoute::setActualDistance(double actualDistance)
{
    this->actualDistance = actualDistance;
}

int GMRoute::getDelayTypeID() const
{
    return delayTypeID;
}

void GMRoute::setDelayTypeID(int delayTypeID)
{
    this->delayTypeID = delayTypeID;
}

int GMRoute::getDelayMinutes() const
{
    return delayMinutes;
}

void GMRoute::setDelayMinutes(int delayMinutes)
{
    this->delayMinutes = delayMinutes;
}

QDateTime GMRoute::getLastContactTime() const
{
    return lastContactTime;
}

void GMRoute::setLastContactTime(const QDateTime &lastContactTime)
{
    this->lastContactTime = lastContactTime;
}

QDateTime GMRoute::getbaseLineComplete() const
{
    return baseLineComplete;
}

void GMRoute::setbaseLineComplete(const QDateTime &baseLineComplete)
{
    this->baseLineComplete = baseLineComplete;
}

QDateTime GMRoute::getPlannedComplete() const
{
    return plannedComplete;
}

void GMRoute::setPlannedComplete(const QDateTime &plannedComplete)
{
    this->plannedComplete = plannedComplete;
}

QDateTime GMRoute::getProjectedComplete() const
{
    return projectedComplete;
}

void GMRoute::setProjectedComplete(const QDateTime &projectedComplete)
{
    this->projectedComplete = projectedComplete;
}

QDateTime GMRoute::getActualComplete() const
{
    return actualComplete;
}

void GMRoute::setActualComplete(const QDateTime &actualComplete)
{
    this->actualComplete = actualComplete;
}

QString GMRoute::getActualStartDataQuality() const
{
    return actualStartDataQuality;
}

void GMRoute::setActualStartDataQuality(const QString &actualStartDataQuality)
{
    this->actualStartDataQuality = actualStartDataQuality;
}

QString GMRoute::getActualDistanceQuality() const
{
    return actualDistanceQuality;
}

void GMRoute::setActualDistanceQuality(const QString &actualDistanceQuality)
{
    this->actualDistanceQuality = actualDistanceQuality;
}

QString GMRoute::getActualDepartDataQuality() const
{
    return actualDepartDataQuality;
}

void GMRoute::setActualDepartDataQuality(const QString &actualDepartDataQuality)
{
    this->actualDepartDataQuality = actualDepartDataQuality;
}

double GMRoute::getbaseLineCost() const
{
    return baseLineCost;
}

void GMRoute::setbaseLineCost(double baseLineCost)
{
    this->baseLineCost = baseLineCost;
}

double GMRoute::getPlannedCost() const
{
    return plannedCost;
}

void GMRoute::setPlannedCost(double plannedCost)
{
    this->plannedCost = plannedCost;
}

double GMRoute::getActualCost() const
{
    return actualCost;
}

void GMRoute::setActualCost(double actualCost)
{
    this->actualCost = actualCost;
}

QDateTime GMRoute::getbaseLineStart() const
{
    return baseLineStart;
}

void GMRoute::setbaseLineStart(const QDateTime &baseLineStart)
{
    this->baseLineStart = baseLineStart;
}

QDateTime GMRoute::getPlannedStart() const
{
    return plannedStart;
}

void GMRoute::setPlannedStart(const QDateTime &plannedStart)
{
    this->plannedStart = plannedStart;
}

QDateTime GMRoute::getProjectedStart() const
{
    return projectedStart;
}

void GMRoute::setProjectedStart(const QDateTime &projectedStart)
{
    this->projectedStart = projectedStart;
}

QDateTime GMRoute::getActualStart() const
{
    return actualStart;
}

void GMRoute::setActualStart(const QDateTime &actualStart)
{
    this->actualStart = actualStart;
}

bool GMRoute::getHasHelper() const
{
    return hasHelper;
}

void GMRoute::setHasHelper(bool hasHelper)
{
    this->hasHelper = hasHelper;
}

QString GMRoute::getDriversName() const
{
    return driversName;
}

void GMRoute::setDriversName(const QString &driversName)
{
    this->driversName = driversName;
}

int GMRoute::getTotalStops() const
{
    return totalStops;
}

void GMRoute::setTotalStops(int totalStops)
{
    this->totalStops = totalStops;
}

int GMRoute::getCanceledStops() const
{
    return canceledStops;
}

void GMRoute::setCanceledStops(int canceledStops)
{
    this->canceledStops = canceledStops;
}

int GMRoute::getUndeliveredStops() const
{
    return undeliveredStops;
}

void GMRoute::setUndeliveredStops(int undeliveredStops)
{
    this->undeliveredStops = undeliveredStops;
}

int GMRoute::getRedeliveredStops() const
{
    return redeliveredStops;
}

void GMRoute::setRedeliveredStops(int redeliveredStops)
{
    this->redeliveredStops = redeliveredStops;
}

int GMRoute::getActualDepartures() const
{
    return actualDepartures;
}

void GMRoute::setActualDepartures(int actualDepartures)
{
    this->actualDepartures = actualDepartures;
}

QString GMRoute::getStatus() const
{
    return status;
}

void GMRoute::setStatus(const QString &status)
{
    this->status = status;
}


int GMRoute::getPlannedTravelTimeMinutes() const
{
    return plannedTravelTimeMinutes;
}

void GMRoute::setPlannedTravelTimeMinutes(int plannedTravelTimeMinutes)
{
    this->plannedTravelTimeMinutes = plannedTravelTimeMinutes;
}

int GMRoute::getbaselineTravelTimeMinutes() const
{
    return baselineTravelTimeMinutes;
}

void GMRoute::setbaselineTravelTimeMinutes(int baselineTravelTimeMinutes)
{
    this->baselineTravelTimeMinutes = baselineTravelTimeMinutes;
}

bool GMRoute::getHasPicture() const
{
    return hasPicture;
}

void GMRoute::setHasPicture(bool hasPicture)
{
    this->hasPicture = hasPicture;
}

void GMRoute::read(const QJsonObject &json)
{
    compareJson(json);

    id                          = json["id"].toInt();
    key                         = json["key"].toString();
    date                        = QDate::fromString(json["date"].toString(), "yyyy-MM-dd");
    //GM_Organization organization
    description                 = json["description"].toString();
    //GM_Location origin;
    //GM_Location destination;
    lastStopIsDestination       = json["lastStopIsDestination"].toBool();
    //GM_Stop stops;
    plannedArrival              = QDateTime::fromString(json["plannedArrival"].toString(),      Qt::ISODateWithMs);
    plannedDeparture            = QDateTime::fromString(json["plannedDeparture"].toString(),    Qt::ISODateWithMs);
    baseLineDeparture           = QDateTime::fromString(json["baseLineDeparture"].toString(),   Qt::ISODateWithMs);
    projectedArrival            = QDateTime::fromString(json["projectedArrival"].toString(),    Qt::ISODateWithMs);
    projectedDeparture          = QDateTime::fromString(json["projectedDeparture"].toString(),  Qt::ISODateWithMs);
    actualArrival               = QDateTime::fromString(json["actualArrival"].toString(),       Qt::ISODateWithMs);
    actualDeparture             = QDateTime::fromString(json["actualDeparture"].toString(),     Qt::ISODateWithMs);
    baseLineDistance             = 0;
    plannedDistance             = 0;
    projectedDistance           = 0;
    actualDistance              = 0;
    delayTypeID                 = 0;
    delayMinutes                = 0;
    lastContactTime             = QDateTime::currentDateTime();
    baseLineComplete            = QDateTime::currentDateTime();
    plannedComplete             = QDateTime::currentDateTime();
    projectedComplete           = QDateTime::currentDateTime();
    actualComplete              = QDateTime::currentDateTime();
    actualStartDataQuality      = QString();
    actualDistanceQuality       = QString();
    actualDepartDataQuality     = QString();
    baseLineCost                = 0;
    plannedCost                 = 0;
    actualCost                  = 0;
    baseLineStart               = QDateTime::currentDateTime();
    plannedStart                = QDateTime::currentDateTime();
    projectedStart              = QDateTime::currentDateTime();
    hasHelper                   = false;
    driversName                 = QString();
    //GM_DriverAssignment driverAssignments;
    //GM_EquipmentAssignment equipmentAssignments;
    totalStops                  = 0;
    canceledStops               = 0;
    undeliveredStops            = 0;
    redeliveredStops            = 0;
    actualDepartures            = 0;
    status                      = QString();
    actualTravelTimeMinutes     = 0;
    plannedTravelTimeMinutes    = 0;
    baselineTravelTimeMinutes   = 0;
    hasPicture  = true;
    //GM_RouteHelperAssignment routeHelperAssignments;
}

QJsonObject GMRoute::write()
{
    QJsonObject jTest;
    QJsonDocument jDoc;

    QString query = "{\n        \"actualArrival\": \"2017-06-20T17:19:04+0000\",\n        \"actualComplete\": \"2017-06-20T17:23:11+0000\",\n        \"actualCompleteDataQuality\": \"GEO_COMPUTED\",\n        \"actualCost\": 706.4167598027519,\n        \"actualDeparture\": \"2017-06-20T07:55:07+0000\",\n        \"actualDepartureDataQuality\": \"GEO_COMPUTED\",\n        \"actualDepartures\": 11,\n        \"actualDistance\": 214000,\n        \"actualDistanceDataQuality\": \"GEO_COMPUTED\",\n        \"actualDistanceRecalculatedAt\": \"2017-06-20T17:29:47+0000\",\n        \"actualServiceTime\": 34084000,\n        \"actualSize1\": 748,\n        \"actualSize2\": 642,\n        \"actualSize3\": 13339,\n        \"actualStart\": \"2017-06-20T07:55:07+0000\",\n        \"actualStartDataQuality\": \"GEO_COMPUTED\",\n        \"actualTravelTimeMinutes\": 182,\n        \"baseLineArrival\": \"2017-06-20T16:33:53+0000\",\n        \"baseLineComplete\": \"2017-06-20T19:00:00+0000\",\n        \"baseLineCost\": 0,\n        \"baseLineDeparture\": \"2017-06-20T08:30:00+0000\",\n        \"baseLineDistance\": 206724.07664223306,\n        \"baseLineStart\": \"2017-06-20T08:30:00+0000\",\n        \"baselineServiceTime\": 37800000,\n        \"baselineTravelTimeMinutes\": 171,\n        \"canceledStops\": 0,\n        \"creationDate\": \"2017-06-20T05:35:05+0000\",\n        \"date\": \"2017-06-19\",\n        \"description\": \"G-GIG\",\n        \"destLatitude\": 47.566536,\n        \"destLongitude\": -122.33265,\n        \"hasGps\": true,\n        \"hasHelper\": false,\n        \"id\": 72286,\n        \"key\": \"G-GIG\",\n        \"lastModificationDate\": \"2017-06-20T17:28:29+0000\",\n        \"lastStopIsDestination\": false,\n        \"lastUpdatedProjectedTime\": \"2017-06-20T17:28:29+0000\",\n        \"origLatitude\": 47.566536,\n        \"origLongitude\": -122.33265,\n        \"plannedArrival\": \"2017-06-20T16:33:53+0000\",\n        \"plannedComplete\": \"2017-06-20T19:00:00+0000\",\n        \"plannedCost\": 742.0526321897355,\n        \"plannedDeparture\": \"2017-06-20T08:30:00+0000\",\n        \"plannedDistance\": 206724.07664223306,\n        \"plannedServiceTime\": 37800000,\n        \"plannedSize1\": 748,\n        \"plannedSize2\": 642,\n        \"plannedSize3\": 13339,\n        \"plannedStart\": \"2017-06-20T08:30:00+0000\",\n        \"plannedTravelTimeMinutes\": 171,\n        \"projectedArrival\": \"2017-06-20T17:27:47+0000\",\n        \"projectedComplete\": \"2017-06-20T19:53:54+0000\",\n        \"projectedDeparture\": \"2017-06-20T08:30:00+0000\",\n        \"projectedDistance\": 135147.50474147976,\n        \"projectedStart\": \"2017-06-20T08:30:00+0000\",\n        \"redeliveredStops\": 0,\n        \"status\": \"COMPLETED\",\n        \"totalStops\": 11,\n        \"undeliveredStops\": 0\n    }";
    jTest = jDoc.fromJson(query.toUtf8()).object();
    read(jTest);

    QJsonObject jTemp;

    jTemp["id"]                             = id;
    jTemp["key"]                            = key;
    jTemp["date"]                           = date.toString("yyyy-MM-dd");
    //jTemp["organization"] = ...organization;
    //jTemp["origin"]                       = ...origin;
    //jTemp["destination"]                  = ...destination;
    jTemp["lastStopIsDestination"]          = lastStopIsDestination;
    jTemp["description"]                    = description;
    //jTemp["stops"]                        = ...stops (array)
    jTemp["plannedArrival"]                 = plannedArrival.toString(Qt::ISODateWithMs);
    jTemp["baseLineArrival"]                = baseLineArrival.toString(Qt::ISODateWithMs);
    jTemp["plannedDeparture"]               = plannedDeparture.toString(Qt::ISODateWithMs);
    jTemp["baseLineDeparture"]              = baseLineDeparture.toString(Qt::ISODateWithMs);
    jTemp["projectedArrival"]               = projectedArrival.toString(Qt::ISODateWithMs);
    jTemp["projectedDeparture"]             = projectedDeparture.toString(Qt::ISODateWithMs);
    jTemp["actualArrival"]                  = actualArrival.toString(Qt::ISODateWithMs);
    jTemp["actualDeparture"]                = actualDeparture.toString(Qt::ISODateWithMs);
    jTemp["baseLineDistance"]               = baseLineDistance;
    jTemp["plannedDistance"]                = plannedDistance;
    jTemp["projectedDistance"]              = projectedDistance;
    jTemp["actualDistance"]                 = actualDistance;
    jTemp["delayTypeID"]                    = delayTypeID;
    jTemp["delayMinutes"]                   = delayMinutes;
    jTemp["lastContactTime"]                = lastContactTime.toString(Qt::ISODateWithMs);
    jTemp["baseLineComplete"]               = baseLineComplete.toString(Qt::ISODateWithMs);
    jTemp["plannedComplete"]                = plannedComplete.toString(Qt::ISODateWithMs);
    jTemp["projectedComplete"]              = projectedComplete.toString(Qt::ISODateWithMs);
    jTemp["actualComplete"]                 = actualComplete.toString(Qt::ISODateWithMs);
    jTemp["actualStartDataQuality"]         = actualStartDataQuality;
    jTemp["actualDistanceQuality"]          = actualDistanceQuality;
    jTemp["actualDepartDataQuality"]        = actualDepartDataQuality;
    jTemp["baseLineCost"]                   = baseLineCost;
    jTemp["plannedCost"]                    = plannedCost;
    jTemp["actualCost"]                     = actualCost;
    jTemp["baseLineStart"]                  = baseLineStart.toString(Qt::ISODateWithMs);
    jTemp["plannedStart"]                   = plannedStart.toString(Qt::ISODateWithMs);
    jTemp["projectedStart"]                 = projectedStart.toString(Qt::ISODateWithMs);
    jTemp["actualStart"]                    = actualStart.toString(Qt::ISODateWithMs);
    jTemp["hasHelper"]                      = hasHelper;
    jTemp["driversName"]                    = driversName;
    //jTemp["driverAssignments"]            = driverAssignments;
    //jTemp["equipmentAssignments"]         = equipmentAssignments;
    jTemp["totalStops"]                     = totalStops;
    jTemp["canceledStops"]                  = canceledStops;
    jTemp["undeliveredStops"]               = undeliveredStops;
    jTemp["redeliveredStops"]               = redeliveredStops;
    jTemp["actualDepartures"]               = actualDepartures;
    jTemp["status"]                         = status;
    jTemp["actualTravelTimeMinutes"]        = actualTravelTimeMinutes;
    jTemp["plannedTravelTimeMinutes"]       = plannedTravelTimeMinutes;
    jTemp["baselineTravelTimeMinutes"]      = baselineTravelTimeMinutes;
    jTemp["hasPicture"]                     = hasPicture;
    //jTemp["helperAssignments"]            = helperAssignments

    QDateTime test = QDateTime::fromString(jTemp["dateTime"].toString(), Qt::ISODateWithMs);
    test.setTimeSpec(Qt::UTC);

    qDebug() << "TEST DATETIME test WRITE" << test.toLocalTime().toString();
    qDebug() << "TEST DATETIME WRITE" << QDateTime::fromString(jTemp["dateTime"].toString(), Qt::ISODateWithMs).toString();
    qDebug() << "TEST DATE WRITE " << date.toString();

    return jTemp;
}


void GMRoute::compareJson(const QJsonObject &json)
{
    setImportedMembersFalse();

    for(auto key : json.keys())
    {
        if(importedMember.contains(key))
            importedMember[key] = true;
    }

    qDebug() << importedMember;
}

void GMRoute::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

void GMRoute::setMembersToDefaults()
{
    id                          = 0;
    key                         = QString();
    date                        = QDate::currentDate();
    //GM_Organization organization;
    description                 = QString();
    //GM_Location orgin;;
    //GM_Location destination;
    lastStopIsDestination       = false;
    //GM_Stop stops;
    plannedArrival              = QDateTime::currentDateTime();
    baseLineArrival             = QDateTime::currentDateTime();
    plannedDeparture            = QDateTime::currentDateTime();
    baseLineDeparture           = QDateTime::currentDateTime();
    projectedArrival            = QDateTime::currentDateTime();
    projectedDeparture          = QDateTime::currentDateTime();
    actualArrival               = QDateTime::currentDateTime();
    actualDeparture             = QDateTime::currentDateTime();
    baseLineDistance            = 0;
    plannedDistance             = 0;
    projectedDistance           = 0;
    actualDistance              = 0;
    delayTypeID                 = 0;
    delayMinutes                = 0;
    lastContactTime             = QDateTime::currentDateTime();
    baseLineComplete            = QDateTime::currentDateTime();
    plannedComplete             = QDateTime::currentDateTime();
    projectedComplete           = QDateTime::currentDateTime();
    actualComplete              = QDateTime::currentDateTime();
    actualStartDataQuality      = QString();
    actualDistanceQuality       = QString();
    actualDepartDataQuality     = QString();
    baseLineCost                = 0;
    plannedCost                 = 0;
    actualCost                  = 0;
    baseLineStart               = QDateTime::currentDateTime();
    plannedStart                = QDateTime::currentDateTime();
    projectedStart              = QDateTime::currentDateTime();
    actualStart                 = QDateTime::currentDateTime();
    hasHelper                   = false;
    driversName                 = QString();
    //GM_DriverAssignment driverAssignments;
    //GM_EquipmentAssignment equipmentAssignments;
    totalStops                  = 0;
    canceledStops               = 0;
    undeliveredStops            = 0;
    redeliveredStops            = 0;
    actualDepartures            = 0;
    status                      = QString();
    actualTravelTimeMinutes     = 0;
    plannedTravelTimeMinutes    = 0;
    baselineTravelTimeMinutes   = 0;
    hasPicture                  = false;
    //GM_RouteHelperAssignment routeHelperAssignments;
    setImportedMembersFalse();
}

void GMRoute::append(const QJsonObject &json)
{

}
