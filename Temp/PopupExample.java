package com.example.exam_prep1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.PopupMenu;

public class PopupExample extends AppCompatActivity implements PopupMenu.OnMenuItemClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_popup_example);
    }
    public void showPopup(View v) {
        PopupMenu popup = new PopupMenu(this, v);
        MenuInflater inflater = popup.getMenuInflater();
        popup.setOnMenuItemClickListener(this);
        inflater.inflate(R.menu.actions, popup.getMenu());
        popup.show();

    }

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        int id=item.getItemId();
        if(id==R.id.home){
            Intent intent = new Intent(getApplicationContext(), MainActivity.class);
            startActivity(intent);
            return true;
        }
        else if(id==R.id.spin){
            Intent intent = new Intent(getApplicationContext(), SpinExample.class);
            startActivity(intent);
            return true;
        }
        else if(id==R.id.dt){
            Intent intent = new Intent(getApplicationContext(), PickerDTExample.class);
            startActivity(intent);
            return true;
        }
        return false;
    }
}