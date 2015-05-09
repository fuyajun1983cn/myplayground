/**
 * VM Args: -Xss2M
 * @author zzm
 */

/**
 * 本测试程序演示创建线程导致内存溢出异常
 */

public class JavaVMStackOOM {

    private void dontStop() {
	while (true) {
	}
    }

    public void stackLeakByThread() {
	while (true) {
	    Thread thread = new Thread(new Runnable() {
		public void run() {
		    dontStop();
		}
	    });
	    thread.start();
	}

    }

    public static void main(String args[]) throws Throwable {
	JavaVMStackOOM oom = new JavaVMStackOOM();
	oom.stackLeakByThread();
    }
}
