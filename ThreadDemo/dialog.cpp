#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Dialog::Dialog(QWidget *parent):QDialog(parent)
{
    setWindowTitle("多线程时间服务器");
    label1 = new QLabel(tr("服务器端口: "));
    label2 = new QLabel;
    quitBtn = new QPushButton(tr("退出"));
    QHBoxLayout *BtnLayout = new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(quitBtn);
    BtnLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(label1);
    mainLayout->addWidget(label2);
    mainLayout->addLayout(BtnLayout);
    connect(quitBtn,SIGNAL(click()),this,SLOT(close()));
}

Dialog::~Dialog()
{

}
