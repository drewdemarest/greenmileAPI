#include "oauthnetconnect.h"

OAuthNetConnect::OAuthNetConnect(QObject *parent) :
    QObject(parent),
    oauthSettings(new QSettings(QApplication::applicationDirPath() + "/oauth.ini", QSettings::IniFormat))
{
    connect(oauth2NetworkAccess, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
    connect(oauth2NetworkAccess, &QOAuth2AuthorizationCodeFlow::granted, this, &OAuthNetConnect::oauthGranted);
    connect(oauth2NetworkAccess, &QOAuth2AuthorizationCodeFlow::requestFailed, this, &OAuthNetConnect::oauthFailed);
}

OAuthNetConnect::OAuthNetConnect(const QString &scope, const QString &address, const QString &credentialFilePath, QObject *parent) :
    QObject(parent),
    oauthSettings(new QSettings(QApplication::applicationDirPath() + "/oauth.ini", QSettings::IniFormat))
{
    //connections
    connect(oauth2NetworkAccess, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
    connect(oauth2NetworkAccess, &QOAuth2AuthorizationCodeFlow::granted, this, &OAuthNetConnect::oauthGranted);
    connect(oauth2NetworkAccess, &QOAuth2AuthorizationCodeFlow::requestFailed, this, &OAuthNetConnect::oauthFailed);
    buildOAuth(scope, address, credentialFilePath);
}

OAuthNetConnect::~OAuthNetConnect()
{
}

void OAuthNetConnect::buildOAuth(const QString &scope, const QString &address, const QString &credentialFilePath)
{
    loadSettings();
    this->address = address;

    //temporary code-- for debuggin server replies
    //connect(oauth2NetworkAccess, &QOAuth2AuthorizationCodeFlow::granted, this, &NetConnect::debugReply);

    //google->setScope("https://www.googleapis.com/auth/spreadsheets.readonly");
    oauth2NetworkAccess->setScope(scope);

    const QJsonObject object = readJsonCredentials(credentialFilePath);

    const auto settingsObject = object["web"].toObject();

    const QUrl authUri(settingsObject["auth_uri"].toString());
    const auto clientId = settingsObject["client_id"].toString();
    const QUrl tokenUri(settingsObject["token_uri"].toString());
    const auto clientSecret(settingsObject["client_secret"].toString());
    const auto redirectUris = settingsObject["redirect_uris"].toArray();
    const QUrl redirectUri(redirectUris[0].toString()); // Get the first URI
    const auto port = static_cast<quint16>(redirectUri.port()); // Get the port

    oauth2NetworkAccess->setAuthorizationUrl(authUri);
    oauth2NetworkAccess->setClientIdentifier(clientId);
    oauth2NetworkAccess->setAccessTokenUrl(tokenUri);
    oauth2NetworkAccess->setClientIdentifierSharedKey(clientSecret);

    if(tokenExpire < QDateTime::currentDateTime())
    {
        auto replyHandler = new QOAuthHttpServerReplyHandler(port, this);
        oauth2NetworkAccess->setReplyHandler(replyHandler);
    }

    //check if the auth token from settings file is valid
    qDebug() << "oauthTok null?"  << oauthToken.isNull() << "empty?" << oauthToken.isEmpty();
    if(oauthToken.isNull())
    {
        oauth2NetworkAccess->grant();
    }
    else if(tokenExpire < QDateTime::currentDateTime())
    {
        oauth2NetworkAccess->grant();
    }
    else
    {
        oauth2NetworkAccess->setToken(oauthToken);
    }
    //oauth2NetworkAccess->requestFailed();
    debugReply();

    //oauth2NetworkAccess->grant();
    //oauth test end
}



QJsonObject OAuthNetConnect::readJsonCredentials(const QString &credentialFilePath)
{
    QByteArray credentials;

    QFile jsonCredentialFile(credentialFilePath);
    if(!jsonCredentialFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return QJsonObject();

    while(!jsonCredentialFile.atEnd())
    {
        credentials.append(jsonCredentialFile.readLine());
    }

    return QJsonObject(QJsonDocument::fromJson(credentials).object());
}

void OAuthNetConnect::loadSettings()
{
    oauthToken = oauthSettings->value("oauth2/token").toString();
    tokenExpire = oauthSettings->value("oauth2/tokenExpire").toDateTime();
}

void OAuthNetConnect::saveSettings()
{
    oauthSettings->setValue("oauth2/token", oauth2NetworkAccess->token());
    oauthSettings->setValue("oauth2/tokenExpire", tokenExpire.toString());
}

QByteArray OAuthNetConnect::get()
{
    return QByteArray();
}

void OAuthNetConnect::debugReply()
{
    //authGranted = true;

    qDebug() << int(oauth2NetworkAccess->status());
    qDebug() << QString(oauth2NetworkAccess->token());
    qDebug() << oauth2NetworkAccess->authorizationUrl();
    QNetworkReply *reply = oauth2NetworkAccess->get(QUrl(address));

    while(!reply->isFinished())
        qApp->processEvents();

    if(reply->errorString() == QNetworkReply::AuthenticationRequiredError)
    {
        qDebug() << reply->errorString();
        oauth2NetworkAccess->grant();
    }
    else
        qDebug() << reply->readAll();

    reply->deleteLater();
}

void OAuthNetConnect::oauthGranted()
{
    oauthToken = oauth2NetworkAccess->token();
    tokenExpire = oauth2NetworkAccess->expirationAt();
    tokenExpire = oauthSettings->value("oauth2/tokenExpire").toDateTime();
    oauthSettings->sync();
    qDebug() << "Bonus tokens?" << oauth2NetworkAccess->extraTokens();
    saveSettings();
}

void OAuthNetConnect::oauthFailed()
{

}
