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
#include "threads/routethreadmanager.h"

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
    RouteThreadManager *rtm = new RouteThreadManager(this);

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
    void beginProcess();
    void displayStringList(QStringList sl);
};

#endif // MAINWINDOW_H
