#ifndef _LIST1_H
#define _LIST1_H
#include <iostream>
#include "xcept.h"

using namespace std;

template<typename T>
class LinearList {
    public:
	LinearList(int MaxListSize = 10);
	~LinearList() { delete [] element; }
	bool IsEmpty() const { return length == 0; }
	int Length() const { return length; }
	bool Find(int k, T& x) const;//返回第k个元素到x中
	int Search(const T& x) const;//返回x所在的位置
	LinearList<T>& Delete(int k, T& x);//删除第k个元素并将它返回到x中
	LinearList<T>& Insert(int k, const T& x);//在第k个元素之后插入x
	void Output(ostream& out) const;
    private:
	int length;
	int MaxSize;
	T *element;//一维动态数组
};

template<typename T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize = MaxListSize;
    element = new T[MaxSize];
    length = 0;
}

template<typename T>
bool LinearList<T>::Find(int k, T& x) const
{
    //把第k个元素取至x中
    //如果不存在第k个元素，则返回false，否则返回true
    if (k < 1 || k > length)
	return false;
    x = element[k - 1];
    return true;
}

template<typename T>
int LinearList<T>::Search(const T&x) const
{
    //查找x,如果找到，则返回x所在的位置，
    //如果x不在表中，则返回 
    //
    for (int i = 0; i < length; i++)
	if (element[i] == x)
	    return ++i;
    return 0;
}

template<typename T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{
    //把第k个元素放入x中，并删除第k个元素
    //如果不存在第k个元素，就抛出OutOfBounds异常
    if (Find(k, x)) {
	for (int i = k; i < length; i++)
	    element[i-1] = element[i];
	length--;
	return *this;
    } else throw OutOfBounds();
}

template<typename T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{
    //在第k个元素之后插入x
    //如果不存在第k个元素，则引发OutOfBounds异常
    //如果表满，则引发异常NoMem
    if (k < 0 || k > length) throw OutOfBounds();
    if (length == MaxSize) throw NoMem();

    for (int i = length-1; i >= k; i--)
	element[i+1] = element[i];
    element[k] = x;
    length++;
    return *this;
}

template<typename T>
void LinearList<T>::Output(ostream& out) const
{
    for (int i = 0; i < length; i++)
	out<<element[i]<<" ";
}

template<typename T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
    x.Output(out);
    return out;
}
#endif
