using System;
using System.Collections.Generic;

namespace _1085_JesiennePorzadki
{
    class Program
    {
        static void Main(string[] args)
        {
            WczytanieDanych();
        }

        static void WczytanieDanych()
        {
            int liczbaPunktow = Convert.ToInt32(Console.ReadLine());

            List<int> wspolrzedneX = new List<int>();
            List<int> wspolrzedneY = new List<int>();


            for (int i = 0; i < liczbaPunktow; i++)
            {
                string[] wspolrzedne = Console.ReadLine().Split(" ");
                int x = Convert.ToInt32(wspolrzedne[0]);
                int y = Convert.ToInt32(wspolrzedne[1]);

                wspolrzedneX.Add(x);
                wspolrzedneY.Add(y);
            }

            // ilosc krokow wzdluz y do głównej alei
            int y_temp;
            int sumaY = 0;
            foreach (var y in wspolrzedneY)
            {
                if (y < 0)
                {
                    y_temp = Math.Abs(y);
                    sumaY += y_temp;
                }
                else
                {
                    sumaY += y;
                }
            }
            Console.WriteLine(sumaY); // liczba krokoW po y

            wspolrzedneX.Sort();
            foreach (var item in wspolrzedneX)
            {
                //Console.WriteLine(item);
            }

            int najmniejszaX = wspolrzedneX[0];
            int największaX = wspolrzedneX[wspolrzedneX.Count - 1];
            //Console.WriteLine(największaX);

            //Console.WriteLine(najmniejszaX);
            double polowa;
            double zaokraglonaPolowa;

            int sumaX = 0;
            int temp_X;

            if (najmniejszaX < 0 && największaX < 0)
            {
                polowa = (najmniejszaX - największaX) / 2;
                zaokraglonaPolowa = Math.Floor(polowa);

                if (wspolrzedneX.Contains((int)zaokraglonaPolowa))
                {
                    foreach (var x in wspolrzedneX)
                    {
                        temp_X = Math.Abs(x - (int)zaokraglonaPolowa);
                        sumaX += temp_X;
                    }

                    int sumaWszystkichkrokow = sumaY + sumaX;
                    Console.WriteLine($"{zaokraglonaPolowa} {sumaWszystkichkrokow}");
                }
                else
                {
                    int najblizszyX = minDiff(wspolrzedneX, zaokraglonaPolowa);

                    foreach (var x in wspolrzedneX)
                    {
                        temp_X = Math.Abs(x - najblizszyX);
                        sumaX += temp_X;
                    }

                    int sumaWszystkichkrokow = sumaY + sumaX;
                    Console.WriteLine($"{najblizszyX} {sumaWszystkichkrokow}");
                }

            }

            else if (najmniejszaX < 0 && największaX > 0)
            {
                polowa = (najmniejszaX + największaX) / 2;
                zaokraglonaPolowa = Math.Floor(polowa);

                if (wspolrzedneX.Contains((int)zaokraglonaPolowa))
                {
                    foreach (var x in wspolrzedneX)
                    {
                        temp_X = Math.Abs(x - (int)zaokraglonaPolowa);
                        sumaX += temp_X;
                    }

                    int sumaWszystkichkrokow = sumaY + sumaX;
                    Console.WriteLine($"{zaokraglonaPolowa} {sumaWszystkichkrokow}");
                }
                else
                {
                    int najblizszyX = minDiff(wspolrzedneX, zaokraglonaPolowa);

                    foreach (var x in wspolrzedneX)
                    {
                        temp_X = Math.Abs(x - najblizszyX);
                        sumaX += temp_X;
                    }

                    int sumaWszystkichkrokow = sumaY + sumaX;
                    Console.WriteLine($"{najblizszyX} {sumaWszystkichkrokow}");
                }
            }

            else if (najmniejszaX >= 0 && największaX >= 0)
            {
                polowa = (największaX - najmniejszaX) / 2;
                zaokraglonaPolowa = Math.Floor(polowa);

                if (wspolrzedneX.Contains((int)zaokraglonaPolowa))
                {
                    foreach (var x in wspolrzedneX)
                    {
                        temp_X = Math.Abs(x - (int)zaokraglonaPolowa);
                        sumaX += temp_X;
                    }

                    int sumaWszystkichkrokow = sumaY + sumaX;
                    Console.WriteLine($"{zaokraglonaPolowa} {sumaWszystkichkrokow}");
                }
                else
                {
                    int najblizszyX = minDiff(wspolrzedneX, zaokraglonaPolowa);

                    foreach (var x in wspolrzedneX)
                    {
                        temp_X = Math.Abs(x - najblizszyX);
                        sumaX += temp_X;
                    }

                    int sumaWszystkichkrokow = sumaY + sumaX;
                    Console.WriteLine($"{najblizszyX} {sumaWszystkichkrokow}");
                }
            }

            //Console.WriteLine($"polowa{polowa}");            
            //Console.WriteLine(zaokraglonaPolowa);

            //Console.WriteLine(sumaX);


        }

        public static int minDiff(List<int> wspolrzedneX, double zaokraglonaPolowa)
        {
            int diff = int.MaxValue;
            int index = 0;
            for (int i = index; i < wspolrzedneX.Count; i++)
            {
                if (Math.Abs(i - (int)zaokraglonaPolowa) < diff)
                {
                    diff = Math.Abs(i - (int)zaokraglonaPolowa);
                }
            }
            return index;
        }

    }
}
