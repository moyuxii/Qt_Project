#include "drawwidget.h"
#include <QMouseEvent>
#include <QPen>
#include <QPainter>
DrawWidget::DrawWidget(QWidget *parent):QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600,400);
}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    startPos = event->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter *painter = new QPainter;
    QPen pen ;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(weight);
    pen.setColor(color);
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos,event->pos());
    painter->end();
    startPos = event->pos();
    update();
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(QPoint(0,0),*pix);
}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if(height()>pix->height() || width()>pix->width()){
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        pix =  newPix;
    }
    QWidget::resizeEvent(event);
}

void DrawWidget::setStyle(int s)
{
    style = s;
}

void DrawWidget::setWidth(int w)
{
    weight = w;
}

void DrawWidget::setColor(QColor c)
{
    color = c;
}

void DrawWidget::clear()
{
    QPixmap *clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}

