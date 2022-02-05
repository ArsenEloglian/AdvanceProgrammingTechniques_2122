using System;

namespace _601_NWD
{
    class Program
    {
        static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            for (int i = 0; i < tests; i++)
            {
                string input = Console.ReadLine();
                string[] tab = input.Split(" ");
                int a = int.Parse(tab[0]);
                int b = int.Parse(tab[1]);

                Console.WriteLine(Nwd(a, b));
            }
        }

        public static int Nwd(int a, int b)
        {
            while (b != 0)
            {
                int c = a % b;
                a = b;
                b = c;
            }
            return a;
        }
    }
}
