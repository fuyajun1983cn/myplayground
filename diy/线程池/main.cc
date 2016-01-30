#include "threadpool.h"
#include <iostream>

class JobItem : public Job
{
public:
	virtual void Process();
};

void JobItem::Process()
{
	static int i = 0;
	std::cout<<"\ni'm no "<<i++<<std::endl;
	do{
		sleep(1);
		break;
	}while(1);
}

int main()
{
	JobItem *job ;
	
	ThreadPool pool(100, TRUE);

	for(int i = 0; i < 100; i++)
	{
		job = new JobItem();
		pool.Assignment(job);
	}
 
	do{}while(1);
	return 0;
}
