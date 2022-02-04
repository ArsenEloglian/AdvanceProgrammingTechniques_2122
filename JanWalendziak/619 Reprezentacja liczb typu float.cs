using System;
using System.Globalization;

namespace task_619_ReprezentacjaLiczbTypuFloat
{
    class Program
    {
        static void Main()
        {

            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                string output = Convert(float.Parse(Console.ReadLine(), CultureInfo.InvariantCulture));
                string[] tab = output.Split('-');
                output = "";
                for (int j = tab.Length - 1; j >= 0; j--)
                {
                    if (tab[j][0] == '0')
                    {
                        output += tab[j][1];
                    }
                    else
                    {
                        output += tab[j];
                    }
                    if (j > 0)
                    {
                        output += " ";
                    }
                }
                Console.WriteLine(output.ToLower());

            }
        }
        private static string Convert(float x)
        {
            return BitConverter.ToString(BitConverter.GetBytes(x));
        }
    }
}

