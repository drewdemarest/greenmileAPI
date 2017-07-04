#include "gmstop.h"
#include "gmroute.h"
#include "gmorder.h"
#include "gmlocation.h"
#include "gmstoptype.h"
#include "gmudfs.h"

GMStop::GMStop()
{
    objInt["id"]                                = objIntInit;
    objInt["baseLineSequenceNum"]               = objIntInit;
    objInt["plannedSequenceNum"]                = objIntInit;
    objInt["actualSequenceNum"]                 = objIntInit;
    objInt["bulkArriveGroup"]                   = objIntInit;
    objInt["arrivalAccuracyMeters"]             = objIntInit;
    objInt["serviceAccuracyMeters"]             = objIntInit;

    objDouble["baseLineDistance"]               = objDoubleInit;
    objDouble["plannedDistance"]                = objDoubleInit;
    objDouble["projectedDistance"]              = objDoubleInit;
    objDouble["actualDistance"]                 = objDoubleInit;
    objDouble["baseLineSize1"]                  = objDoubleInit;
    objDouble["baseLineSize2"]                  = objDoubleInit;
    objDouble["baseLineSize3"]                  = objDoubleInit;
    objDouble["plannedSize1"]                   = objDoubleInit;
    objDouble["plannedSize2"]                   = objDoubleInit;
    objDouble["plannedSize3"]                   = objDoubleInit;
    objDouble["actualSize1"]                    = objDoubleInit;
    objDouble["actualSize2"]                    = objDoubleInit;
    objDouble["actualSize3"]                    = objDoubleInit;
    objDouble["plannedPickupSize1"]             = objDoubleInit;
    objDouble["plannedPickupSize2"]             = objDoubleInit;
    objDouble["plannedPickupSize3"]             = objDoubleInit;
    objDouble["baseLinePickupSize1"]            = objDoubleInit;
    objDouble["baseLinePickupSize2"]            = objDoubleInit;
    objDouble["baseLinePickupSize3"]            = objDoubleInit;
    objDouble["actualPickupSize1"]              = objDoubleInit;
    objDouble["actualPickupSize2"]              = objDoubleInit;
    objDouble["actualPickupSize3"]              = objDoubleInit;
    objDouble["damagedSize1"]                   = objDoubleInit;
    objDouble["damagedSize2"]                   = objDoubleInit;
    objDouble["damagedSize3"]                   = objDoubleInit;

    objFloat["arrivalLatitude"]                 = objFloatInit;
    objFloat["arrivalLongitude"]                = objFloatInit;
    objFloat["serviceLatitude"]                 = objFloatInit;
    objFloat["serviceLongitude"]                = objFloatInit;

    objQString["actualArrivalDataQuality"]      = objQStringInit;
    objQString["actualServiceDataQuality"]      = objQStringInit;
    objQString["actualDepartureDataQuality"]    = objQStringInit;
    objQString["actualDistanceDataQuality"]     = objQStringInit;
    objQString["deliveryReasonCode"]            = objQStringInit;
    objQString["overReasonCode"]                = objQStringInit;
    objQString["shortReasonCode"]               = objQStringInit;
    objQString["damagedReasonCode"]             = objQStringInit;
    objQString["pickupReasonCode"]              = objQStringInit;
    objQString["cancelCode"]                    = objQStringInit;
    objQString["undeliverableCode"]             = objQStringInit;
    objQString["arrivalMobileGpsProvider"]      = objQStringInit;
    objQString["serviceMobileGPSProvider"]      = objQStringInit;
    objQString["signatureFilePath"]             = objQStringInit;
    objQString["stopinstructions"]              = objQStringInit;

    objBool["arrivedInTimeWindow"]              = objBoolInit;
    objBool["hasPicture"]                       = objBoolInit;
    objBool["hasPicture"]                       = objBoolInit;

    objGMRoute["route"]                         = objGMRouteInit;

    objGMOrder["orders"]                        = objGMOrderInit;

    objGMLocation["location"]                   = objGMLocationInit;

    objGMStopType["stopType"]                   = objGMStopTypeInit;

    objGMUdfs["udfs"]                           = objGMUdfsInit;

    objGMStop["redeliveryStop"]                 = objGMStopInit;
    objGMStop["parentRedeliveryStop"]           = objGMStopInit;



    //objGMi18nlocale["i18nlocale"] = objGMi18nlocaleInit;

    memberList << objInt.keys()       << objDouble.keys()
               << objQString.keys()   << objQDate.keys()
               << objBool.keys()      << objQDateTime.keys()
               << objQDateTime.keys() << objGMStop.keys();
}

GMStop::~GMStop()
{
    delete objBoolInit;
    delete objIntInit;
    delete objDoubleInit;
    delete objQStringInit;
    delete objQDateInit;
    delete objQDateTimeInit;

    delete objFloatInit;
    delete objGMRouteInit;
    delete objGMOrderInit;
    delete objGMLocationInit;
    delete objGMStopTypeInit;
    delete objGMUdfsInit;
    delete objGMStopInit;

    qDeleteAll(objInt);
    objInt.clear();

    qDeleteAll(objDouble);
    objDouble.clear();

    qDeleteAll(objFloat);
    objFloat.clear();

    qDeleteAll(objBool);
    objBool.clear();

    qDeleteAll(objQString);
    objQString.clear();

    qDeleteAll(objQDate);
    objQDate.clear();

    qDeleteAll(objQDateTime);
    objQDateTime.clear();

    qDeleteAll(objFloat);
    objFloat.clear();

    qDeleteAll(objGMRoute);
    objGMRoute.clear();

    qDeleteAll(objGMOrder);
    objGMOrder.clear();

    qDeleteAll(objGMLocation);
    objGMLocation.clear();

    qDeleteAll(objGMStopType);
    objGMStopType.clear();

    qDeleteAll(objGMUdfs);
    objGMUdfs.clear();

    qDeleteAll(objFloat);
    objFloat.clear();

    qDeleteAll(objGMStop);
    objGMStop.clear();
}

/*
int *GMStop::getId() const
{
    return objInt["id"];
}

void GMStop::setId(int id)
{
    if(objInt["id"])
        *objInt["id"] = id;
    else
        objInt["id"] = new int(id);
}

QString *GMStop::getKey() const
{
    return objQString["key"];
}

void GMStop::setKey(QString &key)
{
    if(objQString["key"])
        *objQString["key"] = key;
    else
        objQString["key"] = new QString(key);
}

GMRoute *GMStop::getRoute() const
{
    return objGMRoute["route"];
}

void GMStop::setRoute(GMRoute &route)
{
    if(objGMRoute["route"])
        *objGMRoute["route"] = route;
    else
        objGMRoute["route"] = new GMRoute(route);
}

GMOrder *GMStop::getOrder() const
{
    return objGMOrder["order"];
}

void GMStop::setOrder(GMOrder &order)
{
    if(objGMOrder["order"])
        *objGMOrder["order"] = order;
    else
        objGMOrder["order"] = new GMOrder(order);
}

GMLocation *GMStop::getLocation() const
{
    return objGMLocation["location"];
}

void GMStop::setLocation(GMLocation &location)
{
    if(objGMLocation["location"])
        *objGMLocation["location"] = location;
    else
        objGMLocation["location"] = new GMLocation(location);
}

int *GMStop::getBaseLineSequenceNum() const
{
    return objInt["baseLineSequenceNum"];
}

void GMStop::setBaseLineSequenceNum(int baseLineSequenceNum)
{
    if(objInt["baseLineSequenceNum"])
        *objInt["baseLineSequenceNum"] = baseLineSequenceNum;
    else
        objInt["baseLineSequenceNum"] = new int(baseLineSequenceNum);
}

int *GMStop::getPlannedSequenceNum() const
{
    return objInt["plannedSequenceNum"];
}

void GMStop::setPlannedSequenceNum(int plannedSequenceNum)
{
    if(objInt["plannedSequenceNum"])
        *objInt["plannedSequenceNum"] = plannedSequenceNum;
    else
        objInt["plannedSequenceNum"] = new int(plannedSequenceNum);
}

int *GMStop::getActualSequenceNum() const
{
    return objInt["actualSequenceNum"];
}

void GMStop::setActualSequenceNum(int actualSequenceNum)
{
    if(objInt["actualSequenceNum"])
        *objInt["actualSequenceNum"] = actualSequenceNum;
    else
        objInt["actualSequenceNum"] = new int(actualSequenceNum);
}

GMStopType *GMStop::getStopType() const
{
    return objGMStopType["stopType"];
}

void GMStop::setStopType(GMStopType &stopType)
{
    if(objGMStopType["stopType"])
        *objGMStopType["stopType"] = stopType;
    else
        objGMStopType["stopType"] = new GMStopType(stopType);
}

GMUdfs *GMStop::getUdfs() const
{
    return objGMUdfs["udfs"];
}

void GMStop::setUdfs(GMUdfs &udfs)
{
    if(objGMUdfs["udfs"])
        *objGMUdfs["udfs"] = udfs;
    else
        objGMUdfs["udfs"] = new GMUdfs(udfs);
}

QDateTime *GMStop::getBaseLineArrival() const
{
    return objQDateTime["baseLineArrival"];
}

void GMStop::setBaseLineArrival(QDateTime &baseLineArrival)
{
    if(objQDateTime["baseLineArrival"])
        *objQDateTime["baseLineArrival"] = baseLineArrival;
    else
        objQDateTime["baseLineArrival"] = new QDateTime(baseLineArrival);
}

QDateTime *GMStop::getPlannedArrival() const
{
    return objQDateTime["plannedArrival"];
}

void GMStop::setPlannedArrival(QDateTime &plannedArrival)
{
    if(objQDateTime["plannedArrival"])
        *objQDateTime["plannedArrival"] = plannedArrival;
    else
        objQDateTime["plannedArrival"] = new QDateTime(plannedArrival);
}

QDateTime *GMStop::getPlannedDeparture() const
{
    return objQDateTime["plannedDeparture"];
}

void GMStop::setPlannedDeparture(QDateTime &plannedDeparture)
{
    if(objQDateTime["plannedDeparture"])
        *objQDateTime["plannedDeparture"] = plannedDeparture;
    else
        objQDateTime["plannedDeparture"] = new QDateTime(plannedDeparture);
}

QDateTime *GMStop::getProjectedArrival() const
{
    return objQDateTime["projectedArrival"];
}

void GMStop::setProjectedArrival(QDateTime &projectedArrival)
{
    if(objQDateTime["projectedArrival"])
        *objQDateTime["projectedArrival"] = projectedArrival;
    else
        objQDateTime["projectedArrival"] = new QDateTime(projectedArrival);
}

QDateTime *GMStop::getProjectedDeparture() const
{
    return objQDateTime["projectedDeparture"];
}

void GMStop::setProjectedDeparture(QDateTime &projectedDeparture)
{
    if(objQDateTime["projectedDeparture"])
        *objQDateTime["projectedDeparture"] = projectedDeparture;
    else
        objQDateTime["projectedDeparture"] = new QDateTime(projectedDeparture);
}

QDateTime *GMStop::getActualArrival() const
{
    return objQDateTime["actualArrival"];
}

void GMStop::setActualArrival(QDateTime &actualArrival)
{
    if(objQDateTime["actualArrival"])
        *objQDateTime["actualArrival"] = actualArrival;
    else
        objQDateTime["actualArrival"] = new QDateTime(actualArrival);
}

double *GMStop::getBaseLineDistance() const
{
    return objDouble["baseLineDistance"];
}

void GMStop::setBaseLineDistance(double baseLineDistance)
{
    if(objDouble["baseLineDistance"])
        *objDouble["baseLineDistance"] = baseLineDistance;
    else
        objDouble["baseLineDistance"] = new double(baseLineDistance);
}

double *GMStop::getPlannedDistance() const
{
    return objDouble["baseLineDistance"];
}

void GMStop::setPlannedDistance(double plannedDistance)
{
    if(objDouble["plannedDistance"])
        *objDouble["plannedDistance"] = plannedDistance;
    else
        objDouble["plannedDistance"] = new double(plannedDistance);
}

double *GMStop::getProjectedDistance() const
{
    return objDouble["projectedDistance"];
}

void GMStop::setProjectedDistance(double projectedDistance)
{
    if(objDouble["projectedDistance"])
        *objDouble["projectedDistance"] = projectedDistance;
    else
        objDouble["projectedDistance"] = new double(projectedDistance);
}

double *GMStop::getActualDistance() const
{
    return objDouble["actualDistance"];
}

void GMStop::setActualDistance(double actualDistance)
{
    if(objDouble["actualDistance"])
        *objDouble["actualDistance"] = actualDistance;
    else
        objDouble["actualDistance"] = new double(actualDistance);
}

QString *GMStop::getActualArrivalDataQuality() const
{
        return objQString["actualArrivalDataQuality"];
}

void GMStop::setActualArrivalDataQuality(QString &actualArrivalDataQuality)
{
    if(objQString["actualArrivalDataQuality"])
        *objQString["actualArrivalDataQuality"] = actualArrivalDataQuality;
    else
        objQString["actualArrivalDataQuality"] = new QString(actualArrivalDataQuality);
}

QString *GMStop::getServiceDataQuality() const
{
    return objQString["serviceDataQuality"];
}

void GMStop::setServiceDataQuality(QString &serviceDataQuality)
{
    if(objQString["serviceDataQuality"])
        *objQString["serviceDataQuality"] = serviceDataQuality;
    else
        objQString["serviceDataQuality"] = new QString(serviceDataQuality);
}

QString *GMStop::getActualDepartureQuality() const
{
    return objQString["actualDepartureQuality"];
}

void GMStop::setActualDepartureQuality(QString &actualDepartureQuality)
{
    if(objQString["actualDepartureQuality"])
        *objQString["actualDepartureQuality"] = actualDepartureQuality;
    else
        objQString["actualDepartureQuality"] = new QString(actualDepartureQuality);
}

QString *GMStop::getActualDistanceQuality() const
{
    return objQString["actualDistanceQuality"];
}

void GMStop::setActualDistanceQuality(QString &actualDistanceQuality)
{
    if(objQString["actualDistanceQuality"])
        *objQString["actualDistanceQuality"] = actualDistanceQuality;
    else
        objQString["actualDistanceQuality"] = new QString(actualDistanceQuality);
}

double *GMStop::getBaseLineSize1() const
{
    return objDouble["baseLineSize1"];
}

void GMStop::setBaseLineSize1(double baseLineSize1)
{
    if(objDouble["baseLineSize1"])
        *objDouble["baseLineSize1"] = baseLineSize1;
    else
        objDouble["baseLineSize1"] = new double(baseLineSize1);
}

double *GMStop::getBaseLineSize2() const
{
    return objDouble["baseLineSize2"];
}

void GMStop::setBaseLineSize2(double baseLineSize2)
{
    if(objDouble["baseLineSize2"])
        *objDouble["baseLineSize2"] = baseLineSize2;
    else
        objDouble["baseLineSize2"] = new double(baseLineSize2);
}

double *GMStop::getBaseLineSize3() const
{
    return objDouble["baseLineSize3"];
}

void GMStop::setBaseLineSize3(double baseLineSize3)
{
    if(objDouble["baseLineSize3"])
        *objDouble["baseLineSize3"] = baseLineSize3;
    else
        objDouble["baseLineSize3"] = new double(baseLineSize3);
}

double *GMStop::getPlannedSize1() const
{
    return objDouble["plannedLineSize1"];
}

void GMStop::setPlannedSize1(double plannedLineSize1)
{
    if(objDouble["plannedLineSize1"])
        *objDouble["plannedLineSize1"] = plannedLineSize1;
    else
        objDouble["plannedLineSize1"] = new double(plannedLineSize1);
}

double *GMStop::getPlannedSize2() const
{
    return objDouble["baseLineSize2"];
}

void GMStop::setPlannedSize2(double baseLineSize2)
{
    if(objDouble["baseLineSize2"])
        *objDouble["baseLineSize2"] = baseLineSize2;
    else
        objDouble["baseLineSize2"] = new double(baseLineSize2);
}

double *GMStop::getPlannedSize3() const
{
    return objDouble["baseLineSize3"];
}

void GMStop::setPlannedSize3(double baseLineSize3)
{
    if(objDouble["baseLineSize3"])
        *objDouble["baseLineSize3"] = baseLineSize3;
    else
        objDouble["baseLineSize3"] = new double(baseLineSize3);
}

double *GMStop::getBaseLinePickupSize1() const
{
    return objDouble["baseLinePickupSize1"];
}

void GMStop::setBaseLinePickupSize1(double baseLinePickupSize1)
{
    if(objDouble["baseLinePickupSize1"])
        *objDouble["baseLinePickupSize1"] = baseLinePickupSize1;
    else
        objDouble["baseLinePickupSize1"] = new double(baseLinePickupSize1);
}

double *GMStop::getBaseLinePickupSize2() const
{
    return objDouble["baseLinePickupSize2"];
}

void GMStop::setBaseLinePickupSize2(double baseLinePickupSize2)
{
    if(objDouble["baseLinePickupSize2"])
        *objDouble["baseLinePickupSize2"] = baseLinePickupSize2;
    else
        objDouble["baseLinePickupSize2"] = new double(baseLinePickupSize2);
}

double *GMStop::getBaseLinePickupSize3() const
{
    return objDouble["baseLinePickupSize3"];
}

void GMStop::setBaseLinePickupSize3(double baseLinePickupSize3)
{
    if(objDouble["baseLinePickupSize3"])
        *objDouble["baseLinePickupSize3"] = baseLinePickupSize3;
    else
        objDouble["baseLinePickupSize3"] = new double(baseLinePickupSize3);
}

double *GMStop::getActualPickupSize1() const
{
    return objDouble["actualPickupSize1"];
}

void GMStop::setActualPickupSize(double actualPickupSize1)
{
    if(objDouble["actualPickupSize1"])
        *objDouble["actualPickupSize1"] = actualPickupSize1;
    else
        objDouble["actualPickupSize1"] = new double(actualPickupSize1);
}

double *GMStop::getActualPickupSize2() const
{
    return objDouble["actualPickupSize2"];
}

void GMStop::setActualPickupSize2(double actualPickupSize2)
{
    if(objDouble["actualPickupSize2"])
        *objDouble["actualPickupSize2"] = actualPickupSize2;
    else
        objDouble["actualPickupSize2"] = new double(actualPickupSize2);
}

double *GMStop::getActualPickupSize3() const
{
    return objDouble["actualPickupSize3"];
}

void GMStop::actualPickupSize3(double actualPickupSize3)
{
    if(objDouble["actualPickupSize3"])
        *objDouble["actualPickupSize3"] = actualPickupSize3;
    else
        objDouble["actualPickupSize3"] = new double(actualPickupSize3);
}

double *GMStop::getDamagedSize1() const
{
    return objDouble["damagedSize1"];
}

void GMStop::setDamagedSize1(double damagedSize1)
{
    if(objDouble["damagedSize1"])
        *objDouble["damagedSize1"] = damagedSize1;
    else
        objDouble["damagedSize1"] = new double(damagedSize1);
}

double *GMStop::getDamagedSize2() const
{
    return objDouble["damagedSize2"];
}

void GMStop::setDamagedSize2(double damagedSize2)
{
    if(objDouble["damagedSize2"])
        *objDouble["damagedSize2"] = damagedSize2;
    else
        objDouble["damagedSize2"] = new double(damagedSize2);
}

double *GMStop::getDamagedSize3() const
{
    return objDouble["damagedSize3"];
}

void GMStop::setDamagedSize3(double damagedSize3)
{
    if(objDouble["damagedSize3"])
        *objDouble["damagedSize3"] = damagedSize3;
    else
        objDouble["damagedSize3"] = new double(damagedSize3);
}

double *GMStop::getBaselineServiceTime() const
{
    return objDouble["baselineServiceTime"];
}

void GMStop::setBaselineServiceTime(double baselineServiceTime)
{
    if(objDouble["baselineServiceTime"])
        *objDouble["baselineServiceTime"] = baselineServiceTime;
    else
        objDouble["baselineServiceTime"] = new double(baselineServiceTime);
}

double *GMStop::getProjectedServiceTime() const
{
    return objDouble["projectedServiceTime"];
}

void GMStop::setProjectedServiceTime(double projectedServiceTime)
{
    if(objDouble["projectedServiceTime"])
        *objDouble["projectedServiceTime"] = projectedServiceTime;
    else
        objDouble["projectedServiceTime"] = new double(projectedServiceTime);
}

double *GMStop::getPlannedServiceTime() const
{
    return objDouble["plannedServiceTime"];
}

void GMStop::setPlannedServiceTime(double plannedServiceTime)
{
    if(objDouble["plannedServiceTime"])
        *objDouble["plannedServiceTime"] = plannedServiceTime;
    else
        objDouble["plannedServiceTime"] = new double(plannedServiceTime);
}

double *GMStop::getActualServiceTime() const
{
    return objDouble["actualServiceTime"];
}

void GMStop::setActualServiceTIme(double actualServiceTime)
{
    if(objDouble["actualServiceTime"])
        *objDouble["actualServiceTime"] = actualServiceTime;
    else
        objDouble["actualServiceTime"] = new double(actualServiceTime);
}

int *GMStop::getBulkArriveGroup() const
{
    return objInt["bulkArriveGroup"];
}

void GMStop::setBulkArriveGroup(int bulkArriveGroup)
{
    if(objInt["bulkArriveGroup"])
        *objInt["bulkArriveGroup"] = bulkArriveGroup;
    else
        objInt["bulkArriveGroup"] = new int(bulkArriveGroup);
}

QString *GMStop::getDeliveryReasonCode() const
{
    return objQString["deliveryReasonCode"];
}

void GMStop::setDeliveryReasonCode(QString &deliveryReasonCode)
{
    if(objQString["deliveryReasonCode"])
        *objQString["deliveryReasonCode"] = deliveryReasonCode;
    else
        objQString["deliveryReasonCode"] = new QString(deliveryReasonCode);
}

QString *GMStop::getOverReasonCode() const
{
    return objQString["overReasonCode"];
}

void GMStop::setOverReasonCode(QString &overReasonCode)
{
    if(objQString["overReasonCode"])
        *objQString["overReasonCode"] = overReasonCode;
    else
        objQString["overReasonCode"] = new QString(overReasonCode);
}

QString *GMStop::getShortReasonCode() const
{
    return objQString["shortReasonCode"];
}

void GMStop::setShortReasonCode(QString &shortReasonCode)
{
    if(objQString["shortReasonCode"])
        *objQString["shortReasonCode"] = shortReasonCode;
    else
        objQString["shortReasonCode"] = new QString(shortReasonCode);
}

QString *GMStop::getDamagedReasonCode() const
{
    return objQString["damagedReasonCode"];
}

void GMStop::setDamagedReasonCode(QString &damagedReasonCode)
{
    if(objQString["damagedReasonCode"])
        *objQString["damagedReasonCode"] = damagedReasonCode;
    else
        objQString["damagedReasonCode"] = new QString(damagedReasonCode);
}

QString *GMStop::getPickupReasonCode() const
{
    return objQString["pickupReasonCode"];
}

void GMStop::setPickupReasonCode(QString &pickupReasonCode)
{
    if(objQString["pickupReasonCode"])
        *objQString["pickupReasonCode"] = pickupReasonCode;
    else
        objQString["pickupReasonCode"] = new QString(pickupReasonCode);
}

QString *GMStop::getCancelCode() const
{
    return objQString["cancelCode"];
}

void GMStop::setCancelCode(QString &cancelCode)
{
    if(objQString["cancelCode"])
        *objQString["cancelCode"] = cancelCode;
    else
        objQString["cancelCode"] = new QString(cancelCode);
}

QString *GMStop::getUndeliverableCode() const
{
    return objQString["undeliverableCode"];
}

void GMStop::setUndeliverableCode(QString &undeliverableCode)
{
    if(objQString["undeliverableCode"])
        *objQString["undeliverableCode"] = undeliverableCode;
    else
        objQString["undeliverableCode"] = new QString(undeliverableCode);
}

GMStop *GMStop::getRedeliveryStop() const
{
    return objGMStop["redeliveryStop"];
}

void GMStop::setRedeliveryStop(GMStop &redeliveryStop)
{
    if(objGMStop["redeliveryStop"])
        *objGMStop["redeliveryStop"] = redeliveryStop;
    else
        objGMStop["redeliveryStop"] = new GMStop(redeliveryStop);
}

GMStop *GMStop::getParentRedeliveryStop() const
{
    return objGMStop["parentRedeliveryStop"];
}

void GMStop::setParentRedeliveryStop(GMStop &parentRedeliveryStop)
{
    if(objGMStop["parentRedeliveryStop"])
        *objGMStop["parentRedeliveryStop"] = parentRedeliveryStop;
    else
        objGMStop["parentRedeliveryStop"] = new GMStop(parentRedeliveryStop);
}

float *GMStop::getArrivalLatitude() const
{
    return objFloat["arrivalLatitude"];
}

void GMStop::setArrivalLatitude(float arrivalLatitude)
{
    if(objFloat["arrivalLatitude"])
        *objFloat["arrivalLatitude"] = arrivalLatitude;
    else
        objFloat["arrivalLatitude"] = new float(arrivalLatitude);
}

float *GMStop::getArrivalLongitude() const
{
    return objFloat["arrivalLongitiude"];
}

void GMStop::setArrivalLongitude(float arrivalLongitiude)
{
    if(objFloat["arrivalLongitiude"])
        *objFloat["arrivalLongitiude"] = arrivalLongitiude;
    else
        objFloat["arrivalLongitiude"] = new float(arrivalLongitiude);
}

QString *GMStop::getArrivalMobileGpsProvider()
{
    return objQString["arrivalMobileGpsProvider"];
}

void GMStop::setArrivalMobileGpsProvider(QString &arrivalMobileGpsProvider)
{
    if(objQString["arrivalMobileGpsProvider"])
        *objQString["arrivalMobileGpsProvider"] = arrivalMobileGpsProvider;
    else
        objQString["arrivalMobileGpsProvider"] = new QString(arrivalMobileGpsProvider);
}

int *GMStop::getArrivalAccuracyMeters() const
{
    return objInt["arrivalAccuracyMeters"];
}

void GMStop::setArrivalAccuracyMeters(int arrivalAccuracyMeters)
{
    if(objInt["arrivalAccuracyMeters"])
        *objInt["arrivalAccuracyMeters"] = arrivalAccuracyMeters;
    else
        objInt["arrivalAccuracyMeters"] = new int(arrivalAccuracyMeters);
}

bool *GMStop::getArrivedInTimeWindow() const
{
    return objBool["arrivedInTimeWindow"];
}

void GMStop::setArrivedInTimeWindow(bool arrivedInTimeWindow)
{
    if(objBool["arrivedInTimeWindow"])
        *objBool["arrivedInTimeWindow"] = arrivedInTimeWindow;
    else
        objBool["arrivedInTimeWindow"] = new bool(arrivedInTimeWindow);
}

float *GMStop::getServiceLatitude() const
{
    return objFloat["serviceLatitude"];
}

void GMStop::setServiceLatitude(float serviceLatitude)
{
    if(objFloat["serviceLatitude"])
        *objFloat["serviceLatitude"] = serviceLatitude;
    else
        objFloat["serviceLatitude"] = new float(serviceLatitude);
}

int *GMStop::getServiceAccuracyMeters() const
{
    return objInt["serviceAccuracyMeters"];
}

void GMStop::setServiceAccuracyMeters(int serviceAccuracyMeters)
{
    if(objInt["serviceAccuracyMeters"])
        *objInt["serviceAccuracyMeters"] = serviceAccuracyMeters;
    else
        objInt["serviceAccuracyMeters"] = new int(serviceAccuracyMeters);
}

QString *GMStop::getServiceMobileGPSProvider() const
{
    return objQString["serviceMobileGPSProvider"];
}

void GMStop::setServiceMobileGPSProvider(QString &serviceMobileGPSProvider)
{
    if(objQString["serviceMobileGPSProvider"])
        *objQString["serviceMobileGPSProvider"] = serviceMobileGPSProvider;
    else
        objQString["serviceMobileGPSProvider"] = new QString(serviceMobileGPSProvider);
}

QString *GMStop::getStopinstructions() const
{
    return objQString["stopinstructions"];
}

void GMStop::setStopinstructions(QString &stopinstructions)
{
    if(objQString["stopinstructions"])
        *objQString["stopinstructions"] = stopinstructions;
    else
        objQString["stopinstructions"] = new QString(stopinstructions);
}

float *GMStop::getServiceLongitude() const
{
    return objFloat["serviceLongitude"];
}

void GMStop::setServiceLongitude(int serviceLongitude)
{
    if(objFloat["serviceLongitude"])
        *objFloat["serviceLongitude"] = serviceLongitude;
    else
        objFloat["serviceLongitude"] = new float(serviceLongitude);
}

bool *GMStop::getHasPicture() const
{
    return objBool["hasPicture"];

}

void GMStop::setHasPicture(bool hasPicture)
{
    if(objBool["hasPicture"])
        *objBool["hasPicture"] = hasPicture;
    else
        objBool["hasPicture"] = new bool(hasPicture);
}

bool *GMStop::getHasSignature() const
{
    return objBool["hasSignature"];
}

void GMStop::setHasSignature(bool hasSignature)
{
    if(objBool["hasSignature"])
        *objBool["hasSignature"] = hasSignature;
    else
        objBool["hasSignature"] = new bool(hasSignature);
}

QString *GMStop::getSignatureFilePath() const
{
    return objQString["signatureFilePath"];
}

void GMStop::setSignatureFilePath(QString &signatureFilePath)
{
    if(objQString["signatureFilePath"])
        *objQString["signatureFilePath"] = signatureFilePath;
    else
        objQString["signatureFilePath"] = new QString(signatureFilePath);
}
*/

void GMStop::importJson(const QJsonObject &json)
{

}

void GMStop::appendJson(const QJsonObject &json)
{

}

QJsonObject GMStop::exportJson()
{

}

void GMStop::setMembersNull()
{

}

void GMStop::compareJson(const QJsonObject &json)
{

}

void GMStop::setImportedMembersFalse()
{

}

QJsonObject GMStop::exportEngine()
{

}

void GMStop::importEngine(const QJsonObject &json)
{

}




