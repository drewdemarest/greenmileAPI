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
    JsonType<int>       ik;
    JsonType<int>       id{"Tato"};
    JsonType<QString>   iz{"Potato"};
    JsonType<long>      it{"derp"};
    unique_ptr<QString>         key;
    unique_ptr<GM_I18NLocale>   parentLocale;
    unique_ptr<GM_Organization> organizationId;
    unique_ptr<QString>         language;
    unique_ptr<QString>         country;
    unique_ptr<QString>         description;
    unique_ptr<QString>         dateFormat;
    unique_ptr<QString>         timeFormat;
    unique_ptr<QString>         currency;
    unique_ptr<QString>         decimalSymbol;
    unique_ptr<QString>         digitalGrouping;

    QJsonObject                 jsonForm;
};

#endif // GM_I18NLOCALE_H