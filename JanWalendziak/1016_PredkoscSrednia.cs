using System;

namespace _1016_PredkoscSrednia
{
    class Program
    {
        static void Main(string[] args)
        {
            int testy = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < testy; i++)
            {
                string input = Console.ReadLine();
                string[] tablicaDanych = input.Split(" ");

                int v1 = Convert.ToInt32(tablicaDanych[0]);
                int v2 = Convert.ToInt32(tablicaDanych[1]);

                int predkoscSrednia = (2 * v1 * v2) / (v1 + v2);

                Console.WriteLine(predkoscSrednia);

                /*
                if (v1 < v2)
                {
                    int pomocnicza = v1;
                    v1 = v2;
                    v2 = pomocnicza;
                }

                int droga = 2 * v1; //całkowita droga przy założeniu, że trasa trwa 1h
                float czasSredni = 1 + (float)v1 / (float)v2;
                double wynik = Math.Round(droga / czasSredni);
                Console.WriteLine(wynik);
                */

            }
        }
    }
}
