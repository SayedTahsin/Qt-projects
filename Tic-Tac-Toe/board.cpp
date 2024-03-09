#include "board.h"
#include "ui_board.h"
#include "widget.h"
#include <QDebug>
#include <QMessageBox>
board::board(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::board)
{
    ui->setupUi(this);
    if(count%2==1){
        ui->TurnLabel->setText("Player X 's Turn");
    }else{
        ui->TurnLabel->setText("Player O 's Turn");
    }
}


board::~board()
{
    delete ui;
}

void board::Check()
{
    if(count%2==1){
        ui->TurnLabel->setText("Player X 's Turn");
    }else{
        ui->TurnLabel->setText("Player O 's Turn");
    }
    QString PB1=ui->PB1->text();
    QString PB2=ui->PB2->text();
    QString PB3=ui->PB3->text();
    QString PB4=ui->PB4->text();
    QString PB5=ui->PB5->text();
    QString PB6=ui->PB6->text();
    QString PB7=ui->PB7->text();
    QString PB8=ui->PB8->text();
    QString PB9=ui->PB9->text();
    int flag=0;
    if(PB1==PB2 && PB2==PB3){
        flag=1;
        if(PB1=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(PB4==PB5&& PB5==PB6){
         flag=1;
        if(PB4=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(PB7== PB8&& PB8==PB9){
         flag=1;
        if(PB7=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(PB1==PB4&& PB4==PB7){
         flag=1;
        if(PB1=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(PB2==PB5&&PB5==PB8){
         flag=1;
        if(PB2=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(PB3==PB6&&PB6==PB9){
         flag=1;
        if(PB3=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(PB1==PB5&&PB5==PB9){
         flag=1;
        if(PB1=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(PB3==PB5&&PB5==PB7){
         flag=1;
        if(PB3=="X")
            QMessageBox::information(this,"RESULT","Congratulation Player X Wins");
        else QMessageBox::information(this,"RESULT","Congratulation Player O Wins");
    }else if(count==10){
         flag=1;
        QMessageBox::information(this,"RESULT","DRAWN");
    }
    if(flag){
        this->hide();
        Widget *w= new Widget();
        w->show();
    }
}

void board::on_PB1_clicked()
{
    qDebug()<<count;
    if(ui->PB1->text()=="X" ||ui->PB1->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB1->setText("X");
    }else{
        ui->PB1->setText("O");
    }
    count++;
    Check();
}

void board::on_PB2_clicked()
{
    qDebug()<<count;
    if(ui->PB2->text()=="X" ||ui->PB2->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB2->setText("X");
    }else{
        ui->PB2->setText("O");
    }
    count++;
    Check();
}

void board::on_PB3_clicked()
{
    qDebug()<<count;
    if(ui->PB3->text()=="X" ||ui->PB3->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB3->setText("X");
    }else{
        ui->PB3->setText("O");
    }
    count++;
    Check();

}

void board::on_PB4_clicked()
{
    qDebug()<<count;
    if(ui->PB4->text()=="X" ||ui->PB4->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB4->setText("X");
    }else{
        ui->PB4->setText("O");
    }
    count++;
    Check();
}

void board::on_PB5_clicked()
{
    qDebug()<<count;
    if(ui->PB5->text()=="X" ||ui->PB5->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB5->setText("X");
    }else{
        ui->PB5->setText("O");
    }
    count++;
    Check();
}

void board::on_PB6_clicked()
{
    qDebug()<<count;
    if(ui->PB6->text()=="X" ||ui->PB6->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB6->setText("X");
    }else{
        ui->PB6->setText("O");
    }
    count++;
    Check();
}

void board::on_PB7_clicked()
{
    qDebug()<<count;
    if(ui->PB7->text()=="X" ||ui->PB7->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB7->setText("X");
    }else{
        ui->PB7->setText("O");
    }
    count++;
    Check();
}

void board::on_PB8_clicked()
{
    qDebug()<<count;
    if(ui->PB8->text()=="X" ||ui->PB8->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB8->setText("X");
    }else{
        ui->PB8->setText("O");
    }
    count++;
    Check();
}

void board::on_PB9_clicked()
{
    qDebug()<<count;
    if(ui->PB9->text()=="X" ||ui->PB9->text()=="O" ){
        QMessageBox::critical(this,"Error","Wrong Move");
        return;
    }
    if(count%2!=0){
        ui->PB9->setText("X");
    }else{
        ui->PB9->setText("O");
    }
    count++;
    Check();
}
