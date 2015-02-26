#ifndef MESSAGE_H
#define MESSAGE_H

#include <QRunnable>
#include <QMutex>

class Handler;


class Message
{
public:
    int what;
    int arg1;
    int arg2;
    long when;
    Handler *target;

    QRunnable *callback;

    void recyle();
    static Message* obtain();

    void dump();
    bool isInUse() const
    {
        return ((flags & FLAG_IN_USE) == FLAG_IN_USE);
    }

    void markInUse()
    {
        flags |= FLAG_IN_USE;
    }

private:
    Message();

    enum { MAX_POLL_SIZE = 50 };
    enum {
        FLAG_IN_USE = 1 << 0,
        FLAG_ASYNCHRONOUS = 1 << 1
    };

    static Message *sPool ;
    static QMutex sPoolSync;
    static int sPoolSize;

    Message *next;
    int flags;
};

#endif // MESSAGE_H
