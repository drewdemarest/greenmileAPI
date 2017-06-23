#include "gm_entities/gmroute.h"


//REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

GMRoute::GMRoute()
{
    objInt["id"]                              = objIntInit;
    objInt["delayTypeID"]                     = objIntInit;
    objInt["delayMinutes"]                    = objIntInit;
    objInt["totalStops"]                      = objIntInit;
    objInt["canceledStops"]                   = objIntInit;
    objInt["undeliveredStops"]                = objIntInit;
    objInt["redeliveredStops"]                = objIntInit;
    objInt["actualDeparture"]                 = objIntInit;
    objInt["actualTravelTimeMinutes"]         = objIntInit;
    objInt["plannedTravelTimeMinutes"]        = objIntInit;
    objInt["baselineTravelTimeMinutes"]       = objIntInit;

    objDouble["baseLineDistance"]             = objDoubleInit;
    objDouble["plannedDistance"]              = objDoubleInit;
    objDouble["projectedDistance"]            = objDoubleInit;
    objDouble["actualDistance"]               = objDoubleInit;
    objDouble["baseLineCost"]                 = objDoubleInit;
    objDouble["plannedCost"]                  = objDoubleInit;
    objDouble["actualCost"]                   = objDoubleInit;

    objQString["key"]                         = objQStringInit;
    objQString["description"]                 = objQStringInit;
    objQString["actualStartDataQuality"]      = objQStringInit;
    objQString["actualDistanceDataQuality"]   = objQStringInit;
    objQString["actualDepartureDataQuality"]  = objQStringInit;
    objQString["driversName"]                 = objQStringInit;
    objQString["status"]                      = objQStringInit;

    objQDate["date"]                          = objQDateInit;

    objBool["lastStopIsDestination"]          = objBoolInit;
    objBool["hasHelper"]                      = objBoolInit;
    objBool["hasPicture"]                     = objBoolInit;

    objQDateTime["plannedArrival"]            = objQDateTimeInit;
    objQDateTime["baseLineArrival"]           = objQDateTimeInit;
    objQDateTime["plannedDeparture"]          = objQDateTimeInit;
    objQDateTime["baseLineDeparture"]         = objQDateTimeInit;
    objQDateTime["projectedArrival"]          = objQDateTimeInit;
    objQDateTime["projectedDeparture"]        = objQDateTimeInit;
    objQDateTime["actualArrival"]             = objQDateTimeInit;
    objQDateTime["actualDepartures"]          = objQDateTimeInit;
    objQDateTime["lastContactTime"]           = objQDateTimeInit;
    objQDateTime["baseLineComplete"]          = objQDateTimeInit;
    objQDateTime["plannedComplete"]           = objQDateTimeInit;
    objQDateTime["projectedComplete"]         = objQDateTimeInit;
    objQDateTime["actualComplete"]            = objQDateTimeInit;
    objQDateTime["baseLineStart"]             = objQDateTimeInit;
    objQDateTime["plannedStart"]              = objQDateTimeInit;
    objQDateTime["projectedStart"]            = objQDateTimeInit;
    objQDateTime["actualStart"]               = objQDateTimeInit;

    objGMOrganization["organization"]         = objGMOrganizationInit;

    //GOrganization org
    //GLocation orgin;
    //GLocation destination;
    //GStop stops;
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    //GRouteHelperAssignment objHelperAssignments;

    memberList << objInt.keys()       << objDouble.keys()
               << objQString.keys()   << objQDate.keys()
               << objBool.keys()      << objQDateTime.keys()
               << objQDateTime.keys() << objGMOrganization.keys();

    qDebug() << memberList.size() << "memberList";
}


//BEGIN GETTERS/SETTERS

int GMRoute::getId() const
{
    return objInt["id"];
}

void GMRoute::setId(int id)
{
    objInt["id"] = id;
}

QString GMRoute::getKey() const
{
    return objQString["key"];
}

void GMRoute::setKey(const QString &key)
{
    objQString["key"] = key;
}

QString GMRoute::getDescription() const
{
    return objQString["description"];
}

void GMRoute::setDescription(const QString &description)
{
    objQString["description"] = description;
}

QDate GMRoute::getDate() const
{
    return objQDate["date"];
}

void GMRoute::setDate(const QDate &date)
{
    objQDate["date"] = date;
}

bool GMRoute::getLastStopIsDestination() const
{
    return objBool["lastStopIsDestination"];
}

void GMRoute::setLastStopIsDestination(bool lastStopIsDestination)
{
    objBool["lastStopIsDestination"] = lastStopIsDestination;
}

QDateTime GMRoute::getPlannedArrival() const
{
    return objQDateTime["plannedArrival"];
}

void GMRoute::setPlannedArrival(const QDateTime &plannedArrival)
{
    objQDateTime["plannedArrival"] = plannedArrival;
}

QDateTime GMRoute::getBaseLineArrival() const
{
    return objQDateTime["baseLineArrival"];
}

void GMRoute::setBaseLineArrival(const QDateTime &baseLineArrival)
{
    objQDateTime["baseLineArrival"] = baseLineArrival;
}

QDateTime GMRoute::getPlannedDeparture() const
{
    return objQDateTime["plannedDeparture"];
}

void GMRoute::setPlannedDeparture(const QDateTime &plannedDeparture)
{
    objQDateTime["plannedDeparture"] = plannedDeparture;
}

QDateTime GMRoute::getBaseLineDeparture() const
{
    return objQDateTime["baseLineDeparture"];
}

void GMRoute::setBaseLineDeparture(const QDateTime &baseLineDeparture)
{
    objQDateTime["baseLineDeparture"] = baseLineDeparture;
}

QDateTime GMRoute::getProjectedArrival() const
{
    return objQDateTime["projectedArrival"];
}

void GMRoute::setProjectedArrival(const QDateTime &projectedArrival)
{
    objQDateTime["projectedArrival"] = projectedArrival;
}

QDateTime GMRoute::getProjectedDeparture() const
{
    return objQDateTime["projectedDeparture"];
}

void GMRoute::setProjectedDeparture(const QDateTime &projectedDeparture)
{
    objQDateTime["projectedDeparture"] = projectedDeparture;
}

QDateTime GMRoute::getActualArrival() const
{
    return objQDateTime["actualArrival"];
}

void GMRoute::setActualArrival(const QDateTime &actualArrival)
{
    objQDateTime["actualArrival"] = actualArrival;
}

QDateTime GMRoute::getActualDeparture() const
{
    return objQDateTime["actualDeparture"];
}

void GMRoute::setActualDeparture(const QDateTime &actualDeparture)
{
    objQDateTime["actualDeparture"] = actualDeparture;
}

double GMRoute::getbaseLineDistance() const
{
    return objDouble["baseLineDistance"];
}

void GMRoute::setbaseLineDistance(double baseLineDistance)
{
    objDouble["baseLineDistance"] = baseLineDistance;
}

double GMRoute::getPlannedDistance() const
{
    return objDouble["plannedDistance"];
}

void GMRoute::setPlannedDistance(double plannedDistance)
{
    objDouble["plannedDistance"] = plannedDistance;
}

double GMRoute::getProjectedDistance() const
{
    return objDouble["projectedDistance"];
}

void GMRoute::setProjectedDistance(double projectedDistance)
{
    objDouble["projectedDistance"] = projectedDistance;
}

double GMRoute::getActualDistance() const
{
    return objDouble["actualDistance"];
}

void GMRoute::setActualDistance(double actualDistance)
{
    objDouble["actualDistance"] = actualDistance;
}

int GMRoute::getDelayTypeID() const
{
    return objInt["delayTypeID"];
}

void GMRoute::setDelayTypeID(int delayTypeID)
{
    objInt["delayTypeID"] = delayTypeID;
}

int GMRoute::getDelayMinutes() const
{
    return objInt["delayMinutes"];
}

void GMRoute::setDelayMinutes(int delayMinutes)
{
    objInt["delayMinutes"] = delayMinutes;
}

QDateTime GMRoute::getLastContactTime() const
{
    return objQDateTime["lastContactTime"];
}

void GMRoute::setLastContactTime(const QDateTime &lastContactTime)
{
    objQDateTime["lastContactTime"] = lastContactTime;
}

QDateTime GMRoute::getBaseLineComplete() const
{
    return objQDateTime["baseLineComplete"];
}

void GMRoute::setBaseLineComplete(const QDateTime &baseLineComplete)
{
    objQDateTime["baseLineComplete"] = baseLineComplete;
}

QDateTime GMRoute::getPlannedComplete() const
{
    return objQDateTime["plannedComplete"];
}

void GMRoute::setPlannedComplete(const QDateTime &plannedComplete)
{
    objQDateTime["plannedComplete"] = plannedComplete;
}

QDateTime GMRoute::getProjectedComplete() const
{
    return objQDateTime["projectedComplete"];
}

void GMRoute::setProjectedComplete(const QDateTime &projectedComplete)
{
    objQDateTime["projectedComplete"] = projectedComplete;
}

QDateTime GMRoute::getActualComplete() const
{
    return objQDateTime["actualComplete"];
}

void GMRoute::setActualComplete(const QDateTime &actualComplete)
{
    objQDateTime["actualComplete"] = actualComplete;
}

QString GMRoute::getActualStartDataQuality() const
{
    return objQString["actualStartDataQuality"];
}

void GMRoute::setActualStartDataQuality(const QString &actualStartDataQuality)
{
    objQString["actualStartDataQuality"] = actualStartDataQuality;
}

QString GMRoute::getActualDistanceDataQuality() const
{
    return objQString["actualDistanceDataQuality"];
}

void GMRoute::setActualDistanceDataQuality(const QString &actualDistanceDataQuality)
{
    objQString["actualDistanceDataQuality"] = actualDistanceDataQuality;
}

QString GMRoute::getActualDepartDataQuality() const
{
    return objQString["actualDepartureDataQuality"];
}

void GMRoute::setActualDepartDataQuality
    (const QString &actualDepartureDataQuality)
{
    objQString["actualDepartureDataQuality"] = actualDepartureDataQuality;
}

double GMRoute::getbaseLineCost() const
{
    return objDouble["baseLineCost"];
}

void GMRoute::setbaseLineCost(double baseLineCost)
{
    objDouble["baseLineCost"] = baseLineCost;
}

double GMRoute::getPlannedCost() const
{
    return objDouble["plannedCost"];
}

void GMRoute::setPlannedCost(double plannedCost)
{
    objDouble["plannedCost"] = plannedCost;
}

double GMRoute::getActualCost() const
{
    return objDouble["actualCost"];
}

void GMRoute::setActualCost(double actualCost)
{
    objDouble["actualCost"] = actualCost;
}

QDateTime GMRoute::getBaseLineStart() const
{
    return objQDateTime["baseLineStart"];
}

void GMRoute::setBaseLineStart(const QDateTime &baseLineStart)
{
    objQDateTime["baseLineStart"] = baseLineStart;
}

QDateTime GMRoute::getPlannedStart() const
{
    return objQDateTime["plannedStart"];
}

void GMRoute::setPlannedStart(const QDateTime &plannedStart)
{
    objQDateTime["plannedStart"] = plannedStart;
}

QDateTime GMRoute::getProjectedStart() const
{
    return objQDateTime["projectedStart"];
}

void GMRoute::setProjectedStart(const QDateTime &projectedStart)
{
    objQDateTime["projectedStart"] = projectedStart;
}

QDateTime GMRoute::getActualStart() const
{
    return objQDateTime["actualStart"];
}

void GMRoute::setActualStart(const QDateTime &actualStart)
{
    objQDateTime["actualStart"] = actualStart;
}

bool GMRoute::getHasHelper() const
{
    return objBool["hasHelper"];
}

void GMRoute::setHasHelper(bool hasHelper)
{
    objBool["hasHelper"] = hasHelper;
}

QString GMRoute::getDriversName() const
{
    return objQString["driversName"];
}

void GMRoute::setDriversName(const QString &driversName)
{
    objQString["driversName"] = driversName;
}

int GMRoute::getTotalStops() const
{
    return objInt["totalStops"];
}

void GMRoute::setTotalStops(int totalStops)
{
    objInt["totalStops"] = totalStops;
}

int GMRoute::getCanceledStops() const
{
    return objInt["canceledStops"];
}

void GMRoute::setCanceledStops(int canceledStops)
{
    objInt["canceledStops"] = canceledStops;
}

int GMRoute::getUndeliveredStops() const
{
    return objInt["undeliveredStops"];
}

void GMRoute::setUndeliveredStops(int undeliveredStops)
{
    objInt["undeliveredStops"] = undeliveredStops;
}

int GMRoute::getRedeliveredStops() const
{
    return objInt["redeliveredStops"];
}

void GMRoute::setRedeliveredStops(int redeliveredStops)
{
    objInt["redeliveredStops"] = redeliveredStops;
}

int GMRoute::getActualDepartures() const
{
    return objInt["actualDepartures"];
}

void GMRoute::setActualDepartures(int actualDepartures)
{
    objInt["actualDepartures"] = actualDepartures;
}

QString GMRoute::getStatus() const
{
    return objQString["status"];
}

void GMRoute::setStatus(const QString &status)
{
    objQString["status"] = status;
}

int GMRoute::getPlannedTravelTimeMinutes() const
{
    return objInt["plannedTravelTimeMinutes"];
}

void GMRoute::setPlannedTravelTimeMinutes(int plannedTravelTimeMinutes)
{
    objInt["plannedTravelTimeMinutes"] = plannedTravelTimeMinutes;
}

int GMRoute::getbaselineTravelTimeMinutes() const
{
    return objInt["baselineTravelTimeMinutes"];
}

void GMRoute::setbaselineTravelTimeMinutes(int baselineTravelTimeMinutes)
{
    objInt["baselineTravelTimeMinutes"] = baselineTravelTimeMinutes;
}

bool GMRoute::getHasPicture() const
{
    return objBool["hasPicture"];
}

void GMRoute::setHasPicture(bool hasPicture)
{
    objBool["hasPicture"] = hasPicture;
}

GMOrganization GMRoute::getOrganization() const
{
    return objGMOrganization["organization"];
}

void GMRoute::setOrganization(const GMOrganization &organization)
{
    objGMOrganization["organization"] = organization;
}

void GMRoute::importJson(const QJsonObject &json)
{
    compareJson(json);
    importEngine(json);
}

QJsonObject GMRoute::exportJson()
{
    QJsonObject jTest;
    QJsonDocument jDoc;

    QJsonObject jTemp = exportEngine();


    return jTemp;
}

void GMRoute::appendJson(const QJsonObject &json)
{
    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    importEngine(json);
}

void GMRoute::compareJson(const QJsonObject &json)
{
    setImportedMembersFalse();

    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    for(auto key : importedMember.keys())
        qDebug() << key << "," << importedMember[key];
}

//BEGIN PRIVATE FUNCTIONS

void GMRoute::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

void GMRoute::setMembersToDefaults()
{
    for(auto key : objInt.keys())
        if(importedMember[key])
            objInt[key] = objIntInit;

    for(auto key : objQDateTime.keys())
        if(importedMember[key])
            objQDateTime[key] = objQDateTimeInit;

    for(auto key : objBool.keys())
        if(importedMember[key])
            objBool[key] = objBoolInit;

    for(auto key : objQString.keys())
        if(importedMember[key])
            objQString[key] = objQStringInit;

    for(auto key : objQDate.keys())
        if(importedMember[key])
            objQDate[key] = objQDateInit;

    for(auto key : objQDate.keys())
        if(importedMember[key])
            objGMOrganization[key] = objGMOrganizationInit;

    //GOrganization org
    //GLocation orgin;
    //GLocation destination;
    //GStop stops;
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    //GRouteHelperAssignment routeHelperAssignments;

}

void GMRoute::importEngine(const QJsonObject &json)
{
    //import all valid int members
    for(auto key : objInt.keys())
        if(importedMember[key])
            objInt[key] = json[key].toInt();

    //import all valid qdatetime keys
    for(auto key : objQDateTime.keys())
        if(importedMember[key])
            objQDateTime[key] = QDateTime::fromString
                    (json[key].toString(), Qt::ISODateWithMs);

    for(auto key : objBool.keys())
        if(importedMember[key])
            objBool[key] = json[key].toBool();

    for(auto key : objQString.keys())
        if(importedMember[key])
            objQString[key] = json[key].toString();

    for(auto key : objQDate.keys())
        if(importedMember[key])
            objQDate[key] = QDate::fromString
                    (json[key].toString(), "yyyy-MM-dd");

    for(auto key : objGMOrganization.keys())
        if(importedMember[key])
            objGMOrganization[key].importJson(json[key].toObject());
}

QJsonObject GMRoute::exportEngine()
{
    QJsonObject json;

    //import all valid int members
    for(auto key : objInt.keys())
        if(importedMember[key])
            json[key] = objInt[key];

    //import all valid qdatetime members
    for(auto key : objQDateTime.keys())
        if(importedMember[key])
            json[key] = objQDateTime[key].toString(Qt::ISODateWithMs);

    for(auto key : objBool.keys())
        if(importedMember[key])
            json[key] = objBool[key];

    for(auto key : objQString.keys())
        if(importedMember[key])
            json[key] = objQString[key];

    for(auto key : objQDate.keys())
        if(importedMember[key])
            json[key] = objQDate[key].toString("yyyy-MM-dd");

    for(auto key : objGMOrganization.keys())
        if(importedMember[key])
            json[key] = objGMOrganization[key].exportJson();

    return json;
}
