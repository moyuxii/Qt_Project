#include "detail.h"

detail::detail(QWidget *parent):QWidget(parent)
{
    mainLayout = new QGridLayout(this);

    guo = new QLabel(tr("国家:"));
    guo_cb = new QComboBox;
    guo_cb->addItem(tr("中国"));
    shen = new QLabel(tr("省份:"));
    shen_cb = new QComboBox;
    shen_cb->addItem(tr("安徽省"));
    shi = new QLabel(tr("城市:"));
    shi_lt = new QLineEdit;
    desc = new QLabel(tr("个人说明:"));
    desc_lt = new QLineEdit;

    mainLayout->addWidget(guo,0,0);
    mainLayout->addWidget(guo_cb,0,1);
    mainLayout->addWidget(shen,1,0);
    mainLayout->addWidget(shen_cb,1,1);
    mainLayout->addWidget(shi,2,0);
    mainLayout->addWidget(shi_lt,2,1);
    mainLayout->addWidget(desc,3,0);
    mainLayout->addWidget(desc_lt,3,1);

    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


}
