#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("鼠标事件");
    statusLabel = new QLabel;
    statusLabel->setText(tr("当前位置: "));
    statusLabel->setFixedWidth(100);
    MousePosLabel = new QLabel;
    MousePosLabel->setText(tr(""));
    MousePosLabel->setFixedWidth(100);
    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(MousePosLabel);
    resize(400,200);
}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x()) +","+QString::number(e->y())+")";
    if(e->button()==Qt::LeftButton){
        statusBar()->showMessage(tr ("左键： ")+str);
    }else if (e->button() ==Qt::RightButton){
        statusBar()->showMessage(tr("右键： ")+str);
    }else if (e->button()==Qt::MidButton){
        statusBar()->showMessage(tr("中键： ")+str);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QString str=" ("+QString::number(e->x())+","+QString::number(e->y()) +") ";
    statusBar()->showMessage(tr(" 释放在： ") +str, 300);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    MousePosLabel->setText ("("+QString::number (e->x()) +","+QString::number(e->y ()) +")");
}

