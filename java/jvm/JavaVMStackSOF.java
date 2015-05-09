/**
 * VM Args: -Xss128k
 * @author zzm
 */

/**
 * NOTES:
 * 1.
 * 如果线程请求的栈深度大于虚拟机所允许的最大深度，将抛出StackOverflowError异常。
 * 2.
 * 如果虚拟机在扩展栈时无法申请到足够的内存空间，则抛出OutOfMemoryError异常。
 */

/**
 * 测试程序：
 * 如果栈的大小超过128k，就抛出异常
 */

public class JavaVMStackSOF {

    private int stackLength = 1;

    public void stackLeak() {
	stackLength++;
	stackLeak();
    }

    public static void main(String[] args) throws Throwable {

	JavaVMStackSOF oom = new JavaVMStackSOF();

	try {
	    oom.stackLeak();
	} catch (Throwable e) {
	    System.out.println("stack length: " + oom.stackLength);
	    throw e;
	}

    }

}
