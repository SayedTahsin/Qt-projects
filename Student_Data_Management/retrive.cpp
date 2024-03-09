#include "retrive.h"
#include "ui_retrive.h"
#include "mainwindow.h"
retrive::retrive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::retrive)
{
    ui->setupUi(this);
}

retrive::~retrive()
{
    delete ui;
}

void retrive::on_pushButton_clicked()
{
    QString id=ui->lineEdit_id->text();

    MainWindow  log;
    bool ok=log.openconnection();
    if(!ok)QMessageBox::critical(this,"error","Failed to open database");

    QSqlQuery qry;
    int flag=1;
    qry.prepare("select * from Students where ID='"+id+"'");
    if(qry.exec()){
        while(qry.next()){
            flag=0;
            ui->NAME_label->setText(qry.value(1).toString());
            ui->CC_label->setText(qry.value(2).toString());
            ui->CGPA_label->setText(qry.value(3).toString());
            ui->MOBILE_label->setText(qry.value(4).toString());
            ui->ADDRESS_label->setText(qry.value(5).toString());
        }
        if(flag){
            ui->NAME_label->setText(" ");
            ui->CC_label->setText(" ");
            ui->CGPA_label->setText(" ");
            ui->MOBILE_label->setText(" ");
            ui->ADDRESS_label->setText(" ");
            QMessageBox::information(this,"NO RECORD FOUND","NO Such Record Found");
        }
    }else
        QMessageBox::critical(this,"Error",qry.lastError().text());

    log.closeconnection();
}
