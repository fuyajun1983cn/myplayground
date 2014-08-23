package com.fyj.test.common;

public class NativeInterfaces {

	public static native boolean appInit();

	public static native boolean appRender();

	public static native void main(int width, int height);

	public static native void mainEnd();

	static {

		try {
			System.loadLibrary("mytest");
			Logger.info("Loading libmytest.so...");
		} catch (Throwable e) {
			Logger.error("failed to find libmytest.so");
		}

		try {
			System.loadLibrary("testbase");
			Logger.info("Loading libtestbase.so ...");
		} catch (Throwable ee) {
			Logger.error("failed to find libtestbase.so !");
			ee.printStackTrace();
		}

	}
}
