#ifndef GMSTOPTYPE_H
#define GMSTOPTYPE_H

#include <QtCore>

class GMOrganization;

class GMStopType
{
public:
    GMStopType();
    ~GMStopType();

    int *getId() const;
    void setId(int id);

    QString *getKey() const;
    void setKey(QString &key);

    GMOrganization *getOrganization() const;
    void setOrganization(const GMOrganization &organization);

    QString *getDescription() const;
    void setDescription(QString &description);

    QString *getType() const;
    void setType(QString &type);

    bool *setLocationRequired() const;
    void setLocationRequired(bool locationRequired);

    //BEGIN COMPUTATION FUNCTIONS
    void importJson(const QJsonObject &json);
    void appendJson(const QJsonObject &json);
    QJsonObject exportJson();
    void setMembersNull();

private:

    //Computation subsection.
    void compareJson(const QJsonObject &json);
    //void setMembersNull();
    void setImportedMembersFalse();

    QJsonObject exportEngine();
    void importEngine(const QJsonObject &json);

    //Memeber subsection
    bool *objBoolInit                       = Q_NULLPTR;
    int *objIntInit                         = Q_NULLPTR;
    double *objDoubleInit                   = Q_NULLPTR;
    QString *objQStringInit                 = Q_NULLPTR;
    GMOrganization *objGMOrganizationInit   = Q_NULLPTR;

    QStringList memberList;

    QMap<QString, int*>             objInt;
    QMap<QString, double*>          objDouble;
    QMap<QString, bool*>            objBool;
    QMap<QString, QString*>         objQString;
    QMap<QString, GMOrganization*>  objGMOrganization;

    //Meta member to track which members are imported
    QMap<QString, bool>             importedMember;

    //This is needed so that I can turn objects into strings.
    QJsonDocument                   catalyst;
};

#endif // GMSTOPTYPE_H
