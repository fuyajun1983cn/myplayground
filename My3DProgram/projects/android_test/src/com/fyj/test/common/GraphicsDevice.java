package com.fyj.test.common;

import java.util.LinkedList;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLSurface;
import javax.microedition.khronos.opengles.GL10;

import android.graphics.PixelFormat;
import android.view.SurfaceHolder;

public class GraphicsDevice {
	private static GraphicsDevice _instance = null;
	private EGL10 egl10 = null;
	private EGLDisplay eglDisplay = null;
	private EGLSurface eglSurface = null;
	private EGLContext eglContext = null;
	private GL10 gl10 = null;
	private int activeEGLConfigId = -1;
	private EGLConfig activeEGLConfig = null;

	public void init() {
		egl10 = (EGL10) EGLContext.getEGL();

		eglDisplay = egl10.eglGetDisplay(EGL10.EGL_DEFAULT_DISPLAY);

		int[] version = new int[2];
		egl10.eglInitialize(eglDisplay, version);
	}

	public LinkedList<Integer> findValidEGLConfig() {

		LinkedList<Integer> configIdList = new LinkedList<Integer>();

		int[] supported = new int[1];
		int[] numConfigs = new int[1];

		int[] id = new int[1];
		id[0] = -1;

		egl10.eglGetConfigs(eglDisplay, null, 0, numConfigs);
		EGLConfig[] configs = new EGLConfig[numConfigs[0]];

		egl10.eglGetConfigs(eglDisplay, configs, numConfigs[0], numConfigs);

		int targetRBit = 8;
		int targetGBit = 8;
		int targetBBit = 8;
		int targetABit = 8;
		int targetDepth = 8;

		for (int i = 0; i < numConfigs[0]; i++) {
			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_SURFACE_TYPE, supported);
			if ((supported[0] & EGL10.EGL_WINDOW_BIT) != EGL10.EGL_WINDOW_BIT)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_RENDERABLE_TYPE, supported);
			if ((supported[0] & Consts.EGL_OPENGL_ES2_BIT) != Consts.EGL_OPENGL_ES2_BIT)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_CONFIG_CAVEAT, supported);
			if (supported[0] == EGL10.EGL_SLOW_CONFIG)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_RED_SIZE, supported);
			if (supported[0] < targetRBit)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_GREEN_SIZE, supported);
			if (supported[0] < targetGBit)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_BLUE_SIZE, supported);
			if (supported[0] < targetBBit)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_DEPTH_SIZE, supported);
			if (supported[0] < targetDepth)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_ALPHA_SIZE, supported);
			if (supported[0] < targetABit)
				continue;

			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_CONFIG_ID, id);

			configIdList.add(id[0]);
		}

		if (configIdList.size() == 0)
			configIdList.add(-1);

		return configIdList;
	}

	public EGLConfig createEGLContext(int eglConfigId) {
		int[] numConfigs = new int[1];
		egl10.eglGetConfigs(eglDisplay, null, 0, numConfigs);

		EGLConfig[] configs = new EGLConfig[numConfigs[0]];
		egl10.eglGetConfigs(eglDisplay, configs, numConfigs[0], numConfigs);

		int[] attrib_list = { Consts.EGL_CONTEXT_CLIENT_VERSION, 2,
				EGL10.EGL_NONE };

		int[] id = new int[1];
		int i = 0;
		for (i = 0; i < numConfigs[0]; i++) {
			egl10.eglGetConfigAttrib(eglDisplay, configs[i],
					EGL10.EGL_CONFIG_ID, id);
			if (id[0] == eglConfigId)
				break;
		}
		activeEGLConfigId = id[0];
		activeEGLConfig = configs[i];
		eglContext = egl10.eglCreateContext(eglDisplay, activeEGLConfig,
				EGL10.EGL_NO_CONTEXT, attrib_list);

		return activeEGLConfig;
	}

	public boolean createGLSurface(EGLConfig eglConfig,
			SurfaceHolder surfaceHolder) {
		if (eglSurface != null) {
			egl10.eglMakeCurrent(eglDisplay, EGL10.EGL_NO_SURFACE,
					EGL10.EGL_NO_SURFACE, EGL10.EGL_NO_CONTEXT);
			egl10.eglDestroySurface(eglDisplay, eglSurface);
		}

		surfaceHolder.setFormat(PixelFormat.RGBX_8888);

		eglSurface = egl10.eglCreateWindowSurface(eglDisplay, eglConfig,
				surfaceHolder, null);

		if (eglSurface == EGL10.EGL_NO_SURFACE) {
			surfaceHolder.setFormat(PixelFormat.RGBA_8888);
			eglSurface = egl10.eglCreateWindowSurface(eglDisplay, eglConfig,
					surfaceHolder, null);
		}

		if (eglSurface == EGL10.EGL_NO_SURFACE) {
			eglSurface = null;
			Logger.error("NOSURFACE");
			return false;
		}

		if (eglDisplay == EGL10.EGL_NO_DISPLAY) {
			Logger.error("NODISPLAY");
		}

		if (eglContext == EGL10.EGL_NO_CONTEXT) {
			Logger.error("NOCONTEXT");
		}

		egl10.eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);

		gl10 = (GL10) eglContext.getGL();

		return true;
	}

	public void clear(int mask) {
		gl10.glClear(mask);
	}

	public void flush() {
		gl10.glFlush();
	}

	public boolean swapBuffers() {
		return egl10.eglSwapBuffers(eglDisplay, eglSurface);
	}

	public void cleanUp() {
		if (eglSurface != null) {
			egl10.eglMakeCurrent(eglDisplay, EGL10.EGL_NO_SURFACE,
					EGL10.EGL_NO_SURFACE, EGL10.EGL_NO_CONTEXT);
			egl10.eglDestroySurface(eglDisplay, eglSurface);
			eglSurface = null;
		}
		if (eglContext != null) {
			egl10.eglDestroyContext(eglDisplay, eglContext);
			eglContext = null;
		}
		if (eglDisplay != null) {
			egl10.eglTerminate(eglDisplay);
			eglDisplay = null;
		}

		clearActiveEGLConfig();
	}

	public int getActiveEGLConfigId() {
		return activeEGLConfigId;
	}

	public void clearActiveEGLConfig() {
		activeEGLConfigId = -1;
		activeEGLConfig = null;
	}

	public EGLDisplay getEglDisplay() {
		return eglDisplay;
	}

	public EGL10 getEGl10() {
		return egl10;
	}

	public EGLConfig getActiveEGLConfig() {
		return activeEGLConfig;
	}

	public static int eglQuerySurface(int display, int surface, int attribute,
			int[] value) {
		_instance.egl10.eglQuerySurface(_instance.eglDisplay,
				_instance.eglSurface, attribute, value);
		return 1;
	}

	public static int eglGetConfigs(int dispay, EGLConfig[] configs, int size,
			int[] numconfig) {
		_instance.egl10.eglGetConfigs(_instance.eglDisplay, configs, size,
				numconfig);
		return 1;
	}

	public static int eglGetConfigAttrib(int disp, EGLConfig configs,
			int attribute, int[] value) {
		_instance.egl10.eglGetConfigAttrib(_instance.eglDisplay, configs,
				attribute, value);
		return 1;
	}

	public static String eglQueryString(int display, int value) {
		return _instance.egl10.eglQueryString(_instance.eglDisplay, value);
	}

	public static GraphicsDevice instance() {
		if (_instance == null)
			_instance = new GraphicsDevice();

		return _instance;
	}

	public int GetEGLError() {
		return _instance.egl10.eglGetError();
	}
}
