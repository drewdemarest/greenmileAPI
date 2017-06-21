#include "authdialog.h"
#include "ui_authdialog.h"

AuthDialog::AuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    connect(this, &QDialog::accepted, this, &AuthDialog::createCredentials);
}


AuthDialog::~AuthDialog()
{
    delete ui;
}

void AuthDialog::createCredentials()
{
    //make auth
    QString concatenated = ui->userLineEdit->text() + ":" + ui->passwordLineEdit->text();
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    qDebug() << headerData;
    emit authenticationAdded(headerData);
    //request.setRawHeader("Authorization", headerData.toLocal8Bit());
    //auth made
}
