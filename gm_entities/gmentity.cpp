#include "gmentity.h"

GMEntity::GMEntity()
{

}

void GMEntity::read(const QJsonObject &json)
{
    compareJson(json);

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

    //GOrganization org
    //GLocation orgin;
    //GLocation destination;
    //GStop stops;
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    //GRouteHelperAssignment routeHelperAssignments;
}

QJsonObject GMEntity::write()
{
    QJsonObject jTest;
    QJsonDocument jDoc;

    QString query = "{\n        \"actualArrival\": \"2017-06-21T17:04:15+0000\",\n        \"actualComplete\": \"2017-06-21T17:08:43+0000\",\n        \"actualCompleteDataQuality\": \"GEO_COMPUTED\",\n        \"actualCost\": 189.30522160979876,\n        \"actualDeparture\": \"2017-06-21T13:59:29+0000\",\n        \"actualDepartureDataQuality\": \"GEO_COMPUTED\",\n        \"actualDepartures\": 9,\n        \"actualDistance\": 11000,\n        \"actualDistanceDataQuality\": \"GEO_COMPUTED\",\n        \"actualDistanceRecalculatedAt\": \"2017-06-21T17:13:47+0000\",\n        \"actualServiceTime\": 11354000,\n        \"actualSize1\": 210,\n        \"actualSize2\": 117,\n        \"actualSize3\": 2295,\n        \"actualStart\": \"2017-06-21T13:59:29+0000\",\n        \"actualStartDataQuality\": \"GEO_COMPUTED\",\n        \"actualTravelTimeMinutes\": 73,\n        \"baseLineArrival\": \"2017-06-21T16:29:55+0000\",\n        \"baseLineComplete\": \"2017-06-21T20:00:00+0000\",\n        \"baseLineCost\": 0,\n        \"baseLineDeparture\": \"2017-06-21T12:00:00+0000\",\n        \"baseLineDistance\": 18358.465077168876,\n        \"baseLineStart\": \"2017-06-21T12:00:00+0000\",\n        \"baselineServiceTime\": 28800000,\n        \"baselineTravelTimeMinutes\": 18,\n        \"canceledStops\": 3,\n        \"creationDate\": \"2017-06-21T11:34:56+0000\",\n        \"date\": \"2017-06-21\",\n        \"description\": \"T-DT7\",\n        \"destLatitude\": 47.566536,\n        \"destLongitude\": -122.33265,\n        \"hasGps\": true,\n        \"hasHelper\": false,\n        \"id\": 72594,\n        \"key\": \"T-DT7\",\n        \"lastModificationDate\": \"2017-06-21T17:13:27+0000\",\n        \"lastStopIsDestination\": false,\n        \"lastUpdatedProjectedTime\": \"2017-06-21T17:13:27+0000\",\n        \"origLatitude\": 47.566536,\n        \"origLongitude\": -122.33265,\n        \"plannedArrival\": \"2017-06-21T16:29:55+0000\",\n        \"plannedComplete\": \"2017-06-21T20:00:00+0000\",\n        \"plannedCost\": 297.7034768484654,\n        \"plannedDeparture\": \"2017-06-21T12:00:00+0000\",\n        \"plannedDistance\": 10335.49084680573,\n        \"plannedServiceTime\": 28800000,\n        \"plannedSize1\": 264,\n        \"plannedSize2\": 159,\n        \"plannedSize3\": 3049,\n        \"plannedStart\": \"2017-06-21T12:00:00+0000\",\n        \"plannedTravelTimeMinutes\": 66,\n        \"projectedArrival\": \"2017-06-21T18:06:04+0000\",\n        \"projectedComplete\": \"2017-06-21T21:36:09+0000\",\n        \"projectedDeparture\": \"2017-06-21T12:00:00+0000\",\n        \"projectedDistance\": 15412.865532915766,\n        \"projectedStart\": \"2017-06-21T12:00:00+0000\",\n        \"redeliveredStops\": 0,\n        \"status\": \"COMPLETED\",\n        \"totalStops\": 12,\n        \"undeliveredStops\": 0\n    }";
    jTest = jDoc.fromJson(query.toUtf8()).object();
    read(jTest);

    QJsonObject jTemp;

    //import all valid int members
    for(auto key : objInt.keys())
        if(importedMember[key])
            jTemp[key] = objInt[key];

    //import all valid qdatetime members
    for(auto key : objQDateTime.keys())
        if(importedMember[key])
            jTemp[key] = objQDateTime[key].toString(Qt::ISODateWithMs);

    for(auto key : objBool.keys())
        if(importedMember[key])
            jTemp[key] = objBool[key];

    for(auto key : objQString.keys())
        if(importedMember[key])
            jTemp[key] = objQString[key];

    for(auto key : objQDate.keys())
        if(importedMember[key])
            jTemp[key] = objQDate[key].toString("yyyy-MM-dd");

    //BEGIN TEST SECTION

    QDateTime test = QDateTime::fromString
            (jTemp["dateTime"].toString(), Qt::ISODateWithMs);

    test.setTimeSpec(Qt::UTC);

    qDebug() << "TEST DATETIME test WRITE" << test.toLocalTime().toString();

    qDebug() << "TEST DATETIME WRITE" << QDateTime::fromString
                (jTemp["plannedArrival"].toString(),
                Qt::ISODateWithMs).toString();

    qDebug() << "TEST DATE WRITE " << objQDate["date"].toString();

    return jTemp;
}


void GMEntity::compareJson(const QJsonObject &json)
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

void GMEntity::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

void GMEntity::setMembersToDefaults()
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

    //GOrganization org
    //GLocation orgin;
    //GLocation destination;
    //GStop stops;
    //GDriverAssignment driverAssignments;
    //GEquipmentAssignment equipmentAssignments;
    //GRouteHelperAssignment routeHelperAssignments;

}

void GMEntity::append(const QJsonObject &json)
{
    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

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
}
