package com.example.exam_prep1;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MenuExample extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu_example);
        Button button = findViewById(R.id.buttonBack);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.actions, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        int id=item.getItemId();
        if(id==R.id.home){
            TextView textView = findViewById(R.id.textView);
            textView.setText("Home");
            return true;
        }
        else if(id==R.id.spin){
            TextView textView = findViewById(R.id.textView);
            textView.setText("Spin");
            return true;
        }
        else if(id==R.id.dt){
            TextView textView = findViewById(R.id.textView);
            textView.setText("DateTime");
            return true;
        }
        return false;
    }

}