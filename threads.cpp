#include "threads.h"

#include <iostream>
#include <QThread>
#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QTime>
#include <QTimer>


void TestThread::parseData()
{
    QTimer::singleShot(10000, this, &TestThread::emitTestThread);
}


void TimeThread::callCurrentTime()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimeThread::getCurrentTime);
    timer->start(1000);
}


void TimeThread::getCurrentTime()
{
    QDateTime current = QDateTime::currentDateTime();
    QString time = current.toString("hh:mm:ss");
    emit timeUpdated(QString(time));
}


void TestThread::emitTestThread()
{
    emit resultReady("workerThread finished executing!");
}