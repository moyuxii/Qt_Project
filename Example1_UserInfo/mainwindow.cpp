#include "mainwindow.h"
#include <QSplitter>
#include <QListWidget>
#include <content.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSplitter *split = new QSplitter(Qt::Horizontal,0);
    QListWidget *list = new QListWidget(split);
    list->addItem("基础信息");
    list->addItem("联系方式");
    list->addItem("详细信息");
    Content *c =new Content(split);
    connect(list,SIGNAL(currentRowChanged(int)),c->stack,SLOT(setCurrentIndex(int)));
    setCentralWidget(split);
}

MainWindow::~MainWindow()
{
}

