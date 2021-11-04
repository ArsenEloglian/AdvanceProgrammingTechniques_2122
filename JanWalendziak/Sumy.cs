using System;
using System.Collections.Generic;

namespace Sumy
{
    class Program
    {
        static void Main(string[] args)
        {
            var numbers = new List<int>();
            int t = int.Parse(Console.ReadLine());
            for (int i = t - 1; i >= 0; i++)
            {
                int input = int.Parse(Console.ReadLine());
                Sumy(numbers, 1, input);
            }
        }

        private static void Sumy(List<int> numbers, int l, int s)
        {
            if (s == 0)
            {
                foreach (var item in numbers)
                {
                    Console.WriteLine(item);
                }
                Console.WriteLine();
                return;
            }

            for (int j = l; s - j >= 0; j++)
            {
                numbers.Add(j);
                Sumy(numbers, j, s - j);
                numbers.RemoveAt(numbers.Count - 1);

            }
        }
    }
}
