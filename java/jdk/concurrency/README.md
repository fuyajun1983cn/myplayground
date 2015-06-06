##并行API  
使用Thread建立多线程程序，必须亲自处理synchronized,对象锁定,wait(), notify(), notifyAll()等细节。如果需要的是线程池，读写锁等高级操作，从JDK5之后提供了java.util.concurrent包。

1. 使用Lock  
Lock接口的主要操作类之一为`ReentrantLock`，可以达到synchronized的作用。
还有一些特定情况下使用的锁：`ReadWriteLock`, `ReentrantReadWriteLock`

2. 使用Condition  
Condition接口搭配Lock，最基本的用法就是达到Object的wait(),notify(),notifyAll()方法的作用。
```java

Lock lock = new ReentrantLock();
Condition condition = lock.newCondition();

...
try {
    lock.locl();

     while(...) {
         condition.await();
     }

     ...
     condition.signal();

     ...

}
finally {

    lock.unlock();

}
```

3. Executors
```java
Executor excutor;

...

executor.execute(new Runnable() {

    ...


});

```

4. Future API

5. ScheduledExecutorService


