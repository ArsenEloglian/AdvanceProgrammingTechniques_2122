using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flamaster2
{
	class Program
	{
		static void Main(string[] args)
		{
			int C = int.Parse(Console.ReadLine());
			for (int a = 0; a < C; a++)
			{
				string tekst = Console.ReadLine();
				string wynik = "";
				int ile = 1, b = 0;
				while (b < tekst.Length)
				{
					ile = 1;
					char znak = tekst[b];
					b++;
					for (; b < tekst.Length && tekst[b] == znak; b++)
					{
						ile++;
					}
					if (ile == 1)
					{
						wynik += znak.ToString();
					}
					else if (ile == 2)
					{
						wynik += znak.ToString();
						wynik += znak.ToString();
					}
					else
					{
						wynik += znak.ToString() + ile.ToString();
					}
				}
				Console.WriteLine(wynik);
			}
		}
	}
}
