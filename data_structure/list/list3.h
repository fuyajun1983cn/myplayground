#ifndef _LIST3_H
#define _LIST3_H
/**
 * 线性表的链式存储实现
 *
 */
#include <iostream>
#include "xcept.h"

using namespace std;

template<typename T>
class Chain;

template<typename T>
class ChainNode
{
    friend Chain<T>;

private:
    T data;
    ChainNode<T> *link;
};

template<typename T>
class Chain
{
public:
    Chain() { first = last = 0; }
    ~Chain();
    bool IsEmpty() const { return first == 0; }
    int Length() const;
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    Chain<T>& Delete(int k, T& x);
    Chain<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;
    
    //删除链表中所有节点
    void Erase();
    //将链表第一个元素置空
    void Zero() { first = 0; }
    //在链表右端添加一个元素
    Chain<T>& Append(const T& x);

private:
    ChainNode<T> *first; //指向第一个结点的指针
    ChainNode<T> *last;//指向最后一个结点的指针
};

/**
 * 析构函数，删掉链表中的所有函数
 */
template<typename T>
Chain<T>::~Chain()
{
    Erase();   
}

/**
 * 返回链表中的元素总数
 */
template<typename T>
int Chain<T>::Length() const
{
    ChainNode<T> *node = first;
    int length = 0;

    while(node) {
	node = node->link;
	length++;
    }

    return length;
}

template<typename T>
bool Chain<T>::Find(int k, T& x) const
{
    if (k < 1) return false;
    ChainNode<T> *current = first;

    int index = 1;

    while (index < k && current) {
	current = current->link;
	index++;
    }

    if (current) {
	x = current->data;
	return true;
    }

    return false;
}

template<typename T>
int Chain<T>::Search(const T& x) const
{
    ChainNode<T> *current = first;
    int index = 1;

    while (current && current->data != x) {
	index++;
	current = current->link;
    }

    if (current)
	return index;
    return 0;
} 

template<typename T>
void Chain<T>::Output(ostream& out) const
{
    ChainNode<T> *current = first;
    while (current) {
	out<<current->data<<" ";
	current = current->link;
    }
}

template<typename T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
    x.Output(out);
    return out;
}

template<typename T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{
    if (k < 1 || !first)
	throw OutOfBounds();

    ChainNode<T> *p = first;
    ChainNode<T> *q = p->link;
    if (k == 1) {
	first = q;
    } else {
	int index = 1;
	q = first;
	while (index < k && q) {
	    q = q->link;
	    index++;
	}

	if (q && q->link) {
	    p = q->link;
	    if (p == last)
		last = q;
	    q->link = p->link;
	} else throw OutOfBounds();

    }
    x = p->data;
    delete p;

    return *this;

}
/**
 * 在第k个元素之后插入元素
 */
template<typename T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{
    if (k < 0) throw OutOfBounds();

    ChainNode<T> *p = first;
    int index = 1;
    while (index < k && p) {
	p = p->link;
	index++;
    }

    if (k > 0 && !p) throw OutOfBounds();
    ChainNode<T> *y = new ChainNode<T>();
    y->data = x;
    if (k) {
	y->link = p->link;
	p->link = y;
    } else {
	y->link = first;
	first = y;
    }

    if (!y->link)
	last = y;

    return *this;
}

template<typename T>
void Chain<T>::Erase()
{
    ChainNode<T> *next;
    while (first) {
	next = first->link;
	delete first;
	first = next;
    }
}

template<typename T>
Chain<T>& Chain<T>::Append(const T& x)
{
    ChainNode<T> *y;
    y = new ChainNode<T>();
    y->data = x;
    y->link = 0;
    if (first) {//链表非空
	last->link = y;
	last = y;
    } else
	first = last = y;

    return *this;
}
#endif
