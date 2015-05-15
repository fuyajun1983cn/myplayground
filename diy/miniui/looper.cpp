#include "looper.h"
#include "message.h"
#include "messagequeue.h"
#include "handler.h"

#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

Looper* Looper::sMainLooper = 0;
QThreadStorage<Looper*> Looper::sThreadLocal = new QThreadStorage<Looper*>();

Looper::Looper(bool quitAllowed)
{
    mQueue = new MessageQueue(quitAllowed);
}

void Looper::prepare()
{
    prepare(true);
}

void Looper::prepare(bool quitAllowed)
{
    if (!sThreadLocal.hasLocalData()) {
        qDebug()<<"Only one Looper may be created per thread";
        return;
    }
    sThreadLocal.setLocalData(new Looper(quitAllowed));
}

static QMutex mutex;
void Looper::prepareMainLooper()
{
    prepare(false);
    mutex.lock();
    if (sMainLooper != 0) {
        qDebug()<<"The main Looper has already been prepared.";
        return;
    }
    sMainLooper = myLooper();
    mutex.unlock();
}

Looper Looper::getMainLooper() const
{
    QMutexLocker locker(&mutex);
    return sMainLooper;
}

void Looper::loop()
{
    Looper *me = myLooper();
    if (me == 0) {
        QDebug()<<"No Looper, Looper.prepare() wasn't called on this thread?";
        Q_ASSERT(0);
    }
    MessageQueue *queue = me->mQueue;
    for(;;) {
        Message *msg = queue->next();
        if (msg == 0) {
            //no message indicates that the message queue is quiting
            return;
        }

       msg->target->dispatchMessage(msg);

       msg->recyle();
    }
}

Looper* Looper::myLooper()
{
    return sThreadLocal.localData();
}

MessageQueue* Looper::myQueue()
{
    return myLooper()->mQueue;
}

void Looper::quit()
{
    mQueue->quit(false);
}
