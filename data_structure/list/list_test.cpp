#include <iostream>
#include "list1.h"
#include "list3.h"
#include "list4.h"
#include "list5.h"
#include "xcept.h"
using namespace std;

/**
 * 测试线性表：基于公式化描述：location(i) = i - 1
 */
void test1()
{
    try {
#if 0
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
#endif
	//
#if 0
	cout<<"move around list"<<endl;
	LinearList<int> L2;
	L2.Insert(0,2).Insert(0,3).Insert(0,4);
        cout<<"List is "<<L2<<endl;
	L2.Current(z);
	cout<<"current is "<<z<<endl;
	L2.Next();
	L2.Current(z);
	cout<<"current is "<<z<<endl;
	L2.Next();
	L2.Current(z);
	cout<<"current is "<<z<<endl;

	L2.Previous();
	L2.Current(z);
	cout<<"current is "<<z<<endl;

	L2.Previous();
	L2.Current(z);
	cout<<"current is "<<z<<endl;

	L2.Previous();
	L2.Current(z);
	cout<<"current is "<<z<<endl;

	L2.Previous();
	L2.Current(z);
	cout<<"current is "<<z<<endl;
#endif
#if 1
	LinearList<int> L3;
	L3.Insert(0, 1).Insert(1, 4).Insert(2, 6);
	LinearList<int> L4;
	L4.Insert(0, 2).Insert(1, 3).Insert(2,5);

	LinearList<int> L5;
	L5.Alternate(L3, L4);
	cout<<"Alernate L3 & L4 is "<<L5<<endl;

	LinearList<int> L6;
	L6.Merge(L3, L4);
	cout<<"Merge L3 & L4 is "<<L6<<endl;
	
	LinearList<int> L7, L8;
	L6.Split(L7, L8);
	cout<<"Split of L6 "<<endl;
	cout<<"L7: "<<L7<<endl;
	cout<<"L8: "<<L8<<endl;
	
#endif
    } catch (...) {
	cerr<<"An exception has occured"<<endl;
    }
}

/**
 * 线性表测试程序，基于公式： location(i) = (location(1) + i - 1) %
 * MaxSize
 */
void test2()
{
}

void test3()
{
    try {
#if 0
	Chain<int> L;
	cout<<"Length = "<<L.Length()<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	L.Insert(0, 2).Insert(1,6).Insert(2, 7).Insert(3, 8).Insert(4,9);
	cout<<"List is "<<L<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
        cout<<"First Element: "<<L.GetFirst()<<endl;
        cout<<"Last Element: "<<L.GetLast()<<endl;	
	Chain<int> L2(L);
	cout<<"list L2: "<<L2<<endl;
	int z;
        L.Find(1, z);
	cout<<"First Element is "<<z<<endl;
	cout<<"Length = "<<L.Length()<<endl;
	L.Delete(1, z);
	cout<<"Deleted element is "<<z<<endl;
	cout<<"List is "<<L<<endl;
	L.Delete(1,z).Delete(1,z).Delete(1,z);
	cout<<"List is "<<L<<endl;
	cout<<"Length = "<<L.Length()<<endl;
	L.Append(5).Append(7);
	cout<<"List is "<<L<<endl;
	cout<<"Length = "<<L.Length()<<endl;

	cout<<"-------采用链表遍历器输出---------------------"<<endl;
	int *x;
	ChainIterator<int> c;
	x = c.Initialize(L);
	while(x) {
	    cout<<*x<<' ';
	    x = c.Next();
	}
	cout<<endl;

	/************测试单向链表与线性表之间的相互转换*****************/
	LinearList<int> L3;
	L3.Insert(0, 1).Insert(1, 4).Insert(2, 6);
	cout<<"L3 "<<L3<<endl;

	L = L.FromList(L3);
	cout<<"L is "<<L<<endl;
	cout<<"L的反序： "<<L.Reverse()<<endl;

	L.Insert(0, 12).Insert(0, 45);
	LinearList<int> L4;
	L.ToList(L4);
	cout<<"L4 is "<<L4<<endl;
	
	/*************************测试两个链表之间的合并*************************/
	Chain<int> L5;
	L5.Insert(0, 1).Insert(1, 2).Insert(2,3);
	Chain<int> L6;
        L6.Insert(0,4).Insert(1,5).Insert(2,6).Insert(3,7);	
	L.Alternate(L5, L6);
	cout<<" L is "<<L<<endl;
	cout<<"First Element: "<<L.GetFirst()<<endl;
	cout<<"Last Element: "<<L.GetLast()<<endl;

	/************************测试两个有序链表的合并***********************/

	Chain<int> L7;
	L7.Insert(0, 3).Insert(1, 9).Insert(2,10);
	Chain<int> L8;
        L8.Insert(0,4).Insert(1,5).Insert(2,6);	
	L.Merge(L8, L7);
	cout<<" L is "<<L<<endl;

	L.Split(L7, L8);
	cout<<" L7 is "<<L7<<endl;
	cout<<" L8 is "<<L8<<endl;
	

#endif
#if 1
        CircularList<int> L;
        //Double<int> L;
	cout<<"---------------插入测试(2,6,7,8,9)----------------------"<<endl;
	cout<<"Length = "<<L.Length()<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	L.Insert(0, 2).Insert(1,6).Insert(2, 7).Insert(3, 8).Insert(4,9);
	cout<<"List is "<<L<<endl;
	cout<<"IsEmpty = "<<L.IsEmpty()<<endl;
	cout<<"----------------查找测试(2)---------------------"<<endl;
	int z;
        L.Find(1, z);
	cout<<"First Element is "<<z<<endl;
	L.Find(5, z);
	cout<<"第五个元素是："<<z<<endl;
	L.Find(3, z);
	cout<<"第三个元素是："<<z<<endl;
	cout<<"Length = "<<L.Length()<<endl;
	cout<<"---------------删除测试---------------------"<<endl;
	L.Delete(1, z);
	cout<<"删除的第一个元素是："<<z<<endl;
	cout<<"List is "<<L<<endl;
	L.Delete(1,z).Delete(3,z).Delete(1,z);
	cout<<"List is "<<L<<endl;
	cout<<"Length = "<<L.Length()<<endl;
	cout<<"---------------尾部添加元素测试------------"<<endl;
	L.Append(5).Append(7);
	cout<<"List is "<<L<<endl;
	cout<<"Length = "<<L.Length()<<endl;

	cout<<"-------------异常测试-----------------"<<endl;
	try {
	L.Delete(8, z);
	} catch(...) {
	    cout<<"非法删除"<<endl;
	}

	try {
	L.Insert(5, 7);
	} catch (...) {
	    cout<<"非法插入"<<endl;
	}

	CircularList<int> L2;
	L2.Insert(0, 1).Insert(1, 7);
	CircularList<int> L3;
	L3.Insert(0, 4).Insert(1, 5).Insert(2, 6);

	//L.Alternate(L2, L3);
	//L.Merge(L3, L2);
	
	L.Erase();
	L.Insert(0, 1);//.Insert(1, 2).Insert(2, 3).Insert(3, 4).Insert(4, 5).Insert(5,6);
        L2.Erase();
	L3.Erase();
	L.Split(L3, L2);

	cout<<"List L is "<<L<<endl;
	cout<<"Length is "<<L.Length()<<endl;
	cout<<"List L2 is "<<L2<<endl;
	cout<<"List L3 is "<<L3<<endl;

	

#endif

    } catch (...) {
	cerr<<"An exception has occured"<<endl;
    }
}

int list_test(int argc, char *argv[])
{
    //测试1
    test3();

    return 0;
}

int main(int argc, char *argv[])
{
    return list_test(argc, argv);
}
