using System;

namespace task_675_SkarbFinder
{
    class Program
    {
        static void Main(string[] args)
        {
            int numeberOfTests = int.Parse(Console.ReadLine());
            for (int i = 0; i < numeberOfTests; i++)
            {
                int[] trasa = new int[2];
                int liczbaZestawow = int.Parse(Console.ReadLine());

                for (int j = 0; j < liczbaZestawow; j++)
                {
                    string input = Console.ReadLine();
                    string[] tab = input.Split(" ");
                    int kierunek = int.Parse(tab[0]);
                    int kroki = int.Parse(tab[1]);
                    switch (kierunek)
                    {
                        case 0:
                            trasa[0] += kroki;
                            break;
                        case 1:
                            trasa[0] -= kroki;
                            break;
                        case 2:
                            trasa[1] += kroki;
                            break;
                        case 3:
                            trasa[1] -= kroki;
                            break;
                    }
                }
                if (trasa[0] != 0 || trasa[1] != 0)
                {
                    if (trasa[0] > 0)
                    {
                        Console.WriteLine("0 " + trasa[0]);
                    }
                    else if (trasa[0] < 0)
                    {
                        Console.WriteLine("1 " + Math.Abs(trasa[0]));
                    }
                     if (trasa[1] > 0)
                    {
                        Console.WriteLine("2 " + trasa[1]);
                    }
                    else if (trasa[1] < 0)
                    {
                        Console.WriteLine("3 " + Math.Abs(trasa[1]));
                    }
                }
                else
                {
                    Console.WriteLine("Studnia");
                }
            }
        }
    }
}
