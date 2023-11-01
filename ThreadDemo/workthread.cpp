#include "workthread.h"
#include <QtDebug>
WorkThread::WorkThread()
{

}

void WorkThread::run()
{
  while(true){
      for(int i=0;i<10;i++){
          qDebug()<<i;
      }
  }
}
