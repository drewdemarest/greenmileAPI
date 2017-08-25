#include "gm_i18nlocale.h"
#include "gm_organization.h"

GM_I18NLocale::GM_I18NLocale()
{
    testJson = "{\r\n\"id\": 10020,\r\n\"creationDate\": \"2016-05-24T15:09:56+0000\",\r\n\"lastModificationDate\": \"2017-02-28T14:32:45+0000\",\r\n\"lastModifierAddress\": \"174.228.146.0\",\r\n\"key\": \"SEATTLE\",\r\n\"description\": \"SEATTLE\",\r\n\"preferedLocale\": {\r\n\"id\": 10000,\r\n\"key\": \"I18NLocale_en\",\r\n\"language\": \"en\",\r\n\"description\": \"English\",\r\n\"dateFormat\": \"MM/dd/yyyy\",\r\n\"timeFormat\": \"HH:mm\",\r\n\"currency\": \"US$\",\r\n\"decimalSymbol\": \",\",\r\n\"digitalGrouping\": \".\"\r\n},\r\n\"timeZone\": {\r\n\"id\": 10015,\r\n\"description\": \"US/Pacific\",\r\n\"rawOffsetMinutes\": -420,\r\n\"alias\": \"tmzPacificTimeUSCanada\"\r\n},\r\n\"listenerOrganizations\": [],\r\n\"unitSystem\": \"NON_METRIC\",\r\n\"lastModifier\": {\r\n\"id\": 10000\r\n},\r\n\"creator\": {\r\n\"id\": 10003\r\n}\r\n}";
    testObj = QJsonDocument::fromJson(testJson.toUtf8()).object();

    JsonType<QString>         key{"key", testObj};
    shared_ptr<QString> testRtn = key.getValue();
    qDebug() << testRtn.use_count();

    JsonType<QString> test;
    test.setValue(testPtr);
}

GM_I18NLocale::~GM_I18NLocale()
{
}
