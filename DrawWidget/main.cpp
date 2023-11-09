#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFont font("ZYSongl8030",12);
    a.setFont(font);
    w.show();
    return a.exec();
}
