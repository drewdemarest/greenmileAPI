#include "gmstop.h"


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



    //objGMi18nlocale["i18nlocale"] = objGMi18nlocaleInit;

    memberList << objInt.keys()       << objDouble.keys()
               << objQString.keys()   << objQDate.keys()
               << objBool.keys()      << objQDateTime.keys()
               << objQDateTime.keys();
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
}

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
