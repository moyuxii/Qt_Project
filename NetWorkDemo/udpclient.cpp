#include "udpclient.h"
#include <QMessageBox>
UdpClient::UdpClient(QWidget *parent):QDialog(parent)
{
    setWindowTitle(tr("UDP Client"));// 设置窗体的标题
    //／＊初始化各个控件＊／
    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);
    //／＊设置布局＊／
    mainLayout =new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);

    connect(CloseBtn, SIGNAL (clicked()), this, SLOT (CloseBtnClicked()));
    port =5555; // 设置 UDP 的端口号参数，指定在此端口上监听数据
    udpSocket = new QUdpSocket(this); //创建 QUdpSocket
    connect (udpSocket, SIGNAL (readyRead()), this, SLOT (dataReceived()));
    bool result=udpSocket->bind(port); //绑定到指定的端口上
    if(!result){
        QMessageBox::information(this,tr("error"),tr("udp socket create error! "));
        return ;
    }
}

UdpClient::~UdpClient()
{

}

void UdpClient::CloseBtnClicked()
{
    close();
}

void UdpClient::dataReceived()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg = datagram.data();
        ReceiveTextEdit->append("\n"+msg);
    }
}
