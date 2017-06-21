#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QtCore>
#include <QJsonObject>
#include "threads/routeworker.h"

//This class uses the auto type to return whatever the heck
//the thread objects are making. This class facitlites
//thread management and as such is just a go-between for
//threads and also

class ThreadManager : public QObject
{
    Q_OBJECT

public:
    ThreadManager();
    ThreadManager(QObject *parent);
    virtual ~ThreadManager();

    virtual void initThreads();
    virtual void initThreads(int numberOfThreadsIn);

protected:
    virtual void connectThreads(int &threadNumber);
    virtual void clearWorkerVector();
    virtual void clearThreadVector();
    virtual void workerCoroner();
    virtual void threadCoroner();
    virtual void sync();

    //Dynamic pointers. These can be initialized here.
    //These vectors hold the threads and workers and allow for dynamic spawning.

    QVector<QThread*> *threadVector = new QVector<QThread*>;
    QVector<Worker*> *workerVector = new QVector<Worker*>;

    //Private local variables
    //--------------------------------------------------------
    //This is a collection of all errors from each thread spawned.
    QStringList threadErrorList;
    QStringList managerErrorList;
    QStringList allErrorList;

private:
    //Metadata so the thread workers have some awareness of their place in
    //the universe.
    int idealThreadCount = QThread::idealThreadCount();

    //Worker and thread state trackers. The bools are for convenience in conditionals.
    //The counters allow for more granular analysis if needed.
    int numberOfThreads     = 0;
    int numberOfWorkers     = 0;

    int finishedWorkers = 0;
    int finishedThreads = 0;

    bool workersDone = true;
    bool threadsDone = true;

signals:
    void workerRouteOutput(QStringList routeOutput);
    void workerOutput(int output);

    void allErrors(QStringList allErrorList);
    void managerErrors(QStringList managerErrorList);
    void threadErrors(QStringList threadErrorList);
    void allThreadsDone();

protected slots:
    void handleThreadErrors(QString threadErrorMsg);
    void handleManagerErrors(QString threadErrorMsg);
};

#endif // THREADMANAGER_H
