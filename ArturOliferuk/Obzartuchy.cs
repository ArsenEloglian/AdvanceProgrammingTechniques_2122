using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Obzartuchy
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string[] tab = Console.ReadLine().Split();
                int count = int.Parse(tab[0]);
                double box = int.Parse(tab[1]);
                int result = 0;
                for (int j = 0; j < count; j++)
                {
                    result += (86400 / int.Parse(Console.ReadLine())); 
                }
                Console.WriteLine(Math.Ceiling(result/box));
            }
        }
    }
}
