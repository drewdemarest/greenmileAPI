#include "gm_entities/gmroute.h"
#include <gm_entities/gmorganization.h>

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
    objInt["actualDepartures"]                = objIntInit;
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
    objQDateTime["actualDeparture"]           = objQDateTimeInit;
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

    //qDebug() << memberList.size() << "memberList";
}

GMRoute::~GMRoute()
{
    delete objBoolInit;
    delete objIntInit;
    delete objDoubleInit;
    delete objQStringInit;
    delete objQDateInit;
    delete objQDateTimeInit;
    delete objGMOrganizationInit;

    qDeleteAll(objInt);
    objInt.clear();

    qDeleteAll(objDouble);
    objDouble.clear();

    qDeleteAll(objBool);
    objBool.clear();

    qDeleteAll(objQString);
    objQString.clear();

    qDeleteAll(objQDate);
    objQDate.clear();

    qDeleteAll(objQDateTime);
    objQDateTime.clear();

    qDeleteAll(objGMOrganization);
    objGMOrganization.clear();
}

//BEGIN GETTERS/SETTERS

/*
int *GMRoute::getId() const
{
    return objInt["id"];
}

void GMRoute::setId(int id)
{
    if(objInt["id"])
        *objInt["id"] = id;
    else
        objInt["id"] = new int(id);
}

QString *GMRoute::getKey() const
{
    return objQString["key"];
}

void GMRoute::setKey(const QString &key)
{
    if(objQString["key"])
        *objQString["key"] = key;
    else
        objQString["key"] = new QString(key);
}

QString *GMRoute::getDescription() const
{
    return objQString["description"];
}

void GMRoute::setDescription(const QString &description)
{
    if(objQString["description"])
        *objQString["description"] = description;
    else
        objQString["description"] = new QString(description);
}

QDate *GMRoute::getDate() const
{
    return objQDate["date"];
}

void GMRoute::setDate(const QDate &date)
{
    if(objQString["date"])
        *objQDate["date"] = date;
    else
        objQDate["date"] = new QDate(date);
}

bool *GMRoute::getLastStopIsDestination() const
{
    return objBool["lastStopIsDestination"];
}

void GMRoute::setLastStopIsDestination(bool lastStopIsDestination)
{
    if(objBool["lastStopIsDestination"])
        *objBool["lastStopIsDestination"] = lastStopIsDestination;
    else
        objBool["lastStopIsDestination"] = new bool(lastStopIsDestination);
}

QDateTime *GMRoute::getPlannedArrival() const
{
    return objQDateTime["plannedArrival"];
}

void GMRoute::setPlannedArrival(const QDateTime &plannedArrival)
{
    if(objQDateTime["plannedArrival"])
        *objQDateTime["plannedArrival"] = plannedArrival;
    else
        objQDateTime["plannedArrival"] = new QDateTime(plannedArrival);
}

QDateTime *GMRoute::getBaseLineArrival() const
{
    return objQDateTime["baseLineArrival"];
}

void GMRoute::setBaseLineArrival(const QDateTime &baseLineArrival)
{
    if(objQDateTime["baseLineArrival"])
        *objQDateTime["baseLineArrival"] = baseLineArrival;
    else
        objQDateTime["baseLineArrival"] = new QDateTime(baseLineArrival);
}

QDateTime *GMRoute::getPlannedDeparture() const
{
    return objQDateTime["plannedDeparture"];
}

void GMRoute::setPlannedDeparture(const QDateTime &plannedDeparture)
{
    if(objQDateTime["plannedDeparture"])
        *objQDateTime["plannedDeparture"] = plannedDeparture;
    else
        objQDateTime["plannedDeparture"] = new QDateTime(plannedDeparture);
}

QDateTime *GMRoute::getBaseLineDeparture() const
{
    return objQDateTime["baseLineDeparture"];
}

void GMRoute::setBaseLineDeparture(const QDateTime &baseLineDeparture)
{
    if(objQDateTime["baseLineDeparture"])
        *objQDateTime["baseLineDeparture"] = baseLineDeparture;
    else
        objQDateTime["baseLineDeparture"] = new QDateTime(baseLineDeparture);
}

QDateTime *GMRoute::getProjectedArrival() const
{
    return objQDateTime["projectedArrival"];
}

void GMRoute::setProjectedArrival(const QDateTime &projectedArrival)
{
    if(objQDateTime["projectedArrival"])
        *objQDateTime["projectedArrival"] = projectedArrival;
    else
        objQDateTime["projectedArrival"] = new QDateTime(projectedArrival);
}

QDateTime *GMRoute::getProjectedDeparture() const
{
    return objQDateTime["projectedDeparture"];
}

void GMRoute::setProjectedDeparture(const QDateTime &projectedDeparture)
{
    if(objQDateTime["projectedDeparture"])
        *objQDateTime["projectedDeparture"] = projectedDeparture;
    else
        objQDateTime["projectedDeparture"] = new QDateTime(projectedDeparture);
}

QDateTime *GMRoute::getActualArrival() const
{
    return objQDateTime["actualArrival"];
}

void GMRoute::setActualArrival(const QDateTime &actualArrival)
{
    if(objQDateTime["actualArrival"])
        *objQDateTime["actualArrival"] = actualArrival;
    else
        objQDateTime["actualArrival"] = new QDateTime(actualArrival);
}

QDateTime *GMRoute::getActualDeparture() const
{
    return objQDateTime["actualDeparture"];
}

void GMRoute::setActualDeparture(const QDateTime &actualDeparture)
{
    if(objQDateTime["actualDeparture"])
        *objQDateTime["actualDeparture"] = actualDeparture;
    else
        objQDateTime["actualDeparture"] = new QDateTime(actualDeparture);
}

double *GMRoute::getbaseLineDistance() const
{
    return objDouble["baseLineDistance"];
}

void GMRoute::setbaseLineDistance(double baseLineDistance)
{
    if(objDouble["baseLineDistance"])
        *objDouble["baseLineDistance"] = baseLineDistance;
    else
        objDouble["baseLineDistance"] = new double(baseLineDistance);
}

double *GMRoute::getPlannedDistance() const
{
    return objDouble["plannedDistance"];
}

void GMRoute::setPlannedDistance(double plannedDistance)
{
    if(objDouble["plannedDistance"])
        *objDouble["plannedDistance"] = plannedDistance;
    else
        objDouble["plannedDistance"] = new double(plannedDistance);
}

double *GMRoute::getProjectedDistance() const
{
    return objDouble["projectedDistance"];
}

void GMRoute::setProjectedDistance(double projectedDistance)
{
    if(objDouble["projectedDistance"])
        *objDouble["projectedDistance"] = projectedDistance;
    else
        objDouble["projectedDistance"] = new double(projectedDistance);
}

double *GMRoute::getActualDistance() const
{
    return objDouble["actualDistance"];
}

void GMRoute::setActualDistance(double actualDistance)
{
    if(objDouble["actualDistance"])
        *objDouble["actualDistance"] = actualDistance;
    else
        objDouble["actualDistance"] = new double(actualDistance);
}

int *GMRoute::getDelayTypeID() const
{
    return objInt["delayTypeID"];
}

void GMRoute::setDelayTypeID(int delayTypeID)
{
    if(objInt["delayTypeID"])
        *objInt["delayTypeID"] = delayTypeID;
    else
        objInt["delayTypeID"] = new int(delayTypeID);
}

int *GMRoute::getDelayMinutes() const
{
    return objInt["delayMinutes"];
}

void GMRoute::setDelayMinutes(int delayMinutes)
{
    if(objInt["delayMinutes"])
        *objInt["delayMinutes"] = delayMinutes;
    else
        objInt["delayMinutes"] = new int(delayMinutes);
}

QDateTime *GMRoute::getLastContactTime() const
{
    return objQDateTime["lastContactTime"];
}

void GMRoute::setLastContactTime(const QDateTime &lastContactTime)
{
    if(objQDateTime["lastContactTime"])
        *objQDateTime["lastContactTime"] = lastContactTime;
    else
        objQDateTime["lastContactTime"] = new QDateTime(lastContactTime);
}

QDateTime *GMRoute::getBaseLineComplete() const
{
    return objQDateTime["baseLineComplete"];
}

void GMRoute::setBaseLineComplete(const QDateTime &baseLineComplete)
{
    if(objQDateTime["baseLineComplete"])
        *objQDateTime["baseLineComplete"] = baseLineComplete;
    else
        objQDateTime["baseLineComplete"] = new QDateTime(baseLineComplete);
}

QDateTime *GMRoute::getPlannedComplete() const
{
    return objQDateTime["plannedComplete"];
}

void GMRoute::setPlannedComplete(const QDateTime &plannedComplete)
{
    if(objQDateTime["plannedComplete"])
        *objQDateTime["plannedComplete"] = plannedComplete;
    else
        objQDateTime["plannedComplete"] = new QDateTime(plannedComplete);
}

QDateTime *GMRoute::getProjectedComplete() const
{
    return objQDateTime["projectedComplete"];
}

void GMRoute::setProjectedComplete(const QDateTime &projectedComplete)
{
    if(objQDateTime["projectedComplete"])
        *objQDateTime["projectedComplete"] = projectedComplete;
    else
        objQDateTime["projectedComplete"] = new QDateTime(projectedComplete);
}

QDateTime *GMRoute::getActualComplete() const
{
    return objQDateTime["actualComplete"];
}

void GMRoute::setActualComplete(const QDateTime &actualComplete)
{
    if(objQDateTime["actualComplete"])
        *objQDateTime["actualComplete"] = actualComplete;
    else
        objQDateTime["actualComplete"] = new QDateTime(actualComplete);
}

QString *GMRoute::getActualStartDataQuality() const
{
    return objQString["actualStartDataQuality"];
}

void GMRoute::setActualStartDataQuality(const QString &actualStartDataQuality)
{
    if(objQString["actualStartDataQuality"])
        *objQString["actualStartDataQuality"] = actualStartDataQuality;
    else
        objQString["actualStartDataQuality"] = new QString(actualStartDataQuality);
}

QString *GMRoute::getActualDistanceDataQuality() const
{
    return objQString["actualDistanceDataQuality"];
}

void GMRoute::setActualDistanceDataQuality(const QString &actualDistanceDataQuality)
{
    if(objQString["actualDistanceDataQuality"])
        *objQString["actualDistanceDataQuality"] = actualDistanceDataQuality;
    else
        objQString["actualDistanceDataQuality"] = new QString(actualDistanceDataQuality);
}

QString *GMRoute::getActualDepartDataQuality() const
{
    return objQString["actualDepartureDataQuality"];
}

void GMRoute::setActualDepartDataQuality
(const QString &actualDepartureDataQuality)
{
    if(objQString["actualDepartureDataQuality"])
        *objQString["actualDepartureDataQuality"] = actualDepartureDataQuality;
    else
        objQString["actualDepartureDataQuality"] = new QString(actualDepartureDataQuality);
}

double *GMRoute::getbaseLineCost() const
{
    return objDouble["baseLineCost"];
}

void GMRoute::setbaseLineCost(double baseLineCost)
{
    if(objDouble["baseLineCost"])
        *objDouble["baseLineCost"] = baseLineCost;
    else
        objDouble["baseLineCost"] = new double(baseLineCost);
}

double *GMRoute::getPlannedCost() const
{
    return objDouble["plannedCost"];
}

void GMRoute::setPlannedCost(double plannedCost)
{
    if(objDouble["plannedCost"])
        *objDouble["plannedCost"] = plannedCost;
    else
        objDouble["plannedCost"] = new double(plannedCost);
}

double *GMRoute::getActualCost() const
{
    return objDouble["actualCost"];
}

void GMRoute::setActualCost(double actualCost)
{
    if(objDouble["actualCost"])
        *objDouble["actualCost"] = actualCost;
    else
        objDouble["actualCost"] = new double(actualCost);
}

QDateTime *GMRoute::getBaseLineStart() const
{
    return objQDateTime["baseLineStart"];
}

void GMRoute::setBaseLineStart(const QDateTime &baseLineStart)
{
    if(objQDateTime["baseLineStart"])
        *objQDateTime["baseLineStart"] = baseLineStart;
    else
        objQDateTime["baseLineStart"] =new QDateTime(baseLineStart);
}

QDateTime *GMRoute::getPlannedStart() const
{
    return objQDateTime["plannedStart"];
}

void GMRoute::setPlannedStart(const QDateTime &plannedStart)
{
    if(objQDateTime["plannedStart"])
        *objQDateTime["plannedStart"] = plannedStart;
    else
        objQDateTime["plannedStart"] = new QDateTime(plannedStart);
}

QDateTime *GMRoute::getProjectedStart() const
{
    return objQDateTime["projectedStart"];
}

void GMRoute::setProjectedStart(const QDateTime &projectedStart)
{
    if(objQDateTime["projectedStart"])
        *objQDateTime["projectedStart"] = projectedStart;
    else
        objQDateTime["projectedStart"] = new QDateTime(projectedStart);
}

QDateTime *GMRoute::getActualStart() const
{
    return objQDateTime["actualStart"];
}

void GMRoute::setActualStart(const QDateTime &actualStart)
{
    if(objQDateTime["actualStart"])
        *objQDateTime["actualStart"] = actualStart;
    else
        objQDateTime["actualStart"] = new QDateTime(actualStart);
}

bool *GMRoute::getHasHelper() const
{
    return objBool["hasHelper"];
}

void GMRoute::setHasHelper(bool hasHelper)
{
    if(objBool["hasHelper"])
        *objBool["hasHelper"] = hasHelper;
    else
        objBool["hasHelper"] = new bool(hasHelper);
}

QString *GMRoute::getDriversName() const
{
    return objQString["driversName"];
}

void GMRoute::setDriversName(const QString &driversName)
{
    if(objQString["driversName"])
        *objQString["driversName"] = driversName;
    else
        objQString["driversName"] = new QString(driversName);
}

int *GMRoute::getTotalStops() const
{
    return objInt["totalStops"];
}

void GMRoute::setTotalStops(int totalStops)
{
    if(objInt["totalStops"])
        *objInt["totalStops"] = totalStops;
    else
        objInt["totalStops"] = new int(totalStops);
}

int *GMRoute::getCanceledStops() const
{
    return objInt["canceledStops"];
}

void GMRoute::setCanceledStops(int canceledStops)
{
    if(objInt["canceledStops"])
        *objInt["canceledStops"] = canceledStops;
    else
        objInt["canceledStops"] = new int(canceledStops);
}

int *GMRoute::getUndeliveredStops() const
{
    return objInt["undeliveredStops"];
}

void GMRoute::setUndeliveredStops(int undeliveredStops)
{
    if(objInt["undeliveredStops"])
        *objInt["undeliveredStops"] = undeliveredStops;
    else
        objInt["undeliveredStops"] = new int(undeliveredStops);
}

int *GMRoute::getRedeliveredStops() const
{
    return objInt["redeliveredStops"];
}

void GMRoute::setRedeliveredStops(int redeliveredStops)
{
    if(objInt["redeliveredStops"])
        *objInt["redeliveredStops"] = redeliveredStops;
    else
        objInt["redeliveredStops"] = new int(redeliveredStops);
}

int *GMRoute::getActualDepartures() const
{
    return objInt["actualDepartures"];
}


void GMRoute::setActualDepartures(int actualDepartures)
{
    if(objInt["actualDepartures"])
        *objInt["actualDepartures"] = actualDepartures;
    else
        objInt["actualDepartures"] = new int(actualDepartures);

}

QString *GMRoute::getStatus() const
{
    return objQString["status"];
}


void GMRoute::setStatus(const QString &status)
{
    if(objQString["status"])
        *objQString["status"] = status;
    else
        objQString["status"] = new QString(status);

}

int *GMRoute::getActualTravelTimeMinutes() const
{
    return objInt["actualTravelTimeMinutes"];
}

void GMRoute::setActualTravelTimeMinutes(int actualTravelTimeMinutes)
{
    if(objInt["actualTravelTimeMinutes"])
        *objInt["actualTravelTimeMinutes"] = actualTravelTimeMinutes;
    else
        objInt["actualTravelTimeMinutes"] = new int(actualTravelTimeMinutes);
}

int *GMRoute::getPlannedTravelTimeMinutes() const
{
    return objInt["plannedTravelTimeMinutes"];
}

void GMRoute::setPlannedTravelTimeMinutes(int plannedTravelTimeMinutes)
{
    if(objInt["plannedTravelTimeMinutes"])
        *objInt["plannedTravelTimeMinutes"] = plannedTravelTimeMinutes;
    else
        objInt["plannedTravelTimeMinutes"] = new int(plannedTravelTimeMinutes);
}

int *GMRoute::getbaselineTravelTimeMinutes() const
{
    return objInt["baselineTravelTimeMinutes"];
}

void GMRoute::setbaselineTravelTimeMinutes(int baselineTravelTimeMinutes)
{
    if(objInt["baselineTravelTimeMinutes"])
        *objInt["baselineTravelTimeMinutes"] = baselineTravelTimeMinutes;
    else
        objInt["baselineTravelTimeMinutes"] = new int(baselineTravelTimeMinutes);
}

bool *GMRoute::getHasPicture() const
{
    return objBool["hasPicture"];
}

void GMRoute::setHasPicture(bool hasPicture)
{

    if(objBool["hasPicture"])
        *objBool["hasPicture"] = hasPicture;
    else
        objBool["hasPicture"] = new bool(hasPicture);

}

GMOrganization *GMRoute::getOrganization() const
{
    return objGMOrganization["organization"];
}

void GMRoute::setOrganization(const GMOrganization &organization)
{
    if(objGMOrganization["organization"])
        *objGMOrganization["organization"] = organization;
    else
        objGMOrganization["organization"] = new GMOrganization(organization);
}
*/

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

    //    for(auto key : importedMember.keys())
    //        qDebug() << key << "," << importedMember[key];
}

//BEGIN PRIVATE FUNCTIONS

void GMRoute::setImportedMembersFalse()
{
    //this is useful for knowing EXACTLY what was imported
    //from json.
    for(auto t : memberList)
        importedMember[t] = false;
}

void GMRoute::setMembersNull()
{
    for(auto key : objInt.keys())
    {
        delete objInt[key];
        objInt[key] = objIntInit;
    }

    for(auto key : objDouble.keys())
    {
        delete objDouble[key];
        objDouble[key] = objDoubleInit;
    }

    for(auto key : objBool.keys())
    {
        delete objBool[key];
        objBool[key] = objBoolInit;
    }

    for(auto key : objQString.keys())
    {
        delete objQString[key];
        objQString[key] = objQStringInit;
    }

    for(auto key : objQDateTime.keys())
    {
        delete objQDateTime[key];
        objQDateTime[key] = objQDateTimeInit;
    }

    for(auto key : objGMOrganization.keys())
    {
        delete objGMOrganization[key];
        objGMOrganization[key] = objGMOrganizationInit;
    }

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
    {
        if(importedMember[key])
        {
            if(objInt[key])
                *objInt[key] = json[key].toInt();

            else
                objInt[key] = new int(json[key].toInt());
        }
    }

    //import all valid qdatetime keys
    for(auto key : objQDateTime.keys())
    {
        if(importedMember[key])
        {
            if(objQDateTime[key])
                *objQDateTime[key] = QDateTime::fromString
                    (json[key].toString(), Qt::ISODateWithMs);
            else
                objQDateTime[key] = new QDateTime(QDateTime::fromString
                                                  (json[key].toString(), Qt::ISODateWithMs));
        }
    }

    for(auto key : objBool.keys())
    {
        if(importedMember[key])
        {
            if(objBool[key])
                *objBool[key] = json[key].toBool();
            else
                objBool[key] = new bool(json[key].toBool());

        }
    }

    for(auto key : objQString.keys())
    {
        if(importedMember[key])
        {
            if(objQString[key])
                *objQString[key] = json[key].toString();
            else
                objQString[key] = new QString(json[key].toString());
        }
    }

    for(auto key : objQDate.keys())
    {
        if(importedMember[key])
        {
            if(objQDate[key])
                *objQDate[key] = QDate::fromString
                    (json[key].toString(), "yyyy-MM-dd");
            else
                objQDate[key] = new QDate(QDate::fromString
                                          (json[key].toString(), "yyyy-MM-dd"));
        }
    }

    for(auto key : objGMOrganization.keys())
    {
        if(importedMember[key])
        {
            if(objGMOrganization[key])
                objGMOrganization[key]->importJson(json[key].toObject());
            else
            {
                objGMOrganization[key] = new GMOrganization();
                objGMOrganization[key]->importJson(json[key].toObject());
            }
        }
    }
}

//Template example



QJsonObject GMRoute::exportEngine()
{
    QJsonObject json;

    //import all valid int members
    for(auto key : objInt.keys())
        if(importedMember[key] && objInt[key])
            json[key] = *objInt[key];

    //import all valid qdatetime members
    for(auto key : objQDateTime.keys())
        if(importedMember[key] && objQDateTime[key])
            json[key] = objQDateTime[key]->toString(Qt::ISODateWithMs);

    for(auto key : objBool.keys())
        if(importedMember[key] && objBool[key])
            json[key] = *objBool[key];

    for(auto key : objQString.keys())
        if(importedMember[key] && objQString[key])
            json[key] = *objQString[key];

    for(auto key : objQDate.keys())
        if(importedMember[key] && objQDate[key])
            json[key] = objQDate[key]->toString("yyyy-MM-dd");

    for(auto key : objGMOrganization.keys())
        if(importedMember[key] && objGMOrganization[key])
            json[key] = objGMOrganization[key]->exportJson();

    return json;
}
