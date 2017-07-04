#include "gmudfs.h"

GMUdfs::GMUdfs()
{
    objQString["value"] = objQStringInit;
    objQString["key"]   = objQStringInit;

    memberList << objQString.keys();
}

GMUdfs::~GMUdfs()
{
    delete objQStringInit;

    qDeleteAll(objQString);
    objQString.clear();
}

void GMUdfs::importJson(const QJsonObject &json)
{
    compareJson(json);
    importEngine(json);
}

void GMUdfs::appendJson(const QJsonObject &json)
{
    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;

    importEngine(json);
}

QJsonObject GMUdfs::exportJson()
{
    return exportEngine();
}

void GMUdfs::setMembersNull()
{
    for(auto key : objQString.keys())
    {
        delete objQString[key];
        objQString[key] = objQStringInit;
    }
}

void GMUdfs::compareJson(const QJsonObject &json)
{
    setImportedMembersFalse();

    for(auto key : json.keys())
        if(importedMember.contains(key))
            importedMember[key] = true;
}

void GMUdfs::setImportedMembersFalse()
{
    for(auto t : memberList)
        importedMember[t] = false;
}

QJsonObject GMUdfs::exportEngine()
{
    QJsonObject json;

    for(auto key : objQString.keys())
        if(importedMember[key] && objQString[key])
            json[key] = *objQString[key];

    return json;
}

void GMUdfs::importEngine(const QJsonObject &json)
{
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
}
