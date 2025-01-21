#include "threads.h"

#include <iostream>
#include <QThread>
#include <QObject>
#include <QDebug>


void Worker::doWork(const QString &parameter)
{
    int result = 0;
    for (int i = 0; i < 100000; i++) {
            result++;
            emit statusReport("processing " + QString::number(i));
        }
    emit resultReady(result);
}