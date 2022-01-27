package com.example.theamazonsgame.authentication;

import android.app.ProgressDialog;
import android.content.Context;
import android.util.Log;
import android.widget.Toast;

import com.google.firebase.auth.FirebaseAuth;

import lombok.AllArgsConstructor;
import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
@AllArgsConstructor
public class RegistryService {

    private FirebaseAuth mAuth;

    public void createNewUser(String email, String password, Context context, ProgressDialog progressDialog){

        mAuth = FirebaseAuth.getInstance();

         mAuth.createUserWithEmailAndPassword(email, password)
                .addOnCompleteListener(task -> {
                    if(task.isSuccessful()){
                        Log.d("REGISTER","Account : " + email + " succesfully registered");
                        Toast.makeText(context,"Succesfully registered",Toast.LENGTH_LONG).show();
                    }else{
                        Log.w("REGISTER", "Account : " + email + " register failed, cause : " + task.getException());
                        Toast.makeText(context,task.getException().getMessage(),Toast.LENGTH_LONG).show();
                    }
                    progressDialog.dismiss();
                });
    }
}
