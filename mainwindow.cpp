#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
//http://www.creativepulse.gr/en/blog/2014/restful-api-requests-using-qt-cpp-for-linux-mac-osx-ms-windows

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    headers(new QStringList),
    headerModel(new QStringListModel(this)),
    jsonModel(new QJsonModel),
    settings(new QSettings(QApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadSettings();
    headerDialog = new HeaderMGMT(headerModel, this);
    ui->jsonTreeView->setModel(jsonModel);

    connect(ui->queryButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->queryButton, &QPushButton::clicked, this, &MainWindow::saveSettings);
    connect(ui->addHeaderButton, &QPushButton::clicked, headerDialog, &HeaderMGMT::show);

    GM_I18NLocale test;
    //connect(headerDialog, SIGNAL(getRequestHeaders(QList<QString>*)), this, &MainWindow::updateHeaders);

//    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
//    QString testString("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");

//    //Encryption
//    QString result = crypto.encryptToString(testString);

//    //Decryption
//    QString decrypted = crypto.decryptToString(result);
//    qDebug() << testString << result << decrypted;
}


void MainWindow::loadSettings()
{
    ui->addressInput->setText(settings->value("address/websiteAddress").toString());
    ui->queryInput->setText(settings->value("query/monetQuery").toString());

    ui->methodComboBox->setCurrentIndex(settings->value("method/httpMethod").toInt());
    ui->schemeComboBox->setCurrentIndex(settings->value("scheme/httpScheme").toInt());

    //profit report settings
    int size = settings->beginReadArray("headerList");
    for(int i = 0; i < size; i++)
    {
        settings->setArrayIndex(i);
        *headers << settings->value("header").toString();
    }
    settings->endArray();

    headerModel->setStringList(*headers);
    ui->headerListView->setModel(headerModel);
}

void MainWindow::saveSettings()
{
    settings->setValue("address/websiteAddress", ui->addressInput->text());
    settings->setValue("query/monetQuery", ui->queryInput->toPlainText());

    settings->setValue("method/httpMethod", ui->methodComboBox->currentIndex());
    settings->setValue("scheme/httpScheme", ui->schemeComboBox->currentIndex());

    //writing items in the r_BadRouteLetterList to the file.

    int i = 0;
    settings->beginWriteArray("headerList");
    for(auto h : headerModel->stringList())
    {
        settings->setArrayIndex(i);
        settings->setValue("header", h);
        ++i;
    }
    settings->endArray();
    settings->sync();
}


MainWindow::~MainWindow() {
    settings->deleteLater();
    headerDialog->deleteLater();
    headerModel->deleteLater();
    jsonModel->deleteLater();
    //google test
    google->deleteLater();
    delete headers;
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    // trigger the request - see the examples in the following sections
    // msg in this case is the server response.


    //oauth test begin
    google->setScope("https://www.googleapis.com/auth/spreadsheets.readonly");

    connect(google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
        &QDesktopServices::openUrl);

    const QJsonObject object = QJsonDocument::fromJson("{\"web\":{\"client_id\":\"721182423780-a2lo9n7aj1vvqhjo4gjt2q1bfeu39285.apps.googleusercontent.com\",\"project_id\":\"qtauthtest\",\"auth_uri\":\"https://accounts.google.com/o/oauth2/auth\",\"token_uri\":\"https://accounts.google.com/o/oauth2/token\",\"auth_provider_x509_cert_url\":\"https://www.googleapis.com/oauth2/v1/certs\",\"client_secret\":\"rwFKYSmuteyvmbBHVrjSUF-E\",\"redirect_uris\":[\"http://localhost:8080/cb\"]}}").object();

    const auto settingsObject = object["web"].toObject();

    qDebug() << settingsObject["auth_uri"].toString();

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

    google->grant();

    connect(google, &QOAuth2AuthorizationCodeFlow::granted, this, &MainWindow::debugReply);
    //oauth test end

    QString msg;
    QString address = ui->addressInput->text().toLatin1();

    if(ui->schemeComboBox->currentIndex() > 0)
    {
        address = "https://" + address;
    }
    else
    {
        address = "http://" + address;
    }

    qDebug() << address;

    //Format and attach url to network request.
    QUrl url(address.toLatin1());
    QNetworkRequest request(url);

    //For each header, split on a : and attach to
    //the request.
    for(auto h : headerModel->stringList())
    {
        QStringList chunks = h.split(":");
        QByteArray ba0 = chunks.value(0).toUtf8();
        QByteArray ba1 = chunks.value(1).toUtf8();
        request.setRawHeader(ba0, ba1);
    }

    QByteArray query = ui->queryInput->toPlainText().toUtf8();
    QJsonDocument jDoc = QJsonDocument::fromJson(query);

    QNetworkAccessManager nam;

    if(ui->methodComboBox->currentIndex() == 1){
        QNetworkReply *reply = nam.post(request, QJsonDocument(jDoc).toJson());

        const clock_t begin_time = clock();

        while(!reply->isFinished())
        {
            qApp->processEvents();
        }

        ui->responseTime->setText((QString::number((float( clock () - begin_time ) /  CLOCKS_PER_SEC) * 1000)) + "ms");

        if (reply->error() == QNetworkReply::NoError) {
            // communication was successful

            msg = reply->readAll();

            QJsonParseError err;
            QJsonDocument jDoc = QJsonDocument::fromJson(QByteArray(msg.toUtf8()), &err);

            //Give msg result to the JsonTreeVisualizer.
            jsonModel->loadJson(QByteArray::fromStdString(jDoc.toJson(QJsonDocument::Compact).toStdString()));

            //Give msg result to the textEditWidget.
            ui->resultTextEdit->setText(jDoc.toJson(QJsonDocument::Indented));

            //qDebug() << ui->resultTextEdit->toPlainText();
        }

        else {
            // an error occurred
            msg = "Error: " + reply->errorString();
            QMessageBox::information(this, "", msg);
        }

        reply->deleteLater();
    }
}

void MainWindow::displayStringList(QStringList sl)
{
    QString message = sl.join("");
    if(!sl.isEmpty())
        QMessageBox::information(this, "", message);
}

void MainWindow::debugReply()
{
    auto reply = google->get(QUrl("https://sheets.googleapis.com/v4/spreadsheets/1KA7c9bbG2p4f8SFe5ibbkIycwt0wukRe2_xpTB3SI6A/values/Monday"));

    while(!reply->isFinished())
        qApp->processEvents();

    qDebug() << reply->readAll();
    reply->deleteLater();
}
