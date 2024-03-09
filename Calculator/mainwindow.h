#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_decimal_released();

    void on_equal_released();

    void on_clear_released();

private:
    Ui::MainWindow *ui;
    void digit_pressed();
    void unary_operation_pressed();
    void binary_operation_pressed();
};
#endif // MAINWINDOW_H
