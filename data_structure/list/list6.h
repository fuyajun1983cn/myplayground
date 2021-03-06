#ifndef _LIST6_H
#define _LIST6_H
/**
 * 间接寻址链表的实现
 */
#include <iostream>
#include "xcept.h"

template<typename T>
class IndirectListIterator;

template<typename T>
class IndirectList {
    friend IndirectListIterator<T>;
public:
    IndirectList(int MaxListSize = 10);
    ~IndirectList();
    bool IsEmpty() const { return length == 0; }
    int Length() const { return length; }
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    IndirectList<T>& Delete(int k, T& x);
    IndirectList<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;

    //折半查找
    //
    bool BinarySearch(const T& x) const;

    /**
     * 排序函数
     */
    //插入排序
    IndirectList<T>& InsertionSort();

    //冒泡排序
    IndirectList<T>& BubbleSort();

    //选择排序
    IndirectList<T>& SelectionSort();


private:
    T **table; //一维T类型指针数组
    int length, MaxSize;

};

template<typename T>
class IndirectListIterator{
public:
    T* Initialize(IndirectList<T>& list){
	l = &list;
	index = 1;
	if (l->IsEmpty())
	    return nullptr;
	return l->table[0];
    }

    T* Next() {
	if (index < l->length)
	    return l->table[index++];
	return nullptr;
    }

private:
    IndirectList<T> *l;//此处应避免double free的问题,(当声明为栈变量时，会导致double free的情况出现)
    int index;
};


template<typename T>
IndirectList<T>::IndirectList(int MaxListSize)
{
    MaxSize = MaxListSize;
    table = new T*[MaxSize];
    length = 0;
}

template<typename T>
IndirectList<T>::~IndirectList()
{
    if (table == nullptr)
	return;

    for (int i = 0; i < length; i++)
	delete table[i];
    delete []table;
    table = nullptr;
}


template<typename T>
bool IndirectList<T>::Find(int k, T& x) const
{
    if (k < 1 || k > length)
	return false;
    x = *table[k-1];
    return true;
}


template<typename T>
IndirectList<T>& IndirectList<T>::Delete(int k, T& x)
{
    if (Find(k, x)) {
	for (int i = k; i < length; i++)
	    table[i-1] = table[i];
	length--;
	return *this;
    } else throw OutOfBounds();
}

template<typename T>
IndirectList<T>& IndirectList<T>::Insert(int k, const T& x)
{
    if (k < 0 || k > length) throw OutOfBounds();
    if (length == MaxSize) throw NoMem();

    for (int i = length-1; i >= k; i--)
	table[i+1] = table[i];
    table[k] = new T;
    *table[k] = x;
    length++;
    return *this;
}

template<typename T>
void IndirectList<T>::Output(ostream& out) const
{
    for (int i = 0; i < length; i++)
	out<<*table[i]<<" ";
}

template<typename T>
ostream& operator<<(ostream& out, const IndirectList<T>& list)
{
    list.Output(out);
    return out;
}

template<typename T>
bool IndirectList<T>::BinarySearch(const T& x) const
{
    int h = length - 1;
    int l = 0;
    int index;

    do {
	index = (h + l) / 2;
	if (*table[index] == x)
	    return true;
	else if (*table[index] > x)
	    h = index - 1;
	else
	    l = index + 1;
    }while(h != l);

    return false;
}

template<typename T>
IndirectList<T>& IndirectList<T>::InsertionSort()
{
    for (int i = 1; i < length; i++) {
	T *x = table[i];
	int j = i - 1;
	for (; j >= 0; j--) {
	    if (*x > *table[j])
		break;
	    table[j+1] = table[j];
	}
	table[j+1] = x;
    }

    return *this;
}

template<typename T>
IndirectList<T>& IndirectList<T>::BubbleSort()
{

    //find the max element
    //
    bool swap = false;
    for (int j = length - 1; j > 1; j--) {
	//move the max element to the end
	for (int i = 0; i < j; i++) {
	    if (*table[i] > *table[i+1]) {
		T* temp = table[i];
		table[i] = table[i+1];
		table[i+1] = temp;
		swap = true;
	    }
	}
	if (!swap) {
	    break;
	}
    }

    return *this;
}

template<typename T>
IndirectList<T>& IndirectList<T>::SelectionSort()
{

    for (int j = length -1; j > 0; j--) {
	int max_index = 0;
	//choose the max element and swap it with the end element
	for (int i = 1; i <= j; i++) {
	    if (*table[max_index] < *table[i]) {
		max_index = i;
	    }
	}

	if (max_index != j) {
	    //swap
	    T* temp = table[j];
	    table[j] = table[max_index];
	    table[max_index] = temp;
	}

    }

    return *this;
}


#endif
