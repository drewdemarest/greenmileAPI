#include "routeworker.h"

RouteWorker::RouteWorker() :
    Worker()
{

}

RouteWorker::RouteWorker(int &threadNumberIn) :
    Worker(threadNumberIn)
{

}

RouteWorker::RouteWorker(int &threadNumberIn, QStringList *routeSheetIn) :
    Worker(threadNumberIn),
    routeSheet(routeSheetIn)
{

}

void RouteWorker::process() {

    makeRangeAssignment();

    qDebug() << "This is route worker thread " << threadNumber << " or " << QThread::currentThreadId() <<  " if you prefer and I'm reading list of size "
             << containerSize << " from... " << readFrom << " to " << readTo;

    //finished does not carry an argument. It facilitates easy use of the new signal slot syntax
    GMRoute test;
    QJsonObject jTest;

    QString query = "    {        \"actualArrival\": \"2017-06-21T17:04:15+0000\",        \"actualComplete\": \"2017-06-21T17:08:43+0000\",        \"actualCompleteDataQuality\": \"GEO_COMPUTED\",        \"actualCost\": 189.30522160979876,        \"actualDeparture\": \"2017-06-21T13:59:29+0000\",        \"actualDepartureDataQuality\": \"GEO_COMPUTED\",        \"actualDepartures\": 9,        \"actualDistance\": 11000,        \"actualDistanceDataQuality\": \"GEO_COMPUTED\",        \"actualDistanceRecalculatedAt\": \"2017-06-21T17:13:47+0000\",        \"actualServiceTime\": 11354000,        \"actualSize1\": 210,        \"actualSize2\": 117,        \"actualSize3\": 2295,        \"actualStart\": \"2017-06-21T13:59:29+0000\",        \"actualStartDataQuality\": \"GEO_COMPUTED\",        \"actualTravelTimeMinutes\": 73,        \"baseLineArrival\": \"2017-06-21T16:29:55+0000\",        \"baseLineComplete\": \"2017-06-21T20:00:00+0000\",        \"baseLineCost\": 0,        \"baseLineDeparture\": \"2017-06-21T12:00:00+0000\",        \"baseLineDistance\": 18358.465077168876,        \"baseLineStart\": \"2017-06-21T12:00:00+0000\",        \"baselineServiceTime\": 28800000,        \"baselineTravelTimeMinutes\": 18,        \"canceledStops\": 3,        \"creationDate\": \"2017-06-21T11:34:56+0000\",        \"date\": \"2017-06-21\",        \"description\": \"T-DT7\",        \"destLatitude\": 47.566536,        \"destLongitude\": -122.33265,        \"hasGps\": true,        \"hasHelper\": false,        \"id\": 72594,        \"key\": \"T-DT7\",        \"lastModificationDate\": \"2017-06-21T17:13:27+0000\",        \"lastStopIsDestination\": false,        \"lastUpdatedProjectedTime\": \"2017-06-21T17:13:27+0000\",        \"organization\": {            \"creationDate\": \"2016-05-24T15:09:56+0000\",            \"creator\": {                \"id\": 10003            },            \"description\": \"SEATTLE\",            \"id\": 10020,            \"key\": \"SEATTLE\",            \"lastModificationDate\": \"2017-02-28T14:32:45+0000\",            \"lastModifier\": {                \"id\": 10000            },            \"lastModifierAddress\": \"174.228.146.0\",            \"listenerOrganizations\": null,            \"preferedLocale\": {                \"currency\": \"US$\",                \"dateFormat\": \"MM/dd/yyyy\",                \"decimalSymbol\": \",\",                \"description\": \"English\",                \"digitalGrouping\": \".\",                \"id\": 10000,                \"key\": \"I18NLocale_en\",                \"language\": \"en\",                \"timeFormat\": \"HH:mm\"            },            \"timeZone\": {                \"alias\": \"tmzPacificTimeUSCanada\",                \"description\": \"US/Pacific\",                \"id\": 10015,                \"rawOffsetMinutes\": -420            },            \"unitSystem\": \"NON_METRIC\"        },        \"origLatitude\": 47.566536,        \"origLongitude\": -122.33265,        \"plannedArrival\": \"2017-06-21T16:29:55+0000\",        \"plannedComplete\": \"2017-06-21T20:00:00+0000\",        \"plannedCost\": 297.7034768484654,        \"plannedDeparture\": \"2017-06-21T12:00:00+0000\",        \"plannedDistance\": 10335.49084680573,        \"plannedServiceTime\": 28800000,        \"plannedSize1\": 264,        \"plannedSize2\": 159,        \"plannedSize3\": 3049,        \"plannedStart\": \"2017-06-21T12:00:00+0000\",        \"plannedTravelTimeMinutes\": 66,        \"projectedArrival\": \"2017-06-21T18:06:04+0000\",        \"projectedComplete\": \"2017-06-21T21:36:09+0000\",        \"projectedDeparture\": \"2017-06-21T12:00:00+0000\",        \"projectedDistance\": 15412.865532915766,        \"projectedStart\": \"2017-06-21T12:00:00+0000\",        \"redeliveredStops\": 0,        \"status\": \"COMPLETED\",        \"totalStops\": 12,        \"undeliveredStops\": 0    }";
    jTest = QJsonDocument::fromJson(query.toUtf8()).object();


    test.importJson(jTest);

    QJsonDocument jDoc(test.exportJson());
    QTextStream(out) stdout;
    qDebug() << "hasPicture null? " << (false == test.getHasPicture());
    test.setHasPicture(true);
    test.setHasPicture(false);
    qDebug() << "hasPicture null? " << (false == test.getHasPicture());
    qDebug() << QString(jDoc.toJson(QJsonDocument::Indented));
    out << QString(jDoc.toJson(QJsonDocument::Indented));
    emit routeOutput(route);
    emit finished();
}
