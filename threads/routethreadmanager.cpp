#include "routethreadmanager.h"

RouteThreadManager::RouteThreadManager() :
    ThreadManager()
{

}

RouteThreadManager::RouteThreadManager(QObject *parent = Q_NULLPTR) :
    ThreadManager(parent)
{

}

RouteThreadManager::RouteThreadManager(QStringList &routeListIn) :
    ThreadManager()
{
    routeList = routeListIn;
}


RouteThreadManager::RouteThreadManager(QStringList &routeListIn, QObject *parent = Q_NULLPTR) :
    ThreadManager(parent)
{
    routeList = routeListIn;
}

RouteThreadManager::~RouteThreadManager()
{
    delete routeWorkerVector;
}

void RouteThreadManager::connectThreads(int &threadNumber)
{

    qDebug() << "Route stuff" << routeWorkerVector->size();
    threadVector->push_back(new QThread(this));
    routeWorkerVector->push_back(new RouteWorker(threadNumber));

    routeWorkerVector->at(threadNumber)->moveToThread(threadVector->at(threadNumber));
    connect(threadVector->at(threadNumber), SIGNAL(started()), routeWorkerVector->at(threadNumber), SLOT(process()));
    connect(routeWorkerVector->at(threadNumber), SIGNAL(error(QString)), this, SLOT(handleThreadErrors(QString)));
    connect(routeWorkerVector->at(threadNumber), SIGNAL(output(int)), this, SIGNAL(workerOutput(int)));
    connect(routeWorkerVector->at(threadNumber), SIGNAL(routeOutput(QStringList)), this, SIGNAL(workerRouteOutput(QStringList)));
    connect(routeWorkerVector->at(threadNumber), SIGNAL(finished()), threadVector->at(threadNumber), SLOT(quit()));

    connect(routeWorkerVector->at(threadNumber), SIGNAL(finished()), routeWorkerVector->at(threadNumber), SLOT(deleteLater()));
    connect(threadVector->at(threadNumber), SIGNAL(finished()), threadVector->at(threadNumber), SLOT(deleteLater()));
    connect(threadVector->at(threadNumber), &QThread::destroyed, this, &RouteThreadManager::workerCoroner);
    connect(routeWorkerVector->at(threadNumber), &Worker::destroyed, this, &RouteThreadManager::threadCoroner);
}

void RouteThreadManager::clearWorkerVector()
{
    routeWorkerVector->clear();
    routeWorkerVector->squeeze();
}

void RouteThreadManager::clearThreadVector()
{
    threadVector->clear();
    threadVector->squeeze();
}

