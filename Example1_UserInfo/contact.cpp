#include "contact.h"

contact::contact(QWidget *parent):QWidget(parent)
{
    email = new QLabel(tr("电子邮件:"));
    email_lt = new QLineEdit;
    address = new QLabel(tr("联系地址:"));
    address_lt = new QLineEdit;
    code = new QLabel(tr("邮政编码:"));
    code_lt = new QLineEdit;
    mobilePhone = new QLabel(tr("移动电话:"));
    mobile_lt = new QLineEdit;
    busPhone = new QLabel(tr("办公电话:"));
    bus_lt = new QLineEdit;
    flag = new QCheckBox(tr("接受留言"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(email,0,0);
    mainLayout->addWidget(email_lt,0,1);
    mainLayout->addWidget(address,1,0);
    mainLayout->addWidget(address_lt,1,1);
    mainLayout->addWidget(code,2,0);
    mainLayout->addWidget(code_lt,2,1);
    mainLayout->addWidget(mobilePhone,3,0);
    mainLayout->addWidget(mobile_lt,3,1);
    mainLayout->addWidget(flag,3,2);
    mainLayout->addWidget(busPhone,4,0);
    mainLayout->addWidget(bus_lt,4,1);

    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}


contact::~contact(){

}
