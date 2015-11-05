#ifndef _EQUIV_NODE_H
#define _EQUIV_NODE_H

class EquivNode {
    /**
     * 在线等价类所需的三个接口
     */
    friend void Initialize(int n);
    friend void Union(int i, int j);
    friend int Find(int e);

private:
    int E;
    int size;
    int link;
};

extern EquivNode *node;

/**
 * 初始化等价类
 */
inline void Initialize(int n)
{
    //初始化n个类，每个类只有一个元素
    node = new EquivNode[n + 1];
    for (e = 1; e <= n; e++) {
       node[e].E = e;
       node[e].link = 0;
       node[e].size = 1;
    }
}

/**
 * 合并两个等价类
 */
inline void Union(int i, int j)
{
    //合并类i和类j, i代表较小的类
    //
    if (node[i].size > node[j].size)
        swap(i, j);

    //改变较小类的E值
    int k;
    for (k = i; node[k].link; k = node[k].link)
        node[k].E = j;
    node[k].E = j;

    //在链接j的首结点之后插入链表i
    node[j].size += node[i].size;
    node[k].link = node[j].link;
    node[j].link = i;
}

/**
 * 返回结点所在的等价类
 */
int Find(int e)
{
    return node[e].E;
}

#endif
