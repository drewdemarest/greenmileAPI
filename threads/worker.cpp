#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(int &threadNumberIn) :
    threadNumber(threadNumberIn)
{

}

Worker::Worker(int &threadNumberIn, int &continerSizeIn) :
    containerSize(continerSizeIn),
    threadNumber(threadNumberIn)
{

}

Worker::~Worker()
{

}

void Worker::process()
{
    makeRangeAssignment();

    qDebug() << "This is thread " << threadNumber << " or " << QThread::currentThreadId() <<  " if you prefer and I'm reading list of size "
             << containerSize << " from... " << readFrom << " to " << readTo;

    //finished does not carry an argument. It facilitates easy use of the new signal slot syntax
    emit finished();
}

void Worker::makeRangeAssignment()
{

    //This function provides a plan on how to split up a container
    // oject and then assign it to various other functions.

    //If there are more elements to the container than objects to which
    //the discreet chunks will be assigned, the program will assign the
    //container as equally as possible and then tack the remaineder of the
    //container onto the final object.

    if(containerSize >= totalThreadCount)
    {
        readFrom = (threadNumber)*(containerSize/totalThreadCount);

        readTo = (threadNumber+1)*(containerSize/totalThreadCount) - 1;

        if(threadNumber == totalThreadCount - 1)
            readTo = readTo + (containerSize % totalThreadCount);
    }

    //If the container size is smaller than the amount of objects to which it can be assigned
    //then each container element will be assigned to a object and the remaining objects will
    //do nothing.

    //Testing purposes, I think the logic is Redondo.
    //if(containerSize < totalThreadCount && containerSize == 0 && threadNumber < containerSize)

    if(containerSize < totalThreadCount && threadNumber < containerSize)
    {
        totalThreadCount = containerSize;

        readFrom = (threadNumber)*(containerSize/totalThreadCount);

        readTo = (threadNumber+1)*(containerSize/totalThreadCount) - 1;
    }

    //If the container size is 0 then throw errors and do nothing. Otherwise there will
    //be assignment errors and EVERYONE will be sad.

    if(containerSize == 0)
    {
        //Here it is useful to output a very scary error messages to the users... huhahaha
        QString threadPtrStr = QString("0x%1").arg((quintptr)this->thread(),
                                                   QT_POINTER_SIZE * 2, 16, QChar('0'));

        err = "Error 1: Container is empty in  " + QString::number(threadNumber) + " " + threadPtrStr + "\n";

        emit output(ReturnCode::ContainerEmpty);
        emit error(err);
    }

    if(containerSize >= 0)
    {
        emit output(ReturnCode::Successful);
    }
}

QPoint Worker::getReadSeg() const
{
    return QPoint(readFrom, readTo);
}
