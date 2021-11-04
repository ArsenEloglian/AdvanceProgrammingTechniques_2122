import java.util.*;
import java.lang.*;
import java.util.Scanner;
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] tab = new int[n];
		for (int i=0;i<n;i++) tab[i] = scanner.nextInt();
		scanner.close();
		String s;
		for (int i=0;i<n;i++) {
			s = "TAK";
			if (tab[i] == 1) {
				s = "NIE";
				System.out.println(s);
				continue;
			}
			for (int j=2;j<=tab[i]/2;j++) {

				if (tab[i]%j == 0) s = "NIE";
			}
			System.out.println(s);
		}
	}
}