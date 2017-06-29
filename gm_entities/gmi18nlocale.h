#ifndef GMI18NLOCALE_H
#define GMI18NLOCALE_H

#include <QtCore>

//If you noticed the lack of lower camel case on some
//of my variables, good job! It's there to more closely
//match the Greenmile API. They tend to switch from
//lowerCamelCase to ihateeverything format without
//any rhyme or ...raisin.

class GMOrganization;

class GMI18NLocale
{
public:
    GMI18NLocale();
    ~GMI18NLocale();

    int *getId() const;
    void setId(int id);

    QString *getKey() const;
    void setKey(const QString &key);

//    GMI18NLocale *getParentLocaleId() const;
//    void setKey(const GMI18NLocale &parentLocaleid);

//    GMOrganization *getOrganizationId() const;
//    void setOrganizationId(const GMOrganization &organizationId);

    QString *getLanguage() const;
    void setLanguage(const QString &language);

    QString *getCountry() const; //Banjos ensue
    void setCountry(const QString &country);

    QString *getDescription() const;
    void setDescription(const QString &description);

    QString *getDateFormat() const;
    void setDateFormat(const QString &dateformat);

    QString *getTimeFormat() const;
    void setTimeFormat(const QString &timeformat);

    QString *getCurrency() const;
    void setCurrency(const QString &currency);

    QString *getDecimalSymbol() const;
    void setDecimalSymbol(const QString &decimalsymbol);

    QString *getDigitalGrouping() const;
    void setDigitalGrouping(const QString &digitalgrouping);

    //BEGIN COMPUTATION FUNCTIONS
    void importJson(const QJsonObject &json);
    void appendJson(const QJsonObject &json);
    QJsonObject exportJson();

private:
    //Computation subsection.
    void compareJson(const QJsonObject &json);
    void setMembersNull();
    void setImportedMembersFalse();

    QJsonObject exportEngine();
    void importEngine(const QJsonObject &json);


    //Member subsection
    int *objIntInit                         = Q_NULLPTR;
    QString *objQStringInit                 = Q_NULLPTR;
    GMOrganization *objGMOrganizationInit   = Q_NULLPTR;
    GMI18NLocale *objGMI18NLocaleInit       = Q_NULLPTR;

    QStringList memberList;

    QMap<QString, int*>              objInt;
    QMap<QString, QString*>          objQString;
    QMap<QString, GMOrganization*>   objGMOrganization;
    QMap<QString, GMI18NLocale*>     objGMI18NLocale;

    //Meta member to track which members are imported
    QMap<QString, bool>         importedMember;
};

#endif // GMI18NLOCALE_H
