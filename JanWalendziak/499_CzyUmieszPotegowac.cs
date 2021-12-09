using System;

namespace CzyUmieszPotegowac_499
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfOperations = Convert.ToInt32(Console.ReadLine());

            if (numberOfOperations >= 1 && numberOfOperations <= 10)
            {
                for (int i = 0; i < numberOfOperations; i++)
                {
                    string input = Console.ReadLine();
                    string[] separatedInput = input.Split(" ");
                    int @base = Convert.ToInt32(separatedInput[0]);
                    @base = @base % 10;
                    int exponent = Convert.ToInt32(separatedInput[1]);

                    if (@base <= 1000000000 && @base >= 1 && exponent <= 1000000000 && exponent >= 1)
                    {
                        if (exponent % 4 == 0)
                        {
                            exponent = 4;
                        }
                        else
                        {
                            exponent = exponent % 4;
                        }
                        int result = @base;
                        for (int j = 1; j < exponent; j++)
                        {
                            result *= @base;
                        }
                        Console.WriteLine(result % 10);
                    }
                }

            }

        }


    }
}