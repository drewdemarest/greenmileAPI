#include "gmi18nlocale.h"
#include "gmorganization.h"

GMI18NLocale::GMI18NLocale()
{
    objInt["id"]                            = objIntInit;

    objQString["key"]                       = objQStringInit;
    objQString["language"]                  = objQStringInit;
    objQString["country"]                   = objQStringInit;
    objQString["description"]               = objQStringInit;
    objQString["dateformat"]                = objQStringInit;
    objQString["timeformat"]                = objQStringInit;
    objQString["currency"]                  = objQStringInit;
    objQString["decimalsymbol"]             = objQStringInit;
    objQString["digitalgrouping"]           = objQStringInit;

    objGMI18NLocale["parentlocaleid"]       = objGMI18NLocaleInit;

    objGMOrganization["organizationid"]     = objGMOrganizationInit;

    memberList << objInt.keys()             << objQString.keys()
               << objGMOrganization.keys()  << objGMI18NLocale.keys();

}

GMI18NLocale::~GMI18NLocale()
{
    delete objIntInit;
    delete objQStringInit;
    delete objGMOrganizationInit;
    delete objGMI18NLocaleInit;

    qDeleteAll(objInt);
    objInt.clear();

    qDeleteAll(objQString);
    objQString.clear();

    qDeleteAll(objGMOrganization);
    objGMOrganization.clear();

    qDeleteAll(objGMI18NLocale);
    objGMI18NLocale.clear();
}


int *GMI18NLocale::getId() const
{
    return objInt["id"];
}

void GMI18NLocale::setId(int id)
{
    if(objInt["id"])
        *objInt["id"] = id;
    else
        objInt["id"] = new int(id);
}

QString *GMI18NLocale::getKey() const
{
    return objQString["key"];
}

void GMI18NLocale::setKey(const QString &key)
{
    if(objQString["key"])
        *objQString["key"] = key;
    else
        objQString["key"] = new QString(key);
}

GMI18NLocale *GMI18NLocale::getParentLocaleId() const
{
    return objGMI18NLocale["parentLocaleid"];
}

void GMI18NLocale::setKey(const GMI18NLocale &parentLocaleid)
{
    if(objGMI18NLocale["parentLocaleid"])
        *objGMI18NLocale["parentLocaleid"] = parentLocaleid;
    else
        objGMI18NLocale["parentLocaleid"] = new GMI18NLocale(parentLocaleid);
}

GMOrganization *GMI18NLocale::getOrganizationId() const
{
    return objGMOrganization["organizationid"];
}

void GMI18NLocale::setOrganizationID(const GMOrganization &organizationid)
{
    if(objGMOrganization["organizationid"])
        *objGMOrganization["organizationid"] = organizationid;
    else
        objGMOrganization["organizationid"] = new GMOrganization(organizationid);
}

QString *GMI18NLocale::getLanguage() const
{
    return objQString["key"];
}

void GMI18NLocale::setLanguage(const QString &language)
{
    if(objQString["language"])
        *objQString["language"] = language;
    else
        objQString["language"] = new QString(language);
}

QString *GMI18NLocale::getCountry() const
{
    return objQString["key"];
}

void GMI18NLocale::setCountry(const QString &country)
{
    if(objQString["country"])
        *objQString["country"] = country;
    else
        objQString["country"] = new QString(country);
}

QString *GMI18NLocale::getDescription() const
{
    return objQString["description"];
}

void GMI18NLocale::setDescription(const QString &description)
{
    if(objQString["description"])
        *objQString["description"] = description;
    else
        objQString["description"] = new QString(description);
}

QString *GMI18NLocale::getDateFormat() const
{
    return objQString["dateformat"];
}

void GMI18NLocale::setDateFormat(const QString &dateformat)
{
    if(objQString["dateformat"])
        *objQString["dateformat"] = dateformat;
    else
        objQString["dateformat"] = new QString(dateformat);
}

QString *GMI18NLocale::getTimeFormat() const
{
    return objQString["timeformat"];
}

void GMI18NLocale::setTimeFormat(const QString &timeformat)
{
    if(objQString["timeformat"])
        *objQString["timeformat"] = timeformat;
    else
        objQString["timeformat"] = new QString(timeformat);
}

QString *GMI18NLocale::getCurrency() const
{
    return objQString["currency"];
}

void GMI18NLocale::setCurrency(const QString &currency)
{
    if(objQString["currency"])
        *objQString["currency"] = currency;
    else
        objQString["currency"] = new QString(currency);
}

QString *GMI18NLocale::getDecimalSymbol() const
{
    return objQString["decimalsymbol"];
}

void GMI18NLocale::setDecimalSymbol(const QString &decimalsymbol)
{
    if(objQString["decimalsymbol"])
        *objQString["decimalsymbol"] = decimalsymbol;
    else
        objQString["decimalsymbol"] = new QString(decimalsymbol);
}

QString *GMI18NLocale::getDigitalGrouping() const
{
    return objQString["digitalgrouping"];
}

void GMI18NLocale::setDigitalGrouping(const QString &digitalgrouping)
{
    if(objQString["digitalgrouping"])
        *objQString["digitalgrouping"] = digitalgrouping;
    else
        objQString["digitalgrouping"] = new QString(digitalgrouping);
}

void GMI18NLocale::importJson(const QJsonObject &json)
{
    compareJson(json);
    importEngine(json);
}

void GMI18NLocale::appendJson(const QJsonObject &json)
{
    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    importEngine(json);
}

QJsonObject GMI18NLocale::exportJson()
{
    return exportEngine();
}

void GMI18NLocale::compareJson(const QJsonObject &json)
{
    setImportedMembersFalse();

    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;
}

void GMI18NLocale::setMembersNull()
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

    for(auto key : objGMI18NLocale.keys())
    {
        delete objGMI18NLocale[key];
        objGMI18NLocale[key] = objGMI18NLocaleInit;
    }
}

void GMI18NLocale::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

QJsonObject GMI18NLocale::exportEngine()
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

    for(auto key : objGMI18NLocale.keys())
        if(importedMember[key] && objGMI18NLocale[key])
            json[key] = objGMI18NLocale[key]->exportJson();

    return json;
}

void GMI18NLocale::importEngine(const QJsonObject &json)
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

    for(auto key : objGMI18NLocale.keys())
    {
        if(importedMember[key])
        {
            if(objGMI18NLocale[key])
                objGMI18NLocale[key]->importJson(json[key].toObject());
            else
            {
                objGMI18NLocale[key] = new GMI18NLocale();
                objGMI18NLocale[key]->importJson(json[key].toObject());
            }
        }
    }
}


