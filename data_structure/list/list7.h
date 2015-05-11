#ifndef _LIST7_H
#define _LIST7_H
/**
 *
 * 模拟指针方式实现链表
 */

#include <iostream>
#include "xcept.h"


template<typename T>
class SimSpace;

template<typename T>
class SimChain;

template<typename T>
class SimNode {
    friend SimSpace<T>;
    friend SimChain<T>;

private:
    T data;
    int link;
};

template<typename T>
class SimSpace {
    friend SimChain<T>;
public:
    SimSpace(int MaxSpaceSize = 100);
    ~SimSpace() { delete []node; }
    int Allocate(); //分配一个节点
    void Deallocate(int& i); //释放节点

private:
    int NumberOfNodes, first;
    SimNode<T> *node; //节点数组
};

template<typename T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{
    NumberOfNodes = MaxSpaceSize;
    //初始化可用空间表
    //创建一个节点链表
    node = new SimNode<T>[NumberOfNodes];

    for (int i = 0; i < NumberOfNodes; i++) {
	node[i].link = i+1;
    }
    //链表的最后一个节点
    node[NumberOfNodes - 1].link = -1;
    //链表的第一个节点
    first = 0;
}

template<typename T>
int SimSpace<T>::Allocate()
{
    if (first == -1) throw NoMem();

    int i = first;
    first = node[i].link;
    return i;
}

template<typename T>
void SimSpace<T>::Deallocate(int& i)
{
    //释放节点i,使i成为可用空间表的第一个节点
    node[i].link = first;
    first = i;
    i = -1;
}

template<typename T>
class SimChain {
public:
    SimChain() { first = -1; }
    ~SimChain() { Destroy(); }
    void Destroy(); //使表为空
    int Length() const;
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    SimChain<T>& Delete(int k, T& x);
    SimChain<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;

private:
    int first;
    SimSpace<T> S;
};


template<typename T>
ostream& operator<<(ostream& out, const SimChain<T>& list)
{
    list.Output(out);

    return out;
}

template<typename T>
void SimChain<T>::Output(ostream& out) const
{
   int current = first;

   while (current != -1) {
     cout<<S.node[current].data<<" ";
     current = S.node[current].link;
   }
}

template<typename T>
int SimChain<T>::Search(const T& x) const
{
    int current = first;

    while (current != -1) {
	if (S.node[current].data == x)
	    break;
	current = S.node[current].link;
    }
    return current;
}

template<typename T>
void SimChain<T>::Destroy()
{
    //释放链表节点
    int next;
    while (first != -1) {
	next = S.node[first].link;
	S.Deallocate(first);
	first = next;
    }

}


template<typename T>
int SimChain<T>::Length() const
{
    //返回链表的长度
    int current = first;
    int len = 0;

    while (current != -1) {
	current = S.node[current].link;
	len++;
    }

    return len;

}


template<typename T>
bool SimChain<T>::Find(int k, T& x) const
{
    if (k < 1)
	return false;

    int current = first;
    int index = 1;

    while (index < k && current != -1) {
	current = S.node[current].link;
	index++;
    }

    if (current != -1) {
	x = S.node[current].data;
	return true;
    }

    return false;
}


template<typename T>
SimChain<T>& SimChain<T>::Delete(int k, T& x)
{
    if (k < 1 || first == -1)
	throw OutOfBounds();

    //p最终指向第k个节点
    int p = first;
    if (k == 1)
	first = S.node[first].link;
    else {
	int q = first;
	for (int index = 1; index < k - 1 && q != -1; index++)
	    q = S.node[q].link;

	//验证第k个元素的存在性
	if (q == -1 || S.node[q].link == -1)
	    throw OutOfBounds();

	p = S.node[q].link;
	S.node[q].link = S.node[p].link;
    }

    x = S.node[p].data;
    S.Deallocate(p);

    return *this;
}

template<typename T>
SimChain<T>& SimChain<T>::Insert(int k, const T& x)
{
    //
    if (k < 0)
	throw OutOfBounds();

    int p = first;
    for (int index = 1; index < k && p != -1; index++)
	p = S.node[p].link;

    //验证第k个节点
    if (k > 0 && p == -1)
	throw OutOfBounds();

    int y = S.Allocate();
    S.node[y].data = x;

    if (k) {
	S.node[y].link = S.node[p].link;
	S.node[p].link = y;
    } else {
	S.node[y].link = first;
	first = y;
    }

    return *this;

}


#endif
