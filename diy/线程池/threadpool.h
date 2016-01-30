#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include <list>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define BOOL bool
#define TRUE true
#define FALSE false

/* Asynchronized Queue */
template <class T>
class AsynchQueue {
public:
	AsynchQueue();
	~AsynchQueue();

	void Enqueue(T* data);
	T* Dequeue();

private:
	std::list<T*> queue;
	pthread_mutex_t hMutex;//for the control of enter the queue
	sem_t hSem;//for the contorl of leaving the queue

	AsynchQueue(const AsynchQueue<T>& q);
	AsynchQueue &operator=(const AsynchQueue<T>&);
};

/* Job that passed to the thread */
class Job {
public:
	virtual void Process() = 0;
	virtual ~Job() {};
};

/* Thread Pool */
class ThreadPool {
public:
	ThreadPool(int num, BOOL releaseJob);
	~ThreadPool();
	void Assignment(Job *job);
	void Work();
	BOOL IsStopping();

private:
	ThreadPool(const ThreadPool &);
	ThreadPool &operator=(const ThreadPool &);

	static void *ThreadFunc(void *arg);

	int m_iThread;// num of threads in the pool
	AsynchQueue<Job> queue;
	std::list<pthread_t> threads;
	pthread_mutex_t hMutex;
	BOOL stopMe;
	BOOL m_releaseJob;
};#endif
