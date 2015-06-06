import java.util.concurrent.locks.*;

class Resource {
    private Lock lock = new ReentrantLock();
    private String name;
    private int resource;

    Resource(String name, int resource) {
        this.resource = resource;
        this.name =name;
    }

    String getName() {
        return name;
    }

    int doSome() {
        return ++resource;
    }

    void cooperate(Resource resource) {
        while (true) {
            boolean myLock = this.lock.tryLock();
            boolean resourceLock = resource.lock.tryLock();

            try {
                if (myLock && resourceLock) {
                    resource.doSome();
                    System.out.printf("%s use %s 's resource%n");
                    break;
                }
            } finally {
                if (myLock) {
                    this.lock.unlock();
                }
                if (resourceLock) {
                    resource.lock.unlock();
                }
            }
        }
    }

}

public class NoDeadLockDemo {

    public static void main(String args[] ) {
        final Resource resource1 = new Resource("resource1", 10);
        final Resource resource2 = new Resource("resource2", 20);
        Thread t1 = new Thread() {
            public void run() {
                for (int i = 0; i < 10; i++) {
                    resource1.cooperate(resource2);
                }
            }
        };

        Thread t2 = new Thread() {
            public void run() {
                for (int i = 0; i < 10; i++) {
                    resource2.cooperate(resource1);
                }
            }
        };

        t1.start();
        t2.start();
    }
}





