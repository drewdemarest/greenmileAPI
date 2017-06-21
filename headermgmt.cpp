#include "headermgmt.h"
#include "ui_headermgmt.h"

HeaderMGMT::HeaderMGMT(QStringListModel *headerModel, QWidget *parent) :
    QDialog(parent),
    authDialog(new AuthDialog(this)),
    ui(new Ui::HeaderMGMT)
{
    ui->setupUi(this);
    this->headerModel = headerModel;
    ui->headerListView->setModel(headerModel);

    connect(this, &QDialog::accepted, this, &HeaderMGMT::saveSettings);
    connect(authDialog, SIGNAL(authenticationAdded(QString)), this, SLOT(receiveAuthentication(QString)));
    connect(ui->addAuthButton, &QPushButton::clicked, authDialog, &AuthDialog::show);
    connect(ui->insertHeaderButton, &QPushButton::clicked, this, &HeaderMGMT::insertHeader);
    connect(ui->removeHeaderButton, &QPushButton::clicked, this, &HeaderMGMT::removeHeader);
    connect(ui->removeAllHeaderButton, &QPushButton::clicked, this, &HeaderMGMT::removeAllHeaders);
}


HeaderMGMT::~HeaderMGMT()
{
    delete authDialog;
    delete ui;
}

void HeaderMGMT::saveSettings()
{
    //qDebug() << settings->value("address/websiteAddress").toString();
}

void HeaderMGMT::receiveAuthentication(QString authentication)
{
    qDebug() << authentication;
    QString simpleText = ("Authorization:" + authentication).simplified();

    headerModel->insertRow(headerModel->rowCount());
    QModelIndex index = headerModel->index(headerModel->rowCount()-1);
    headerModel->setData(index, simpleText);
}

void HeaderMGMT::insertHeader()
{
    int row = ui->headerListView->currentIndex().row();

    //qDebug() << row;
    row = (row < 0) ? 0 : row;

    headerModel->insertRows(row, 1);

    QModelIndex index = headerModel->index(row);
    ui->headerListView->setCurrentIndex(index);
    ui->headerListView->edit(index);
}

void HeaderMGMT::removeAllHeaders()
{
    headerModel->removeRows(0, headerModel->rowCount());
}

void HeaderMGMT::removeHeader()
{
    headerModel->removeRows(ui->headerListView->currentIndex().row(), 1);
}
