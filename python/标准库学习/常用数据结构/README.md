##常用数据结构：  
* collections -- 包含了几种数据结构：Deque, defaultdic, OderedDict, Defaultdict,
  * Counter -- 跟踪相同的值被加入了几次
  * defaultdict -- 让调用者指定dict某个key值对应的默认值
  * deque -- 双端队列，支持从队列两端增加或删除元素
  * namedtuple -- 命名元组,可以使用字符串做索引
  * OrderedDict -- 有序字典，记住元素添加时的顺序
* array -- 比list更能有效使用内存, 元素类型必须一致
* heapq -- 在修改列表内容的时候，也同时保留list的排序。实现了最小堆排序算法，非常适合与列表一起使用
* bisect --用二分查找法搜索新元素的插入点。适用于对一个元素经常变动的列表进行排序。  
* Queue -- 线程安全的队列实现。  
* struct -- 解析来自另一个应用程序的数据。
* weakref -- 弱引用  
* copy -- 复制数据结构和它的内容，包含递归复制：deepcopy()
* pprint -- 更好的打印函数。





* 解压数据  
当解压数据时，丢弃一些数据的做法：   
```Python
>>> data = [ 'ACME', 50, 91.1, (2012, 12, 21) ]
>>> _, shares, price, _ = data
>>> shares
50
>>> price
91.1
>>>
```

当被解压的数据大于变量的个数时，可以使用“星表达式”：  
```python
>>> record = ('Dave', 'dave@example.com', '773-555-1212', '847-555-1212')
>>> name, email, *phone_numbers = user_record
>>> name
'Dave'
>>> email
'dave@example.com'
>>> phone_numbers
['773-555-1212', '847-555-1212']
>>>
```

"星表达式"也可以置于最前面   
```python
>>> *trailing, current = [10, 8, 7, 1, 9, 5, 10, 3]
>>> trailing
[10, 8, 7, 1, 9, 5, 10]
>>> current
3
```

遍历可变长度的元组：   
```python
records = [
     ('foo', 1, 2),
     ('bar', 'hello'),
     ('foo', 3, 4),
]

def do_foo(x, y):
    print('foo', x, y)

def do_bar(s):
    print('bar', s)

for tag, *args in records:
    if tag == 'foo':
        do_foo(*args)
    elif tag == 'bar':
        do_bar(*args)
```

用于字符串处理：   
```python
 >>> line = 'nobody:*:-2:-2:Unprivileged User:/var/empty:/usr/bin/false'
>>> uname, *fields, homedir, sh = line.split(':')
>>> uname
'nobody'
>>> homedir
'/var/empty'
>>> sh
'/usr/bin/false'
>>>       
```

使用星表达式丢弃:   
```python
>>> record = ('ACME', 50, 123.45, (12, 18, 2012))
>>> name, *_, (*_, year) = record
>>> name
'ACME'
>>> year
2012
>>>
```


