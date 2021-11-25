using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt16(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                int l = 0;
                string word  = Console.ReadLine();
                string temp = "";
                for (int j = 0; j < word.Length; j++)
                {
                    for (l=j; l < word.Length; l++)
                    {
                        if (word[j] == word[l])
                            count++;
                        else
                            break;
                    }
                    if (count >= 3)
                    {
                        temp += word[j] + count.ToString();
                    }
                    else
                    {
                        while (count != 0)
                        {
                            temp += word[j];
                            count--;
                        }
                    }
                    j=l-1;
                    count = 0;
                }
                Console.WriteLine(temp);
                Console.Read();
            }
        }
    }
}
