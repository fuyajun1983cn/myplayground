#ifndef THREADS_H
#define THREADS_H

#include "helpers.h"
#include <string>
#include <pthread.h>
#include <sys/time.h>

using std::string;

typedef int status_t;

/*
 *
 * @brief Simple Mutex Class:  the mutex must unlock by the thread that lock it. no recursive lock supported
 * you cannot lock it multiple times in one thread.
 */
class Mutex : private Uncopable
{
public:
    enum {
        PRIVATE = 0,
        SHARED = 1
    };
    Mutex();
    Mutex(const string& name);
    Mutex(int type, const string& name="");
    ~Mutex();

    status_t Lock();
    void UnLock();
    status_t TryLock();

    class AutoLock
    {
    public:
        inline AutoLock(Mutex& mutex) : m_Lock(mutex) { m_Lock.Lock(); }
        inline AutoLock(Mutex* mutex) : m_Lock(*mutex) { m_Lock.Lock(); }
        inline ~AutoLock() { m_Lock.UnLock(); }

    private:
        Mutex& m_Lock;

    };

private:
    pthread_mutex_t m_Mutex;

};

inline Mutex::Mutex()
{
    pthread_mutex_init(&m_Mutex, NULL);
}

inline Mutex::Mutex(const string& name)
{
    pthread_mutex_init(&m_Mutex, NULL);
}

inline Mutex::Mutex(int type, const string& name)
{
    if (type == SHARED) {
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED); //多进程中可见，同步多进程访问
        pthread_mutex_init(&m_Mutex, &attr);
        pthread_mutexattr_destroy(&attr);
    } else {
        pthread_mutex_init(&m_Mutex, NULL);
    }
}

inline ~Mutex()
{
    pthread_mutex_destroy(&m_Mutex);
}

inline status_t Mutex::Lock()
{
    return -pthread_mutex_lock(&m_Mutex);
}

inline void Mutex::UnLock()
{
    pthread_mutex_unlock(&m_Mutex);
}

inline status_t Mutex::TryLock()
{
    pthread_mutex_trylock(&m_Mutex);
}

/*
 *@brief : paried with mutex, lock the mutex, call wait if resource if unavailable
 *
 */
class Condition : private Uncopable
{
public:
    enum {
        PRIVATE = 0,
        SHARED = 1
    };
    Condition();
    Condition(int type);
    ~Condition();

    status_t Wait(Mutex& mutex);
    status_t WaitWithTimeout(Mutex& mutex, unsigned long long u_seconds);//微秒
    void Signal(); //wake up one single thread
    void Broadcast(); //wake up all threads.

private:
    friend class Condition;
    pthread_cond_t m_Cond;
};

inline Condition::Condition()
{
    pthread_cond_init(&m_Cond, NULL);
}

inline Condition::Condition(int type)
{
    if (type == SHARED) {
        pthread_condattr_t attr;
        pthread_condattr_init(&attr);
        pthread_condattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);//多进程中可见，同步多进程访问
        pthread_cond_init(&m_Cond, &attr);
    } else {
         pthread_cond_init(&m_Cond, NULL);
    }
}

inline Condition::~Condition()
{
    pthread_cond_destroy(&m_Cond);
}

inline status_t Condition::Wait(Mutex& mutex)
{
    return -pthread_cond_wait(&m_Cond, &mutex.m_Mutex);
}

inline status_t Condition::WaitWithTimeout(Mutex& mutex,  unsigned long long u_seconds)
{
    /* absolute time specifier */
    struct timespec ts;
    struct timeval tv;
    if (0 != gettimeofday(&tv, NULL))
    {

        return -1;
    }

    tv.tv_usec += u_seconds;

#define USECS_PER_SECOND 1000000LL
#define NANOSECS_PER_USEC 1000LL

    /* did we overflow a second in the usec part? */
    while (tv.tv_usec >= USECS_PER_SECOND)
    {
        tv.tv_usec -= USECS_PER_SECOND;
        tv.tv_sec++;
    }
    /* copy to the correct struct */
    ts.tv_sec = tv.tv_sec;
    ts.tv_nsec = (tv.tv_usec * NANOSECS_PER_USEC);

#undef USECS_PER_SECOND
#undef NANOSECS_PER_USEC

    return -pthread_cond_timedwait( &p_Cond, &mutex.m_Mutex, &ts );

}

inline void Condition::Signal() //wake up one single thread
{
    pthread_cond_signal(&m_Cond);
}

inline void Condition::Broadcast() //wake up all threads.
{
    pthread_cond_broadcast(&m_Cond);
}


//event



//thread

class Thread : private NoCopable
{
public:
    Thread();
    virtual ~Thread();

    virtual status_t Run();

    virtual void RequestExit();
    virtual void RequestExitAndWait();
    status_t ReadyToRun(); //a good place to do one-time initialization
    status_t Join();

protected:
    bool ExitPending() const;

private:
    virtual bool threadLoop() = 0;

    //always hold m_Lock when reading or writing.
    pthread_t m_Thread;
    mutable Mutex m_Lock;
    Condition m_ThreadExitedCond;

    volatile bool m_ExitPending;
    volatile bool m_Running;

};

#endif // THREADS_H
