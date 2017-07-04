#ifndef GMUDFS_H
#define GMUDFS_H

#include <QtCore>

class GMUdfs
{
public:
    //BEGIN COMPUTATION FUNCTIONS
    void importJson(const QJsonArray &json);
    void appendJson(const Q &json);
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
    bool *objUdfsInit = Q_NULLPTR;

    QStringList memberList;

    QMap<QString, QString*>             objQString;

    //Meta member to track which members are imported
    QMap<QString, bool>             importedMember;

#endif // GMUDFS_H
