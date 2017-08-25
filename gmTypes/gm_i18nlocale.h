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

    const QStringList knownKeys
    {
        "key",
        "parentLocale",
        "organizationId",
        "language",
        "country",
        "description",
        "dateFormat",
        "timeFormat",
        "currency",
        "decimalSymbol",
        "degitalGrouping"
    };

    JsonType<int>         key{"Doddle", QVariant(int(10))};
    //GM_I18NLocale                parentLocale
    //GM_Organization              organizationId;
    JsonType<int>         language{"Doodle", QVariant()};
    JsonType<int>         country{"intKey", 10};
    JsonType<int>         description;
    JsonType<int>         dateFormat;
    JsonType<int>         timeFormat;
    JsonType<int>         currency;
    JsonType<int>         decimalSymbol;
    JsonType<int>         digitalGrouping;

    QJsonObject           sonForm;

//    QMap<QString, shared_ptr<QVariant>> testMap
//    {
//        {"Test0", key},
//        {"Test1", language}
//    };
};

#endif // GM_I18NLOCALE_H
