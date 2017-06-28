#ifndef GMORGANIZATION_H
#define GMORGANIZATION_H

#include <QtCore>

class GMI18NLocale;

class GMOrganization
{
public:
    GMOrganization();
    ~GMOrganization();

    int *getId() const;
    void setId(int id);

    QDateTime *getCreationDate() const;
    void setCreationDate(const QDateTime &creationDate);

    QDateTime *getLastModificationDate() const;
    void setLastModificationDate(const QDateTime &lastModifcationDate);

    QString *getKey() const;
    void setKey(const QString &key);

    QString *getDescription() const;
    void setDescription(const QString &description);

    QString *getUnitSystem() const;
    void setUnitSystem(const QString &unitSystem);

    GMOrganization *getParentOrganization() const;
    void setParentOrganization(const GMOrganization &parentOrganization);

    //GMLastModifier getLastModifier() const;
    //void setLastModifier(GMLastModifier &lastModifier);

    //GMCreator getLastCreator() const;
    //void getLastCreator(GMCreator &creator);


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
    bool *objBoolInit                       = Q_NULLPTR;
    int *objIntInit                         = Q_NULLPTR;
    double *objDoubleInit                   = Q_NULLPTR;
    QString *objQStringInit                 = Q_NULLPTR;
    QDate *objQDateInit                     = Q_NULLPTR;
    QDateTime *objQDateTimeInit             = Q_NULLPTR;
    GMOrganization *objGMOrganizationInit   = Q_NULLPTR;
    GMI18NLocale *objGMI18NLocaleInit       = Q_NULLPTR;

    QStringList memberList;

    QMap<QString, int*>              objInt;
    QMap<QString, double*>           objDouble;
    QMap<QString, bool*>             objBool;
    QMap<QString, QString*>          objQString;
    QMap<QString, QDate*>            objQDate;
    QMap<QString, QDateTime*>        objQDateTime;
    QMap<QString, GMOrganization*>   objGMOrganization;
    QMap<QString, GMI18NLocale*>     objGMI18NLocale;
    //Meta member to track which members are imported
    QMap<QString, bool>         importedMember;
};

#endif // GMORGANIZATION_H
