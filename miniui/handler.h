#ifndef HANDLER_H
#define HANDLER_H

class Looper;
class Message;
class MessageQueue;

class Handler
{
public:
    Handler(Looper *looper);
    Handler(Looper *looper, bool async);

    virtual void handleMessage(Message* msg) {}
    void dispatchMessage(Message *msg);
    void removeMessages(int what);
    bool sendMessageAtTime(Message *msg, long uptimeMillis);
    bool sendMessage(Message *msg);
    bool sendEmptyMessage(int what);
    bool sendEmptyMessageDelayed(int what, long delayMillis);
    bool sendEmptyMessageAtTime(int what, long uptimeMillis);
    bool sendMessageDelayed(Message *msg, long delayMillis);
    bool sendMessageAtFrontOfQueue(Message *msg);

private:
    bool enqueueMessage(MessageQueue *queue, Message *msg, long uptimeMillis);

private:
    Looper *mLooper;
    MessageQueue *mQueue;
    bool mAsynchronous;
};

#endif // HANDLER_H
