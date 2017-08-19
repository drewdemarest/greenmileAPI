#include "gm_i18nlocale.h"
#include "gm_organization.h"

GM_I18NLocale::GM_I18NLocale()
{
    qDebug() << bool(testMap.value("Test0"));

    //key = make_shared<QString>("potato");

    testMap["Test0"].reset(new QString("Potato"));

    qDebug() << testMap["Test0"].use_count() << "," << key.use_count();

    qDebug() << bool(testMap.value("Test0"));
}

GM_I18NLocale::~GM_I18NLocale()
{

}
