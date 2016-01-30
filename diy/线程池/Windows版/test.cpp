#include <iostream>
#include <tchar.h>
#include "threadpool.h"

using namespace std;

class MyJob1 : public Job {
public:
	MyJob1(int index) : data(index) {};
	virtual void Process() {
		cout << data << endl;
	}
	~MyJob1() {};

private:
	int data;
};

class MyJob2 : public Job {
public:
	MyJob2(int index) : data(index+1000) {};
	virtual void Process() {
		cout << data << endl;
	}
	~MyJob2() {};

private:
	int data;
};

class MyJob3 : public Job {
public:
	MyJob3(char index) : data(index) {};
	virtual void Process() {
		cout << data << endl;
	}
	~MyJob3() {};

private:
	char data;
};

void RandomTest() {
	ThreadPool tp(4, TRUE);

	for (int i=0; i<100; i++) {
		Job *job = new MyJob1(i);
		tp.Assignment(job);
		job = new MyJob2(i);
		tp.Assignment(job);
		job = new MyJob3('a');
		tp.Assignment(job);
	}
}

int
main(int argc, char **argv) {
	RandomTest();
	return 0;
}
