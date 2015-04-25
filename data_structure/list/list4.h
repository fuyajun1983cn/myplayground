#ifndef _LIST4_H
#define _LIST4_H
/**
 * 线性表的链式存储实现
 * 带头结点的循环链表实现
 *
 */
#include <iostream>
#include "xcept.h"

using namespace std;

template<typename T>
class CircularList;

template<typename T>
class ChainNode
{
    friend CircularList<T>;

private:
    T data;
    ChainNode<T> *link;
};

template<typename T>
class CircularList
{
public:
    CircularList() { first = new ChainNode<T>; first->link = first; }
    ~CircularList();
    bool IsEmpty() const { return first == first->link; }
    int Length() const;
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    CircularList<T>& Delete(int k, T& x);
    CircularList<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;
    
    //删除链表中所有节点
    void Erase();
    //将链表第一个元素置空
    void Zero() { first = 0; }
    //在链表右端添加一个元素
    CircularList<T>& Append(const T& x);

private:
    ChainNode<T> *first; //指向第一个结点的指针
};

/**
 * 析构函数，删掉链表中的所有函数
 */
template<typename T>
CircularList<T>::~CircularList()
{
    Erase();   
    delete first;
    first = 0;
}

/**
 * 返回链表中的元素总数
 */
template<typename T>
int CircularList<T>::Length() const
{
    ChainNode<T> *node = first->link;
    int length = 0;

    while(node && node != first) {
	node = node->link;
	length++;
    }

    return length;
}

template<typename T>
bool CircularList<T>::Find(int k, T& x) const
{
    if (k < 1) return false;
    if (k > Length()) return false;

    ChainNode<T> *current = first->link;

    int index = 1;

    while (index < k && current != first) {
	current = current->link;
	index++;
    }

    if (current != first) {
	x = current->data;
	return true;
    }

    return false;
}

template<typename T>
int CircularList<T>::Search(const T& x) const
{
    ChainNode<T> *current = first->link;
    int index = 1;
    first->data = x;

    while (current && current->data != x) {
	index++;
	current = current->link;
    }

    return ((current == first) ? 0 : index);
} 

template<typename T>
void CircularList<T>::Output(ostream& out) const
{
    ChainNode<T> *current = first->link;
    while (current && current != first) {
	out<<current->data<<" ";
	current = current->link;
    }
}

template<typename T>
ostream& operator<<(ostream& out, const CircularList<T>& x)
{
    x.Output(out);
    return out;
}

template<typename T>
CircularList<T>& CircularList<T>::Delete(int k, T& x)
{
    if (k < 1 || first == first->link)
	throw OutOfBounds();

    ChainNode<T> *p = first;
    ChainNode<T> *q = first->link;
    int index = 1;
    while (index < k && q != first) {
	p = q;
	q = q->link;
	index++;
    }

    if (q == first)
	throw OutOfBounds();

    p->link = q->link;
    p = q;
    x = p->data;
    delete p;
    p = NULL;

    return *this;

}
/**
 * 在第k个元素之后插入元素
 */
template<typename T>
CircularList<T>& CircularList<T>::Insert(int k, const T& x)
{
    if (k < 0) throw OutOfBounds();

    ChainNode<T> *p = first;
    int index = 0;
    while (index < k && p->link != first) {
	p = p->link;
	index++;
    }
    if (index < k) throw OutOfBounds();
    ChainNode<T> *y = new ChainNode<T>();
    y->data = x;
    y->link = p->link;
    p->link = y;

    return *this;
}

template<typename T>
void CircularList<T>::Erase()
{
    ChainNode<T> *next = first->link;
    while (next != first) {
        first->link = next->link;
        delete next;
        next = first->link;
    }	 
}

template<typename T>
CircularList<T>& CircularList<T>::Append(const T& x)
{
    ChainNode<T> *y;
    y = new ChainNode<T>();
    y->data = x;
    y->link = first;

    ChainNode<T> *p = first->link;
    while (p->link != first) {
	p = p->link;
    }

    p->link = y; 

    return *this;
}
#endif
