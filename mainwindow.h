#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QApplication>
#include <QtWidgets>
#include <QtNetwork>
#include <time.h>
#include "headermgmt.h"
#include "qjsonmodel.h"
#include "simplecrypt.h"
#include "gmTypes/gm_i18nlocale.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QStringList *headers;
    QStringListModel *headerModel;
    QJsonModel *jsonModel;
    QSettings *settings;
    Ui::MainWindow *ui;

    HeaderMGMT *headerDialog;

    void on_pushButton_clicked();
    void initialise();
    void loadSettings();
    void saveSettings();

public slots:
    void displayStringList(QStringList sl);
};

#endif // MAINWINDOW_H
