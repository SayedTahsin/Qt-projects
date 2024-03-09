#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Digital Clock & Stopwatch with Timer");
    w.show();
    return a.exec();
}
