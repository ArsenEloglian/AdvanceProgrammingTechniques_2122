package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] tab = new int[n];
        for (int i=0;i<n;i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            tab[i] = nwd(a,b);
        }
        for (int i=0;i<n;i++) {
            System.out.println(tab[i]);
        }

    }
    static int nwd(int a, int b) {
        while (a != b)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
        return a;
    }


}
