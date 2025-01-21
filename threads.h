#include <QObject>
#include <QString>


class Worker : public QObject
{
    Q_OBJECT
public:
    Worker() = default;
    ~Worker() = default;
public slots:
    void doWork(const QString &parameter);
signals:
    void resultReady(const int &result);
    void statusReport(const QString &status);
};