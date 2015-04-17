#include <iostream>
#include "list1.h"
#include "xcept.h"
using namespace std;
int main(int argc, char *argv[])
{
    try {
	LinearList<int> L(5);
	cout<<"Length = "<<L.Length()<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	L.Insert(0, 2).Insert(1,6);
	cout<<"List is "<<L<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	int z;
        L.Find(1, z);
	cout<<"First Element is "<<z<<endl;
	cout<<"Length = "<<L.Length()<<endl;
	L.Delete(1, z);
	cout<<"Deleted element is "<<z<<endl;
	cout<<"List is "<<L<<endl;
    } catch (...) {
	cerr<<"An exception has occured"<<endl;
    }
}

