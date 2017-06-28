#include "gmorganization.h"

GMOrganization::GMOrganization()
{
    objInt["id"]                            = objIntInit;
    objQDateTime["creationDate"]            = objQDateTimeInit;
    objQDateTime["lastModificationDate"]    = objQDateTimeInit;
    objQString["lastModifierAddress"]       = objQStringInit;
    objQString["key"]                       = objQStringInit;
    objQString["description"]               = objQStringInit;
    objGMOrganization["parentOrganization"] = objGMOrganizationInit;

    //objGMi18nlocale["i18nlocale"] = objGMi18nlocaleInit;

    memberList << objInt.keys()       << objDouble.keys()
               << objQString.keys()   << objQDate.keys()
               << objBool.keys()      << objQDateTime.keys()
               << objQDateTime.keys() << objGMOrganization.keys();
}

int *GMOrganization::getId() const
{
    return objInt["id"];
}

void GMOrganization::setId(int id)
{
    if(objInt["id"])
        *objInt["id"] = id;
    else
        objInt["id"] = new int(id);
}

QDateTime *GMOrganization::getCreationDate() const
{
    return objQDateTime["creationDate"];
}
void GMOrganization::setCreationDate(const QDateTime &creationDate)
{
    if(objQDateTime["creationDate"])
        *objQDateTime["creationDate"] = creationDate;
    else
        objQDateTime["creationDate"] = new QDateTime(creationDate);
}

QDateTime *GMOrganization::getLastModificationDate() const
{
    return objQDateTime["lastModificationDate"];
}
void GMOrganization::setLastModificationDate(const QDateTime &lastModifcationDate)
{
    if(objQDateTime["lastModifcationDate"])
        *objQDateTime["lastModifcationDate"] = lastModifcationDate;
    else
        objQDateTime["lastModifcationDate"] = new QDateTime(lastModifcationDate);
}

QString *GMOrganization::getKey() const
{
    return objQString["key"];
}

void GMOrganization::setKey(const QString &key)
{
    if(objQString["key"])
        *objQString["key"] = key;
    else
        objQString["key"] = new QString(key);
}

QString *GMOrganization::getDescription() const
{
    return objQString["description"];
}

void GMOrganization::setDescription(const QString &description)
{
    if(objQString["description"])
        *objQString["description"] = description;
    else
        objQString["description"] = new QString(description);
}

QString *GMOrganization::getUnitSystem() const
{
    return objQString["unitSystem"];
}
void GMOrganization::setUnitSystem(const QString &unitSystem)
{
    if(objQString["unitSystem"])
        *objQString["unitSystem"] = unitSystem;
    else
        objQString["unitSystem"] = new QString(unitSystem);
}

GMOrganization *GMOrganization::getParentOrganization() const
{
    return objGMOrganization["organization"];
}

void GMOrganization::setParentOrganization(const GMOrganization &organization)
{
    if(objGMOrganization["organization"])
        *objGMOrganization["organization"] = organization;
    else
        objGMOrganization["organization"] = new GMOrganization(organization);
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

void GMOrganization::setMembersNull()
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

void GMOrganization::importEngine(const QJsonObject &json)
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

QJsonObject GMOrganization::exportEngine()
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
