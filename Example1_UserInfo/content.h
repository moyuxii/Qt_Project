#ifndef CONTENT_H
#define CONTENT_H
#include <QFrame>
#include <QStackedWidget>
#include <QPushButton>
#include <baseinfo.h>
#include <contact.h>
#include <detail.h>
class Content:public QFrame
{
    Q_OBJECT
public:
    Content(QWidget *parent=nullptr);
    ~Content();
    QStackedWidget *stack;

private:

    QPushButton *bt_ok;
    QPushButton *bt_cl;
    baseInfo *b;
    contact *c;
    detail *d;
};

#endif // CONTENT_H
