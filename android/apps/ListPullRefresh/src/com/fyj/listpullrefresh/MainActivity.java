package com.fyj.listpullrefresh;

import android.app.Activity;
import android.app.ListActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends Activity {
	
	private ListView listView = null;
	
	private String[] strings = {
			"List Item 1",
			"List Item 2",
			"List Item 3",
			"List Item 4",
			"List Item 5",
			"List Item6",
	};

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		listView = (ListView)findViewById(R.id.listview);
		ArrayAdapter arrayAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, strings);
		listView.setAdapter(arrayAdapter);
	
	}
}
