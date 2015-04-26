#ifndef _LIST5_H
#define _LIST5_H
/**
 * 线性表的链式存储实现
 * 双向链表的实现
 *
 */
#include <iostream>
#include "xcept.h"

using namespace std;

template<typename T>
class Double;

template<typename T>
class DoubleNode
{
    friend Double<T>;

private:
    T data;
    DoubleNode<T> *left, *right;
};

template<typename T>
class Double
{
public:
    Double() { LeftEnd = RightEnd = 0; }
    ~Double();
    bool IsEmpty() const { return LeftEnd == 0; }
    int Length() const;
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    Double<T>& Delete(int k, T& x);
    Double<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;

    void Erase();
    Double<T>& Append(const T& x);
    
private:
    DoubleNode<T> *LeftEnd; //指向第一个结点的指针
    DoubleNode<T> *RightEnd; //指向最后一个结点的指针
};

/**
 * 析构函数，删掉链表中的所有函数
 */
template<typename T>
Double<T>::~Double()
{
    Erase();
}

/**
 * 返回链表中的元素总数
 */
template<typename T>
int Double<T>::Length() const
{
    DoubleNode<T> *node = LeftEnd;
    int length = 0;

    while(node) {
	node = node->right;
	length++;
    }

    return length;
}

template<typename T>
bool Double<T>::Find(int k, T& x) const
{
    if (k < 1) return false;

    DoubleNode<T> *current = LeftEnd;

    int index = 1;

    while (index < k && current) {
	current = current->right;
	index++;
    }

    if (current != NULL) {
	x = current->data;
	return true;
    }

    return false;
}

template<typename T>
int Double<T>::Search(const T& x) const
{
    DoubleNode<T> *current = LeftEnd;
    int index = 1;

    while (current && current->data != x) {
	index++;
	current = current->right;
    }

    return index;
} 

template<typename T>
void Double<T>::Output(ostream& out) const
{
    DoubleNode<T> *current = LeftEnd;
    while (current) {
	out<<current->data<<" ";
	current = current->right;
    }
}

template<typename T>
ostream& operator<<(ostream& out, const Double<T>& x)
{
    x.Output(out);
    return out;
}

template<typename T>
Double<T>& Double<T>::Delete(int k, T& x)
{
    if (k < 1 )
	throw OutOfBounds();

    DoubleNode<T> *p = LeftEnd;
    int index = 1;
    while (p && index < k) {
         p = p->right;
	 index++;
    }

    if (index != k)
	throw OutOfBounds();

    if (p == LeftEnd) {
	LeftEnd = p->right;
	LeftEnd->left = 0;
    } else if (p == RightEnd) {
	RightEnd = p->left;
	RightEnd->right = 0;
    } else {
	p->left->right = p->right;
	p->right->left = p->left;
    }

    delete p;
    p = NULL;
    
    return *this;

}
/**
 * 在第k个元素之后插入元素
 */
template<typename T>
Double<T>& Double<T>::Insert(int k, const T& x)
{
    if (k < 0) throw OutOfBounds();

    DoubleNode<T> *p = LeftEnd;
    int index = 1;
    while (index < k && p) {
	p = p->right;
	index++;
    }
    if (index < k) throw OutOfBounds();
    
    DoubleNode<T> *y = new DoubleNode<T>();
    y->data = x;

    if (IsEmpty()) {//链表为空时
	y->right = y->left = 0;
	LeftEnd = RightEnd = y;
    } else if (k == 0) {//在第一个元素前插入元素
	y->right = LeftEnd;
	y->left = 0;
	LeftEnd->right = y;
	LeftEnd = y;
    } else if (p == RightEnd) {//在链表尾部插入元素
	y->left = RightEnd;
	y->right = 0;
	RightEnd->right = y;
	RightEnd = y;
    } else {
	y->left = p;
	y->right = p->right;
	p->right = y;
    }

    return *this;
}

template<typename T>
void Double<T>::Erase()
{
    DoubleNode<T> *next = LeftEnd;
    while (next != NULL) {
        LeftEnd = next->right;
        delete next;
        next = LeftEnd;
    }	 
}

template<typename T>
Double<T>& Double<T>::Append(const T& x)
{
    DoubleNode<T> *y;
    y = new DoubleNode<T>();
    y->data = x;
    y->left = RightEnd;
    y->right = 0;
    RightEnd->right = y;
    RightEnd = y;
    return *this;
}
#endif
