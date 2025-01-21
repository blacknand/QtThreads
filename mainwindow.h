#include <QMainWindow>
#include <QTextEdit>
#include <QThread>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread workerThread;
    QThread _workerThread;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;
private:
    QTextEdit *defaultText;
    QTextEdit *timerText;
    QTextEdit *reportText;
public slots:
    void handleResults(const int &result);
    void updateStatus(const QString &status);   
signals:
    void operate(const QString &);
};