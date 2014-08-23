package com.fyj.test.common;

import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Log;

import com.fyj.test.R;

public class Utilities {

	// called from native c++ code filename with no extension name
	public static Bitmap loadImageFromDrawable(String filename) {
		Bitmap imageBitmap = null;
		int resId = 0;

		int index = filename.indexOf('.');// remove extension if has
		if (index != -1)
			filename = filename.substring(0, index);

		try {

			Field field = R.drawable.class.getField(filename);

			resId = field.getInt(new R.drawable());

		} catch (Exception e) {
			Log.i("Utilities", "failed to get resouce id");
			return null;
		}

		Log.i("Utilities", "resource id : " + resId);

		imageBitmap = BitmapFactory.decodeResource(
				GlobalVariables.sharedContext.getResources(), resId);
		if (imageBitmap != null) {
			Logger.info("Width: " + imageBitmap.getWidth() + " ,  Height: "
					+ imageBitmap.getHeight());
		} else {
			Logger.warn("image is null");
		}
		return imageBitmap;
	}

	public static Bitmap loadImageFromRaw(String filename) {
		Bitmap imageBitmap = null;
		int resId = 0;

		Resources res = GlobalVariables.sharedContext.getResources();
		resId = res.getIdentifier(filename, "raw", null);

		imageBitmap = BitmapFactory.decodeResource(
				GlobalVariables.sharedContext.getResources(), resId);
		if (imageBitmap != null) {
			Logger.info("Width: " + imageBitmap.getWidth() + " ,  Height: "
					+ imageBitmap.getHeight());
		} else {
			Logger.warn("image is null");
		}
		return imageBitmap;
	}

	public static Bitmap loadImageFromAssets(String filename) {

		InputStream in = null;
		Bitmap bitmap = null;

		try {
			in = GlobalVariables.sharedContext.getAssets().open(filename);
			bitmap = BitmapFactory.decodeStream(in);
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if (in != null) {
				try {
					in.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

		return bitmap;
	}
}
