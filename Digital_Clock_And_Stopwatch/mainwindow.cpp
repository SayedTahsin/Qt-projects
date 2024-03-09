#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QThread>

int startH,startM,startS;
int TimerH,TimerM,TimerS;
int TimerRunH,TimerRunM,TimerRunS;
int runH,runM,runS;
int pauseH=0,pauseM=0,pauseS=0;
QString dayName,month, day,year;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Time
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Showtime()));
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Showtime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    if(time.second()%2==0){
        time_text[3]=' ';
        time_text[8]=' ';
    }
    //Date
    QDateTime datetime=QDateTime::currentDateTime();
    QString datetimetext=datetime.toString();
    QStringList dt=datetimetext.split(" ");
    dayName=dt[0];
    month=dt[1];
    day=dt[2];
    year=dt[4];
    QString date= dayName+" "+month+","+day+" "+year;
    ui->label_Time->setText(date+"\n"+time_text);
}
//1.Start
//      i.Stop
//      ii.Lap
//2.Stop
//      i.Resume
//      ii.Reset

void MainWindow::StopWatchTime()
{
    QTime time=QTime::currentTime();
    runH=time.hour()-startH;
    runM=time.minute()-startM;
    runS=time.second()-startS;
    if(runS<0){
        runS+=60;
        runM--;
    }
    if(runM<0){
        runM+=60;
        runH--;
    }
    if(runH<0){
        runH+=24;
    }
    runS+=pauseS;
    if(runS>60){
        runM++;
        runS-=60;
    }
    runM+=pauseM;
    if(runM>60){
        runH++;
        runM-=60;
    }
    ui->Stopwatch_label->setText(QString::number(runH)+":"+QString::number(runM)+":"+QString::number(runS));
}


void MainWindow::on_Start_clicked()
{

    QTime time=QTime::currentTime();
    startH=time.hour();
    startM=time.minute();
    startS=time.second();
    timer2=new QTimer(this);
    timer2->start();
    connect(timer2,SIGNAL(timeout()),this,SLOT(StopWatchTime()));
    ui->Start->setEnabled(false);
    ui->Start->setText("Resume");
    ui->Stop->setEnabled(true);
    ui->Lap->setEnabled(true);
    ui->reset->setEnabled(false);

}

void MainWindow::on_Stop_clicked()
{
    timer2->stop();
    QString pause=ui->Stopwatch_label->text();
    QStringList HMS = pause.split(":");
    pauseH=HMS[0].toInt();
    pauseM=HMS[1].toInt();
    pauseS=HMS[2].toInt();

    ui->reset->setEnabled(true);
    ui->Start->setEnabled(true);
    ui->Lap->setEnabled(false);
    ui->Stop->setEnabled(false);
}

void MainWindow::on_Lap_clicked()
{
    QString lap=ui->Stopwatch_label->text();
    ui->listWidget->addItem(lap);
}

void MainWindow::on_reset_clicked()
{
    pauseH=0;
    pauseM=0;
    pauseS=0;
    ui->Stopwatch_label->setText("0:0:0");
    ui->Start->setText("Start");
    ui->Start->setEnabled(true);
    ui->Lap->setEnabled(false);
    ui->Stop->setEnabled(false);
    ui->reset->setEnabled(false);
    ui->listWidget->clear();
}


