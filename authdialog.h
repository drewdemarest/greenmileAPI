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

public:
    explicit AuthDialog(QWidget *parent = 0);
    ~AuthDialog();

private:
    Ui::AuthDialog *ui;
    void createCredentials();

signals:
    void authenticationAdded(QString authentication);

};

#endif // AUTHDIALOG_H
