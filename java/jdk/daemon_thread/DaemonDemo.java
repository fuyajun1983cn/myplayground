
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
  
