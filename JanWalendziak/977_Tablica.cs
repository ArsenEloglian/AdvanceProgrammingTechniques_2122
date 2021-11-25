using System;

namespace _977_Tablica
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] dane = input.Split(" ");

            for (int i = dane.Length - 1; i >= 0; i--)
            {
                Console.Write($"{dane[i]} ");
            }
        }
    }
}
