package com.fyj.listpullrefresh;

import android.content.Context;
import android.os.Handler;
import android.text.format.Time;
import android.util.AttributeSet;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AbsListView;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;

public class RefreshListView extends ListView {

	private View header;
	private int headerHeight;
	private int firstVisibleItem = -1;
	private float currentY = 0;
	private TextView tipView = null;
	private TextView lastUdateView = null;
	private ImageView arrowView = null;
	private ProgressBar progressBar = null;

	public RefreshListView(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		// TODO Auto-generated constructor stub
		initView(context);
	}

	public RefreshListView(Context context, AttributeSet attrs) {
		super(context, attrs);
		// TODO Auto-generated constructor stub
		initView(context);
	}

	public RefreshListView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
		initView(context);

	}

	/**
	 * 初始化界面，添加顶部布局文件到ListView中。
	 * 
	 * @param context
	 */
	private void initView(Context context) {
		LayoutInflater inflater = LayoutInflater.from(context);
		header = (View) inflater.inflate(R.layout.header_view, null);
		measureView(header);
		headerHeight = header.getMeasuredHeight();
		Log.i("test", "headerHeight = " + headerHeight);
		topPadding(-headerHeight);
		this.addHeaderView(header);
		
		lastUdateView = (TextView)header.findViewById(R.id.lastUpdateTime);
		tipView = (TextView) header.findViewById(R.id.tip);
		arrowView = (ImageView)header.findViewById(R.id.arrow);
		progressBar = (ProgressBar)header.findViewById(R.id.progress);

		this.setOnScrollListener(new OnScrollListener() {

			/**
			 * ListView的状态改变时触发
			 */
			@Override
			public void onScrollStateChanged(AbsListView view, int scrollState) {
				// TODO Auto-generated method stub
				switch (scrollState) {
				case OnScrollListener.SCROLL_STATE_IDLE:// 空闲状态
					// Toast.makeText(getContext(), "空闲状态",
					// Toast.LENGTH_SHORT).show();
					// Toast.makeText(getContext(), "触摸后流动" +
					// view.getFirstVisiblePosition(),
					// Toast.LENGTH_SHORT).show();
					//firstVisibleItem = view.getFirstVisiblePosition();
					break;
				case OnScrollListener.SCROLL_STATE_FLING:// 正在滚动状态
					// Toast.makeText(getContext(), "滚动状态",
					// Toast.LENGTH_SHORT).show();

					break;
				case OnScrollListener.SCROLL_STATE_TOUCH_SCROLL:// 触摸后开始滚动状态
					// Toast.makeText(getContext(), "触摸后流动",
					// Toast.LENGTH_SHORT).show();
					break;
				}
			}

			/**
			 * 正在滚动 firstVisibleItem第一个Item的位置 visibleItemCount 可见的Item的数量
			 * totalItemCount item的总数
			 */
			@Override
			public void onScroll(AbsListView view, int firstVisibleItem,
					int visibleItemCount, int totalItemCount) {
				// TODO Auto-generated method stub
				RefreshListView.this.firstVisibleItem = firstVisibleItem;
			}
		});
	}

	/**
	 * 通知父布局占多大
	 * 
	 * @param view
	 */
	private void measureView(View view) {
		ViewGroup.LayoutParams p = view.getLayoutParams();
		if (p == null) {
			p = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT,
					ViewGroup.LayoutParams.WRAP_CONTENT);
		}

		int width = ViewGroup.getChildMeasureSpec(0, 0, p.width);
		int height;
		int tempHeight = p.height;
		if (tempHeight > 0) {
			height = MeasureSpec.makeMeasureSpec(tempHeight,
					MeasureSpec.EXACTLY);
		} else {
			height = MeasureSpec.makeMeasureSpec(0, MeasureSpec.UNSPECIFIED);
		}
		view.measure(width, height);
	}

	/**
	 * 设置header view的上边距
	 * 
	 * @param topPadding
	 */
	private void topPadding(int topPadding) {
		header.setPadding(header.getPaddingLeft(), topPadding,
				header.getPaddingRight(), header.getPaddingBottom());
		header.invalidate();
	}

	@Override
	public boolean onTouchEvent(MotionEvent ev) {
		// TODO Auto-generated method stub
		if (ev.getAction() == MotionEvent.ACTION_DOWN) {
			 if (firstVisibleItem == 0)
				 currentY = ev.getY();
		} else if (ev.getAction() == MotionEvent.ACTION_MOVE) {
			if (firstVisibleItem == 0) {
				int height = -headerHeight + (int)(ev.getY() - currentY);
				if (height < headerHeight)
					topPadding(height);
				else {
					topPadding(headerHeight);
					if (ev.getY() - currentY > 30) {
						tipView.setText("松开后进行刷新！");
					}
				}
			}
		} else if (ev.getAction() == MotionEvent.ACTION_UP) {
			Handler handler = new Handler();
			handler.postDelayed(new Runnable() {
				
				@Override
				public void run() {
					// TODO Auto-generated method stub
					Time time = new Time();
					time.setToNow();
					String currentTime = "上次更新时间" + time.month + "月" + time.monthDay + "日" + time.hour + "时" + time.minute
							+ "分" + time.second + "秒" ;
					lastUdateView.setText(currentTime);
					lastUdateView.setVisibility(View.VISIBLE);
					tipView.setVisibility(View.GONE);
					arrowView.setVisibility(View.VISIBLE);
					progressBar.setVisibility(View.GONE);
				}
			},  3000);
			Handler handler2 = new Handler();
			handler2.postDelayed(new Runnable() {
				
				@Override
				public void run() {
					// TODO Auto-generated method stub
					topPadding(-headerHeight);
					lastUdateView.setVisibility(View.GONE);
					tipView.setVisibility(View.VISIBLE);
					tipView.setText("继续下拉可以刷新!");
					arrowView.setVisibility(View.VISIBLE);
					progressBar.setVisibility(View.GONE);
				}
			}, 5000);
			tipView.setText("正在刷新...");
			arrowView.setVisibility(View.GONE);
			progressBar.setVisibility(View.VISIBLE);
		}
		return super.onTouchEvent(ev);
	}

}
