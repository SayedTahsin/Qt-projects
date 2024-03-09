#ifndef BOARD_H
#define BOARD_H

#include <QDialog>
namespace Ui {
class board;
}

class board : public QDialog
{
    Q_OBJECT

public:
    explicit board(QWidget *parent = nullptr);
    ~board();
    void Check();

private slots:
    void on_PB1_clicked();

    void on_PB2_clicked();

    void on_PB3_clicked();

    void on_PB4_clicked();

    void on_PB5_clicked();

    void on_PB6_clicked();

    void on_PB7_clicked();

    void on_PB8_clicked();

    void on_PB9_clicked();

private:
    Ui::board *ui;
    int count=1;
};

#endif // BOARD_H
