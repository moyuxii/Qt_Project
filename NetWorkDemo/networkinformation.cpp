#include "networkinformation.h"
#include <QHostInfo>
#include <QNetworkInterface>
#include <QDebug>
#include <QTextEdit>
Networkinformation::Networkinformation(QWidget *parent):QWidget(parent)
{
    hostLabel = new QLabel(tr(" 主机名： ")) ;
    LineEditLocalHostName= new QLineEdit;
    ipLabel = new QLabel(tr("IP 地址： ")) ;
    LineEditAddress = new QLineEdit;
    detailBtn = new QPushButton(tr(" 详细")) ;
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(hostLabel,0,0);
    mainLayout->addWidget(LineEditLocalHostName,0,1);
    mainLayout->addWidget(ipLabel,1,0);
    mainLayout->addWidget(LineEditAddress,1,1);
    mainLayout->addWidget(detailBtn,2,0,1,2);
    getHostinformation();
    connect (detailBtn, SIGNAL (clicked()), this, SLOT (slotDetail ()));
}


Networkinformation::~Networkinformation(){

}

void Networkinformation::getHostinformation()
{
    QString localhostname = QHostInfo::localHostName();
    LineEditLocalHostName->setText(localhostname);
    QHostInfo hostinfo = QHostInfo::fromName(localhostname);
    QList<QHostAddress> listAddress = hostinfo.addresses();
    if(!listAddress.isEmpty()){
        LineEditAddress->setText(listAddress.last().toString());
//        for(QHostAddress a :listAddress){
//            qDebug()<<a.toString();
//        }
    }

}

void Networkinformation::slotDetail()
{
    QString detail ="";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for(QNetworkInterface i:list){
        detail = detail+tr("设备")+i.name()+"\n";
        detail = detail+tr("硬件地址")+i.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList = i.addressEntries();
        for(QNetworkAddressEntry e:entryList){
            if(e.ip().protocol() == QAbstractSocket::IPv4Protocol && e.ip() != QHostAddress::LocalHost)    {
            detail = detail+"\t"+tr("IP地址:")+e.ip().toString()+"\n";
            detail = detail+"\t"+tr("子网掩码:")+e.netmask().toString()+"\n";
            detail = detail+"\t"+tr("广播地址:")+e.broadcast().toString()+"\n";}

        }
    }
    QDialog *w = new QDialog;
    w->resize(400,400);
    QTextEdit *e = new QTextEdit(w);
    e->append(detail);
    w->show();
}
