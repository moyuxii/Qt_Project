#include "udpclient.h"
#include "udpserver.h"
#include "networkinformation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Networkinformation n;
    UdpClient w;
    UdpServer s;
//    s.show();
//    w.show();
    n.show();
    return a.exec();
}
