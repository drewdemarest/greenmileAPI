#ifndef NETCONNECT_H
#define NETCONNECT_H


#include <QObject>
#include <QtNetwork>
#include <QDesktopServices>
#include <QOAuth2AuthorizationCodeFlow>
#include <QOAuthHttpServerReplyHandler>

class NetConnect : public QObject
{
    Q_OBJECT
public:
    explicit NetConnect(QObject *parent = nullptr);
    ~NetConnect();

    QByteArray postRequest(QStringList &headers, QString &address, QString &body);
    void googleSheetsRead();

private:
    QOAuth2AuthorizationCodeFlow *google = new QOAuth2AuthorizationCodeFlow;
    bool authGranted = false;

signals:
    void networkError(QString);

public slots:
private slots:
    void debugReply();
};

#endif // NETCONNECT_H
