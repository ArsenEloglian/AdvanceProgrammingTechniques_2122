using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tablice
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                var temp = Console.ReadLine().Split().Select(s => int.Parse(s)).ToList();
                for (int j = temp[0]; j >= 1; j--)
                {
                    Console.Write(temp[j]+" ");
                }
            }
        }
    }
}
