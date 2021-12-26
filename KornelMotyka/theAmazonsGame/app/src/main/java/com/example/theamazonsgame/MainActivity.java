package com.example.theamazonsgame;

import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import com.example.theamazonsgame.authentication.LoginService;
import com.example.theamazonsgame.authentication.RegistryService;

public class MainActivity extends AppCompatActivity {

    private EditText emailEditText;
    private EditText passwordEditText;
    private ProgressDialog progressDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        emailEditText = findViewById(R.id.mainActivity_EditTextEmail);
        passwordEditText = findViewById(R.id.mainActivity_EditTextPassword);
        progressDialog = new ProgressDialog(MainActivity.this);
    }

    public void login(View view) {
        /*prepareProgressDialog();
        LoginService loginService = new LoginService();
        loginService.loginUser(emailEditText.getText().toString(), passwordEditText.getText().toString(), getApplicationContext(), progressDialog);*/
        prepareProgressDialog();
        LoginService loginService = new LoginService();
        loginService.loginUser("kornel.motyka1@gmail.com", "qwerty", getApplicationContext(), progressDialog);

    }

    public void register(View view) {
        prepareProgressDialog();
        RegistryService registerService = new RegistryService();
        registerService.createNewUser(emailEditText.getText().toString(), passwordEditText.getText().toString(), getApplicationContext(), progressDialog);
    }

    private void prepareProgressDialog(){
        progressDialog.setMessage("Loading...");
        progressDialog.show();
    }
}