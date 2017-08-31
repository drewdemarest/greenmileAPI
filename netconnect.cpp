#include "netconnect.h"

NetConnect::NetConnect(QObject *parent) : QObject(parent)
{

}


NetConnect::~NetConnect()
{
    google->deleteLater();
}

QByteArray NetConnect::postRequest(QStringList &headers, QString &address, QString &body)
{
    // trigger the request - see the examples in the following sections
    // stringReply in this case is the server response.

    QString stringReply;
    QJsonArray jsonReply;

    //From UI
    //QString address = ui->addressInput->text().toLatin1();

    qDebug() << address;

    //Format and attach url to network request.
    QUrl url(address.toLatin1());
    QNetworkRequest request(url);

    //For each header, split on a : and attach to
    //the request.
    for(auto h : headers)
    {
        QStringList chunks = h.split(":");
        QByteArray ba0 = chunks.value(0).toUtf8();
        QByteArray ba1 = chunks.value(1).toUtf8();
        request.setRawHeader(ba0, ba1);
    }


    QNetworkAccessManager nam;

    //if(ui->methodComboBox->currentIndex() == 1){
    QNetworkReply *reply = nam.post(request, QJsonDocument(QJsonDocument::fromJson(body.toUtf8())).toJson());

    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    if (reply->error() == QNetworkReply::NoError) {
        // communication was successful
        qDebug() << reply->readAll();
    }

    else {
        // an error occurred
        stringReply = "Error: " + reply->errorString();
        qDebug() << stringReply;
        emit networkError(stringReply);
        //QMessageBox::information(this, "", stringReply);
    }


    reply->deleteLater();
    return QByteArray(reply->readAll());
}

void NetConnect::googleSheetsRead()
{
    //oauth test begin
    if(!authGranted)
    {
    google->setScope("https://www.googleapis.com/auth/spreadsheets.readonly");

    connect(google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
        &QDesktopServices::openUrl);

    const QJsonObject object = QJsonDocument::fromJson("{\"web\":{\"client_id\":\"721182423780-a2lo9n7aj1vvqhjo4gjt2q1bfeu39285.apps.googleusercontent.com\",\"project_id\":\"qtauthtest\",\"auth_uri\":\"https://accounts.google.com/o/oauth2/auth\",\"token_uri\":\"https://accounts.google.com/o/oauth2/token\",\"auth_provider_x509_cert_url\":\"https://www.googleapis.com/oauth2/v1/certs\",\"client_secret\":\"rwFKYSmuteyvmbBHVrjSUF-E\",\"redirect_uris\":[\"http://localhost:8080\"]}}").object();
    const auto settingsObject = object["web"].toObject();

    const QUrl authUri(settingsObject["auth_uri"].toString());
    const auto clientId = settingsObject["client_id"].toString();
    const QUrl tokenUri(settingsObject["token_uri"].toString());
    const auto clientSecret(settingsObject["client_secret"].toString());
    const auto redirectUris = settingsObject["redirect_uris"].toArray();
    const QUrl redirectUri(redirectUris[0].toString()); // Get the first URI
    const auto port = static_cast<quint16>(redirectUri.port()); // ◙Get the port


    google->setAuthorizationUrl(authUri);
    google->setClientIdentifier(clientId);
    google->setAccessTokenUrl(tokenUri);
    google->setClientIdentifierSharedKey(clientSecret);


    auto replyHandler = new QOAuthHttpServerReplyHandler(port, this);

    google->setReplyHandler(replyHandler);

    google->grant();

    connect(google, &QOAuth2AuthorizationCodeFlow::granted, this, &NetConnect::debugReply);
    }
    else
        debugReply();
    //oauth test end
}

void NetConnect::debugReply()
{

    auto reply = google->get(QUrl("https://sheets.googleapis.com/v4/spreadsheets/1KA7c9bbG2p4f8SFe5ibbkIycwt0wukRe2_xpTB3SI6A/values/Monday"));
    qDebug() << "token:" << google->accessTokenUrl();
    while(!reply->isFinished())
        qApp->processEvents();

    qDebug() << reply->readAll();

    reply->deleteLater();
}
