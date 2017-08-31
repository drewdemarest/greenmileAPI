#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
//http://www.creativepulse.gr/en/blog/2014/restful-api-requests-using-qt-cpp-for-linux-mac-osx-ms-windows

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    netConct(new NetConnect),
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
    netConct->deleteLater();
    //google test
    //google->deleteLater();
    delete headers;
    delete ui;
}

void MainWindow::on_pushButton_clicked() {

    QString address = ui->addressInput->text().toLatin1();
    QString body = ui->queryInput->toPlainText();
    QStringList headers = headerModel->stringList();

    QRegularExpression httpRegEx("https?://", QRegularExpression::CaseInsensitiveOption);
    qDebug() << httpRegEx;

    QRegularExpressionMatch match = httpRegEx.match(address);
    qDebug() << match.hasMatch();
    //set http scheme combo box based on address in.
    if(match.captured(0).toLower() == QString("https://"))
    {
        ui->schemeComboBox->setCurrentIndex(1);
    }
    else if(match.captured(0).toLower() == QString("http://"))
    {
        ui->schemeComboBox->setCurrentIndex(0);
    }
    else
    {
        if(ui->schemeComboBox->currentIndex() > 0)
        {
            address = "https://" + address;
        }
        else
        {
            address = "http://" + address;
        }
    }

    const clock_t begin_time = clock();

    //QByteArray gmOut = netConct.postRequest(headers, address, body);
    netConct->googleSheetsRead();

    ui->responseTime->setText((QString::number((float( clock () - begin_time ) /  CLOCKS_PER_SEC) * 1000)) + "ms");

    address.remove(httpRegEx);
    ui->addressInput->setText(address);
}

void MainWindow::displayStringList(QStringList sl)
{
    QString message = sl.join("");
    if(!sl.isEmpty())
        QMessageBox::information(this, "", message);
}


