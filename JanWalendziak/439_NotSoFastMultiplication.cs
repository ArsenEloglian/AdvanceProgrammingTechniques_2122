using System;
using System.IO;

namespace _439_NotSoFastMultiplication
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("dane.txt");

            int testy = Convert.ToInt32(sr.ReadLine()) + 1;
            for (int i = 1; i < testy; i++)
            {
                string[] line = sr.ReadLine().Split(" ");
                int liczba1 = Convert.ToInt32(line[0]);
                int liczba2 = Convert.ToInt32(line[1]);
                int wynik = liczba1 * liczba2;
                Console.WriteLine(wynik);
                using (StreamWriter sw = File.AppendText("output.txt"))
                {
                    sw.WriteLine(wynik);

                }
            }
        }
    }
}
