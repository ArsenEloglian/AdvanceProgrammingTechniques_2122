using System;
using System.Collections.Generic;

namespace _1077_BajtlandzkaWojenka
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] tablicaWejciowa = PobranieDanych();
            List<int> posortowane = SortowanieDanych(tablicaWejciowa);
            List<int> tablicaPorownawcza = TablicaPorownawcza(posortowane);
            ObliczanieZwyciestwa(posortowane, tablicaPorownawcza);
        }

        public static string[] PobranieDanych()
        {
            string input = Console.ReadLine();
            string[] tab = input.Split(" ");

            return tab;
        }

        public static List<int> SortowanieDanych(string[] tab)
        {
            List<int> liczby = new List<int>();
            for (int i = 0; i < tab.Length; i++)
            {
                int liczba = Convert.ToInt32(tab[i]);
                liczby.Add(liczba);
            }
            liczby.Sort();

            return liczby;
        }

        public static List<int> TablicaPorownawcza(List<int> posortowane)
        {
            List<int> drugiZbior = new List<int>();
            for (int i = 1; i <= 52; i++)
            {
                if (!posortowane.Contains(i))
                {
                    drugiZbior.Add(i);
                }
            }
            drugiZbior.Sort();

            return drugiZbior;
        }

        public static void ObliczanieZwyciestwa(List<int> list1, List<int> list2)
        {
            int counter = 0;

            for (int i = list1.Count - 1; i > 0; i--)
            {
                for (int j = list2.Count - 1; j > 0; j--)
                {
                    if (list1[i] > list2[j])
                    {
                        counter++;
                        break;
                    }
                }
            }
            Console.WriteLine(counter);
        }
    }
}
