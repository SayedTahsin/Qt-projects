#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Student Database Management System");
    w.show();
    return a.exec();
}
/*
  splachScrene
  Menu:
       1.AddInfo.
       2.Show Specific Student's Info
       3.Show All Students Info
       4.Modify Info
       5.Delete Info
*/
