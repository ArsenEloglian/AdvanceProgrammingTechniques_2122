package com.example.theamazonsgame.authentication;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import com.example.theamazonsgame.MainActivity;
import com.example.theamazonsgame.MenuActivity;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

import lombok.AllArgsConstructor;
import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
@AllArgsConstructor
public class LoginService {

    private FirebaseAuth mAuth;

    public void loginUser(String email, String password, Context context, ProgressDialog progressDialog) {

        mAuth = FirebaseAuth.getInstance();

        mAuth.signInWithEmailAndPassword(email, password)
                .addOnCompleteListener(task -> {
                    if (task.isSuccessful()) {
                        Log.d("LOGIN", "Account : " + email + " succesfully logged");
                        Toast.makeText(context, "Succesfully logged", Toast.LENGTH_LONG).show();
                        context.startActivity(getIntent(context));
                    } else {
                        Log.w("LOGIN", "Account : " + email + " login failed, cause : " + task.getException());
                        Toast.makeText(context, task.getException().getMessage(), Toast.LENGTH_LONG).show();
                    }
                    progressDialog.dismiss();
                });
    }

    private Intent getIntent(Context context){
        Intent intent = new Intent(context, MenuActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        return intent;
    }
}
