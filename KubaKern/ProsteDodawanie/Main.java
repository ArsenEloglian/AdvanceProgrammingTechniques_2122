package com.company;

import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int tests = 0;
            tests = scan.nextInt();

        for (int i = 0; i < tests; i++) {
            int n = scan.nextInt();
            int[] tab = new int[n];
            for (int j = 0; j < n; j++) {
                int num = scan.nextInt();
                tab[j] = num;
            }
            System.out.println(IntStream.of(tab).sum());
        }
        scan.close();
    }

}