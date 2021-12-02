using System;

namespace _1116_PierwiastkiRównaniaKwadratowego
{
    class Program
    {
        static void Main(string[] args)
        {
            int tests = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < tests; i++)
            {
                string input = Console.ReadLine();
                string[] tab = input.Split(" ");

                int a = Convert.ToInt32(tab[0]);
                int b = Convert.ToInt32(tab[1]);
                int c = Convert.ToInt32(tab[2]);
                int k = Convert.ToInt32(tab[3]);

                decimal zaokraglenie = (decimal)Math.Pow(10, -k);

                //obliczanie delty, sprawdzenie ile rozwiązan ma równanie
                float delta = b * b - 4 * a * c;
                // Console.WriteLine($"delta{delta}");
                int liczbaPierwiastkow;
                if (delta > 0)
                {
                    liczbaPierwiastkow = 2;
                    Console.Write($"{liczbaPierwiastkow} ");
                }
                else if (delta == 0)
                {
                    liczbaPierwiastkow = 1;
                    Console.Write($"{liczbaPierwiastkow} ");
                }
                else
                {
                    liczbaPierwiastkow = 0;
                    Console.Write($"{liczbaPierwiastkow} ");
                }

                //obliczenie wartości rzeczywistej dokładnej 
                if (liczbaPierwiastkow == 2)
                {
                    //obliczanie x1 i x2
                    decimal x1 = ((decimal)((-b - Math.Sqrt(delta))) / (2 * a));
                    decimal x2 = ((decimal)((-b + Math.Sqrt(delta))) / (2 * a));

                    decimal x1_ = Math.Round(x1, k);
                    decimal x2_ = Math.Round(x2, k);

                    if (x1 < x1_) // gwarantuje sobie ze x1 zawsze bedzie wieksze
                    {
                        decimal pomocnicza = x1;
                        x1 = x1_;
                        x1_ = pomocnicza;
                    }
                    decimal roznica1 = x1 - x1_;

                    if (x2 < x2_) // gwarantuje sobie ze x1 zawsze bedzie wieksze
                    {
                        decimal pomocnicza = x2;
                        x2 = x2_;
                        x2_ = pomocnicza;
                    }
                    decimal roznica2 = x2 - x2_;

                    if (roznica1 <= zaokraglenie && roznica2 <= zaokraglenie)
                    {
                        Console.Write($"{x1_} {x2_}");
                        Console.WriteLine();
                    }
                }
                else if (liczbaPierwiastkow == 1)
                {
                    decimal x1 = ((decimal)(-b / (2 * a)));
                    decimal x1_ = Math.Round(x1, k);
                    Console.Write(x1_);
                    Console.WriteLine();
                }
                else
                {
                    Console.WriteLine();
                }
            }
        }
    }
}
