using System;

namespace _968_Suma
{
    class Program
    {
        static void Main(string[] args)
        {
            int suma = 0;
            string liczba;

            while ((liczba = Console.ReadLine()) != null)
            {
                Console.WriteLine(suma += Convert.ToInt32(liczba));
            }
        }
    }
}
