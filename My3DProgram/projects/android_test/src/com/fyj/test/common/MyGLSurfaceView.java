package com.fyj.test.common;

import android.content.Context;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class MyGLSurfaceView extends SurfaceView implements
		SurfaceHolder.Callback {

	private SurfaceHolder surfaceHolder = null;
	private RenderThread renderThread = null;
	private Context context = null;

	public MyGLSurfaceView(Context context) {
		super(context);
		this.context = context;
		surfaceHolder = getHolder();
		surfaceHolder.addCallback(this);
		startRenderThread();
	}

	public void startRenderThread() {
		renderThread = new RenderThread(context);
		renderThread.setSurfaceHolder(surfaceHolder);
		renderThread.start();
	}

	@Override
	public void surfaceCreated(SurfaceHolder holder) {
		Logger.info("MyGLSurfaceView::surfaceCreated");
		renderThread.surfaceCreated();
	}

	@Override
	public void surfaceDestroyed(SurfaceHolder holder) {
		Logger.info("surfaceDestroyed");
		renderThread.surfaceDestroyed();
	}

	@Override
	public void surfaceChanged(SurfaceHolder holder, int format, int w, int h) {
		Logger.info("surfaceChanged");
		renderThread.onWindowResize(w, h);
	}

	@Override
	public void onWindowFocusChanged(boolean hasFocus) {
		super.onWindowFocusChanged(hasFocus);
		renderThread.onWindowFocusChanged(hasFocus);
	}

	/**
	 * Inform the view that the activity is paused.
	 */
	public void onPause() {
		renderThread.onPause();
	}

	/**
	 * Inform the view that the activity is resumed.
	 */
	public void onResume() {
		renderThread.onResume();
	}

	/**
	 * Queue an "event" to be run on the GL rendering thread.
	 * 
	 * @param r
	 *            the runnable to be run on the GL rendering thread.
	 */
	public void queueEvent(Runnable r) {
		renderThread.queueEvent(r);
	}

	@Override
	protected void onDetachedFromWindow() {
		super.onDetachedFromWindow();
		renderThread.requestExitAndWait();
	}

}
