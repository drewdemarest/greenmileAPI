#include "gmstoptype.h"
#include "gmorganization.h"

GMStopType::GMStopType()
{
    objInt["id"]                                = objIntInit;

    objQString["key"]                           = objQStringInit;

    objGMOrganization["organization"]           = objGMOrganizationInit;

    objQString["description"]                   = objQStringInit;

    objQString["type"]                          = objQStringInit;

    objBool["locationRequired"]                 = objBoolInit;

    memberList << objInt.keys() << objQString.keys()
               << objGMOrganization.keys() << objQString.keys()
               << objBool.keys();
}

GMStopType::~GMStopType()
{
    delete objBoolInit;
    delete objIntInit;
    delete objQStringInit;
    delete objGMOrganizationInit;

    qDeleteAll(objInt);
    objInt.clear();

    qDeleteAll(objBool);
    objBool.clear();

    qDeleteAll(objQString);
    objQString.clear();

    qDeleteAll(objGMOrganization);
    objGMOrganization.clear();
}

/*
int *GMStopType::getId() const
{
    return objInt["id"];
}

void GMStopType::setId(int id)
{
    if(objInt["id"])
        *objInt["id"] = id;
    else
        objInt["id"] = new int(id);
}

QString *GMStopType::getKey() const
{
    return objQString["key"];
}

void GMStopType::setKey(QString &key)
{
    if(objQString["key"])
        *objQString["key"] = key;
    else
        objQString["key"] = new QString(key);
}

GMOrganization *GMStopType::getOrganization() const
{
    return objGMOrganization["organization"];
}

void GMStopType::setOrganization(const GMOrganization &organization)
{
    if(objGMOrganization["organization"])
        *objGMOrganization["organization"] = organization;
    else
        objGMOrganization["organization"] = new GMOrganization(organization);
}

QString *GMStopType::getDescription() const
{
    return objQString["description"];
}

void GMStopType::setDescription(QString &description)
{
    if(objQString["description"])
        *objQString["description"] = description;
    else
        objQString["description"] = new QString(description);
}

QString *GMStopType::getType() const
{
    return objQString["type"];
}

void GMStopType::setType(QString &type)
{
    if(objQString["type"])
        *objQString["type"] = type;
    else
        objQString["type"] = new QString(type);
}

bool *GMStopType::setLocationRequired() const
{
    return objBool["locationRequired"];
}

void GMStopType::setLocationRequired(bool locationRequired)
{
    if(objBool["locationRequired"])
        *objBool["locationRequired"] = locationRequired;
    else
        objBool["locationRequired"] = new bool(locationRequired);
}
*/

void GMStopType::importJson(const QJsonObject &json)
{
    compareJson(json);
    importEngine(json);
}

void GMStopType::appendJson(const QJsonObject &json)
{
    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    importEngine(json);
}

QJsonObject GMStopType::exportJson()
{
    return exportEngine();
}

void GMStopType::setMembersNull()
{
    for(auto key : objInt.keys())
    {
        delete objInt[key];
        objInt[key] = objIntInit;
    }

    for(auto key : objQString.keys())
    {
        delete objQString[key];
        objQString[key] = objQStringInit;
    }

    for(auto key : objGMOrganization.keys())
    {
        delete objGMOrganization[key];
        objGMOrganization[key] = objGMOrganizationInit;
    }

    for(auto key : objBool.keys())
    {
        delete objBool[key];
        objBool[key] = objBoolInit;
    }
}

void GMStopType::compareJson(const QJsonObject &json)
{
    setImportedMembersFalse();

    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;
}

void GMStopType::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

QJsonObject GMStopType::exportEngine()
{
    QJsonObject json;

    //import all valid int members
    for(auto key : objInt.keys())
        if(importedMember[key] && objInt[key])
            json[key] = *objInt[key];

    for(auto key : objQString.keys())
        if(importedMember[key] && objQString[key])
            json[key] = *objQString[key];

    for(auto key : objGMOrganization.keys())
        if(importedMember[key] && objGMOrganization[key])
            json[key] = objGMOrganization[key]->exportJson();

    for(auto key : objBool.keys())
        if(importedMember[key] && objBool[key])
            json[key] = *objBool[key];

    return json;
}

void GMStopType::importEngine(const QJsonObject &json)
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

    for(auto key : objBool.keys())
    {
        if(importedMember[key])
        {
            if(objBool[key])
                *objBool[key] = json[key].toBool();
            else
            {
                objBool[key] = new bool(json[key].toBool());
            }
        }
    }
}
