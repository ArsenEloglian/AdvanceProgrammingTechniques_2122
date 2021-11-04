package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws java.lang.Exception {

        Scanner scan = new Scanner(System.in);
        int tests = scan.nextInt();

        for (int i = 0; i < tests; i++) {

            int length = scan.nextInt();
            int[] tab = new int[length];

            for (int j = length; j > 0; j--) {
                tab[j - 1] = scan.nextInt();
            }

            System.out.println(Arrays.toString(tab).replaceAll("[,\\[\\]]", ""));

        }
    }
}

