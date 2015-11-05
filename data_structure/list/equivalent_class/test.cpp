#include "equivnode.h"

EquivNode *node = nullptr;

/**
 * 任务调度
 * 列表所有的任务调度序列，对于每个任务：确定与最后期限最接近的空闲时间段。
 * @param tv 时间段
 */

int start_time[] = { 0, 0, 1, 2 };
/**
 * 对任意时间段a, 定义near(a)为最大i(时间段), i <= a时，时间段i空闲。
 * 如果不存在这样的i, 则定义near(a) = near(b) = 0. 
 */
int near(int tv) 
{
    if (tv == 0)
        return 0;
    int e = Find(tv);

    //e 等价类的值，也即任务的最后期限
    if (node[e].link == 0)
        return e;
    return near(tv - 1);
}


/**
 * 调度任务
 */



int main(int argc, const char *argv[])
{
    /**
     * 任务调度问题
     */
    Initialize(4);
    //

    return 0;
}


1 2 3 4 
0 0 1 2
4 4 2 3

1 3 4 2
near(1) = 1
near(2) = 2
near(3) = 3
near(4) = 4

near(1) = 1
near(2) = 
