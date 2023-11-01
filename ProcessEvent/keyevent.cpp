#include "keyevent.h"
#include <QPainter>
#include <QPen>
#include <QKeyEvent>
#include <QDebug>
KeyEvent::KeyEvent(QWidget *parent):QWidget(parent)
{
    setWindowTitle(("键盘事件")) ;
    setAutoFillBackground(true);
    QPalette palette = this->palette ();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);
    setMinimumSize(512,256);
    setMaximumSize(512,256);
    width=size().width();
    height=size().height();
    pix= new QPixmap(width,height);
    pix->fill (Qt::white);
    image.load("printText.png");
    qDebug()<<image.size().width();
    startX=100;
    startY=100;
    step=20;
    drawPix();
    resize(512,256);
}

KeyEvent::~KeyEvent()
{

}

void KeyEvent::drawPix()
{
    pix->fill (Qt::white); //重新刷新 pix 对象为白色底色
    QPainter *painter = new QPainter; //创建一个 QPainter 对象
    QPen pen (Qt:: DotLine); //(a)
    for(int i=step;i<width;i=i+step) //按照步进值的间隔绘制纵向的网格线
    {
        painter->begin(pix); //指定 pix 为绘图设备
        //painter->setPen (pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }
    for(int j=step; j<height; j=j+step) //按照步进值的间隔绘制横向的网格线
    {
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(QPoint(0,j),QPoint(width,j));
    painter->end ();
    }
    painter->begin(pix);
    painter->drawImage(QPoint(startX,startY),image); //(b)
    painter->end();
}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
    //按住ctrl模式
    if(event->modifiers()==Qt::ControlModifier){
        if(event->key()==Qt::Key_Left){
            startX= (startX-1<0) ?startX:startX-1;
        }
        if (event->key ()==Qt::Key_Right){
            startX= (startX+1+image.width()>width)?startX: startX+1;
        }
        if (event->key ()==Qt::Key_Up){
            startY=(startY-1<0)?startY:startY-1;
        }
        if(event->key()==Qt::Key_Down){
            startY= (startY+1+image.height() >height) ?startY: startY+1;
        }
    }else{
        startX=startX-startX%step;
        startY=startY-startY%step;
        if (event->key () ==Qt::Key_Left){
            startX=(startX-step<0)?startX:startX-step;
        }
        if (event->key ()==Qt::Key_Right){
            startX= (startX+step+image.width()>width)?startX: startX+step;
        }
        if (event->key ()==Qt::Key_Up){
            startY=(startY-step<0)?startY:startY-step;
        }
        if(event->key()==Qt::Key_Down){
            startY= (startY+step+image.height() >height) ?startY: startY+step;
        }
        if(event->key()==Qt::Key_Home){
            startX=0;
            startY=0;
        }
        if(event->key()==Qt::Key_End){
            startX=width-image.width();
            startY=height-image.height();
        }
    }
    drawPix();
    update();
}

void KeyEvent::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}
