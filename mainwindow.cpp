#include "mainwindow.h"
#include "threads.h"

#include <iostream>
#include <QTimer>
#include <QTextEdit>
#include <QDateTime>
#include <QHBoxLayout>
#include <QWidget>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);

    textEdit = new QTextEdit("INITIAL TEXT");
    textEdit->setAlignment(Qt::AlignCenter);

    mainText = new QTextEdit("MAIN TEXT");
    mainText->setAlignment(Qt::AlignCenter);

    layout->addWidget(textEdit);
    layout->addWidget(mainText);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    TestThread *testWorker = new TestThread();
    testWorker->moveToThread(&testThread);
    connect(&testThread, &QThread::finished, testWorker, &QObject::deleteLater);
    connect(testWorker, &TestThread::resultReady, this, &MainWindow::handleTestThread);
    connect(this, &MainWindow::startTestThread, testWorker, &TestThread::parseData);

    TimeThread *timeWorker = new TimeThread();
    timeWorker->moveToThread(&timeThread);
    connect(&timeThread, &QThread::finished, timeWorker, &QObject::deleteLater);
    connect(timeWorker, &TimeThread::timeUpdated, this, &MainWindow::handleTimeThread);
    connect(this, &MainWindow::startTimerThread, timeWorker, &TimeThread::getCurrentTime);

    testThread.start();
    timeThread.start();

    emit startTestThread();
    emit startTimerThread();

    resize(400, 300);
    setWindowTitle("Threads playground");
}


void MainWindow::handleTestThread(const QString &) 
{
    textEdit->setText("workerThread finished executing!");
}


void MainWindow::handleTimeThread(const QString &time)
{
    mainText->setText(time);
}