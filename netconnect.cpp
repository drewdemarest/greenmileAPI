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
    qDebug() << address;

    //Format and attach url to network request.
    QUrl url(address.toLatin1());
    QNetworkRequest request(url);
    QByteArray response;
    QString errorStr;

    //For each header, split on a : and attach to
    //the request.
    for(auto h : headers)
    {
        QStringList chunks = h.split(":");
        //Headers should only split into two chunks.
        if(chunks.length() == 2)
        {
            //serialize headers
            request.setRawHeader(QByteArray(chunks.value(0).toUtf8()), QByteArray(chunks.value(1).toUtf8()));
        }
        //If headers do not split into two chunks, complain and return empty QBtyeArray
        else
        {
            errorStr =  "A header did not cleanly split into two parts,"
                        " please verify integrity of your headers.";
            emit networkError(errorStr);
            return QByteArray();
        }
    }

    //Create a network access manager.
    QNetworkAccessManager nam;

    //Send a post request with the network manager. nam.post returns a pointer. I find this to be an
    //inconvenience and delete the post at the end of this function.
    QNetworkReply *reply = nam.post(request, QJsonDocument(QJsonDocument::fromJson(body.toUtf8())).toJson());

    //While waiting on the server do not lock up the ui on main thread.
    while(!reply->isFinished())
    {
        qApp->processEvents();
    }

    //If all went well, turn the reply into a bytearray.
    if (reply->error() == QNetworkReply::NoError) {
        response = reply->readAll();
    }

    // an error occurred. emit a signal with the error message
    // to any function that cares.
    else {
        errorStr = "Error: " + reply->errorString();
        qDebug() << errorStr;
        emit networkError(errorStr);
        //QMessageBox::information(this, "", stringReply);
    }

    reply->deleteLater();
    return response;
}

void NetConnect::googleSheetsRead()
{
    //oauth test begin

    if(!authGranted)
    {
    google->setScope("https://www.googleapis.com/auth/spreadsheets.readonly");

    connect(google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
        &QDesktopServices::openUrl);

    const auto settingsObject = object["web"].toObject();

    const QUrl authUri(settingsObject["auth_uri"].toString());
    const auto clientId = settingsObject["client_id"].toString();
    const QUrl tokenUri(settingsObject["token_uri"].toString());
    const auto clientSecret(settingsObject["client_secret"].toString());
    const auto redirectUris = settingsObject["redirect_uris"].toArray();
    const QUrl redirectUri(redirectUris[0].toString()); // Get the first URI
    const auto port = static_cast<quint16>(redirectUri.port()); // Get the port

    google->setAuthorizationUrl(authUri);
    google->setClientIdentifier(clientId);
    google->setAccessTokenUrl(tokenUri);
    google->setClientIdentifierSharedKey(clientSecret);


    auto replyHandler = new QOAuthHttpServerReplyHandler(port, this);

    google->setReplyHandler(replyHandler);

    google->setToken("ya29.Glu5BI0UMGH0_99dLuWLKYK8l9CVaTFrloOZE78QZeZ1SpQR2PjYM4ymCiCQuMmNkcoebJI9MsEXNDMf9yOi7mzpaiULZUZm66RbOcoRCN_HTi2ngzYyxfbxYUW6");
    debugReply();
    //google->grant();
    connect(google, &QOAuth2AuthorizationCodeFlow::granted, this, &NetConnect::debugReply);
    }
    else
        debugReply();
    //oauth test end
}

void NetConnect::debugReply()
{
    authGranted = true;

    qDebug() << int(google->status());
    qDebug() << QString(google->token());
    qDebug() << google->authorizationUrl();
    auto reply = google->get(QUrl("https://sheets.googleapis.com/v4/spreadsheets/1KA7c9bbG2p4f8SFe5ibbkIycwt0wukRe2_xpTB3SI6A/values/Monday"));
    while(!reply->isFinished())
        qApp->processEvents();

    qDebug() << reply->readAll();

    reply->deleteLater();
}
