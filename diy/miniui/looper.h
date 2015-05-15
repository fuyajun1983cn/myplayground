#ifndef LOOPER_H
#define LOOPER_H

#include <QThreadStorage>

class QThread;
class MessageQueue;

class Looper
{
public:

    static void prepare();
    static void prepare(bool quitAllowed);
    static void prepareMainLooper();
    static Looper getMainLooper() const;
    static void loop();
    static Looper* myLooper();
    static MessageQueue* myQueue();

    void quit();

private:
    Looper(bool quitAllowed);

    static Looper *sMainLooper;
    static QThreadStorage<Looper*> sThreadLocal;
    QThread *mThread;
    MessageQueue *mQueue;
};

#endif // LOOPER_H
