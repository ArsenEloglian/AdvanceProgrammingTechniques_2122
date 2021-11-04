using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringMerge
{
    class Program
    {
        static string string_merge(string a, string b)
        {
            int n = a.Length < b.Length ? a.Length : b.Length;
            string result = "";
            for (int i = 0; i < n; i++)
            {
                result += a[i];
                result += b[i];
            }
            return result;
        }

        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string[] temp; string a, b;
                
                temp = Console.ReadLine().Split(' ');
                a = temp[0]; b = temp[1];
                
                Console.WriteLine(string_merge(a,b));
            }
        }
    }
}
