#include "timeserver.h"
#include "timethread.h"
#include "dialog.h"
TimeServer::TimeServer(QObject *parent):QTcpServer(parent)
{
   dlg = (Dialog *)parent;
}

void TimeServer::incomingConnection(qintptr handle)
{
    TimeThread *thread = new TimeThread(handle,0);
    connect(thread,SIGNAL(finished()),dlg,SLOT(slotShow()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);
    thread->start();
}
