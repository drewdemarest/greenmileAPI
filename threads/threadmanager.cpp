#include "threadmanager.h"

ThreadManager::ThreadManager()
{

}

ThreadManager::ThreadManager(QObject *parent = Q_NULLPTR) :
    QObject(parent)
{

}

ThreadManager::~ThreadManager()
{
    threadErrorList.clear();
    managerErrorList.clear();
    allErrorList.clear();

    delete threadVector;
    delete workerVector;
}

void ThreadManager::initThreads()
{
    qDebug() << "Init threads";
    //Clear out all previous thread errors...
    threadErrorList.clear();
    managerErrorList.clear();
    allErrorList.clear();

    if(workersDone && threadsDone){
        for(int i = 0; i < idealThreadCount; i++){
            connectThreads(i);
            sync();
        }
        qDebug() << "Init if";
        workersDone = false;
        threadsDone = false;

        for(int i = 0; i < idealThreadCount; i++){
            threadVector->at(i)->start();
        }
    }
    else
    {
        qDebug() << "Init else";
        handleThreadErrors("Error 2: Not all threads have completed!\n");
        emit managerErrors(managerErrorList);
        //emit allErrors(threadErrorList);
    }
}

void ThreadManager::initThreads(int threadNumberIn)
{
    qDebug() << "Init arbitrary thread count";
    //Clear out all previous thread errors...
    threadErrorList.clear();
    managerErrorList.clear();
    allErrorList.clear();
    threadErrorList = QStringList();
    managerErrorList = QStringList();
    allErrorList = QStringList();

    if(workersDone && threadsDone){
        for(int i = 0; i < threadNumberIn; i++){
            connectThreads(i);
            sync();
        }
        qDebug() << "Init if";
        workersDone = false;
        threadsDone = false;

        for(int i = 0; i < threadNumberIn; i++){
            threadVector->at(i)->start();
        }
    }
    else
    {
        qDebug() << "Init else";
        handleThreadErrors("Error 2: Not all threads spawned have completed!\n");
        emit managerErrors(managerErrorList);
        //emit allErrors(threadErrorList);
    }
}

void ThreadManager::connectThreads(int &threadNumber)
{
    qDebug() << "Base stuff" << workerVector->size();
    threadVector->push_back(new QThread(this));
    workerVector->push_back(new Worker(threadNumber));

    connect(workerVector->at(threadNumber), SIGNAL(output(int)), this, SIGNAL(workerOutput(int)));

    workerVector->at(threadNumber)->moveToThread(threadVector->at(threadNumber));
    connect(threadVector->at(threadNumber), SIGNAL(started()), workerVector->at(threadNumber), SLOT(process()));

    connect(workerVector->at(threadNumber), SIGNAL(error(QString)), this, SLOT(handleThreadErrors(QString)));
    connect(workerVector->at(threadNumber), SIGNAL(finished()), threadVector->at(threadNumber), SLOT(quit()));
    connect(workerVector->at(threadNumber), SIGNAL(finished()), workerVector->at(threadNumber), SLOT(deleteLater()));
    connect(threadVector->at(threadNumber), SIGNAL(finished()), threadVector->at(threadNumber), SLOT(deleteLater()));

    connect(threadVector->at(threadNumber), &QThread::destroyed, this, &ThreadManager::threadCoroner);
    connect(workerVector->at(threadNumber), &Worker::destroyed, this, &ThreadManager::workerCoroner);

    qDebug() << "Workers" << numberOfWorkers;
    qDebug() << "Threads" << numberOfThreads;
}


void ThreadManager::threadCoroner()
{
    finishedThreads++;
    if(finishedThreads == numberOfThreads){
        clearThreadVector();
        numberOfThreads = 0;
        finishedThreads = 0;
        threadsDone = true;
        if(workersDone && threadsDone){
            emit threadErrors(threadErrorList);
            emit allThreadsDone();
        }
    }
}

void ThreadManager::workerCoroner()
{
    finishedWorkers++;
    if(finishedWorkers == numberOfWorkers){
        clearWorkerVector();
        numberOfWorkers = 0;
        finishedWorkers = 0;
        workersDone = true;
        if(workersDone && threadsDone){
            emit threadErrors(threadErrorList);
            emit allThreadsDone();
        }
    }
}

void ThreadManager::handleManagerErrors(QString managerErrorMsg)
{
    managerErrorList << managerErrorMsg;
    allErrorList << managerErrorMsg;
}

void ThreadManager::handleThreadErrors(QString threadErrorMsg)
{
    threadErrorList << threadErrorMsg;
    allErrorList << managerErrorList;
}

void ThreadManager::clearWorkerVector()
{

    workerVector->clear();
    workerVector->squeeze();
}

void ThreadManager::clearThreadVector()
{
    threadVector->clear();
    threadVector->squeeze();
}

void ThreadManager::sync()
{
    numberOfWorkers++;
    numberOfThreads++;
}
