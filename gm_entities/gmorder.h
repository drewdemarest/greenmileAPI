#ifndef GMORDER_H
#define GMORDER_H

#include <QJsonObject>
#include <QtCore>

class GMStop;
class GMLineItem;

class GMOrder
{
public:
    GMOrder();
    ~GMOrder();

    /*
    int *getId() const;
    void setId(int id);
    */

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

    //NEW OBJECTS HERE

    QStringList memberList;

    QMap<QString, int*>              objInt;
    QMap<QString, double*>           objDouble;
    QMap<QString, bool*>             objBool;
    QMap<QString, QString*>          objQString;
    QMap<QString, QDate*>            objQDate;
    QMap<QString, QDateTime*>        objQDateTime;

    //Members which will need new loops written for them.
    QMap<QString, GMOrder*>          objGMOrder;


    //Meta member to track which members are imported
    QMap<QString, bool>             importedMember;

    //This is needed so that I can turn objects into strings.
    QJsonDocument                   catalyst;
};
#endif // GMORDER_H
