package com.clericyi.player;

import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.lang.annotation.Native;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("audioencoder");
    }

    private Button mp3_encoder_btn;
    private final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mp3_encoder_btn = (Button) findViewById(R.id.mp3_encoder_btn);
        mp3_encoder_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Mp3Encoder encoder = new Mp3Encoder();
                String pcmPath = "/mnt/sdcard/Download/vocal.pcm";
                Log.e(TAG, pcmPath);
                int audioChannels = 2;
                int bitRate = 128 * 1024;
                int sampleRate = 44100;
                String mp3Path = "/mnt/sdcard/Download/vocal.mp3";
                int ret = encoder.init(pcmPath, audioChannels, bitRate, sampleRate, mp3Path);
                Log.e(TAG, "ret is:" + ret);
                if (ret >= 0) {
                    encoder.encode();
                    encoder.destroy();
                    Log.e(TAG, "Encode Mp3 Success");
                } else {
                    Log.e(TAG, "Encoder Initialized Failed...");
                }
            }
        });

        PermissionUtil.checkAndRequestPermission(this,
                Manifest.permission.WRITE_EXTERNAL_STORAGE
                , 1);
        PermissionUtil.checkAndRequestPermission(this,
                Manifest.permission.READ_EXTERNAL_STORAGE
                , 1);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}