##Daemon线程  

主线程会从`main()`方法开始执行，直到`main()`方法结束后，停止JVM。如果主线程中启动了额外线程，默认会等待被
启动的所有线程执行完`run()`方法才会中止JVM。如果一个`Thread`被标示为`Daemon`线程，在所有非`Daemon`线程结束时，JVM自动就会终止。  

  从`main()`方法开始的就是一个非`Daemon`线程，可以使用`setDeamon`方法来设定一个线程是否为Daemon线程。
  代码示例如下：
  ```java
  public class DaemonDemo {
      
      public static void main(String args[]) {
          
          Thread thread = new Thread() {
              
              public void run() {
                  
                  while (true) {
                      System.out.println("Orz");
                  }
              }
          };

          thread.setDaemon(true);

          thread.start();

      }
  }
  
  ```
