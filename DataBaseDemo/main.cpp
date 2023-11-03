#include "mainwindow.h"
#include "connectdlg.h"
#include <QApplication>
#include <QCoreApplication>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
   // QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    ConnDlg dialog;
    if(dialog.exec() != QDialog::Accepted){
        return -1;
    }
    QFile *carDetails = new QFile("attribs.xml");
    MainWindow window ("factory", "cars", carDetails);
    window.show();
    return a.exec();

}
