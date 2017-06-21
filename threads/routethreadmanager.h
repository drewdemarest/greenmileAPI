#ifndef ROUTETHREADMANAGER_H
#define ROUTETHREADMANAGER_H

#include <QtCore>
#include "threads/routeworker.h"
#include "threads/threadmanager.h"

class RouteThreadManager : public ThreadManager
{
    Q_OBJECT
public:
    RouteThreadManager();
    RouteThreadManager(QObject *parent);
    RouteThreadManager(QStringList &routeListIn);
    RouteThreadManager(QStringList &routeListIn, QObject *parent);
    ~RouteThreadManager();

private:
    QVector<RouteWorker*> *routeWorkerVector = new QVector<RouteWorker*>;
    QStringList routeList;
    void connectThreads(int &threadNumber);
    void clearWorkerVector();
    void clearThreadVector();
};

#endif // ROUTETHREADMANAGER_H
