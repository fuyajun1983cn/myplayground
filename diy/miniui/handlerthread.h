#ifndef HANDLERTHREAD_H
#define HANDLERTHREAD_H

#include <QThread>

class Looper;
class QWaitCondition;
class QMutex;

class HandlerThread : public QThread
{
public:
    HandlerThread();
    virtual ~HandlerThread();

    void run();

    Looper* getLooper() const;
    bool quit();
    bool quitSafely();

private:
//    int mPriority;
//    int mTid;
    Looper *mLooper;
    QWaitCondition *mCondition;
    QMutex *mMutex;
};

#endif // HANDLERTHREAD_H
