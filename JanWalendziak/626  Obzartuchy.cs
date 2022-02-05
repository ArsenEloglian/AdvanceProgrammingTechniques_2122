using System;

namespace task_626_Obzartuchy
{
    class Program
    {
        static void Main()
        {
            int test = int.Parse(Console.ReadLine());
            for (int i = 0; i < test; i++)
            {
                string input = Console.ReadLine();
                string[] tab = input.Split(' ');
                int osoby = int.Parse(tab[0]);
                double ciastkaPudelko = double.Parse(tab[1]);
                double day = 24 * 60 * 60;
                double ciastkaZjedzone = 0;
                for (int j = 0; j < osoby; j++)
                    {
                        double czasJedzenia = double.Parse(Console.ReadLine());
                        double ileZje = Math.Floor (day / czasJedzenia);
                        ciastkaZjedzone += ileZje;

                    }

                double ileKupic = Math.Ceiling (ciastkaZjedzone / ciastkaPudelko);
                Console.WriteLine(ileKupic);
                
            }
        }
    }
}
