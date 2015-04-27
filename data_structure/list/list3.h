#ifndef _LIST3_H
#define _LIST3_H
/**
 * 线性表的链式存储实现
 *
 */
#include <iostream>
#include "xcept.h"
#include "list1.h"

using namespace std;

template<typename T>
class Chain;
template<typename T>
class ChainIterator;

template<typename T>
class ChainNode
{
    friend Chain<T>;
    friend ChainIterator<T>;

public:
    void Output(ostream& out) const;

private:
    T data;
    ChainNode<T> *link;
};

template<typename T>
void ChainNode<T>::Output(ostream& out) const
{
    out<<data;
}

template<typename T>
ostream& operator<<(ostream& out, const ChainNode<T>& x)
{
    x.Output(out);
    return out;
}
template<typename T>
ostream& operator<<(ostream& out, const ChainNode<T> *x)
{
    if (x)
        x->Output(out);
    return out;
}

template<typename T>
class ChainIterator
{
public:
    T* Initialize(const Chain<T>& c)
    {
	location = c.first;
	if (location) 
	    return &location->data;
	return 0;
    }

    T* Next()
    {
	if (!location)
	    return 0;
	location = location->link;
	if (location) 
	    return &location->data;
	return 0;
    }

private:
    ChainNode<T> *location;
};

template<typename T>
class Chain
{
    friend ChainIterator<T>;
public:
    Chain() { first = last = 0; }
    Chain(const Chain<T>& C);
    ~Chain();
    bool IsEmpty() const { return first == 0; }
    int Length() const;
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    Chain<T>& Delete(int k, T& x);
    Chain<T>& Insert(int k, const T& x);
    const ChainNode<T>* GetFirst() const { return first; }
    const ChainNode<T>* GetLast() const { return last; }
    void Output(ostream& out) const;
    
    //删除链表中所有节点
    void Erase();
    //将链表第一个元素置空
    void Zero() { first = 0; }
    //在链表右端添加一个元素
    Chain<T>& Append(const T& x);
    //反序，不要分配任何新的节点
    Chain<T>& Reverse();

    /**
     * 把一个线性表转换成单向链表
     */
    Chain<T>& FromList(const LinearList<T>& L);

    /**
     * 把一个单向链表转换成线性表
     */
    void ToList(LinearList<T>& L);

    /**
     * 将两个链表合并，元素交替地出现在新的链表上
     */
    Chain<T>& Alternate(Chain<T>& a, Chain<T>& b);

private:
    ChainNode<T> *first; //指向第一个结点的指针
    ChainNode<T> *last;//指向最后一个结点的指针
};

/**
 * 将两个链表合并，元素交替地出现在新的链表中
 */
template<typename T>
Chain<T>& Chain<T>::Alternate(Chain<T>& a, Chain<T>& b)
{
    //清除当前链表的结点
    Erase();

    ChainNode<T> *aCurrent = a.first;
    ChainNode<T> *bCurrent = b.first;


    ChainNode<T> *current = NULL;
    while (aCurrent != NULL && bCurrent != NULL){
	if (!current)
	     current = aCurrent;
	else {
	    current->link = aCurrent;
	    current = aCurrent;
	}
	 aCurrent = aCurrent->link;
	 if (!first)
	     first = current;
	 current->link = bCurrent;
	 current = bCurrent;
	 bCurrent = bCurrent->link;
    }

    if (aCurrent == NULL && bCurrent == NULL) {
	cout<<"1"<<endl;
	last = current;
    }
    
    while (aCurrent != NULL) {
	if (!current) {
	    current = aCurrent;
	    first = current;
	} else {
	    current->link = aCurrent;
	    current = aCurrent;
	}
	if (current == a.last)
	    last = current;
	aCurrent = aCurrent->link;
    } 

     while (bCurrent != NULL) {
	 if (!current) {
	     current = bCurrent;
	     first = current;
	 } else {
	    current->link = bCurrent;
	    current = bCurrent;
	 }
	if (current == b.last)
	    last = current;
	bCurrent = bCurrent->link;
    }

    return *this;
}



template<typename T>
Chain<T>& Chain<T>::Reverse()
{
    ChainNode<T> *tmp;
    ChainNode<T> *head = NULL;
    ChainNode<T> *p = first;
    while(p) {
	tmp = p->link;
	p->link = head;
	head = p;
	p = tmp;
    }	 
    tmp = first;
    first = last;
    last = tmp;
    return *this;
}
   

template<typename T>
Chain<T>& Chain<T>::FromList(const LinearList<T>& L)
{
    //Erase old data
    Erase();
   
    for (int i = 1; i <= L.Length(); i++) {
          int x;
          if (L.Find(i, x))
	      Insert(i-1, x);
    }
    
    return *this;
}

template<typename T>
void Chain<T>::ToList(LinearList<T>& L)
{
    int index = 1;
    int x;
    while (Find(index, x)) {
	L.Insert(index-1, x);
	index++;
    }
}

/**
 * 析构函数，删掉链表中的所有函数
 */
template<typename T>
Chain<T>::~Chain()
{
    Erase();   
}

template<typename T>
Chain<T>::Chain(const Chain<T>& c)
{
    ChainNode<T> *current = c.first;
    while(current){
	ChainNode<T> *node = new ChainNode<T>();
	node->data = current->data;
	node->link = NULL;
	if (current == c.first){
	    first = node;
	    last = node;
	} else {
	    last->link = node;
	    last = node;
	}
	current = current->link;
    }
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
    first = last = 0;
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
