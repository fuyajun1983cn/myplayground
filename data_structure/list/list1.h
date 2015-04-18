#ifndef _LIST1_H
#define _LIST1_H
#include <iostream>
#include "xcept.h"

using namespace std;

template<typename T>
class LinearList {
    public:
	LinearList();
	LinearList(const LinearList<T>& L);
	~LinearList() { delete [] element; }
	bool IsEmpty() const { return length == 0; }
	int Length() const { return length; }
	bool Find(int k, T& x) const;//返回第k个元素到x中
	int Search(const T& x) const;//返回x所在的位置
	LinearList<T>& Delete(int k, T& x);//删除第k个元素并将它返回到x中
	LinearList<T>& Insert(int k, const T& x);//在第k个元素之后插入x
	LinearList<T>& Reverse();//将表中元素次序变反
	LinearList<T>& Half();//删除链表中的半数元素
	void Output(ostream& out) const;
	/**
	 * 前移，后移操作
	 */
	void Reset() { current = 1; }
	void Current(T& x) const { x = element[current-1]; }
	bool End() const { return current == length; }
	bool Front() const { return current == 1; }
	void Next() ;
	void Previous();
    private:
	int length;
	int MaxSize;
	int current;
	T *element;//一维动态数组
};
/**
 *新建线性表时，置MaxSize为1,之后在执行插入操作期间
 *如果在表中已经有了MaxSize个元素，则将MaxSize加倍
 *执行删除操作时，如果线性表的尺寸降至当前MaxSize的四分之一
 *，则分配一个更小的，尺寸为MaxSize/2的数组。
 * 
 */
template<typename T>
LinearList<T>::LinearList()
{
    MaxSize = 1;
    element = new T[MaxSize];
    length = 0;
    current = 1;
}

template<typename T>
LinearList<T>::LinearList(const LinearList<T>& L)
{
    MaxSize = L.MaxSize;
    length = L.length;
    element = new T[MaxSize];
    for (int i = 0; i < MaxSize; i++)
	element[i] = L.element[i];
}

template<typename T>
void LinearList<T>::Next()
{
    if (current >= length)
	throw OutOfBounds();
    else
	current++;
}

template<typename T>
void LinearList<T>::Previous()
{
    if (current <= 1)
	throw OutOfBounds();
    else
	current--;
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
/**
 * 如果当前length已经降至当前的MaxSize的四分之一，
 * 则缩小数组大小
 */
template<typename T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{
    //把第k个元素放入x中，并删除第k个元素
    //如果不存在第k个元素，就抛出OutOfBounds异常
    if (Find(k, x)) {
	for (int i = k; i < length; i++)
	    element[i-1] = element[i];
	length--;
	if (length <= MaxSize/4) {
	   MaxSize /= 4;
	   T *new_elements = new T[MaxSize];
	   for (int i = 0; i < length; i++)
		new_elements[i] = element[i];
	   delete[] element;
	   element = new_elements;
	}
	return *this;
    } else throw OutOfBounds();
}
/**
 * 如果当前数组大小已经达到MaxSize,
 * 则数组大小再翻倍
 */
template<typename T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{
    //在第k个元素之后插入x
    //如果不存在第k个元素，则引发OutOfBounds异常
    //如果表满，则引发异常NoMem
    if (k < 0 || k > length) throw OutOfBounds();
    if (length == MaxSize) {
       MaxSize *= 2;
       T* new_elements = new T[MaxSize];
       for (int i = 0; i < length; i++)
    	   new_elements[i] = element[i];
       delete[] element;       
       element = new_elements;
    }

    for (int i = length-1; i >= k; i--)
	element[i+1] = element[i];
    element[k] = x;
    length++;
    return *this;
}

/**
 * 删除链表中的半数元素
 */
template<typename T>
LinearList<T>& LinearList<T>::Half()
{
    if (length == 0)
	return *this;
    int j = 0;
    int n = length/2;
    if (length % 2)
	n = (length + 1)/2;
    for (int i = 0; i < n; i++ ) 
	element[j++] = element[2*i];
    length = j;
    return *this;
}

/**
 * 反序操作
 */
template<typename T>
LinearList<T>& LinearList<T>::Reverse()
{
    int tmp = 0;
    for(int i = 0; i < length/2; i++) {
         tmp = element[i];
	 element[i] = element[length-1-i];
	 element[length-1-i] = tmp;
    }

    return *this;
}

template<typename T>
void Reverse(LinearList<T>& x)
{
    x.Reverse();
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
