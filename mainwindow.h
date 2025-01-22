#include <QMainWindow>
#include <QTextEdit>
#include <QThread>
#include <QTime>
#include <QTimer>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread testThread;
    QThread timeThread;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;
private:
    QTextEdit *textEdit;
    QTextEdit *mainText;
    QTimer *timer;
public slots:
    void handleTestThread(const QString &);
    void handleTimeThread(const QString &);
signals:
    void startTestThread();
    void startTimerThread();
};