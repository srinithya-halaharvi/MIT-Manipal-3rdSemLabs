package com.example.exam_prep1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    GridView l1;
    ArrayAdapter<String> adapter;
    String items[]={"Reset","Export","Dark mode","Popup","Next page"};
    Button button2, button3;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        l1=findViewById(R.id.ListData);
        adapter= new ArrayAdapter<String>(this,android.R.layout.simple_list_item_single_choice,items);
        l1.setChoiceMode(ListView.CHOICE_MODE_SINGLE);
        l1.setAdapter(adapter);
        registerForContextMenu(l1);
        l1.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String item=(String) adapterView.getItemAtPosition(i);
                Toast.makeText(MainActivity.this,item,Toast.LENGTH_SHORT).show();
                Intent intent = new Intent(getApplicationContext(), SpinExample.class);
                startActivity(intent);
            }
        });
        button2 = (Button) findViewById(R.id.button2);
        button3 = (Button) findViewById(R.id.button3);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openNewActivity();
            }
        });

    }
    public void openNewActivity(){
        Intent intent = new Intent(this, SpinExample.class);
        startActivity(intent);
    }
}