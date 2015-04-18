#include <iostream>
#include "list1.h"
#include "xcept.h"
using namespace std;
int main(int argc, char *argv[])
{
    try {
	LinearList<int> L;
	cout<<"Length = "<<L.Length()<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	L.Insert(0, 2).Insert(1,6).Insert(2, 7).Insert(3, 8).Insert(4,9);
	cout<<"List is "<<L<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	L.Reverse();
	cout<<"Reverse the list"<<L<<endl;
	int z;
        L.Find(1, z);
	cout<<"First Element is "<<z<<endl;
	cout<<"Length = "<<L.Length()<<endl;
	L.Delete(1, z);
	cout<<"Deleted element is "<<z<<endl;
	Reverse(L);
	cout<<"List is "<<L<<endl;
	L.Delete(1,z).Delete(1,z).Delete(1,z);
	cout<<"List is "<<L<<endl;
	cout<<"Length = "<<L.Length()<<endl;

	//half
	L.Insert(0,2).Insert(1,13).Insert(2,4).Insert(3,5).Insert(4,17).Insert(5,8).Insert(6,29);
	cout<<"list is "<<L<<endl;
	cout<<"Length is "<<L.Length()<<endl;
	L.Half();
	cout<<"Halfed List is "<<L<<endl;
	L.Delete(1,z);
	cout<<"list is "<<L<<endl;
	L.Half();
	cout<<"list is "<<L<<endl;
	cout<<"Halfed List is "<<L<<endl;
    } catch (...) {
	cerr<<"An exception has occured"<<endl;
    }
}

