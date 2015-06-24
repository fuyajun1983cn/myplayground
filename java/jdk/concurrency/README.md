##线程安全  
编写线程安全的代码的实质就是管理对*状态*，特别是*共享的*，*可改变的状态*的访问。
当多个线程访问一个状态变量，且其中一个会对它进行写操作，这里必须使用同步机制来协调对该状态变量的访问。
解决并行访问导致的问题的方法如下：  
* 不要跨线程共享状态变量。  
* 将状态变量设置为不可修改的。
* 或任何时候访问状态变量时，使用同步。  
**线程安全**的类封装了任何需要同步访问的地方，使得使用者无需提供自己的同步方法。  
**无状态的对象问题线程安全的**    
为了保证状态的一致性，在单个原子操作内更新相关的状态变量。  

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

6. 利用线程安全类  
  如AtomicLong, AtomicBoolean等。

7. intrinsic lock  
  Java中的每个对象都可以作为intrinsic
  lock，每个intrinsic都是可重入的。这样的锁是每-线程锁，而不是每-调用锁(如pthread)。意味着，在Java中，
  由synchronized保护起来的代码只能阻止线程间的多次访问，但是不能阻止线程内的多次访问。  

