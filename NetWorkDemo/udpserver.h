#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
class UdpServer:public QDialog
{
    Q_OBJECT
public:
    UdpServer(QWidget *parent=nullptr);
    ~UdpServer();


public slots:
    void StartBtnClicked();
    void timeout();

private:
    QLabel *TimerLabel;
    QLineEdit *TextLineEdit;
    QPushButton *StartBtn;
    QVBoxLayout *mainLayout;
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
};

#endif // UDPSERVER_H