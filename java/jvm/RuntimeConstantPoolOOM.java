/**
 * vM Args -XX: PermSize=10M -XX:MaxPermSize=10M
 * @authro zzm
 */

import java.util.*;

/**
 * 本示例程序测试常量池流出
 * String.inter():这个方法的作用是：
 * 如果池中已经包含一个等于引String对象的字符串，则返回代表池中的这个字符串的String对象
 * ，否则，将此String对象包含的字符串添加到常量池中，并且返回此String对象的引用。
 */


public class RuntimeConstantPoolOOM {

    public static void main(String args[]) {
	//使用List保持着常量池的引用，避免Full GC回收常量池行为
	//
	List<String> list = new ArrayList<String>();

	int i = 0;
	while (true) {
	    list.add(String.valueOf(i++).intern());
	}
    }
}

