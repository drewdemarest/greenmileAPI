#ifndef HEADERMGMT_H
#define HEADERMGMT_H

#include <QtCore>
#include <QApplication>
#include <QtWidgets>
#include <authdialog.h>

namespace Ui {
class HeaderMGMT;
}

class HeaderMGMT : public QDialog
{
    Q_OBJECT

public:
    explicit HeaderMGMT(QStringListModel *headerModel, QWidget *parent = 0);
    ~HeaderMGMT();
    void saveSettings();

private:
    AuthDialog *authDialog;
    Ui::HeaderMGMT *ui;

    QStringListModel *headerModel;

    void loadSettings();
    void insertHeader();
    void removeHeader();
    void removeAllHeaders();

private slots:
    void receiveAuthentication(QString authentication);

signals:
    void getRequestHeaders(QList<QString>* headers);
};

#endif // HEADERMGMT_H
