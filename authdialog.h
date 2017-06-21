#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT

signals:
    void authenticationAdded(QString authentication);

public:
    explicit AuthDialog(QWidget *parent = 0);
    ~AuthDialog();

private:
    Ui::AuthDialog *ui;
    void createCredentials();

};

#endif // AUTHDIALOG_H
