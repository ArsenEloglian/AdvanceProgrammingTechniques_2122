using System;
using System.Globalization;

namespace _609_PolePewnegoKoła
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] tab = input.Split(" ");
            double r = double.Parse(tab[0]);
            double d = double.Parse(tab[1]);
            Console.WriteLine(Pole(r, d).ToString().Replace(',', '.'));
        }

        public static double Pole(double r, double d)
        {
            double pi = 3.141592654;
            double promienSzukany = -1 * ((d / 2) * (d / 2) - r * r);
            return Math.Round(promienSzukany * pi, 2);
        }
    }
}
