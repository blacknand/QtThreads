#include "mainwindow.h"
#include "threads.h"

#include <iostream>
#include <QTimer>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    defaultText = new QTextEdit(this);
    defaultText->setText("Hello, world!");

    reportText = new QTextEdit(this);
    defaultText->setText("Status report");
    reportText->setGeometry(10, 50, 380, 200);

    Worker *worker = new Worker();
    worker->moveToThread(&workerThread);

    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &MainWindow::operate, worker, &Worker::doWork);
    connect(worker, &Worker::resultReady, this, &MainWindow::handleResults);
    connect(worker, &Worker::statusReport, this, &MainWindow::updateStatus);

    workerThread.start();

    emit operate("start");
    
    resize(400, 300);
    setWindowTitle("Threads playground");
}


void MainWindow::handleResults(const int &result)
{
    defaultText->setText("Result is: " + QString::number(result));
}


void MainWindow::updateStatus(const QString &status)
{
    reportText->setText(status);
}