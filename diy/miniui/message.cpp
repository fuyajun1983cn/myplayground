#include "message.h"

#include <QMutexLocker>
#include <QDebug>

Message * Message::sPool = 0;
int Message::sPoolSize = 0;
QMutex Message::sPoolSync;

Message::Message()
{
    what = 0;
    arg1 = 0;
    arg2 = 0;
    target = NULL;
    flags = 0;
    callback = 0;
}

Message* Message::obtain()
{
    QMutexLocker locker(&sPoolSync);
    {
        if (sPool != 0) {
            Message *m = sPool;
            sPool = m->next;
            m->next = 0;
            sPoolSize--;
            return m;
        }
    }
    return new Message();
}

void Message::recyle()
{
    what = 0;
    arg1 = 0;
    arg2 = 0;
    target = NULL;
    flags = 0;
    callback = 0;

    QMutexLocker locker(&sPoolSync);
    {
        if (sPoolSize < MAX_POLL_SIZE) {
            next = sPool;
            sPool = this;
            sPoolSize++;
        }
    }
}

void Message::dump()
{
    QMutexLocker locker(&sPoolSync);
    qDebug()<<"Current Poll Size: "<<sPoolSize;
}
