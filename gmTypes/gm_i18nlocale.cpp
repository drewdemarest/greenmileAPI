#include "gm_i18nlocale.h"
#include "gm_organization.h"

GM_I18NLocale::GM_I18NLocale()
{
    qDebug() << "is key valid?" << bool(key);
    if(key)
    {
        qDebug() << "key is now" << *key.get();
    }

    qDebug() << "is map valid?" << bool(testMap["Test0"]);
    if(testMap["Test0"])
    {
        qDebug() << "map is now" << *testMap["Test0"].get();
    }

    qDebug() << testMap["Test0"].use_count() << "," << key.use_count();

    /*End test 1, starting test 2 changing key...*/

    qDebug() << "change key...";
    *key.get() = QVariant(QString("Potato"));

    qDebug() << "is key valid?" << bool(key);
    if(key)
    {
        qDebug() << "key is now" << *key.get();
    }

    qDebug() << "is map valid?" << bool(testMap["Test0"]);
    if(testMap["Test0"])
    {
        qDebug() << "map is now" << *testMap["Test0"].get();
    }

    qDebug() << testMap["Test0"].use_count() << "," << key.use_count();

    qDebug() << bool(testMap.value("Test0"));

    /*End test 2, starting test 3 changing map...*/

    qDebug() << "change key...";
    *testMap["Test0"].get() = QVariant(QString("otatoP"));

    qDebug() << "is key valid?" << bool(key);
    if(key)
    {
        qDebug() << "key is now" << *key.get();
    }

    qDebug() << "is map valid?" << bool(testMap["Test0"]);
    if(testMap["Test0"])
    {
        qDebug() << "map is now" << *testMap["Test0"].get();
    }

    qDebug() << testMap["Test0"].use_count() << "," << key.use_count();

    qDebug() << bool(testMap.value("Test0"));
}

GM_I18NLocale::~GM_I18NLocale()
{

}
