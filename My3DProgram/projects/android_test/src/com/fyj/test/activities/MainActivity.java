package com.fyj.test.activities;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

import com.fyj.test.common.GlobalVariables;
import com.fyj.test.common.MyGLSurfaceView;

public class MainActivity extends Activity {

	private MyGLSurfaceView appView = null;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);

		GlobalVariables.sharedContext = this;

		// full screen
		final Window window = this.getWindow();
		window.addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
		window.clearFlags(WindowManager.LayoutParams.FLAG_FORCE_NOT_FULLSCREEN);
		window.requestFeature(Window.FEATURE_NO_TITLE);

		appView = new MyGLSurfaceView(this);
		setContentView(appView);
	}

	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		super.onPause();
		appView.onPause();
	}

	@Override
	protected void onResume() {
		// TODO Auto-generated method stub
		super.onResume();
		appView.onResume();
	}

}
