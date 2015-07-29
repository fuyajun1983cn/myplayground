* 后台进程   
在一些情况下，我们希望创建一个后台线程执行一些简单的，周期性的任务。
`setDaemon()`方法可用于标记一个线程为后台线程。  
后台线程只有在其他非后台线程退出后，才会被杀掉。  
```java
class Devil extends Thread {
        Devil() {
            setDaemon( true );
            start();
        }
        public void run() {
            // perform evil tasks
        }
    }
```    


* Fork/Join Framework   
The Fork/Join framework is a new API added in Java 7 that provides just this—a way for you to structure your tasks so that they can be split up as needed to keep all of the available threads busy working on data with as much continuity as possible.   

 The Fork/Join framework API centers on a ForkJoinPool and various implementations of a kind of Future called a ForkJoinTask. The Fork/Join framework can be used in many different ways depending on how you wish to structure the tasks and make decisions about their division (forking) and collecting results (joining);   

* Synchronization Constructs    
The java.util.concurrent package adds several higher-level synchronization utilities borrowed from other languages, including CountDownLatch, Semaphore, CyclicBarrier, Phaser, and Exchanger.    


