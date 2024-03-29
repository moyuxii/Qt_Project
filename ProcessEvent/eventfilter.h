#ifndef EVENTFILTER_H
#define EVENTFILTER_H
#include <QDialog>
#include <QLabel>
#include <QImage>
#include <QEvent>

class EventFilter : public QDialog
{
    Q_OBJECT
public:
    EventFilter(QWidget *parent=nullptr,Qt::WindowFlags f=0);
    ~EventFilter();
public slots:
    bool eventFilter(QObject *watched, QEvent *event);
private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *stateLabel;
    QImage Imagel;
    QImage Image2;
    QImage Image3;
};

#endif // EVENTFILTER_H
