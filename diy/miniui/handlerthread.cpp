#include "handlerthread.h"
#include "looper.h"

#include <QWaitCondition>
#include <QMutex>

HandlerThread::HandlerThread()
{
    mCondition = new QWaitCondition;
    mMutex = new QMutex;
    mLooper = 0;
}

HandlerThread::~HandlerThread()
{
    delete mCondition;
    delete mMutex;
    delete mLooper;
}

void HandlerThread::run()
{
    Looper::prepare();
    mMutex->lock();
    mLooper = Looper::myLooper();
    mCondition->wakeAll();
    mMutex->unlock();
    Looper::loop();
}

Looper* HandlerThread::getLooper() const
{
    if (!isRunning())
        return 0;

    mMutex->lock();
    while( isRunning() && mLooper == 0 ) {
        mCondition->wait(mMutex);
    }
    mMutex->unlock();

    return mLooper;
}

bool HandlerThread::quit()
{
    Looper *looper = getLooper();
    if (looper != 0) {
        looper->quit();
        return true;
    }
    return false;
}

bool HandlerThread::quitSafely()
{

}
