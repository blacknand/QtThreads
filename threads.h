#include <QObject>
#include <QString>


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
public slots:
    void getCurrentTime();
signals:
    void timeUpdated(const QString &time);
};