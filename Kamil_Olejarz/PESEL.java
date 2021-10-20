import java.util.InputMismatchException;
import java.util.Scanner;

public class PESEL {

    public static void main(String[] args){

            String pesel = null;
            String[] tab = new String[0];
            int iloscTestow = 0;
            int res = 0;

            Scanner scanner = new Scanner(System.in);
            Scanner scannerInt = new Scanner(System.in);

            try{
                iloscTestow = scannerInt.nextInt();
            }catch(InputMismatchException e){
                System.out.printf("Blad");
            }


            if (iloscTestow <= 100) {
                tab = new String[iloscTestow];
                for (int i = 0; i < iloscTestow; i++) {

                    try {
                        pesel = scanner.nextLine();
                        tab[i] = pesel;
                    }catch (Exception e){
                        System.out.printf("Blad");
                    }
                }
            }

            for (int j = 0; j < iloscTestow; j++) {


                if (tab[j].length() == 11) {

                    res = Integer.parseInt(String.valueOf(tab[j].charAt(0))) * 1 + Integer.parseInt(String.valueOf(tab[j].charAt(1))) * 3 +
                            Integer.parseInt(String.valueOf(tab[j].charAt(2))) * 7 + Integer.parseInt(String.valueOf(tab[j].charAt(3))) * 9 +
                            Integer.parseInt(String.valueOf(tab[j].charAt(4))) * 1 + Integer.parseInt(String.valueOf(tab[j].charAt(5))) * 3 +
                            Integer.parseInt(String.valueOf(tab[j].charAt(6))) * 7 + Integer.parseInt(String.valueOf(tab[j].charAt(7))) * 9 +
                            Integer.parseInt(String.valueOf(tab[j].charAt(8))) * 1 + Integer.parseInt(String.valueOf(tab[j].charAt(9))) * 3 +
                            Integer.parseInt(String.valueOf(tab[j].charAt(10))) * 1;


                    if (Integer.toString(res).charAt(2) == '0') {
                        System.out.printf("D \n");
                    } else {
                        System.out.printf("N \n");
                    }

                }

            }

            scanner.close();
            scannerInt.close();
    }
}
