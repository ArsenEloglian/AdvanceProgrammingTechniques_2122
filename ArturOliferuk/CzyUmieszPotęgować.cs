using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Potęg
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt16(Console.ReadLine());
            for (int j = 0; j < n; j++)
            {
                var integers = Console.ReadLine().Split().Select(s=> int.Parse(s)).ToList();
                long a = integers[0];
                long b = integers[1];
                long temp = a;
                for (int i = 1; i < b; i++)
                {
                    a *= temp;
                }
                Console.WriteLine(a % 10);
            }
            
            Console.Read();
        }
    }
}
