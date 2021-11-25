using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ROL
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                var input = Console.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                int[] result = new int[input[0]];
                result[input[0] - 1] = input[1];
                for (int j = 2; j <= input[0]; j++)
                {
                    result[j - 2] = input[j];
                }
                for (int j = 0; j < result.Length; j++)
                {
                    Console.Write(result[j]);
                    if (j < result.Length - 1)
                        Console.Write(" ");
                }
                Console.WriteLine();
            }
        }
    }
}
