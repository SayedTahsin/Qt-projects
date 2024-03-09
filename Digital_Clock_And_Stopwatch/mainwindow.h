#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void Showtime();
    void on_pushButton_clicked();

    void on_Start_Stop_clicked();
    void StopWatchTime();


    void on_Start_clicked();

    void on_Stop_clicked();

    void on_Lap_clicked();

    void on_reset_clicked();

    void on_TimerStart_clicked();

    void on_TimerPause_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer2;
    QElapsedTimer *stopwatchtimer;
};
#endif // MAINWINDOW_H
