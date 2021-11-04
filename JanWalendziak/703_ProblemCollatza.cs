using System;

namespace taks_703_ProblemCollatza
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int s = int.Parse(Console.ReadLine());

                Console.WriteLine(Wynik(s, 0)); 
            }
        }

        private static int Wynik(int s, int n)
        {
            int n_wyraz;
            if (s == 1)
            {
                return n;
            }
            else
            {
                if ( s % 2 == 1)
                {
                    return Wynik(3 * s + 1, ++n);
                }
                else
                {
                     return Wynik(s / 2, ++n);
                }
            }
        }
    }
}
