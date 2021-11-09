using System;

namespace _751_CiekawaWyliczanka
{
    class Program
    {
        static void Main(string[] args)
        {
            int k = Convert.ToInt32(Console.ReadLine());

            int s = 0;
            int n = 0;
            int w = 1;
            int wynik;

            while (s < k)
            {
                s = (int)(s + Math.Pow(2, w));
                n++;
                w++;
            }

            int temp = (int)(Math.Pow(2, n)) - (s - k);

            for (int i = n; i > 0; i--)
            {
                wynik = (int)Math.Ceiling(temp / (Math.Pow(2, i - 1)));

                if (wynik % 2 == 0)
                {
                    Console.Write("6");
                }
                else
                {
                    Console.Write("5");
                }
            }

        }


    }
}
