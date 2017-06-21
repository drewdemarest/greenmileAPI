#ifndef ROUTEWORKER_H
#define ROUTEWORKER_H

#include <threads/worker.h>
#include <gm_entities/gmroute.h>

class RouteWorker : public Worker
{
    Q_OBJECT
public:
    RouteWorker();
    RouteWorker(int &threadNumberIn);
    RouteWorker(int &threadNumberIn, QStringList *routeSheetIn);

private:
    QStringList *routeSheet;
    QStringList route;
    void process();

signals:
    void routeOutput(QStringList);
};

#endif // ROUTEWORKER_H
