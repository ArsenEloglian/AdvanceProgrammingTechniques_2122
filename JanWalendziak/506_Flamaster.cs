using System;
using System.Collections.Generic;
namespace Flamaster_506
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfOperations = Convert.ToInt32(Console.ReadLine());

            if (numberOfOperations >= 1 && numberOfOperations <= 50)
            {
                for (int i = 0; i < numberOfOperations; i++)
                {
                    IDictionary<char, int> numChar = new Dictionary<char, int>();
                    string input = Console.ReadLine();

                    foreach (char c in input)
                    {
                        if (numChar.ContainsKey(c))
                        {
                            int counter = numChar[c];
                            numChar[c] = ++counter;
                        }
                        else
                        {
                            numChar.Add(c, 1);
                        }
                    }

                    string output = "";
                    foreach (KeyValuePair<char, int> kvp in numChar)
                    {
                        if (kvp.Value == 1)
                        {
                            output += $"{kvp.Key}";
                        }
                        else if (kvp.Value == 2)
                        {
                            output += $"{kvp.Key}{kvp.Key}";
                        }
                        else
                        {
                            output += $"{kvp.Key}{kvp.Value}";
                        }
                    }

                    Console.WriteLine(output);
                }
            }
        }
    }
}