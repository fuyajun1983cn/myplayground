#include "threadpool.h"
#include <iostream>

/************************************************************/
/*							    */
/*definition for class AsynchQueue			    */
/************************************************************/
template <class T>
AsynchQueue<T>::AsynchQueue() {
	int res = pthread_mutex_init(&hMutex, NULL) ;// PTHREAD_MUTEX_INITIALIZER
	if(res != 0)
	{
		std::cout<<"fail to initialize mutex"<<__LINE__<<" at "<<__FILE__<<std::endl;
		exit(0);
	}
	res = sem_init(&hSem, 0, 0) ;
	if(res != 0)
	{
		std::cout<<"fail to initialize semaphore"<<__LINE__<<" at "<<__FILE__<<std::endl;
		exit(0);
	}	
}

template <class T>
AsynchQueue<T>::~AsynchQueue() {
	pthread_mutex_destroy(&hMutex);
	sem_destroy(&hSem);
}

template <class T>
void AsynchQueue<T>::Enqueue(T* data) {
	pthread_mutex_lock(&hMutex);
	queue.push_back(data);
	pthread_mutex_unlock(&hMutex);
	sem_post(&hSem);//increase sem value
}

template <class T>
T *AsynchQueue<T>::Dequeue() {
	sem_wait(&hSem);//decrease sem value
	pthread_mutex_lock(&hMutex);
	T* data = queue.front();
	queue.pop_front();
	pthread_mutex_unlock(&hMutex);
	return data;
}

/*****************************************************************************/
/*									     */
/*definition for class ThreadPool					     */
/*****************************************************************************/


ThreadPool::ThreadPool(int num, BOOL releaseJob) : 
	m_iThread(num), m_releaseJob(releaseJob) {
	for (int i=0; i<num; i++) {
		pthread_t a_thread; 
		int res = pthread_create(&a_thread, NULL, ThreadFunc, (void *)this);
		if(res == 0)
		{
			threads.push_back(a_thread);
		}

	}

	int res = pthread_mutex_init(&hMutex, NULL) ;// PTHREAD_MUTEX_INITIALIZER
	if(res != 0)
	{
		std::cout<<"fail to initialize mutex"<<__LINE__<<" at "<<__FILE__<<std::endl;
		exit(0);
	}
	pthread_mutex_lock(&hMutex);
	stopMe = FALSE;
	pthread_mutex_unlock(&hMutex);
}

ThreadPool::~ThreadPool() {
	pthread_mutex_lock(&hMutex);
	stopMe = TRUE;
	pthread_mutex_unlock(&hMutex); 

	pthread_mutex_destroy(&hMutex);
}

BOOL ThreadPool::IsStopping() {
	pthread_mutex_lock(&hMutex);
	BOOL stop = stopMe;
	pthread_mutex_unlock(&hMutex);
	return stop;
}

void ThreadPool::Assignment(Job *job) {
	queue.Enqueue(job);
}

void ThreadPool::Work() {
	Job *job = queue.Dequeue();
	job->Process();
	if (m_releaseJob) {
		delete job;
	}
};

void *ThreadPool::ThreadFunc(void *arg) {
	ThreadPool *pool = static_cast<ThreadPool *>(arg);
	while (!pool->IsStopping()) {
		pool->Work();
	}
	return 0;
}
