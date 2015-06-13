package com.fyj.androidui;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.widget.Toast;

public class MainActivity extends ActionBarActivity {


	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        Topbar topbar = (Topbar)findViewById(R.id.topbar);
        topbar.setOnClickListener(new Topbar.OnClickListener() {
			
			@Override
			public void rightClick() {
				// TODO Auto-generated method stub
				Toast.makeText(MainActivity.this, "RIGHT", Toast.LENGTH_SHORT).show();;
			}			

			@Override
			public void leftClick() {
				// TODO Auto-generated method stub
				Toast.makeText(MainActivity.this, "LEFT", Toast.LENGTH_SHORT).show();;
			}
		});
		
		
    }
}
