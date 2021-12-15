using System;

namespace DwieCyfrySilni_496
{
    class Program
    {
        static int silnia(int n)
        {
            int result = 1;
            for (int i = 1; i <= n; i++)
            {
                result *= i;
            }
            return result;
        }

        static void Main(string[] args)
        {
            int d = Convert.ToInt32(Console.ReadLine());
            int[] tab = new int[d];
            int tmp;

            if (d >= 1 && d <= 30)
            {
                for (int i = 0; i < d; i++)
                {
                    tab[i] = Convert.ToInt32(Console.ReadLine());
                }

                for (int i = 0; i < d; i++)
                {
                    if (tab[i] < 10)
                    {
                        tmp = silnia(tab[i]);
                        //wypisana liczba setek, jednosci
                        Console.WriteLine("{0} {1}", (tmp / 10) % 10, tmp % 10);
                    }
                    //silnia z n>=10 konczy sie zawsze dwoma zerami
                    else
                    {
                        Console.WriteLine("0 0");
                    }
                }
            }
        }
    }
}