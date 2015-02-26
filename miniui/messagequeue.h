#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <QMutex>

class Message;

class MessageQueue
{
public:
    MessageQueue(bool quitAllowed);
    Message* next();
    void quit(bool safe);
    bool enqueueMessage(Message *msg, long when);

private:

    void removeAllFutureMessagesLocked();
    void removeAllMessagesLocked();

    bool mQuitAllowed;
    Message *mMessages;
    bool mBlocked;
    bool mQuiting;
    QMutex mMutex;
};

#endif // MESSAGEQUEUE_H
