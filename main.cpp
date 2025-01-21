#include "mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QThread>
#include <QTimer>


int main(int argc, char* argv[]) {
    QApplication threads(argc, argv);
    QCoreApplication::setOrganizationName("blacknand");
    QCoreApplication::setApplicationName("Threads");
    QCoreApplication::setApplicationVersion("0.1");

	MainWindow window;
    window.show();

    int result = threads.exec();
    return result;
}