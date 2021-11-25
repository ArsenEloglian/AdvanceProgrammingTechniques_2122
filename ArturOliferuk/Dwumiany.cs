using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Wiatraczki
{
    class Program
    {
        private static long faktorial(long p)
        {
            if (p == 0)
                return 1;
            long result = 1;
            for (int i = 1; i <= p; i++)
            {
                result *= i;
            }
            return result;
        }
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int[] temp = Console.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                Console.WriteLine(faktorial(temp[0]) / (faktorial(temp[1]) * faktorial(temp[0]-temp[1])));
            }
        }   
    }
}
