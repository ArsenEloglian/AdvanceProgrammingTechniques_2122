import java.util.*;
import java.lang.*;

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc= new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str= sc.nextLine(); 
        System.out.print("\nstring: " + str + "\n");

        
        String[] strTab = str.split(" ");
        for(int i = strTab.length-1; i > -1 ; i--){
            System.out.print(strTab[i]);
            if(i != 0){
                System.out.print(" ");
            }
        }

	}
}