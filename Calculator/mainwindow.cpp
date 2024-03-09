#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

double firstnum;
bool UserisTypingSecondNumber=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_1,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_2,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_3,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_4,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_5,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_6,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_7,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_8,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->pushButton_9,&QPushButton::released,this,&MainWindow::digit_pressed);
    connect(ui->PlusMinus,&QPushButton::released,this,&MainWindow::unary_operation_pressed);
    connect(ui->MOD,&QPushButton::released,this,&MainWindow::unary_operation_pressed);
    connect(ui->Plus,&QPushButton::released,this,&MainWindow::binary_operation_pressed);
    connect(ui->minus,&QPushButton::released,this,&MainWindow::binary_operation_pressed);
    connect(ui->multiply,&QPushButton::released,this,&MainWindow::binary_operation_pressed);
    connect(ui->divide,&QPushButton::released,this,&MainWindow::binary_operation_pressed);

    ui->Plus->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->multiply->setCheckable(true);
    ui->divide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{

    QPushButton * button = (QPushButton*)sender();

    double labelnumber;
    QString newlabel;
    if((ui->Plus->isChecked() ||ui->minus->isChecked()
        || ui->multiply->isChecked()|| ui->divide->isChecked())&& (!UserisTypingSecondNumber)){
        labelnumber=button->text().toDouble();
        UserisTypingSecondNumber=true;
        newlabel =QString::number(labelnumber,'g',15);
    }else{
        if(ui->label->text().contains(".") && button->text()=="0"){
            newlabel= ui->label->text()+button->text();
        }else{

            labelnumber=(ui->label->text()+button->text()).toDouble();
            newlabel=QString::number(labelnumber,'g',15);
        }
    }

    ui->label->setText(newlabel);

}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelnumber;
    QString newlabel;
    if(button->text()=="+/-"){
        labelnumber= ui->label->text().toDouble();
        labelnumber=labelnumber*(-1);
        newlabel =QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
    }
    if(button->text()=="%"){
        labelnumber= ui->label->text().toDouble();
        labelnumber=labelnumber*(0.001);
        newlabel =QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
    }
}

void MainWindow::binary_operation_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    firstnum= ui->label->text().toDouble();
    button->setChecked(true);
}


void MainWindow::on_decimal_released()
{
    ui->label->setText(ui->label->text()+'.');
}

void MainWindow::on_equal_released()
{
    double labelNumber, secondNumber;
    QString newlabel;
    secondNumber=ui->label->text().toDouble();
    if(ui->Plus->isChecked()){
        labelNumber= firstnum+secondNumber;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->Plus->setChecked(false);
    }
    if(ui->multiply->isChecked()){
        labelNumber= firstnum*secondNumber;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->multiply->setChecked(false);
    }
    if(ui->minus->isChecked()){
        labelNumber= firstnum-secondNumber;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->minus->setChecked(false);
    }
    if(ui->divide->isChecked()){
        labelNumber= firstnum/secondNumber;
        newlabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newlabel);
        ui->divide->setChecked(false);
    }
    UserisTypingSecondNumber=false;
}

void MainWindow::on_clear_released()
{
    ui->label->setText("0");
    ui->Plus->setChecked(false);
    ui->minus->setChecked(false);
    ui->multiply->setChecked(false);
    ui->divide->setChecked(false);

    UserisTypingSecondNumber=false;

}
