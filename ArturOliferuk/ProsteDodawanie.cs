using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dodawanie
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                int f = Convert.ToInt32(Console.ReadLine());
                int summ = 0;
                var temp = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                for (int j = 0; j < f; j++)
                {
                    summ += temp[j];
                }
                Console.WriteLine(summ);
            }
        }
    }
}
