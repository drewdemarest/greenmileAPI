#include "gm_entities/gmroute.h"

GMRoute::GMRoute()
{
    routeInt["id"]                          = routeIntInit;
    routeInt["delayTypeID"]                 = routeIntInit;
    routeInt["delayMinutes"]                = routeIntInit;
    routeInt["totalStops"]                  = routeIntInit;
    routeInt["canceledStops"]               = routeIntInit;
    routeInt["undeliveredStops"]            = routeIntInit;
    routeInt["redeliveredStops"]            = routeIntInit;
    routeInt["actualDeparture"]             = routeIntInit;
    routeInt["actualTravelTimeMinutes"]     = routeIntInit;
    routeInt["plannedTravelTimeMinutes"]    = routeIntInit;
    routeInt["baselineTravelTimeMinutes"]   = routeIntInit;

    routeDouble["baseLineDistance"]         = routeDoubleInit;
    routeDouble["plannedDistance"]          = routeDoubleInit;
    routeDouble["projectedDistance"]        = routeDoubleInit;
    routeDouble["actualDistance"]           = routeDoubleInit;
    routeDouble["baseLineCost"]             = routeDoubleInit;
    routeDouble["plannedCost"]              = routeDoubleInit;
    routeDouble["actualCost"]               = routeDoubleInit;

    routeQString["key"]                     = routeQStringInit;
    routeQString["description"]             = routeQStringInit;
    routeQString["actualStartDataQuality"]  = routeQStringInit;
    routeQString["actualDistanceDataQuality"]   = routeQStringInit;
    routeQString["actualDepartureDataQuality"] = routeQStringInit;
    routeQString["driversName"]             = routeQStringInit;
    routeQString["status"]                  = routeQStringInit;

    routeQDate["date"]                      = routeQDateInit;

    routeBool["lastStopIsDestination"]      = routeBoolInit;
    routeBool["hasHelper"]                  = routeBoolInit;
    routeBool["hasPicture"]                 = routeBoolInit;

    routeQDateTime["plannedArrival"]        = routeQDateTimeInit;
    routeQDateTime["baseLineArrival"]       = routeQDateTimeInit;
    routeQDateTime["plannedDeparture"]      = routeQDateTimeInit;
    routeQDateTime["baseLineDeparture"]     = routeQDateTimeInit;
    routeQDateTime["projectedArrival"]      = routeQDateTimeInit;
    routeQDateTime["projectedDeparture"]    = routeQDateTimeInit;
    routeQDateTime["actualArrival"]         = routeQDateTimeInit;
    routeQDateTime["actualDepartures"]       = routeQDateTimeInit;
    routeQDateTime["lastContactTime"]       = routeQDateTimeInit;
    routeQDateTime["baseLineComplete"]      = routeQDateTimeInit;
    routeQDateTime["plannedComplete"]       = routeQDateTimeInit;
    routeQDateTime["projectedComplete"]     = routeQDateTimeInit;
    routeQDateTime["actualComplete"]        = routeQDateTimeInit;
    routeQDateTime["baseLineStart"]         = routeQDateTimeInit;
    routeQDateTime["plannedStart"]          = routeQDateTimeInit;
    routeQDateTime["projectedStart"]        = routeQDateTimeInit;
    routeQDateTime["actualStart"]           = routeQDateTimeInit;

    //GOrganization org
    //GLocation orgin;
    //GLocation destination;
    //GStop stops;
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    //GRouteHelperAssignment routeHelperAssignments;

    memberList << routeInt.keys()       << routeDouble.keys()
               << routeQString.keys()   << routeQDate.keys()
               << routeBool.keys()      << routeQDateTime.keys()
               << routeQDateTime.keys();

    qDebug() << memberList.size() << "memberList";
}

int GMRoute::getId() const
{
    return routeInt["id"];
}

void GMRoute::setId(int id)
{
    routeInt["id"] = id;
}

QString GMRoute::getKey() const
{
    return routeQString["key"];
}

void GMRoute::setKey(const QString &key)
{
    routeQString["key"] = key;
}

QString GMRoute::getDescription() const
{
    return routeQString["description"];
}

void GMRoute::setDescription(const QString &description)
{
    routeQString["description"] = description;
}

QDate GMRoute::getDate() const
{
    return routeQDate["date"];
}

void GMRoute::setDate(const QDate &date)
{
    routeQDate["date"] = date;
}

bool GMRoute::getLastStopIsDestination() const
{
    return routeBool["lastStopIsDestination"];
}

void GMRoute::setLastStopIsDestination(bool lastStopIsDestination)
{
    routeBool["lastStopIsDestination"] = lastStopIsDestination;
}

QDateTime GMRoute::getPlannedArrival() const
{
    return routeQDateTime["plannedArrival"];
}

void GMRoute::setPlannedArrival(const QDateTime &plannedArrival)
{
    routeQDateTime["plannedArrival"] = plannedArrival;
}

QDateTime GMRoute::getBaseLineArrival() const
{
    return routeQDateTime["baseLineArrival"];
}

void GMRoute::setBaseLineArrival(const QDateTime &baseLineArrival)
{
    routeQDateTime["baseLineArrival"] = baseLineArrival;
}

QDateTime GMRoute::getPlannedDeparture() const
{
    return routeQDateTime["plannedDeparture"];
}

void GMRoute::setPlannedDeparture(const QDateTime &plannedDeparture)
{
    routeQDateTime["plannedDeparture"] = plannedDeparture;
}

QDateTime GMRoute::getBaseLineDeparture() const
{
    return routeQDateTime["baseLineDeparture"];
}

void GMRoute::setBaseLineDeparture(const QDateTime &baseLineDeparture)
{
    routeQDateTime["baseLineDeparture"] = baseLineDeparture;
}

QDateTime GMRoute::getProjectedArrival() const
{
    return routeQDateTime["projectedArrival"];
}

void GMRoute::setProjectedArrival(const QDateTime &projectedArrival)
{
    routeQDateTime["projectedArrival"] = projectedArrival;
}

QDateTime GMRoute::getProjectedDeparture() const
{
    return routeQDateTime["projectedDeparture"];
}

void GMRoute::setProjectedDeparture(const QDateTime &projectedDeparture)
{
    routeQDateTime["projectedDeparture"] = projectedDeparture;
}

QDateTime GMRoute::getActualArrival() const
{
    return routeQDateTime["actualArrival"];
}

void GMRoute::setActualArrival(const QDateTime &actualArrival)
{
    routeQDateTime["actualArrival"] = actualArrival;
}

QDateTime GMRoute::getActualDeparture() const
{
    return routeQDateTime["actualDeparture"];
}

void GMRoute::setActualDeparture(const QDateTime &actualDeparture)
{
    routeQDateTime["actualDeparture"] = actualDeparture;
}

double GMRoute::getbaseLineDistance() const
{
    return routeDouble["baseLineDistance"];
}

void GMRoute::setbaseLineDistance(double baseLineDistance)
{
    routeDouble["baseLineDistance"] = baseLineDistance;
}

double GMRoute::getPlannedDistance() const
{
    return routeDouble["plannedDistance"];
}

void GMRoute::setPlannedDistance(double plannedDistance)
{
    routeDouble["plannedDistance"] = plannedDistance;
}

double GMRoute::getProjectedDistance() const
{
    return routeDouble["projectedDistance"];
}

void GMRoute::setProjectedDistance(double projectedDistance)
{
    routeDouble["projectedDistance"] = projectedDistance;
}

double GMRoute::getActualDistance() const
{
    return routeDouble["actualDistance"];
}

void GMRoute::setActualDistance(double actualDistance)
{
    routeDouble["actualDistance"] = actualDistance;
}

int GMRoute::getDelayTypeID() const
{
    return routeInt["delayTypeID"];
}

void GMRoute::setDelayTypeID(int delayTypeID)
{
    routeInt["delayTypeID"] = delayTypeID;
}

int GMRoute::getDelayMinutes() const
{
    return routeInt["delayMinutes"];
}

void GMRoute::setDelayMinutes(int delayMinutes)
{
    routeInt["delayMinutes"] = delayMinutes;
}

QDateTime GMRoute::getLastContactTime() const
{
    return routeQDateTime["lastContactTime"];
}

void GMRoute::setLastContactTime(const QDateTime &lastContactTime)
{
    routeQDateTime["lastContactTime"] = lastContactTime;
}

QDateTime GMRoute::getBaseLineComplete() const
{
    return routeQDateTime["baseLineComplete"];
}

void GMRoute::setBaseLineComplete(const QDateTime &baseLineComplete)
{
    routeQDateTime["baseLineComplete"] = baseLineComplete;
}

QDateTime GMRoute::getPlannedComplete() const
{
    return routeQDateTime["plannedComplete"];
}

void GMRoute::setPlannedComplete(const QDateTime &plannedComplete)
{
    routeQDateTime["plannedComplete"] = plannedComplete;
}

QDateTime GMRoute::getProjectedComplete() const
{
    return routeQDateTime["projectedComplete"];
}

void GMRoute::setProjectedComplete(const QDateTime &projectedComplete)
{
    routeQDateTime["projectedComplete"] = projectedComplete;
}

QDateTime GMRoute::getActualComplete() const
{
    return routeQDateTime["actualComplete"];
}

void GMRoute::setActualComplete(const QDateTime &actualComplete)
{
    routeQDateTime["actualComplete"] = actualComplete;
}

QString GMRoute::getActualStartDataQuality() const
{
    return routeQString["actualStartDataQuality"];
}

void GMRoute::setActualStartDataQuality(const QString &actualStartDataQuality)
{
    routeQString["actualStartDataQuality"] = actualStartDataQuality;
}

QString GMRoute::getActualDistanceDataQuality() const
{
    return routeQString["actualDistanceDataQuality"];
}

void GMRoute::setActualDistanceDataQuality(const QString &actualDistanceDataQuality)
{
    routeQString["actualDistanceDataQuality"] = actualDistanceDataQuality;
}

QString GMRoute::getActualDepartDataQuality() const
{
    return routeQString["actualDepartureDataQuality"];
}

void GMRoute::setActualDepartDataQuality
    (const QString &actualDepartureDataQuality)
{
    routeQString["actualDepartureDataQuality"] = actualDepartureDataQuality;
}

double GMRoute::getbaseLineCost() const
{
    return routeDouble["baseLineCost"];
}

void GMRoute::setbaseLineCost(double baseLineCost)
{
    routeDouble["baseLineCost"] = baseLineCost;
}

double GMRoute::getPlannedCost() const
{
    return routeDouble["plannedCost"];
}

void GMRoute::setPlannedCost(double plannedCost)
{
    routeDouble["plannedCost"] = plannedCost;
}

double GMRoute::getActualCost() const
{
    return routeDouble["actualCost"];
}

void GMRoute::setActualCost(double actualCost)
{
    routeDouble["actualCost"] = actualCost;
}

QDateTime GMRoute::getBaseLineStart() const
{
    return routeQDateTime["baseLineStart"];
}

void GMRoute::setBaseLineStart(const QDateTime &baseLineStart)
{
    routeQDateTime["baseLineStart"] = baseLineStart;
}

QDateTime GMRoute::getPlannedStart() const
{
    return routeQDateTime["plannedStart"];
}

void GMRoute::setPlannedStart(const QDateTime &plannedStart)
{
    routeQDateTime["plannedStart"] = plannedStart;
}

QDateTime GMRoute::getProjectedStart() const
{
    return routeQDateTime["projectedStart"];
}

void GMRoute::setProjectedStart(const QDateTime &projectedStart)
{
    routeQDateTime["projectedStart"] = projectedStart;
}

QDateTime GMRoute::getActualStart() const
{
    return routeQDateTime["actualStart"];
}

void GMRoute::setActualStart(const QDateTime &actualStart)
{
    routeQDateTime["actualStart"] = actualStart;
}

bool GMRoute::getHasHelper() const
{
    return routeBool["hasHelper"];
}

void GMRoute::setHasHelper(bool hasHelper)
{
    routeBool["hasHelper"] = hasHelper;
}

QString GMRoute::getDriversName() const
{
    return routeQString["driversName"];
}

void GMRoute::setDriversName(const QString &driversName)
{
    routeQString["driversName"] = driversName;
}

int GMRoute::getTotalStops() const
{
    return routeInt["totalStops"];
}

void GMRoute::setTotalStops(int totalStops)
{
    routeInt["totalStops"] = totalStops;
}

int GMRoute::getCanceledStops() const
{
    return routeInt["canceledStops"];
}

void GMRoute::setCanceledStops(int canceledStops)
{
    routeInt["canceledStops"] = canceledStops;
}

int GMRoute::getUndeliveredStops() const
{
    return routeInt["undeliveredStops"];
}

void GMRoute::setUndeliveredStops(int undeliveredStops)
{
    routeInt["undeliveredStops"] = undeliveredStops;
}

int GMRoute::getRedeliveredStops() const
{
    return routeInt["redeliveredStops"];
}

void GMRoute::setRedeliveredStops(int redeliveredStops)
{
    routeInt["redeliveredStops"] = redeliveredStops;
}

int GMRoute::getActualDepartures() const
{
    return routeInt["actualDepartures"];
}

void GMRoute::setActualDepartures(int actualDepartures)
{
    routeInt["actualDepartures"] = actualDepartures;
}

QString GMRoute::getStatus() const
{
    return routeQString["status"];
}

void GMRoute::setStatus(const QString &status)
{
    routeQString["status"] = status;
}

int GMRoute::getPlannedTravelTimeMinutes() const
{
    return routeInt["plannedTravelTimeMinutes"];
}

void GMRoute::setPlannedTravelTimeMinutes(int plannedTravelTimeMinutes)
{
    routeInt["plannedTravelTimeMinutes"] = plannedTravelTimeMinutes;
}

int GMRoute::getbaselineTravelTimeMinutes() const
{
    return routeInt["baselineTravelTimeMinutes"];
}

void GMRoute::setbaselineTravelTimeMinutes(int baselineTravelTimeMinutes)
{
    routeInt["baselineTravelTimeMinutes"] = baselineTravelTimeMinutes;
}

bool GMRoute::getHasPicture() const
{
    return routeBool["hasPicture"];
}

void GMRoute::setHasPicture(bool hasPicture)
{
    routeBool["hasPicture"] = hasPicture;
}

void GMRoute::read(const QJsonObject &json)
{
    compareJson(json);

    //import all valid int members
    for(auto key : routeInt.keys())
        if(importedMember[key])
            routeInt[key] = json[key].toInt();

    //import all valid qdatetime keys
    for(auto key : routeQDateTime.keys())
        if(importedMember[key])
            routeQDateTime[key] = QDateTime::fromString
                    (json[key].toString(), Qt::ISODateWithMs);

    for(auto key : routeBool.keys())
        if(importedMember[key])
            routeBool[key] = json[key].toBool();

    for(auto key : routeQString.keys())
        if(importedMember[key])
            routeQString[key] = json[key].toString();

    for(auto key : routeQDate.keys())
        if(importedMember[key])
            routeQDate[key] = QDate::fromString
                    (json[key].toString(), "yyyy-MM-dd");

    //GOrganization org
    //GLocation orgin;
    //GLocation destination;
    //GStop stops;
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    //GRouteHelperAssignment routeHelperAssignments;
}

QJsonObject GMRoute::write()
{
    QJsonObject jTest;
    QJsonDocument jDoc;

    QString query = "{\n        \"actualArrival\": \"2017-06-21T17:04:15+0000\",\n        \"actualComplete\": \"2017-06-21T17:08:43+0000\",\n        \"actualCompleteDataQuality\": \"GEO_COMPUTED\",\n        \"actualCost\": 189.30522160979876,\n        \"actualDeparture\": \"2017-06-21T13:59:29+0000\",\n        \"actualDepartureDataQuality\": \"GEO_COMPUTED\",\n        \"actualDepartures\": 9,\n        \"actualDistance\": 11000,\n        \"actualDistanceDataQuality\": \"GEO_COMPUTED\",\n        \"actualDistanceRecalculatedAt\": \"2017-06-21T17:13:47+0000\",\n        \"actualServiceTime\": 11354000,\n        \"actualSize1\": 210,\n        \"actualSize2\": 117,\n        \"actualSize3\": 2295,\n        \"actualStart\": \"2017-06-21T13:59:29+0000\",\n        \"actualStartDataQuality\": \"GEO_COMPUTED\",\n        \"actualTravelTimeMinutes\": 73,\n        \"baseLineArrival\": \"2017-06-21T16:29:55+0000\",\n        \"baseLineComplete\": \"2017-06-21T20:00:00+0000\",\n        \"baseLineCost\": 0,\n        \"baseLineDeparture\": \"2017-06-21T12:00:00+0000\",\n        \"baseLineDistance\": 18358.465077168876,\n        \"baseLineStart\": \"2017-06-21T12:00:00+0000\",\n        \"baselineServiceTime\": 28800000,\n        \"baselineTravelTimeMinutes\": 18,\n        \"canceledStops\": 3,\n        \"creationDate\": \"2017-06-21T11:34:56+0000\",\n        \"date\": \"2017-06-21\",\n        \"description\": \"T-DT7\",\n        \"destLatitude\": 47.566536,\n        \"destLongitude\": -122.33265,\n        \"hasGps\": true,\n        \"hasHelper\": false,\n        \"id\": 72594,\n        \"key\": \"T-DT7\",\n        \"lastModificationDate\": \"2017-06-21T17:13:27+0000\",\n        \"lastStopIsDestination\": false,\n        \"lastUpdatedProjectedTime\": \"2017-06-21T17:13:27+0000\",\n        \"origLatitude\": 47.566536,\n        \"origLongitude\": -122.33265,\n        \"plannedArrival\": \"2017-06-21T16:29:55+0000\",\n        \"plannedComplete\": \"2017-06-21T20:00:00+0000\",\n        \"plannedCost\": 297.7034768484654,\n        \"plannedDeparture\": \"2017-06-21T12:00:00+0000\",\n        \"plannedDistance\": 10335.49084680573,\n        \"plannedServiceTime\": 28800000,\n        \"plannedSize1\": 264,\n        \"plannedSize2\": 159,\n        \"plannedSize3\": 3049,\n        \"plannedStart\": \"2017-06-21T12:00:00+0000\",\n        \"plannedTravelTimeMinutes\": 66,\n        \"projectedArrival\": \"2017-06-21T18:06:04+0000\",\n        \"projectedComplete\": \"2017-06-21T21:36:09+0000\",\n        \"projectedDeparture\": \"2017-06-21T12:00:00+0000\",\n        \"projectedDistance\": 15412.865532915766,\n        \"projectedStart\": \"2017-06-21T12:00:00+0000\",\n        \"redeliveredStops\": 0,\n        \"status\": \"COMPLETED\",\n        \"totalStops\": 12,\n        \"undeliveredStops\": 0\n    }";
    jTest = jDoc.fromJson(query.toUtf8()).object();
    read(jTest);

    QJsonObject jTemp;

    //import all valid int members
    for(auto key : routeInt.keys())
        if(importedMember[key])
            jTemp[key] = routeInt[key];

    //import all valid qdatetime members
    for(auto key : routeQDateTime.keys())
        if(importedMember[key])
            jTemp[key] = routeQDateTime[key].toString(Qt::ISODateWithMs);

    for(auto key : routeBool.keys())
        if(importedMember[key])
            jTemp[key] = routeBool[key];

    for(auto key : routeQString.keys())
        if(importedMember[key])
            jTemp[key] = routeQString[key];

    for(auto key : routeQDate.keys())
        if(importedMember[key])
            jTemp[key] = routeQDate[key].toString("yyyy-MM-dd");

    //BEGIN TEST SECTION

    QDateTime test = QDateTime::fromString
            (jTemp["dateTime"].toString(), Qt::ISODateWithMs);

    test.setTimeSpec(Qt::UTC);

    qDebug() << "TEST DATETIME test WRITE" << test.toLocalTime().toString();

    qDebug() << "TEST DATETIME WRITE" << QDateTime::fromString
                (jTemp["plannedArrival"].toString(),
                Qt::ISODateWithMs).toString();

    qDebug() << "TEST DATE WRITE " << routeQDate["date"].toString();

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

    for(auto key : importedMember.keys())
        qDebug() << key << "," << importedMember[key];

}

void GMRoute::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

void GMRoute::setMembersToDefaults()
{
    for(auto key : routeInt.keys())
        if(importedMember[key])
            routeInt[key] = routeIntInit;

    for(auto key : routeQDateTime.keys())
        if(importedMember[key])
            routeQDateTime[key] = routeQDateTimeInit;

    for(auto key : routeBool.keys())
        if(importedMember[key])
            routeBool[key] = routeBoolInit;

    for(auto key : routeQString.keys())
        if(importedMember[key])
            routeQString[key] = routeQStringInit;

    for(auto key : routeQDate.keys())
        if(importedMember[key])
            routeQDate[key] = routeQDateInit;

    //GOrganization org
    //GLocation orgin;
    //GLocation destination;
    //GStop stops;
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    //GRouteHelperAssignment routeHelperAssignments;

}

void GMRoute::append(const QJsonObject &json)
{
    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    //import all valid int members
    for(auto key : routeInt.keys())
        if(importedMember[key])
            routeInt[key] = json[key].toInt();

    //import all valid qdatetime keys
    for(auto key : routeQDateTime.keys())
        if(importedMember[key])
            routeQDateTime[key] = QDateTime::fromString
                    (json[key].toString(), Qt::ISODateWithMs);

    for(auto key : routeBool.keys())
        if(importedMember[key])
            routeBool[key] = json[key].toBool();

    for(auto key : routeQString.keys())
        if(importedMember[key])
            routeQString[key] = json[key].toString();

    for(auto key : routeQDate.keys())
        if(importedMember[key])
            routeQDate[key] = QDate::fromString
                    (json[key].toString(), "yyyy-MM-dd");
}
