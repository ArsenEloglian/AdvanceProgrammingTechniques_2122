using System;

namespace _617_StringMerge
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string input = Console.ReadLine();
                string[] tab = input.Split(" ");
                Console.WriteLine(Laczenie(tab[0], tab[1]));
            }
        }

        private static string Laczenie(string a, string b)
        {
            int dlugosc = a.Length < b.Length ? a.Length : b.Length;
            string result = "";

            for (int i = 0; i < dlugosc; i++)
            {
                result += a[i];
                result += b[i];
            }
            return result;
        }
    }
}
