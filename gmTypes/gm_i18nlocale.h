#ifndef GM_I18NLOCALE_H
#define GM_I18NLOCALE_H

#include <jsonTypes/jsonType.hpp>
#include <QtCore>
#include <QJsonObject>
#include <memory>

using namespace std;
class GM_Organization;

class GM_I18NLocale
{


public:
    GM_I18NLocale();
    ~GM_I18NLocale();
private:

//    const QStringList knownKeys
//    {
//        "key",
//        "parentLocale",
//        "organizationId",
//        "language",
//        "country",
//        "description",
//        "dateFormat",
//        "timeFormat",
//        "currency",
//        "decimalSymbol",
//        "degitalGrouping"
//    };

    QString testJson; //= "{\r\n\"id\": 10020,\r\n\"creationDate\": \"2016-05-24T15:09:56+0000\",\r\n\"lastModificationDate\": \"2017-02-28T14:32:45+0000\",\r\n\"lastModifierAddress\": \"174.228.146.0\",\r\n\"key\": \"SEATTLE\",\r\n\"description\": \"SEATTLE\",\r\n\"preferedLocale\": {\r\n\"id\": 10000,\r\n\"key\": \"I18NLocale_en\",\r\n\"language\": \"en\",\r\n\"description\": \"English\",\r\n\"dateFormat\": \"MM/dd/yyyy\",\r\n\"timeFormat\": \"HH:mm\",\r\n\"currency\": \"US$\",\r\n\"decimalSymbol\": \",\",\r\n\"digitalGrouping\": \".\"\r\n},\r\n\"timeZone\": {\r\n\"id\": 10015,\r\n\"description\": \"US/Pacific\",\r\n\"rawOffsetMinutes\": -420,\r\n\"alias\": \"tmzPacificTimeUSCanada\"\r\n},\r\n\"listenerOrganizations\": [],\r\n\"unitSystem\": \"NON_METRIC\",\r\n\"lastModifier\": {\r\n\"id\": 10000\r\n},\r\n\"creator\": {\r\n\"id\": 10003\r\n}\r\n}";
    QJsonDocument         testDoc; //= QJsonDocument::fromJson(testJson.toUtf8());
    QJsonObject           testObj; //= testDoc.object();

    //JsonType<QString>         key{"key", testObj};
    //GM_I18NLocale                parentLocale
    //GM_Organization              organizationId;
//    JsonType<QString>         language{"language"};
//    JsonType<QString>         country{"country"};
//    JsonType<QString>         description{"description"};
//    JsonType<QString>         dateFormat{"dateFromat"};
//    JsonType<QString>         timeFormat{"timeFormat"};
//    JsonType<QString>         currency{"currency"};
//    JsonType<QString>         decimalSymbol{"decimalGrouping"};
//    JsonType<QString>         digitalGrouping{"currency"};

    QJsonObject           jsonForm;

//    QMap<QString, shared_ptr<QVariant>> testMap
//    {
//        {"Test0", key},
//        {"Test1", language}
//    };
    shared_ptr<QString> testPtr = make_shared<QString>(QString("Potato"));
};

#endif // GM_I18NLOCALE_H
