using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SkarbFinder
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            int x = 0, y = 0;
            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(Console.ReadLine());
                for (int j = 0; j < n; j++)
                {
                    int[] temp = Console.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    switch (temp[0])
                    {
                        case 0:
                            y += temp[1];
                            break;
                        case 1:
                            y -= temp[1];
                            break;
                        case 2:
                            x += temp[1];
                            break;
                        case 3:
                            x -= temp[1];
                            break;
                    }
                }
                if (x == 0 && y == 0)
                {
                    Console.WriteLine("studnia");
                }
                else
                {
                    if (y > 0)
                    {
                        Console.WriteLine("0 " + y);
                    }
                    if (y < 0)
                    {
                        Console.WriteLine("1 " + -y);
                    }
                    if (x > 0)
                    {
                        Console.WriteLine("2 " + x);
                    }
                    if (x < 0)
                    {
                        Console.WriteLine("3 " + -x);
                    }
                }
                x = 0; y = 0;
            }
        }
    }
}
