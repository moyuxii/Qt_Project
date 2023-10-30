#include "baseinfo.h"

baseInfo::baseInfo(QWidget *parent):QWidget(parent)
{
    leftLayout = new QGridLayout();
    userName = new QLabel(tr("用户名:"));
    userName_lt = new QLineEdit;
    name = new QLabel(tr("姓名:"));
    name_lt = new QLineEdit;
    sex = new QLabel(tr("性别:"));
    sex_cb = new QComboBox;
    sex_cb->addItem("男");
    sex_cb->addItem("女");
    department = new QLabel(tr("部门:"));
    dept_lt = new QTextEdit;
    old = new QLabel(tr("年龄:"));
    old_lt = new QLineEdit;
    other = new QLabel("备注:");
    //设置标签控件框架样式
    other->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    leftLayout->addWidget(userName,0,0);
    leftLayout->addWidget(userName_lt,0,1);
    leftLayout->addWidget(name,1,0);
    leftLayout->addWidget(name_lt,1,1);
    leftLayout->addWidget(sex,2,0);
    leftLayout->addWidget(sex_cb,2,1);
    leftLayout->addWidget(department,3,0);
    leftLayout->addWidget(dept_lt,3,1);
    leftLayout->addWidget(old,4,0);
    leftLayout->addWidget(old_lt,4,1);
    leftLayout->addWidget(other,5,0,1,2);
    //设定每列占比，此处设置1，2列比例为 1：3
    leftLayout->setColumnStretch(0,1);
    leftLayout->setColumnStretch(1,3);

    rightLayout=new QGridLayout;
    picture = new QLabel(tr("头像:"));
    describe = new QLabel(tr("个人说明:"));
    desc_lt = new QTextEdit;
    update = new QPushButton(tr("更新"));
    rightLayout->addWidget(picture,0,0);
    rightLayout->addWidget(update,0,1);
    rightLayout->addWidget(describe,1,0,1,2);
    rightLayout->addWidget(desc_lt,2,0,1,2);

    mainLayout = new QGridLayout(this);
    mainLayout->addLayout(leftLayout,0,0);
    mainLayout->addLayout(rightLayout,0,1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


}


baseInfo::~baseInfo(){

}
