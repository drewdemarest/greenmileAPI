#ifndef GMUDFS_H
#define GMUDFS_H

#include <QtCore>

class GMUdfs
{
public:
    GMUdfs();
    ~GMUdfs();
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

    //Member subsection
    QString *objQStringInit = Q_NULLPTR;

    QMap<QString, QString*> objQString;

    //Meta member to track which members are imported
    QMap<QString, bool>     importedMember;
    QStringList             memberList;
};

#endif // GMUDFS_H
