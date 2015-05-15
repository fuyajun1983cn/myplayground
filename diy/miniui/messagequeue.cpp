#include "messagequeue.h"
#include "message.h"

#include <QMutexLocker>
#include <QDateTime>

MessageQueue::MessageQueue(bool quitAllowed)
    :mQuitAllowed(quitAllowed), mBlocked(false), mQuiting(false),mMessages(NULL)
{
}

Message* MessageQueue::next()
{
    int nextTimeoutMillis;

    for (;;) {
        {
            QMutexLocker locker(&mMutex);
            long now = QDateTime::currentDateTime().toTime_t();
            Message *prevMsg = NULL;
            Message *msg = mMessages;

            //FIXME: to handle more cases
            if (msg != NULL && msg->target != NULL) {
        #if 0
                if (now < msg->when) {
                    //set a timeout
                    nextTimeoutMillis = qMin(msg->when - now, LONG_MAX)
                }
#endif
                //got a message
                {
                    mBocked = false;
                    if (prevMsg != NULL) {
                        prevMsg->next = msg->next;
                    } else {
                        mMessages = msg->next;
                    }
                    msg->next = NULL;
                    msg->markInUse();
                    return msg;
                }
            } else {
                // No more messages
                nextTimeoutMillis = -1;
            }

            // Process the quit message now that all pending messages have been handled
            if (mQuiting) {
                //process quit msg
                return null;
            }
        }
    }
}

void MessageQueue::quit(bool safe)
{
    if (!mQuitAllowed) {
        qDebug()<<"Main thread not allowed to quit";
    }

    QMutexLocker locker(&mMutex);
    if (mQuiting) {
        return;
    }

    mQuiting = true;

    if (safe) {
        removeAllFutureMessagesLocked();
    } else {
        removeAllMessagesLocked();
    }
}

bool MessageQueue::enqueueMessage(Message *msg, long when)
{
    if (msg->isInUse()) {
        qDebug()<<"This message is already in use";
        return false;
    }
    if (msg->target != NULL) {
        qDebug()<<"Message must have a target";
        return false;
    }
    bool needWake;
    QMutexLocker locker(&mMutex);
    if (mQuiting) {
        return false;
    }

    msg->when = when;
    Message *p = mMessages;
    if (p == NULL || when = 0 || when < p->when) {
        //new head, wake up the event queue if blocked
        msg->next = p;
        mMessages = msg;
        needWake = mBlocked;
    } else {
        /**
          * inserted with the middle of the queue
          *
*/
           // needWake = mBlocked && p->target == NULL;
        Message prev;
        for (;;) {
            prev = p;
            p = p->next;
            if (p == NULL || when < p->when) {
                break;
            }
            //process other cases
        }

        msg->next = p;
        prev.next = msg;

    }

    if (needWake) {
        //do something
    }

    return true;
}

void MessageQueue::removeAllFutureMessagesLocked()
{
    long now = QDateTime::currentDateTime().toTime_t();
    Message *p = mMessages;
    if (p != NULL) {
        if (p->when > now) {
            removeAllMessagesLocked();
        } else {
            Message *n;
            for (;;) {
                n = p->next;
                if (n == NULL) {
                    return;
                }
                if (n->when > now)
                    break;
                p = n;
            }
            p->next = NULL;
            do {
                p = n;
                n = p->next;
                p->recyle();
            } while (n != NULL);
        }
    }
}

void MessageQueue::removeAllMessagesLocked()
{
    Message *p = mMessages;
    while (p != NULL) {
        Message *n = p->next;
        p->recyle();
        p = n;
    }
    mMessages = NULL;
}
