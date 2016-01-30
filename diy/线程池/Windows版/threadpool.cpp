#include "threadpool.h"

template <class T>
AsynchQueue<T>::AsynchQueue() {
	hMutex = CreateMutex(NULL, FALSE, NULL);
	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
}

template <class T>
AsynchQueue<T>::~AsynchQueue() {
	CloseHandle(hMutex);
	CloseHandle(hEvent);
}

template <class T>
void AsynchQueue<T>::Enqueue(T* data) {
	WaitForSingleObject(hMutex, INFINITE);
	queue.push_back(data);
	ReleaseMutex(hMutex);
	SetEvent(hEvent);
}

template <class T>
T *AsynchQueue<T>::Dequeue() {
	WaitForSingleObject(hEvent, INFINITE);
	WaitForSingleObject(hMutex, INFINITE);
	T* data = queue.front();
	queue.pop_front();
	if (queue.size() > 0) SetEvent(hEvent);
	ReleaseMutex(hMutex);
	return data;
}

DWORD WINAPI ThreadFunc(LPVOID lpParam);

ThreadPool::ThreadPool(int num, BOOL releaseJob) : 
	m_iThread(num), m_releaseJob(releaseJob) {
	for (int i=0; i<num; i++) {
		DWORD dwThreadId;
		HANDLE hThread; 

		hThread = CreateThread( 
			NULL,                        // default security attributes 
			0,                           // use default stack size  
			ThreadFunc,                  // thread function 
			this,						 // argument to thread function 
			0,                           // use default creation flags 
			&dwThreadId);                // returns the thread identifier 
		threads.push_back(hThread);
	}

	hMutex = CreateMutex(NULL, TRUE, NULL);
	stopMe = FALSE;
	ReleaseMutex(hMutex);
}

ThreadPool::~ThreadPool() {
	WaitForSingleObject(hMutex, INFINITE);
	stopMe = TRUE;
	ReleaseMutex(hMutex);

	HANDLE *handles = new HANDLE[m_iThread];
	int i=0;
	for (std::list<HANDLE>::iterator iter = threads.begin(); 
		 iter != threads.end();
		 iter ++) {
		handles[i++] = *iter;
	}
	WaitForMultipleObjects(m_iThread, handles, TRUE, 2000);
	for (iter = threads.begin(); 
		 iter != threads.end();
		 iter ++) {
		CloseHandle(*iter);
	}
	delete [] handles;

	CloseHandle(hMutex);
}

BOOL ThreadPool::IsStopping() {
	WaitForSingleObject(hMutex, INFINITE);
	BOOL stop = stopMe;
	ReleaseMutex(hMutex);
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

DWORD WINAPI ThreadFunc(LPVOID lpParam) {
	ThreadPool *pool = static_cast<ThreadPool *>(lpParam);
	while (!pool->IsStopping()) {
		pool->Work();
	}
	return 0;
}
