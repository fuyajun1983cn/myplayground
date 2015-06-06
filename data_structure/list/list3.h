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
    Chain() { first = last = nullptr; }
    Chain(const Chain<T>& C);
    ~Chain();
    bool IsEmpty() const { return first == nullptr; }
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
    void Zero() { first = nullptr; }
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

    /**
     * 将两个有序链表合并
     */
    Chain<T>& Merge(Chain<T>& a, Chain<T>& b);

    /**
     * 拆分当前链表，其中奇数位上的元素和偶数位上的函数分别置于不同的链表中
     */
    void Split(Chain<T>& a, Chain<T>& b);

    /**
     * 排序操作
     */
    //插入排序
    Chain<T>& InsertionSort();

    /**
     * 箱子排序
     */
#if BINSORT_TEST
    void BinSort(int range);
#endif

private:
    ChainNode<T> *first; //指向第一个结点的指针
    ChainNode<T> *last;//指向最后一个结点的指针
};

/**
 * 箱子排序
 */
#if BINSORT_TEST
template<typename T>
void Chain<T>::BinSort(int range)
{// 按分数排序
    int b; // 箱子索引号
    ChainNode<T> **bottom, **top;
    //箱子初始化
    bottom = new ChainNode<T>* [range + 1];
    top = new ChainNode<T>* [range + 1];

    for (b = 0; b <= range; b++)
        bottom[b] = 0;
    //把节点分配到各箱子中

    for (; first; first = first->link) {// 添加到箱子中
        b = first->data;
    if (bottom[b]) {//箱子非空
        top[b]->link = first;
        top[b] = first;
    }else // 箱子为空
        bottom [ b ] = top[b] = first;
    }

    //收集各箱子中的元素,产生一个排序链表
    ChainNode<T> *y = 0;
    for (b = 0; b <= range; b++)
        if (bottom[b]) {//箱子非空
            if (y) // 不是第一个非空的箱子
                y->link = bottom[b];
            else // 第一个非空的箱子
                first = bottom[b];
            y = top[b];
        }

    if (y) y->link = 0;

    delete [] bottom;
    delete [] top;
}

#endif
/**
 * 排序算法
 */
template<typename T>
Chain<T>& Chain<T>::InsertionSort()
{
    if (!first || !first->link)
	return *this;

    ChainNode<T> *p = first->link;
    
    last = first;
    last->link = nullptr;

    while (p != nullptr) {
	ChainNode<T> *temp = p;
	p = p->link;
    
	ChainNode<T> *prev = nullptr;
	ChainNode<T> *cur = first;
	
	while (cur != nullptr) {
	    if (temp->data > cur->data)
		break;//find the insert pos
	    prev = cur;
	    cur = cur->link;
	}

	if (prev == nullptr) {
	    temp->link = cur;
	    first = temp;
	} else if (cur == nullptr) {
	    prev->link = temp;
	    temp->link = nullptr;
	    last = temp;
	} else {
	    prev->link = temp;
	    temp->link = cur;
	}

    }

   return *this;
         
}


/**
 * 将两个有序链表合并
 */
template<typename T>
Chain<T>& Chain<T>::Merge(Chain<T>& a, Chain<T>& b)
{
    //先重置当前链表为空
    Erase();
    //如果链表a, b都为空,则返回空链表
    if (a.IsEmpty() && b.IsEmpty()) {
	return *this;
    } else if (a.IsEmpty()) {//如果链表a为空,则直接将B链表做为当前链表
	first = b.first;
	last = b.last;
	b.first = b.last = nullptr;
	return *this;
    } else if (b.IsEmpty()) {//如果链表b为空,则直接将A链表做为当前链表
	first = a.first;
	last = a.last;
	a.first = a.last = nullptr;
	return *this;
    }
    ChainNode<T> *aCurrent = a.first;
    ChainNode<T> *bCurrent = b.first;
    ChainNode<T> *current = nullptr;

    if (a.last->data < b.first->data) {//链表a中所有的元素都比链表b中的元素小
	first = a.first;
	current = a.last;
	current->link = b.first;
	last = b.last;
	a.first = a.last = nullptr;
	b.first = b.last = nullptr;
	return *this;
    } else if (a.first->data > b.last->data) {//链表b中所有的元素都比链表a中的元素小
	first = b.first;
	current = b.last;
	current->link = a.first;
	last = a.last;
	a.first = b.last = nullptr;
	b.first = b.last = nullptr;
	return *this;
    } else {//先决定链表的头结点
	if (aCurrent->data < bCurrent->data) {
	    current = aCurrent;
	    first = current;
	    aCurrent = aCurrent->link;
	} else {
	    current = bCurrent;
	    first = current;
	    bCurrent = bCurrent->link;
	}
	while (aCurrent != nullptr && bCurrent != nullptr) {
	    if (aCurrent->data < bCurrent->data) {
		current->link = aCurrent; 
		current = aCurrent;
		aCurrent = aCurrent->link;
	    } else {
		current->link = bCurrent;
		current = bCurrent;
		bCurrent = bCurrent->link;
	    }
	}

	if (aCurrent != nullptr) {
	    current->link = aCurrent;
	    last = a.last;
	} else if (bCurrent != nullptr) {
	    current->link = bCurrent;
	    last = b.last;
	} else {
	    last = current;
	}


	//重围链表A和B为空表
	a.first = a.last = nullptr;
	b.first = b.last = nullptr;

    }

    return *this;

}

/**
 * 拆分当前链表，其中奇数位上的元素和偶数位上的函数分别置于不同的链表中
 */
template<typename T>
void Chain<T>::Split(Chain<T>& a, Chain<T>& b)
{
    if (IsEmpty())
	return;

    int index = 1;
    ChainNode<T> *current = first;

    while (current != nullptr) {
	if (index % 2) {
	    a.Append(current->data);//奇数位置放在链表a中
	} else {
	    b.Append(current->data);//偶数位位置放在链表b中
	}
	current = current->link;
	index++;
    }
}

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


    ChainNode<T> *current = nullptr;
    while (aCurrent != nullptr && bCurrent != nullptr){
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

    if (aCurrent == nullptr && bCurrent == nullptr) {
	last = current;
    }
    
    while (aCurrent != nullptr) {
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

     while (bCurrent != nullptr) {
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

     //最后将链表a,b置空
     a.first = a.last = nullptr;
     b.first = b.last = nullptr;

    return *this;
}



template<typename T>
Chain<T>& Chain<T>::Reverse()
{
    ChainNode<T> *tmp;
    ChainNode<T> *head = nullptr;
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
	node->link = nullptr;
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
