package com.fyj.test.common;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.concurrent.Semaphore;

import javax.microedition.khronos.egl.EGLConfig;

import android.content.Context;
import android.view.SurfaceHolder;

public class RenderThread extends Thread {
	private static final Semaphore eglSemaphore = new Semaphore(1);
	private boolean isPaused = false;
	private boolean isContextLost = false;
	private boolean hasSurface = false;
	private boolean lostFocus = false;
	private boolean hasFocus = false;
	private int width = 0;
	private int height = 0;
	private GraphicsDevice graphicsDevice = null;
	private SurfaceHolder surfaceHolder = null;
	private ArrayList<Runnable> eventQueue = new ArrayList<Runnable>();
	private Context context = null;

	public RenderThread(Context ctx) {
		super();
		context = ctx;
		setName("RenderThread");
		graphicsDevice = GraphicsDevice.instance();
	}

	private void waitWhileSurfaceIsCreated() {
		try {
			while (!hasSurface) {
				synchronized (this) {
					wait(100);
				}
			}
		} catch (Exception ex) {
			Logger.error(ex.toString());
			ex.printStackTrace();
		}
	}

	private boolean handleEvents() {
		try {
			synchronized (this) {
				Runnable r;
				while ((r = getEvent()) != null) {
					r.run();
				}
				if (isPaused) {
					// GLBNativeFunctions.appSkipCurrentTest();
					lostFocus = true;
					Logger.info("------------------isPaused-----------------------");
					return false;
				}
				if (needToWait()) {
					while (needToWait()) {
						wait();
					}
				}
			}
		} catch (InterruptedException e) {
			Logger.error(e.toString());
			e.printStackTrace();
		}

		return true;
	}

	private boolean updateAndRender() {

		NativeInterfaces.appRender();

		graphicsDevice.swapBuffers();

		return true;

	}

	private void drawLoadingScreen() {
		graphicsDevice.swapBuffers();
	}

	private void drawRunningScreen() {
		graphicsDevice.swapBuffers();
	}

	private boolean createGraphicsContext() {
		int selectedConfigId = -1;
		boolean isSurfaceCreated = false;

		LinkedList<Integer> configIdList = graphicsDevice.findValidEGLConfig();
		Iterator<Integer> iterator = configIdList.iterator();

		while (!isSurfaceCreated && iterator.hasNext()) {
			selectedConfigId = iterator.next();

			if (selectedConfigId == -1) {
				graphicsDevice.clearActiveEGLConfig();

				return false;
			}

			EGLConfig currentEGLConfig = graphicsDevice
					.createEGLContext(selectedConfigId);
			waitWhileSurfaceIsCreated();
			isSurfaceCreated = graphicsDevice.createGLSurface(currentEGLConfig,
					surfaceHolder);
		}

		Logger.info("Selected EGLConfig Id: " + selectedConfigId);

		return isSurfaceCreated;
	}

	private void guardedRun() throws InterruptedException {

		graphicsDevice.cleanUp();
		graphicsDevice.init();

		boolean isValidEGLConfigFound = createGraphicsContext();
		if (isValidEGLConfigFound == false) {
			graphicsDevice.cleanUp();
			return;
		}

		NativeInterfaces.main(width, height);

		drawLoadingScreen();
		if (NativeInterfaces.appInit() == true) {

			drawRunningScreen();

			while (true) {
				if (!handleEvents()) {
					Logger.info("-----------------handleEvents-----------------------");
					break;
				}

				boolean isRunning = updateAndRender();

				if (!isRunning) {
					Logger.info("---------------updateAndRender--------------------------");
					break;
				}

				if (lostFocus) {
					Logger.info("---------------lost focus--------------");
					break;
				}
			}

		}

		graphicsDevice.cleanUp();
		NativeInterfaces.mainEnd();
	}

	private boolean needToWait() {
		return (isPaused || (!hasFocus) || (!hasSurface) || isContextLost);
	}

	@Override
	public void run() {
		lostFocus = false;
		/*
		 * When the android framework launches a second instance of an activity,
		 * the new instance's onCreate() method may be called before the first
		 * instance returns from onDestroy().
		 * 
		 * This semaphore ensures that only one instance at a time accesses EGL.
		 */
		try {
			try {
				eglSemaphore.acquire();
			} catch (InterruptedException e) {
				return;
			}
			guardedRun();
		} catch (InterruptedException e) {
			// fall thru and exit normally
			Logger.exception(e);
		} finally {
			eglSemaphore.release();
		}
	}

	public void setSurfaceHolder(SurfaceHolder holder) {
		surfaceHolder = holder;
	}

	public void surfaceCreated() {
		Logger.info("RenderThread::surfaceCreated");
		synchronized (this) {
			hasSurface = true;
			isContextLost = false;
			notify();
		}
	}

	public void surfaceDestroyed() {
		Logger.info("surfaceDestroyed");
		synchronized (this) {
			hasSurface = false;
			notify();
		}
	}

	public void onPause() {
		Logger.info("onPause");
		synchronized (this) {
			isPaused = true;
		}
	}

	public void onResume() {
		synchronized (this) {
			isPaused = false;
			notify();
		}
	}

	public void onWindowResize(int _width, int _height) {
		synchronized (this) {

			width = _width;
			height = _height;

		}
	}

	public void requestExitAndWait() {
		synchronized (this) {
			lostFocus = false;
			notify();
		}
		try {
			join();
		} catch (InterruptedException ex) {
			Thread.currentThread().interrupt();
		}
	}

	public void onWindowFocusChanged(boolean hasFocus) {
		synchronized (this) {
			this.hasFocus = hasFocus;
			if (hasFocus == true) {
				notify();
			}
		}
	}

	/**
	 * Queue an "event" to be run on the GL rendering thread.
	 * 
	 * @param r
	 *            the runnable to be run on the GL rendering thread.
	 */
	public void queueEvent(Runnable r) {
		synchronized (this) {
			eventQueue.add(r);
		}
	}

	private Runnable getEvent() {
		synchronized (this) {
			if (eventQueue.size() > 0) {
				Logger.error("Queue size: " + eventQueue.size());
				return eventQueue.remove(0);
			}
		}
		return null;
	}
}
