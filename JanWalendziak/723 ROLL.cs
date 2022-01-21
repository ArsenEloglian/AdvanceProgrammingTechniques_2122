using System;
using System.Collections.Generic;

namespace task_723_ROL
{
    class Program
    {
        static void Main(string[] args)
        {
            int numeberOfTests = int.Parse(Console.ReadLine());
            for (int i = 0; i < numeberOfTests; i++)
            {
                string input = Console.ReadLine();
                string[] tab = input.Split(" ");
                Queue<string> kolejka = new Queue<string>(tab);
                kolejka.Dequeue();
                string  element = kolejka.Dequeue();
                kolejka.Enqueue(element);
                                          
                foreach (string x in kolejka)
                {
                    Console.Write(x + " ");
                }
                Console.WriteLine();

            }
        }
    }
}
