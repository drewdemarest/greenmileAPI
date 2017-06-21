#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
//http://www.creativepulse.gr/en/blog/2014/restful-api-requests-using-qt-cpp-for-linux-mac-osx-ms-windows

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    headers(new QStringList),
    headerModel(new QStringListModel),
    jsonModel(new QJsonModel),
    settings(new QSettings(QApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadSettings();
    headerDialog = new HeaderMGMT(headerModel, this);
    ui->jsonTreeView->setModel(jsonModel);

    connect(rtm, SIGNAL(threadErrors(QStringList)), this, SLOT(displayStringList(QStringList)));
    connect(rtm, SIGNAL(managerErrors(QStringList)), this, SLOT(displayStringList(QStringList)));

    connect(ui->queryButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->queryButton, &QPushButton::clicked, this, &MainWindow::saveSettings);
    connect(ui->addHeaderButton, &QPushButton::clicked, headerDialog, &HeaderMGMT::show);
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
    rtm->deleteLater();

    delete jsonModel;
    delete headerModel;
    delete headers;
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    // trigger the request - see the examples in the following sections
    QString msg;
    QString address = ui->addressInput->text().toLatin1();
    beginProcess();

    if(ui->schemeComboBox->currentIndex() > 0)
    {
        address = "https://" + address;
    }
    else
    {
        address = "http://" + address;
    }
    qDebug() << address;

    QUrl url(address.toLatin1());

    QNetworkRequest request(url);

    for(auto h : headerModel->stringList())
    {
        QStringList chunks = h.split(":");
        QByteArray ba0 = chunks.value(0).toUtf8();
        QByteArray ba1 = chunks.value(1).toUtf8();
        request.setRawHeader(ba0, ba1);
    }

    QString query = ui->queryInput->toPlainText();
    QJsonDocument jDoc = QJsonDocument::fromJson(query.toUtf8());

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

            QByteArray hmm = msg.toUtf8();
            QJsonParseError err;
            QJsonDocument jDoc = QJsonDocument::fromJson(hmm, &err);

            jsonModel->loadJson(QByteArray::fromStdString(jDoc.toJson(QJsonDocument::Compact).toStdString()));
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

void MainWindow::beginProcess()
{
    rtm->initThreads(2);
}

void MainWindow::displayStringList(QStringList sl)
{
    QString message = sl.join("");
    if(!sl.isEmpty())
        QMessageBox::information(this, "", message);
}

