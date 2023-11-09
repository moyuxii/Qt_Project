#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QMainWindow>

class DrawWidget:public QWidget
{
    Q_OBJECT
public:
    DrawWidget(QWidget *parent=nullptr);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
    QPixmap *pix;
    QPoint startPos;
    QPoint endPos;
    int style;
    int weight;
    QColor color;
public slots:
    void setStyle(int);;
    void setWidth(int);
    void setColor(QColor);
    void clear();
};

#endif // DRAWWIDGET_H
