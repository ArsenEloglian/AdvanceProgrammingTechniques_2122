using System;

namespace Silnia
{
    class Program
    {
        static void Main(string[] args)
        {
            int A = int.Parse(Console.ReadLine());
            for (int i = 0; i < A; i++)
            {
                int n = int.Parse(Console.ReadLine());
                int wynik = 1;
                for ( int j = 2; j <= n; j++)
                {
                    wynik *= j;
                }

                int jednosc = wynik % 10;
                int dziesiatki = (wynik / 10) % 10;
                Console.WriteLine("{0} {1}", dziesiatki, jednosc);
            }
        }
    }
}
