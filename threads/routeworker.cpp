#include "routeworker.h"

RouteWorker::RouteWorker() :
    Worker()
{

}

RouteWorker::RouteWorker(int &threadNumberIn) :
    Worker(threadNumberIn)
{

}

RouteWorker::RouteWorker(int &threadNumberIn, QStringList *routeSheetIn) :
    Worker(threadNumberIn),
    routeSheet(routeSheetIn)
{

}

void RouteWorker::process() {

    makeRangeAssignment();

    qDebug() << "This is route worker thread " << threadNumber << " or " << QThread::currentThreadId() <<  " if you prefer and I'm reading list of size "
             << containerSize << " from... " << readFrom << " to " << readTo;

    //finished does not carry an argument. It facilitates easy use of the new signal slot syntax
    GMRoute test;
    test.write();
    emit routeOutput(route);
    emit finished();
}
