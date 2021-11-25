using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemCollatza
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int temp = int.Parse(Console.ReadLine());
                int count = 0, x=temp;
                while (x != 1)
                {
                    if (x % 2 !=0)
                    {
                        x = 3 * x + 1;
                        count++;
                    }
                    else
                    {
                        x = x / 2;
                        count++;
                    }
                }
                Console.WriteLine(count);
            }
        }
    }
}
