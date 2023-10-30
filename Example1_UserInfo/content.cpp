#include "content.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

Content::Content(QWidget *parent):QFrame(parent)
{
    stack = new QStackedWidget(this);
    b = new baseInfo;
    c = new contact;
    d = new detail;
    stack->addWidget(b);
    stack->addWidget(c);
    stack->addWidget(d);

    bt_ok = new QPushButton(tr("修改"));
    bt_cl = new QPushButton(tr("关闭"));
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(bt_ok);
    bottomLayout->addWidget(bt_cl);
    bottomLayout->addStretch(1);
    bottomLayout->setDirection(QBoxLayout::RightToLeft);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stack);
    mainLayout->addLayout(bottomLayout);

}

Content::~Content(){

}
