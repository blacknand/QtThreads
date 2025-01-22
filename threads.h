#include <QObject>
#include <QString>
#include <QTimer>


class TestThread : public QObject
{
    Q_OBJECT
public:
    TestThread() = default;
    ~TestThread() = default;
public slots:
    void parseData();
    void emitTestThread();
signals:
    void resultReady(const QString &msg);
};


class TimeThread : public QObject 
{
    Q_OBJECT
public:
    TimeThread() = default;
    ~TimeThread() = default;
private:
    QTimer *timer;
    void getCurrentTime();
public slots:
    void callCurrentTime();
signals:
    void timeUpdated(const QString &time);
};