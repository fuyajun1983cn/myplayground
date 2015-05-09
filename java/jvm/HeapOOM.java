/**
 * VM Args: -Xms20m -Xmx20m -XX:+HeapDumpOnOutOfMemoryError
 * Test: java -verbose:gc -Xms20M -Xmx20M -XX:+HeapDumpOnOutOfMemoryError HeapOOM
 * @author zzm
 */
/**
 * notes added by Yajun Fu(fuyajun1983cn@163.com) Copyright 2015 Yajun Fu, all rights
 * reserved 
 *
 *  1. 确认虚拟机内存泄漏的步骤：
       1.1 内存中的对象是否必要，即到底是内存泄漏还是内存溢出
       1.2
       如果是内存泄漏，就要分析是什么原因导致的垃圾回收器无法自动回收泄漏的对象。
       如果不存在泄漏，则要检查虚拟机的堆参数（-Xmx与-Xms）,与物理内存对比看是否还可以调大
 *
 */

import java.util.*;
/**
 * Java堆溢出实例测试
 */

public class HeapOOM {

    static class OOMObject {
    }

    public static void main(String[] args) {
	List<OOMObject> list = new ArrayList<OOMObject>();

	while (true) {
	    list.add(new OOMObject());
	}
    }
}


/**
 * Results:
* 
*[GC 5126K->3041K(19968K), 0.0201050 secs]
*[GC 8417K->6964K(19968K), 0.0413320 secs]
*[GC 12340K->12349K(19968K), 0.0277070 secs]
*[Full GC 12349K->9265K(19968K), 0.3020940 secs]
*[Full GC 14641K->11475K(19968K), 0.2124890 secs]
*[Full GC 14489K->14454K(19968K), 0.3461920 secs]
*[Full GC 14454K->14444K(19968K), 0.2775270 secs]
*java.lang.OutOfMemoryError: Java heap space
*Dumping heap to java_pid5290.hprof ...
*Heap dump file created [26232715 bytes in 0.299 secs]
*Exception in thread "main" java.lang.OutOfMemoryError: Java heap space
	*at java.util.Arrays.copyOf(Arrays.java:2245)
	*at java.util.Arrays.copyOf(Arrays.java:2219)
	*at java.util.ArrayList.grow(ArrayList.java:242)
	*at java.util.ArrayList.ensureExplicitCapacity(ArrayList.java:216)
	*at java.util.ArrayList.ensureCapacityInternal(ArrayList.java:208)
	*at java.util.ArrayList.add(ArrayList.java:440)
	*at HeapOOM.main(HeapOOM.java:16)
**/
