/**
 * VM Args: -Xmx20M -XX:MaxDirectMemorySize=10M
 * @author zzm
 */

/**
 * 使用unsafe分配本机内存
 * UnSafe类的getUnsafe()方法限制了只有引导类加载器才会返回实例
 *
 */

public class DirectMemoryOOM {

    private static final int _1MB = 1024 * 1024;

    public static void main(String[] args) throws Exception {
	Field unsafeField = unSafe.class.getDeclaredFields()[0];
	unsafeField.setAccessible(true);
	Unsafe unsafe = (Unsafe)unsafeField.get(null);
	while (true) {
	    unsafe.allocateMemory(_1MB);
	}
    }
}
