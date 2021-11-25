package com.company;
import java.util.Scanner;

public class Main {

    static int reverse(int num) {
        int reversed = 0;
        while (num != 0) {
            reversed = reversed * 10;
            reversed = reversed + num % 10;
            num = num / 10;
        }
        return reversed;
    }
    static void palindrome(int number) {
        int count = 0;
        int unreversed = number;
        while (unreversed != reverse(unreversed)) {
            unreversed += reverse(unreversed);
            count++;
        }
        System.out.println(unreversed + " " + count);
    }

    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        for (int i = 0; i < n; i++) {
            palindrome(scan.nextInt());
        }
        scan.close();
    }
}
