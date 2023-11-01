#include "threaddlg.h"
#include "dialog.h"
#include <QApplication>
#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QtDebug>
const int DataSize=1000;
const int BufferSize=80;
int buffer[BufferSize];
//信号
QSemaphore freeBytes(BufferSize);
QSemaphore useBytes(0);
//唤醒与等待
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numUsedBytes=0;
int rIndex=0;


class Producer: public QThread
{
public:
    Producer();
    void run();
};


Producer::Producer()
{

}

void Producer::run()
{
    for(int i=0;i<DataSize;i++){
//        freeBytes.acquire();
//        buffer[i%BufferSize]=(i%BufferSize);
//        useBytes.release();
        mutex.lock();
        if(numUsedBytes==BufferSize){
            bufferEmpty.wait(&mutex);
        }
        buffer[i%BufferSize]=numUsedBytes;
        ++numUsedBytes;
        bufferFull.wakeAll();
        mutex.unlock();
    }
}


class Consumer:public QThread
{
public:
    Consumer();
    void run();
};

Consumer::Consumer()
{

}

void Consumer::run()
{
    for(int i=0;i<DataSize;i++){
//       useBytes.acquire();
//       qDebug()<<buffer[i%BufferSize];
//        if(i%16==0&&i!=0){
//            qDebug()<<"\n";
//        }
//        freeBytes.release();
        mutex.lock();
        if(numUsedBytes==0){
            bufferFull.wait(&mutex);
        }
        printf("%u1::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);
        rIndex=(++rIndex)%BufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
    qDebug()<<"\n";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog w;
    w.show();
//    Producer producer;
//    Consumer consumer;
//    Consumer consumer2;
//    //／＊启动生产者和消费者线程＊／
//    producer.start();
//    consumer.start();
//    consumer2.start();
//    //／＊等待生产者和消费者各自执行完毕后自动退出＊／
//    producer.wait();
//    consumer.wait();
//    consumer2.wait();
    return a.exec();
}
