#include <list>
#include <windows.h>

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
	HANDLE hMutex;
	HANDLE hEvent;

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

	int m_iThread;
	AsynchQueue<Job> queue;
	std::list<HANDLE> threads;
	HANDLE hMutex;
	BOOL stopMe;
	BOOL m_releaseJob;
};
