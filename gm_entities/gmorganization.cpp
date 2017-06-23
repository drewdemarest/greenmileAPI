#include "gmorganization.h"

GMOrganization::GMOrganization()
{
    objInt["id"]                            = objIntInit;
    objQDateTime["creationDate"]            = objQDateTimeInit;
    objQDateTime["lastModificationDate"]    = objQDateTimeInit;
    objQString["lastModifierAddress"]       = objQStringInit;
    objQString["key"]                       = objQStringInit;
    objQString["description"]               = objQStringInit;

    //objGMi18nlocale["i18nlocale"] = objGMi18nlocaleInit;

    memberList << objInt.keys()       << objDouble.keys()
               << objQString.keys()   << objQDate.keys()
               << objBool.keys()      << objQDateTime.keys()
               << objQDateTime.keys() << objGMOrganization.keys();
}

int GMOrganization::getId() const
{
    return objInt["id"];
}
void GMOrganization::setId(const int id)
{
    objInt["id"] = id;
}

QDateTime GMOrganization::getCreationDate() const
{
    return objQDateTime["creationDate"];
}
void GMOrganization::setCreationDate(const QDateTime &creationDate)
{
    objQDateTime["creationDate"] = creationDate;
}

QDateTime GMOrganization::getLastModificationDate() const
{
    return objQDateTime["lastModificationDate"];
}
void GMOrganization::setLastModificationDate(const QDateTime &lastModifcationDate)
{
    objQDateTime["lastModifcationDate"] = lastModifcationDate;
}

QString GMOrganization::getKey() const
{
    return objQString["key"];
}
void GMOrganization::setKey(const QString &key)
{
    objQString["key"] = key;
}

QString GMOrganization::getDescription() const
{
    return objQString["description"];
}
void GMOrganization::setDescription(const QString &description)
{
    objQString["description"] = description;
}

QString GMOrganization::getUnitSystem() const
{
    return objQString["unitSystem"];
}
void GMOrganization::setUnitSystem(const QString &unitSystem)
{
    objQString["unitSystem"] = unitSystem;
}

//GMLastModifier getLastModifier() const;
//void setLastModifier(GMLastModifier &lastModifier);

void GMOrganization::importJson(const QJsonObject &json)
{
    compareJson(json);
    importEngine(json);
}

QJsonObject GMOrganization::exportJson()
{
    QJsonObject jTemp = exportEngine();
    return jTemp;
}

void GMOrganization::appendJson(const QJsonObject &json)
{
    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    importEngine(json);
}

void GMOrganization::compareJson(const QJsonObject &json)
{
    setImportedMembersFalse();

    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    for(auto key : importedMember.keys())
        qDebug() << key << "," << importedMember[key];
}

//BEGIN PRIVATE FUNCTIONS

void GMOrganization::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

void GMOrganization::setMembersToDefaults()
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

void GMOrganization::importEngine(const QJsonObject &json)
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
}

QJsonObject GMOrganization::exportEngine()
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

    return json;
}
