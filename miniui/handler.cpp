#include "handler.h"
#include "message.h"
#include "messagequeue.h"

#include <QThreadPool>
#include <QDateTime>
#include <QDebug>

Handler::Handler(Looper *looper)
{
    this(looper, false);
}

Handler::Handler(Looper *looper, bool async)
{
    mLooper = looper;
    mAsynchronous = async;
}

bool Handler::enqueueMessage(MessageQueue *queue, Message *msg, long uptimeMillis)
{
    msg->target = this;

    return queue->enqueueMessage(msg, uptimeMillis);
}

void Handler::dispatchMessage(Message *msg)
{
    if (msg->callback != NULL) {
        QThreadPool::globalInstance()->start(msg->callback);
    } else {
        handleMessage(msg);
    }
}

void Handler::removeMessages(int what)
{

}

bool Handler::sendMessageAtTime(Message *msg, long uptimeMillis)
{
    MessageQueue *queue = mQueue;
    if (queue == NULL) {
        qDebug()<<"Message Queue is NULL !!!";
        return false;
    }
    return enqueueMessage(queue, msg, uptimeMillis);
}

bool sendMessage(Message *msg)
{
    return sendMessageDelayed(msg, 0);
}

bool sendEmptyMessage(int what)
{
    return sendEmptyMessageDelayed(what, 0);
}

bool sendEmptyMessageDelayed(int what, long delayMillis)
{
    Message *msg = Message::obtain();
    msg->what = what;
    return sendMessageDelayed(msg, delayMillis);
}

bool sendEmptyMessageAtTime(int what, long uptimeMillis)
{
    Message *msg = Message::obtain();
    msg->what = what;
    return sendMessageAtTime(msg, uptimeMillis);
}

bool sendMessageDelayed(Message *msg, long delayMillis)
{
    if (delayMillis < 0)
        delayMillis = 0;

    return sendMessageAtTime(msg, QDateTime::currentDateTime().addMSecs(delayMillis).toTime_t());
}

bool Handler::sendMessageAtFrontOfQueue(Message *msg)
{
    MessageQueue *queue = mQueue;
    if (queue == NULL) {
        qDebug()<<"Message Queue is NULL !!!";
        return false;
    }
    return enqueueMessage(queue, msg, 0);
}
