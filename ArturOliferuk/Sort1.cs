using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sort_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(Console.ReadLine());
                List<Point> list  = new List<Point>();
                for (int j = 0; j < n; j++)
                {
                    string[] tab = Console.ReadLine().Split(' ');
                    Point point = new Point(tab[0], int.Parse(tab[1]), int.Parse(tab[2]));
                    list.Add(point);
                }
                list.Sort();
                foreach (Point item in list)
                {
                    Console.WriteLine("{0} {1} {2}", item.Name, item.X, item.Y);
                }
                Console.ReadLine();
            }
            }            
        }
    }
    public class Point: IComparable<Point> 
    {
        public string Name { set; get; }
        public int X { set; get; }
        public int Y { set; get; }
        public double Distance { set; get; }
        public Point(string name, int x, int y)
        {
            Name = name;
            X = x;
            Y = y;
            Distance = Math.Sqrt(x * x + y * y);

        }
        public int CompareTo(Point other)
        {
            return Distance.CompareTo(other.Distance);
        }
    } 
}
