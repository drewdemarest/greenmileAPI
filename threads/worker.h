#ifndef WORKER_H
#define WORKER_H

#include <QtCore>
#include <QObject>

using namespace std;

class Worker : public QObject
{
    Q_OBJECT
public:
    enum ReturnCode{Successful, ContainerEmpty};

    explicit Worker();
    explicit Worker(int &threadNumberIn);
    explicit Worker(int &threadNumberIn, int &continerSizeIn);
    virtual ~Worker();

public slots:
    virtual void process();

signals:
    void output(int);
    void error(QString);
    void finished();

protected:
    //functions
    QPoint getReadSeg() const;
    void makeRangeAssignment();
    //members

    QVector<QJsonObject> outputObj;

    QString err = QString();
    int containerSize = 0;
    int threadNumber = 0;
    int totalThreadCount = QThread::idealThreadCount();
    int readFrom = 0;
    int readTo = 0;
};

#endif // WORKER_H
