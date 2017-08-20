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

    shared_ptr<QVariant>         key = make_shared<QVariant>();
    unique_ptr<GM_I18NLocale>    parentLocale;
    unique_ptr<GM_Organization> organizationId;
    shared_ptr<QVariant>         language;
    unique_ptr<QVariant>         country;
    unique_ptr<QVariant>         description;
    unique_ptr<QVariant>         dateFormat;
    unique_ptr<QVariant>         timeFormat;
    unique_ptr<QVariant>         currency;
    unique_ptr<QVariant>         decimalSymbol;
    unique_ptr<QVariant>         digitalGrouping;

    QJsonObject                 jsonForm;

    QMap<QString, shared_ptr<QVariant>> testMap
    {
        {"Test0", key},
        {"Test1", language}
    };
};

#endif // GM_I18NLOCALE_H
