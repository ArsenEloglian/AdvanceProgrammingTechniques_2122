package com.company;
import java.util.*;
import java.lang.*;

public class Main {

    public static void main (String[] args){

        Scanner scan = new Scanner(System.in);
        int i = 0;
        while(i<= 100){
            char operator = scan.next().charAt(0);
            int a = scan.nextInt();
            int b = scan.nextInt();
            switch (operator) {
                case '+':
                    System.out.println(a+b);
                    break;
                case '-':
                    System.out.println(a-b);
                    break;
                case '*':
                    System.out.println(a*b);
                    break;
                case '/':
                    System.out.println(a/b);
                    break;
                case '%':
                    System.out.println(a%b);
                default:
                    i++;
            }
        }
    }
}
