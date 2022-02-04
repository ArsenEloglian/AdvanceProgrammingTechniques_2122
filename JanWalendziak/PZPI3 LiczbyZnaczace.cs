using System;

namespace PZPI3_LiczbyZnaczacw
{
    class Program
    {
        static void Main(string[] args)
        {

            int tests = int.Parse(Console.ReadLine());
            for (int i = 0; i < tests; i++)
            {
                string input = Console.ReadLine();
                string[] tab = input.Split(" ");

                int num1 = int.Parse(tab[0]);

                int num2 = int.Parse(tab[1]);

                int counter = 0;
                for (int j = num1; j <= num2; j++)
                {
                    decimal srednia = SredniaDzielniki(j);
                    //Console.WriteLine($"Srednia {j} to {srednia}");
                    decimal pierwiastek = (decimal)Math.Sqrt(j);
                    //Console.WriteLine($"Pierwiastek {j} to: {pierwiastek}");

                    if (srednia != 0)
                    {
                        if (srednia < pierwiastek)
                        {
                            counter++;
                        }
                    }
                }
                Console.WriteLine(counter);
            }
        }
        public static decimal SredniaDzielniki(int num)
        {
            int sum = 0;
            int counter = 0;
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    sum = sum + i;
                    counter++;
                }
            }

            if (counter == 0)
            {
                return 0;
            }
            else
            {
                return (decimal)(sum / counter);
            }
        }
    }
}
