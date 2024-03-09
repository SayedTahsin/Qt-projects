#include "widget.h"
#include "ui_widget.h"
#include "board.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    hide();
    board dialog;
    dialog.setModal(true);
    dialog.setWindowTitle("Tic Tac Toe");
    dialog.exec();
}

void Widget::on_pushButton_2_clicked()
{
    QApplication::quit();
}
