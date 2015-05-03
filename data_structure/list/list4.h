#ifndef _LIST4_H
#define _LIST4_H
/**
 * 线性表的链式存储实现
 * 带头结点的单向循环链表实现
 *
 */
#include <iostream>
#include "xcept.h"

using namespace std;

template<typename T>
class CircularList;

template<typename T>
class CircularListNode
{
    friend CircularList<T>;

private:
    T data;
    CircularListNode<T> *link;
};

template<typename T>
class CircularList
{
public:
    CircularList() { first = new CircularListNode<T>; first->link = first; }
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
    void Zero() { first = nullptr; }
    //在链表右端添加一个元素
    CircularList<T>& Append(const T& x);

    /**
     * 将链表中的元素反序
     */
    CircularList<T>& Reverse();

    /**
     * 将链表A和B的元素轮流放入链表中。
     */
    CircularList<T>& Alternate(CircularList<T>& a, CircularList<T>& b);

    /**
     * 将两个有序按(升序)表合并到当前链表中，合并后，两个链表为空
     */
    CircularList<T>& Merge(CircularList<T>& a, CircularList<T>& b);

    /**
     * 将当前链表拆分成为两个链表，
     * 奇数位和偶数位的元素分别放置于不同的链表中
     */
    void Split(CircularList<T>& a, CircularList<T>& b);


private:
    CircularListNode<T> *first; //指向第一个结点的指针
};

/**
 * 析构函数，删掉链表中的所有函数
 */
template<typename T>
CircularList<T>::~CircularList()
{
    Erase();   
    delete first;
    first = nullptr;
}

/**
 * 将链表中的元素反序
 */
template<typename T>
CircularList<T>& CircularList<T>::Reverse()
{
    CircularListNode<T> *node = first->link;
    
    /**
     * Let's process the first node
     */
    node = node->link;
    first->link->link = first;

    while(node && node != first) {
	CircularListNode<T> *old = first->link;
	CircularListNode<T> *current = node;
	node = node->link;
	first->link = current;
	current->link = old;
    }

    return *this;
}

/**
 * 将链表A和B的元素轮流放入链表中。
 */
template<typename T>
CircularList<T>& CircularList<T>::Alternate(CircularList<T>& a, CircularList<T>& b)
{
    if (a.IsEmpty() && b.IsEmpty())
	return *this;
    Erase();
    CircularList<T> dummy;
    CircularList<T>& list ((a.IsEmpty() && !b.IsEmpty())? b: (!a.IsEmpty() && b.IsEmpty()) ? a : dummy);
    if (!list.IsEmpty() ) {//链表a或b任何一个不为空时
	CircularListNode<T>* node = list.first->link;
	first->link = node;
	while (node && node->link != list.first) {
	    node = node->link;
	}

	node->link = first;

	list.first->link = list.first;
    
    } else {//list is dummy, 则两个链表都不为空
        CircularListNode<T> *aCurrent = a.first->link;
        CircularListNode<T> *bCurrent = b.first->link;
	CircularListNode<T> *current = first;

        while (aCurrent && bCurrent) {
	    current->link = aCurrent;
	    aCurrent = aCurrent->link;
	    current = current->link;
	    current->link = bCurrent;
	    bCurrent = bCurrent->link;
	    current = current->link;

	    if (aCurrent == a.first || bCurrent == b.first)
		break;
	}

	if (aCurrent == a.first) {//链表b些
	    current->link = bCurrent;
	    while (bCurrent->link != b.first)
		bCurrent = bCurrent->link;
	    bCurrent->link = first;
	} else if (bCurrent == b.first) {
	    current->link = aCurrent;
            while (aCurrent->link != a.first)
		aCurrent = aCurrent->link;
	    aCurrent->link = first;
	} else {
	    current->link = first;
	}

	a.first->link = a.first;
	b.first->link = b.first;
    }

    return *this;
}

/**
 * 将两个有序按(升序)表合并到当前链表中，合并后，两个链表为空
 */
template<typename T>
CircularList<T>& CircularList<T>::Merge(CircularList<T>& a, CircularList<T>& b)
{

    if (a.IsEmpty() && b.IsEmpty())
	return *this;
    Erase();
    CircularList<T> dummy;
    CircularList<T>& list = (a.IsEmpty() && !b.IsEmpty())? b: ((!a.IsEmpty() && b.IsEmpty()) ? a : dummy);
    if (!list.IsEmpty()) {//链表a或b有一个为空时
	CircularListNode<T>* node = list.first->link;
	first->link = node;
	while (node && node->link != list.first) {
	    node = node->link;
	}

	node->link = first;

	list.first->link = list.first;
    
    } else {//链表都不为空

        CircularListNode<T> *aCurrent = a.first->link;
        CircularListNode<T> *bCurrent = b.first->link;
	CircularListNode<T> *current = first;

        while (aCurrent && bCurrent) {
	    if (aCurrent->data < bCurrent->data){
		current->link = aCurrent;
		aCurrent = aCurrent->link;
		current = current->link;
	    } else {
		current->link = bCurrent;
		bCurrent = bCurrent->link;
		current = current->link;
	    }

	    if (aCurrent == a.first || bCurrent == b.first)
		break;
	}

	if (aCurrent == a.first) {//链表a已经比较完？
	    current->link = bCurrent;
	    while (bCurrent->link != b.first)
		bCurrent = bCurrent->link;
	    bCurrent->link = first;
	} else if (bCurrent == b.first) {
	    current->link = aCurrent;
            while (aCurrent->link != a.first)
		aCurrent = aCurrent->link;
	    aCurrent->link = first;
	} else {
	    current->link = first;
	}

	a.first->link = a.first;
	b.first->link = b.first;
    }
    return *this;
}

/**
 * 将当前链表拆分成为两个链表，
 * 奇数位和偶数位的元素分别放置于不同的链表中
 */
template<typename T>
void CircularList<T>::Split(CircularList<T>& a, CircularList<T>& b)
{
    if (IsEmpty())
	return;
    CircularListNode<T> *current = first->link;
    CircularListNode<T> *aCurrent = a.first;
    CircularListNode<T> *bCurrent = b.first;
    while (current != first) {
         aCurrent->link = current;
	 aCurrent = aCurrent->link;
	 
	 current = current->link;
	if (current == first)
	   break;

        bCurrent->link = current;
        bCurrent = bCurrent->link;
	current = current->link;

    }
    aCurrent->link = a.first;
    bCurrent->link = b.first;

    //当前链表已经变为空
    first->link = first; 

}    


/**
 * 返回链表中的元素总数
 */
template<typename T>
int CircularList<T>::Length() const
{
    CircularListNode<T> *node = first->link;
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

    CircularListNode<T> *current = first->link;

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
    CircularListNode<T> *current = first->link;
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
    CircularListNode<T> *current = first->link;
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

    CircularListNode<T> *p = first;
    CircularListNode<T> *q = first->link;
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

    CircularListNode<T> *p = first;
    int index = 0;
    while (index < k && p->link != first) {
	p = p->link;
	index++;
    }
    if (index < k) throw OutOfBounds();
    CircularListNode<T> *y = new CircularListNode<T>();
    y->data = x;
    y->link = p->link;
    p->link = y;

    return *this;
}

template<typename T>
void CircularList<T>::Erase()
{
    CircularListNode<T> *next = first->link;
    while (next != first) {
        first->link = next->link;
        delete next;
        next = first->link;
    }	 
    first->link = first;
}

template<typename T>
CircularList<T>& CircularList<T>::Append(const T& x)
{
    CircularListNode<T> *y;
    y = new CircularListNode<T>();
    y->data = x;
    y->link = first;

    CircularListNode<T> *p = first->link;
    while (p->link != first) {
	p = p->link;
    }

    p->link = y; 

    return *this;
}
#endif
