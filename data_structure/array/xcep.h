#ifndef _XCEP_H
#define _XCEP_H
#include <new>
using namespace std;
//内存不足
class NoMem {
    public:
	NoMem() {}
};

//使new引发NoMem异常而不是xalloc异常
void my_new_handler()
{
    throw NoMem();
}

new_handler Old_Handler = set_new_handler(my_new_handler);

class OutOfBounds {
    public:
	OutOfBounds() {}
};

class SizeMismatch {
 public:
  SizeMismatch() {}
};

#endif
