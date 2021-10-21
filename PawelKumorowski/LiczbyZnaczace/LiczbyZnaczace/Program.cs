using System;
using System.Collections.Generic;

namespace LiczbyZnaczace
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Podaj ilość przypadków testowych: ");
            int ilePrzypadkow = int.Parse(Console.ReadLine());
            int[] wyniki = new int[ilePrzypadkow];

            for (int i = 0; i < ilePrzypadkow; i++)
            {
                Console.WriteLine("Podaj zakres: ");
                String zakres = Console.ReadLine();
                int zakresStart = int.Parse(zakres.Split(" ")[0]);
                int zakresKoniec = int.Parse(zakres.Split(" ")[1]);
                wyniki[i] = ileZnaczacych(zakresStart, zakresKoniec);
            }

            for (int i = 0; i < ilePrzypadkow; i++)
            {
                Console.WriteLine(wyniki[i]);
            }
        }

        private static int ileZnaczacych(int start, int koniec)
        {
            int ilosc = 0;

            for(int i = start; i <= koniec; i++)
            {
                if (czyZnaczaca(i))
                    ilosc++;
            }

            return ilosc;
        }

        private static bool czyZnaczaca(int liczba)
        {
            if (sredniaDzielnikow(liczba) != 0 && sredniaDzielnikow(liczba) <= Math.Sqrt(liczba))
                return true;

            return false;
        }

        private static double sredniaDzielnikow(int liczba)
        {
            List<int> dzielniki = generujDzielniki(liczba);
            int sumaDzielnikow = 0;

            foreach(int d in dzielniki)
            {
                sumaDzielnikow += d;
            }

            return dzielniki.Count > 0 ? (double)sumaDzielnikow / dzielniki.Count : 0;
        }

        private static List<int> generujDzielniki(int liczba)
        {
            List<int> dzielniki = new List<int> {};

            for(int i = 2; i <= liczba/2; i++)
            {
                if (liczba % i == 0)
                    dzielniki.Add(i);
            }

            return dzielniki;
        }
    }
}
