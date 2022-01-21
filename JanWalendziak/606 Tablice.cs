using System;

namespace _606_Tablice
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                string input = Console.ReadLine();
                input = input.Substring(2);
                string[] tab = input.Split(" ");

                for (int j = tab.Length - 1; j >= 0; j--)
                {
                    Console.Write(tab[j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
