
using System;

namespace LiczbyPierwsze_438
{
    class Program
    {
        static String pierwsza(int n)
        {
            if (n < 2) return "NIE";

            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                {
                    return "NIE";
                }
            }
            return "TAK";
        }
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int[] tab = new int[n];

            for (int i = 0; i < n; i++)
            {
                tab[i] = Convert.ToInt32(Console.ReadLine());
            }

            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("{0}", pierwsza(tab[i]));
            }
        }
    }
}