using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ReprezentacjaLiczbTypuFloat
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                printfloat(float.Parse(Console.ReadLine()));
            }
        }
        static void printfloat(float p)
        {
            string result = BitConverter.ToString(BitConverter.GetBytes(p));
            string[] tab = result.Split('-');
            result = "";
            for (int j = tab.Length - 1; j >= 0; j--)
            {
                tab[j] = tab[j].ToLower();
                if (tab[j][0].Equals('0'))
                {
                    result += tab[j][1];
                }
                else
                {
                    result += tab[j];
                }
                if (j > 0)
                {
                    result += " ";
                }
            }
            Console.WriteLine(result);
        }
    }
}
