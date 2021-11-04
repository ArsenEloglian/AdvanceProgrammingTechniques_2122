using System;

namespace Liczby
{
    class Program
    {
        static void Main(string[] args)
        {
            int l = int.Parse(Console.ReadLine());
            string wynik;

            for ( int i = 0; i < l; i++)
            {
               wynik = LiczbaPierwsza(int.Parse(Console.ReadLine())) == true ? "Tak" : "Nie";
                Console.WriteLine(wynik);
            }

            Console.ReadKey();
        }

        private static bool LiczbaPierwsza(int c)
        {
            if (c == 1)
            {
                return false;
            }
            for (int i = 2; i < (c/2)+1; i++)
            {
                if (c % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
