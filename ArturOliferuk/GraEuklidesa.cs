using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraEuklidesa
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                var mass = Console.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                int a = mass[0], b = mass[1];
                while (a != b && (a != 0 && b != 0))
                {
                    if (a < b)
                    {
                        b -= a;
                    }
                    else 
                    {
                        a -= b;
                    }
                }
                Console.WriteLine(a + b);
            }
        }
    }
}
