using System;
using System.Collections.Generic;

namespace task_663_Sort_1
{
    class Program
    {
        static void Main()
        {
            int tests = int.Parse(Console.ReadLine());
            if (tests >= 1 && tests <= 1000)
            {
                for (int i = 0; i < tests; i++)
                {
                    int n = int.Parse(Console.ReadLine());
                    List<Punkt> list = new List<Punkt>();
                    for (int j = 0; j < n; j++)
                    {
                        string input = Console.ReadLine();

                        string[] tab = input.Split(' ');

                        Punkt punkt = new Punkt((tab[0]), int.Parse(tab[1]), int.Parse(tab[2]));
                        list.Add(punkt);
                    }
                    list.Sort();
                    foreach (Punkt item in list)
                    {
                        Console.WriteLine($"{item.GetNazwa()} {item.X} {item.Y}");
                    }
                    Console.WriteLine();
                }
            }
        }
    }

    public class Punkt : IComparable<Punkt>
    {
        private string Nazwa;
        public int X { get; }
        public int Y { get; }
        public double C { get; set; }

        public Punkt(string nazwa, int x, int y)
        {
            Nazwa = nazwa;
            X = x;
            Y = y;
            C = Math.Sqrt(x * x + y * y);
        }

        public string GetNazwa()
        {
            return Nazwa;
        }

        public int CompareTo(Punkt other)
        {
            return C.CompareTo(other.C);
        }
    }
}
