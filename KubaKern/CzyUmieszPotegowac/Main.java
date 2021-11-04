package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class Main {

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        for (int i = scanner.nextInt(); i > 0; i--)
            System.out.println(((int) Math.pow(scanner.nextInt() % 10, 4 + scanner.nextInt() % 4) % 10));
    }


}