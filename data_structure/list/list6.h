#ifndef _LIST6_H
#define _LIST6_H

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
    IndirectList<T> *l;//此处应避免double free的问题
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






#endif
