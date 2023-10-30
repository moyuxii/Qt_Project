
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QDebug>
#include <QToolBar>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("计算器（个人理解版）");
    resize(400,400);
    QWidget* centerWdiget = new QWidget;
    this->setCentralWidget(centerWdiget);
    text = new QLineEdit(this);
    text->setReadOnly(true);
    text->setFixedHeight(40);
    text->setAlignment(Qt::AlignRight);
    text->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    preNumber=0;
    flag = false;
    currentType=0;
    //定义两个按钮组
    //数字
    QButtonGroup* numberGroup = new QButtonGroup(this);
    //操作
    QButtonGroup* operationGroup = new QButtonGroup(this);
    //数字按钮对象实例化
    number0 = new QPushButton("0",this);
    number0->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number1 = new QPushButton("1",this);
    number1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number2 = new QPushButton("2",this);
    number2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number3 = new QPushButton("3",this);
    number3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number4 = new QPushButton("4",this);
    number4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number5 = new QPushButton("5",this);
    number5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number6 = new QPushButton("6",this);
    number6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number7 = new QPushButton("7",this);
    number7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number8 = new QPushButton("8",this);
    number8->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    number9 = new QPushButton("9",this);
    number9->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    point = new QPushButton(".",this);
    point->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    toBlack = new QPushButton("AC",this);
    toBlack->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    numberGroup->setExclusive(true);
    numberGroup->addButton(number0);
    numberGroup->addButton(number1);
    numberGroup->addButton(number2);
    numberGroup->addButton(number3);
    numberGroup->addButton(number4);
    numberGroup->addButton(number5);
    numberGroup->addButton(number6);
    numberGroup->addButton(number7);
    numberGroup->addButton(number8);
    numberGroup->addButton(number9);
    numberGroup->addButton(point);
    numberGroup->addButton(toBlack);


    add = new QPushButton("+",this);
    add->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    sub = new QPushButton("-",this);
    sub->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mult = new QPushButton("*",this);
    mult->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    div = new QPushButton("/",this);
    div->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    equals = new QPushButton("=",this);
    equals->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    operationGroup->setExclusive(true);
    operationGroup->addButton(add);
    operationGroup->addButton(sub);
    operationGroup->addButton(mult);
    operationGroup->addButton(div);
    operationGroup->addButton(equals);


    p_layout = new QGridLayout();
    p_layout->setContentsMargins(0,0,0,0);
    p_layout->setSpacing(0);
    p_layout->addWidget(text,0,0,2,4);
    p_layout->addWidget(toBlack,2,0,1,3);
    p_layout->addWidget(div,2,3);
    p_layout->addWidget(number7,3,0);
    p_layout->addWidget(number8,3,1);
    p_layout->addWidget(number9,3,2);
    p_layout->addWidget(mult,3,3);
    p_layout->addWidget(number4,4,0);
    p_layout->addWidget(number5,4,1);
    p_layout->addWidget(number6,4,2);
    p_layout->addWidget(sub,4,3);
    p_layout->addWidget(number1,5,0);
    p_layout->addWidget(number2,5,1);
    p_layout->addWidget(number3,5,2);
    p_layout->addWidget(add,5,3);
    p_layout->addWidget(number0,6,0,1,2);
    p_layout->addWidget(point,6,2);
    p_layout->addWidget(equals,6,3);

    centerWdiget->setLayout(p_layout);
    connect(equals,SIGNAL(onclick()),this,SLOT(getResult()));
    connect(numberGroup,SIGNAL(buttonClicked(QAbstractButton *)),this,SLOT(onNumberClick(QAbstractButton *)));
    connect(operationGroup,SIGNAL(buttonClicked(QAbstractButton *)),this,SLOT(onOperationClick(QAbstractButton *)));


}

MainWindow::~MainWindow()
{
    qDebug() << "this is end";
}

void MainWindow::getResult()
{
    int currentNum = (text->text()==""?0:text->text().toDouble());
    switch (this->currentType) {
    case 1:
        text->setText(QString::number(preNumber + currentNum));
        break;
    case 2:
        text->setText(QString::number(preNumber - currentNum));
        break;
    case 3:
        text->setText(QString::number(preNumber * currentNum));
        break;
    case 4:
        text->setText(QString::number(preNumber / currentNum));
        break;
    }
}


void MainWindow::onNumberClick(QAbstractButton* button){
    if(currentType!=0&&flag){
        preNumber = text->text().toDouble();
        text->setText("");
        flag = false;
    }
    if(button == number0&&text->text()!=""){
        text->insert("0");
    }else if(button == number1){
        text->insert("1");
    }else if(button == number2){
        text->insert("2");
    }else if(button == number3){
        text->insert("3");
    }else if(button == number4){
        text->insert("4");
    }else if(button == number5){
        text->insert("5");
    }else if(button == number6){
        text->insert("6");
    }else if(button == number7){
        text->insert("7");
    }else if(button == number8){
        text->insert("8");
    }else if(button == number9){
        text->insert("9");
    }else if(button == point&&!text->text().contains(".")){
        text->insert(".");
    }else if(button == toBlack){
         text->setText("");
         preNumber=0;
         currentType=0;
    }

}

void MainWindow::onOperationClick(QAbstractButton *button)
{
    if(preNumber!=0 || button == equals){
        getResult();
        preNumber=0;
    }
    if(button==add){
        currentType=1;
        flag = true;
    }else if (button == sub){
        currentType = 2;
        flag = true;
    }else if (button == mult){
        currentType = 3;
        flag = true;
    }else if (button == div){
        currentType = 4;
        flag = true;
    }else if (button == equals){
        currentType=0;
    }
}




// QObject::connect(w.button, SIGNAL(clicked()), &w, SLOT(changeText()));
