#!/usr/bin/env python3
#encoding:utf-8

def insert_sort(lists):
    #插入排序
    count = len(lists)
    for i in range(1, count):
        key = lists[i]
        j = i - 1
        while j >= 0:
            if lists[j] > key:
                lists[j+1] = lists[j]
                lists[j] = key
                j -= 1

    return lists


def shell_sort(lists):
    '''
    希尔排序
    基本操作：把记录按下标的一定增量逐渐减少，
    每组包含的关键词越来越多，当增量减至1时，整个
    记录恰被分成一组，算法便终止。
    '''
    count = len(lists)
    step = 2
    group = count / step
    while group > 0:
        for i in range(0, group):
            j = i + group
            while j < count:
                k = j - group
                key = lists[j]
                while k >= 0:
                    if lists[k] > key:
                        lists[k + group] = lists[k]
                        lists[k] = key
                        k -= group
                        j += group
                        group /= step

    return lists


def bubble_sort(lists):
    '''
    冒泡排序
    基本操作：
    重复访问待排序的序列，一次比较两个元素，
    如果顺序错误，就把他们交换过来。
    '''
    count = len(lists)
    for i in range(0, count):
        swap = False
        for j in range(i + 1, count):
            if lists[i] > lists[j]:
                lists[i], lists[j] = lists[j], lists[i]
                swap = True

            if swap is True:
                break

    return lists

def quick_sort(lists, left, right):
    '''
    快速排序：
    基本操作：每趟将数据分割成独立的两个部分，
    一部分的数据要比另一部分的数据大或小。
    '''
    if left >= right:
        return lists

    key = lists[left]
    low = left
    hight = right

    while left < right:
        while left < right and lists[right] >= key:
            right -= 1
        lists[left] = lists[right]

        while left < right and lists[left] <= key:
            left += 1
        lists[right] = lists[left] 

    lists[right] = key 
    quick_sort(lists, low, left - 1)
    quick_sort(lists, left + 1, hight)

    return lists
    
    
