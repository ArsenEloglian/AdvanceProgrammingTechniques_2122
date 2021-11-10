using System;

namespace _997_Kalkulator
{
    class Program
    {
        static void Main(string[] args)
        {
            int wynik;
            string input;
            while ((input = Console.ReadLine()) != null)
            {
                string[] tablicaDanych = input.Split(" ");
                if (input == null || tablicaDanych.Length < 1)
                    break;

                string znak = tablicaDanych[0];
                int liczba1 = Convert.ToInt32(tablicaDanych[1]);
                int liczba2 = Convert.ToInt32(tablicaDanych[2]);

                switch (znak)
                {
                    case "+":
                        wynik = liczba1 + liczba2;
                        Console.WriteLine(wynik);
                        break;
                    case "-":
                        wynik = liczba1 - liczba2;
                        Console.WriteLine(wynik);
                        break;
                    case "*":
                        wynik = liczba1 * liczba2;
                        Console.WriteLine(wynik);
                        break;
                    case "/":
                        wynik = liczba1 / liczba2;
                        Console.WriteLine(wynik);
                        break;
                    case "%":
                        wynik = liczba1 % liczba2;
                        Console.WriteLine(wynik);
                        break;
                    default:
                        Console.WriteLine($"Podano złe dane");
                        break;
                }
            }
        }
    }
}
