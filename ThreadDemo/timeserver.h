#ifndef TIMESERVER_H
#define TIMESERVER_H
#include <QTcpServer>
class Dialog;
class TimeServer:public QTcpServer
{
    Q_OBJECT
public:
    TimeServer(QObject *parent=nullptr);

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle);
private:
    Dialog *dlg;
};

#endif // TIMESERVER_H
