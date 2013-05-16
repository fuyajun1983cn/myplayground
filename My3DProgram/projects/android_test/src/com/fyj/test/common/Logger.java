package com.fyj.test.common;

import android.util.Log;

public class Logger {
	public final static void error(String message) {
		if (Consts.CURRENT_DEBUG_LEVEL <= Consts.ERROR) {
			Log.e("Android Test", message);
		}
	}

	public final static void warn(String message) {
		if (Consts.CURRENT_DEBUG_LEVEL <= Consts.WARNING) {
			Log.w("Android Test", message);
		}
	}

	public final static void info(String message) {
		if (Consts.CURRENT_DEBUG_LEVEL <= Consts.INFO) {
			Log.i("Android Test", message);
		}
	}

	public final static void exception(Throwable t) {
		t.printStackTrace();
	}

	public final static void exception(Exception ex) {
		ex.printStackTrace();
	}
}
