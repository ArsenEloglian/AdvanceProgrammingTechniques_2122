using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSK
{
    class Program
    {
        static void Main(string[] args)
        {
            int k = Convert.ToInt16(Console.ReadLine());
            for (int i = 0; i < k; i++)
            {
                int a, b;
                var rul = Console.ReadLine().Split().Select(s => int.Parse(s)).ToList();
                a = rul[0];
                b = rul[1];
                for (int j = 1; j < a * b + 1; j++)
                {
                    if (j % a == 0 && j % b == 0)
                    {
                        Console.WriteLine(j);
                        break;
                    }
                }
            }
            Console.ReadLine();
        }
    }
}
