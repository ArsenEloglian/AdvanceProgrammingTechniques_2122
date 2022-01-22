using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Amazons
{
    public partial class Form1 : Form
    {
        Check check = new Check();
        public Form1()
        {
            InitializeComponent();
            
            button2.BackgroundImage = Amazons.Properties.Resources._4;
            button5.BackgroundImage = Amazons.Properties.Resources._4;
            button7.BackgroundImage = Amazons.Properties.Resources._4;
            button12.BackgroundImage = Amazons.Properties.Resources._4;
            button25.BackgroundImage = Amazons.Properties.Resources._5;
            button30.BackgroundImage = Amazons.Properties.Resources._5;
            button32.BackgroundImage = Amazons.Properties.Resources._5;
            button35.BackgroundImage = Amazons.Properties.Resources._5;

        }
        public Button Off(int position,int mode)
        {
            switch (position)
            {
                case 1:
                    if(mode ==0)
                    button1.BackgroundImage = null;
                    return button1;
                case 2:
                    if (mode == 0)
                    button2.BackgroundImage = null;
                    return button2;
                case 3:
                    if (mode == 0)
                    button3.BackgroundImage = null;
                    return button3;
                case 4:
                    if (mode == 0)
                    button4.BackgroundImage = null;
                    return button4;
                case 5:
                    if (mode == 0)
                    button5.BackgroundImage = null;
                    return button5;
                case 6: 
                    if (mode == 0)
                    button6.BackgroundImage = null;
                    return button6;
                case 7:
                    if (mode == 0)
                    button7.BackgroundImage = null;
                    return button7;
                case 8:
                    if (mode == 0)
                    button8.BackgroundImage = null;
                    return button8;
                case 9:
                    button9.BackgroundImage = null;
                    return button9;
                case 10:
                    if (mode == 0)
                    button10.BackgroundImage = null;
                    return button10;
                case 11:
                    if (mode == 0)
                    button11.BackgroundImage = null;
                    return button11;
                case 12:
                    if (mode == 0)
                    button12.BackgroundImage = null;
                    return button12;
                case 13:
                    if (mode == 0)
                    button13.BackgroundImage = null;
                    return button13;
                case 14:
                    if (mode == 0)
                    button14.BackgroundImage = null;
                    return button14;
                case 15:
                    if (mode == 0)
                    button15.BackgroundImage = null;
                    return button15;
                case 16:
                    if (mode == 0)
                    button16.BackgroundImage = null;
                    return button16;
                case 17:
                    if (mode == 0)
                    button17.BackgroundImage = null;
                    return button17;
                case 18:
                    if (mode == 0)
                    button18.BackgroundImage = null;
                    return button18;
                case 19:
                    if (mode == 0)
                    button19.BackgroundImage = null;
                    return button19;
                case 20:
                    if (mode == 0)
                    button20.BackgroundImage = null;
                    return button20;
                case 21:
                    if (mode == 0)
                    button21.BackgroundImage = null;
                    return button21;
                case 22:
                    if (mode == 0)
                    button22.BackgroundImage = null;
                    return button22;
                case 23:
                    if (mode == 0)
                    button23.BackgroundImage = null;
                    return button23;
                case 24:
                    if (mode == 0)
                    button24.BackgroundImage = null;
                    return button24;
                case 25:
                    if (mode == 0)
                    button25.BackgroundImage = null;
                    return button25;
                case 26:
                    if (mode == 0)
                    button26.BackgroundImage = null;
                    return button26;
                case 27:
                    if (mode == 0)
                    button27.BackgroundImage = null;
                    return button27;
                case 28:
                    if (mode == 0)
                    button28.BackgroundImage = null;
                    return button28;
                case 29:
                    if (mode == 0)
                    button29.BackgroundImage = null;
                    return button29;
                case 30:
                    if (mode == 0)
                    button30.BackgroundImage = null;
                    return button30;
                case 31:
                    if (mode == 0)
                    button31.BackgroundImage = null;
                    return button31;
                case 32:
                    if (mode == 0)
                    button32.BackgroundImage = null;
                    return button32;
                case 33:
                    if (mode == 0)
                    button33.BackgroundImage = null;
                    return button33;
                case 34:
                    if (mode == 0)
                    button34.BackgroundImage = null;
                    return button34;
                case 35:
                    if (mode == 0)
                    button35.BackgroundImage = null;
                    return button35;
                case 36:
                    if (mode == 0)
                    button36.BackgroundImage = null;
                    return button36;
                default:
                    return button1;
            }
        }
        public bool Qeens(int position)
        {
            bool result = true;
            for (int i = 0; i < check.Qeens.Length; i++)
            {
             if(position==check.Qeens[i])
                {
                    result = false;
                    break;
                }
            }
            return result;
        }
        public bool Baned(int position)
        {
            bool result = true;
            for (int i = 0; i < check.Baned.Length; i++)
            {
                if (position == check.Baned[i])
                {
                    result = false;
                    break;
                }
            }
            return result;
        }
        public bool Posible(int position)
        {
            bool result = false;
            for (int i = check.position; i <= (check.position / 6 + 1) * 6 + 1; ++i)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (!Baned(i))
                    break;
                if (i == position && i != check.position)
                {
                    result = true;
                    break;
                }
                if (i % 6 == 0)
                    break;
            }
            for (int i = check.position; i > (check.position % 6 == 0 ? (check.position / 6 - 1) * 6 : (check.position / 6) * 6) && i > 0; i--)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (!Baned(i))
                    break;
                if (i == position && i != check.position)
                {
                    result = true;
                    break;
                }
            }
            for (int i = check.position; i <= 36; i+=5)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                    if (!Baned(i))
                        break;
                if (i == position && i != check.position)
                {
                    result = true;
                    break;
                }
                if (i % 6 == 1)
                    break;
            }
            for (int i = check.position; i <= 36; i += 6)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                    if (!Baned(i))
                        break;
                if (i == position && i != check.position)
                {
                    result = true;
                    break;
                }
            }
            for (int i = check.position; i > 0; i -= 6)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                    if (!Baned(i))
                        break;
                if (i == position && i != check.position)
                {
                    result = true;
                    break;
                }
            }
            for (int i = check.position; i > 0; i -= 5)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                    if (!Baned(i))
                        break;
                if (i == position && i != check.position)
                {
                    result = true;
                    break;
                }
                if (i % 6 == 0)
                    break;
            }
            for (int i = check.position; i > 0; i -= 7)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                    if (!Baned(i))
                        break;
                    if (i == position && i != check.position)
                    {
                        result = true;
                        break;
                    }
                    if (i % 6 == 1)
                        break;
            }
            for (int i = check.position; i <= 36; i += 7)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                    if (!Baned(i))
                        break;
                if (i == position && i != check.position)
                {
                    result = true;
                    break;
                }
                if (i % 6 == 0)
                    break;
            }
            return result;
        }
        public void Ban(int position, Button button)
        {
            if (check.ban)
            {
                if (Posible(position))
                {
                    if (check.queue == 2)
                    {
                        button.BackgroundImage = Amazons.Properties.Resources._2;
                        textBox1.Text = "Red Player Turn";
                    }
                    if (check.queue == 1)
                    {
                        button.BackgroundImage = Amazons.Properties.Resources._3;
                        textBox1.Text = "Blue Player Turn";
                    }
                    for (int i = 0; i < check.Baned.Length; i++)
                    {
                        if (0 == check.Baned[i])
                        {
                            check.Baned[i] = position;
                            check.time = 31;
                            break;
                        }
                    }
                    check.ban = false;
                }
                else
                {
                    textBox1.Text = "Error, invalid move!";
                }
            }
        }
        public int Cost(int ban)
        {
            int price = 0;
            int max = 0;
            int move = 0;
            int Queen = 0;
            if (check.queue == 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    if(ban==0)
                        check.position = check.Blue[i];
                    if(ban!=0)
                         {check.position = ban; i=3;}
                    for (int j = 1; j <= 36; j++)
                    {
                        if (Posible(j))
                        {
                            for (int q = 0; q < check.Red.Length; q++)
                            {
                                if (j == 1)
                                {
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price++;
                                }
                                if (j == 6)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j == 31)
                                {
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price++;
                                }
                                if (j == 36)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price++;
                                }
                                if (j >= 2 && j <= 5)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price++;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price++;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price++;
                                }
                                if (j >= 32 && j <= 35)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price++;
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price++;
                                }
                                if (j % 6 == 0 && j != 36 && j != 6)
                                {
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price++;
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j % 6 == 1 && j != 31 && j != 1)
                                {
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price++;
                                }
                                if ((j >= 8 && j <= 11) || (j >= 14 && j <= 17) || (j >= 20 && j <= 23) || (j >= 26 && j <= 29))
                                {
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price++;
                                }
                            }
                            for (int q = 0; q < check.Baned.Length; q++)
                            {
                                if (j == 1)
                                {
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                }
                                if (j == 6)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j == 31)
                                {
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                }
                                if (j == 36)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                }
                                if (j >= 2 && j <= 5)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                }
                                if (j >= 32 && j <= 35)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                }
                                if (j % 6 == 0 && j != 36 && j != 6)
                                {
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j % 6 == 1 && j != 31 && j != 1)
                                {
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                }
                                if ((j >= 8 && j <= 11) || (j >= 14 && j <= 17) || (j >= 20 && j <= 23) || (j >= 26 && j <= 29))
                                {
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                }
                            }
                            for (int q = 0; q < check.Blue.Length; q++)
                            {
                                if (j == 1)
                                {
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price--;
                                }
                                if (j == 6)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price--;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price--;
                                }
                                if (j == 31)
                                {
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price--;
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price--;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price--;
                                }
                                if (j == 36)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price--;
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price--;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price--;
                                }
                                if (j >= 2 && j <= 5)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price--;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price--;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price--;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price--;
                                }
                                if (j >= 32 && j <= 35)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price--;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price--;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price--;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price--;
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price--;
                                }
                                if (j % 6 == 0 && j != 36 && j != 6)
                                {
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price--;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price--;
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price--;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price--;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price--;
                                }
                                if (j % 6 == 1 && j != 31 && j != 1)
                                {
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price--;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price--;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price--;
                                }
                                if ((j >= 8 && j <= 11) || (j >= 14 && j <= 17) || (j >= 20 && j <= 23) || (j >= 26 && j <= 29))
                                {
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price--;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price--;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price--;
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price--;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price--;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price--;
                                }
                            }
                        }
                        if (max < price)
                        { max = price; move = j; Queen = check.position; }
                        price = 0;
                    }
                }   
            }
            if (check.queue == 2)
            {
                for (int i = 0; i < 4; i++)
                {
                    if(ban==0)
                        check.position = check.Red[i];
                    if(ban!=0)
                    {check.position = ban; i=3;}
                    for (int j = 1; j <= 36; j++)
                    {
                        if (Posible(j))
                        {
                            for (int q = 0; q < check.Blue.Length; q++)
                            {
                                if (j == 1)
                                {
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price++;
                                }
                                if (j == 6)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j == 31)
                                {
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price++;
                                }
                                if (j == 36)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price++;
                                }
                                if (j >= 2 && j <= 5)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price++;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price++;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price++;
                                }
                                if (j >= 32 && j <= 35)
                                {
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price++;
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price++;
                                }
                                if (j % 6 == 0 && j != 36 && j != 6)
                                {
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price++;
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j % 6 == 1 && j != 31 && j != 1)
                                {
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price++;
                                }
                                if ((j >= 8 && j <= 11) || (j >= 14 && j <= 17) || (j >= 20 && j <= 23) || (j >= 26 && j <= 29))
                                {
                                    if (j - 6 == check.Blue[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Blue[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Blue[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Blue[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Blue[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 1 == check.Blue[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Blue[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Blue[q] && j + 5 != check.position)
                                        price++;
                                }
                            }
                            for (int q = 0; q < check.Baned.Length; q++)
                            {
                                if (j == 1)
                                {
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                }
                                if (j == 6)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j == 31)
                                {
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                }
                                if (j == 36)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                }
                                if (j >= 2 && j <= 5)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                }
                                if (j >= 32 && j <= 35)
                                {
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                }
                                if (j % 6 == 0 && j != 36 && j != 6)
                                {
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                }
                                if (j % 6 == 1 && j != 31 && j != 1)
                                {
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                }
                                if ((j >= 8 && j <= 11) || (j >= 14 && j <= 17) || (j >= 20 && j <= 23) || (j >= 26 && j <= 29))
                                {
                                    if (j - 6 == check.Baned[q] && j - 6 != check.position)
                                        price++;
                                    if (j + 6 == check.Baned[q] && j + 6 != check.position)
                                        price++;
                                    if (j + 1 == check.Baned[q] && j + 1 != check.position)
                                        price++;
                                    if (j + 7 == check.Baned[q] && j + 7 != check.position)
                                        price++;
                                    if (j - 5 == check.Baned[q] && j - 5 != check.position)
                                        price++;
                                    if (j - 1 == check.Baned[q] && j - 1 != check.position)
                                        price++;
                                    if (j - 7 == check.Baned[q] && j - 7 != check.position)
                                        price++;
                                    if (j + 5 == check.Baned[q] && j + 5 != check.position)
                                        price++;
                                }
                            }
                            for (int q = 0; q < check.Red.Length; q++)
                            {
                                if (j == 1)
                                {
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price--;
                                }
                                if (j == 6)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price--;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price--;
                                }
                                if (j == 31)
                                {
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price--;
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price--;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price--;
                                }
                                if (j == 36)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price--;
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price--;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price--;
                                }
                                if (j >= 2 && j <= 5)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price--;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price--;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price--;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price--;
                                }
                                if (j >= 32 && j <= 35)
                                {
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price--;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price--;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price--;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price--;
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price--;
                                }
                                if (j % 6 == 0 && j != 36 && j != 6)
                                {
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price--;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price--;
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price--;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price--;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price--;
                                }
                                if (j % 6 == 1 && j != 31 && j != 1)
                                {
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price--;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price--;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price--;
                                }
                                if ((j >= 8 && j <= 11) || (j >= 14 && j <= 17) || (j >= 20 && j <= 23) || (j >= 26 && j <= 29))
                                {
                                    if (j - 6 == check.Red[q] && j - 6 != check.position)
                                        price--;
                                    if (j + 6 == check.Red[q] && j + 6 != check.position)
                                        price--;
                                    if (j + 1 == check.Red[q] && j + 1 != check.position)
                                        price--;
                                    if (j + 7 == check.Red[q] && j + 7 != check.position)
                                        price--;
                                    if (j - 5 == check.Red[q] && j - 5 != check.position)
                                        price--;
                                    if (j - 1 == check.Red[q] && j - 1 != check.position)
                                        price--;
                                    if (j - 7 == check.Red[q] && j - 7 != check.position)
                                        price--;
                                    if (j + 5 == check.Red[q] && j + 5 != check.position)
                                        price--;
                                }
                            }
                        }
                        if (max < price)
                        { max = price; move = j; Queen = check.position; }
                        price = 0;
                    }
                }
            }
            check.position = Queen;
            return move;
        }
        public void Moves(Button button, int number)
        {
            if (check.select && !check.ban)
            {
                if (Posible(number))
                {
                    Off(check.position,0);
                    if(check.queue == 1)
                        button.BackgroundImage = Amazons.Properties.Resources._4;
                    if (check.queue == 2)
                        button.BackgroundImage = Amazons.Properties.Resources._5;
                    check.ban = true;
                    check.banPos = number;
                    for (int i = 0; i < check.Qeens.Length; i++)
                    {
                        if (check.Qeens[i] == check.position)
                        {
                            check.Qeens[i] = number;
                            break;
                        }
                    }
                    for (int i = 0; i < check.Red.Length; i++)
                    {
                        if (check.Red[i] == check.position && check.queue == 2)
                        {
                            check.Red[i] = number;
                            check.select = false;
                            check.position = number;
                            break;
                        }
                    }
                    for (int i = 0; i < check.Blue.Length; i++)
                    {
                        if (check.Blue[i] == check.position && check.queue == 1)
                        {
                            check.Blue[i] = number;
                            check.select = false;
                            check.position = number;
                            break;
                        }
                    }
                    if (check.queue == 1)
                    {
                        check.queue = 2;
                        textBox1.Text = "Blue Player Fire";
                    }
                    else
                    {
                        check.queue = 1;
                        textBox1.Text = "Red Player Fire";
                    }
                }
                else
                {
                    check.select = false;
                    textBox1.Text = "False move, choose Queen again!";
                }

            }
            else
            {
                for (int i = 0; i < check.Blue.Length; i++)
                {
                    if (check.Blue[i] == number && check.queue == 1)
                    {
                        check.select = true;
                        textBox1.Text = "Blue Queen selected";
                        check.position = number;
                        break;
                    }
                    if (check.Red[i] == number && check.queue == 2)
                    {
                        check.select = true;
                        textBox1.Text = "Red Queen selected";
                        check.position = number;
                        break;
                    }
                    else
                    {
                        check.select = false;
                        check.position = check.banPos;
                        Ban(number, button);
                    }
                }
            } 
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Moves(button1, 1);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Moves(button2, 2);
        }
        private void button3_Click(object sender, EventArgs e)
        {
            Moves(button3, 3);   
        }
        private void button4_Click(object sender, EventArgs e)
        {
            Moves(button4, 4);
        }
        private void button5_Click(object sender, EventArgs e)
        {
            Moves(button5, 5);
        }
        private void button6_Click(object sender, EventArgs e)
        {
            Moves(button6, 6);
        }
        private void button7_Click(object sender, EventArgs e)
        {
            Moves(button7, 7);
        }
        private void button8_Click(object sender, EventArgs e)
        {
            Moves(button8, 8);
        }
        private void button9_Click(object sender, EventArgs e)
        {
            Moves(button9, 9);
        }
        private void button10_Click(object sender, EventArgs e)
        {
            Moves(button10, 10);
        }
        private void button11_Click(object sender, EventArgs e)
        {
            Moves(button11, 11);
        }
        private void button12_Click(object sender, EventArgs e)
        {
            Moves(button12, 12);
        }
        private void button13_Click(object sender, EventArgs e)
        {
            Moves(button13, 13);
        }
        private void button14_Click(object sender, EventArgs e)
        {
            Moves(button14, 14);
        }
        private void button15_Click(object sender, EventArgs e)
        {
            Moves(button15, 15);
        }
        private void button16_Click(object sender, EventArgs e)
        {
            Moves(button16, 16);
        }
        private void button17_Click(object sender, EventArgs e)
        {
            Moves(button17, 17);   
        }
        private void button18_Click(object sender, EventArgs e)
        {
            Moves(button18, 18);  
        }
        private void button19_Click(object sender, EventArgs e)
        {
            Moves(button19, 19);
        }
        private void button20_Click(object sender, EventArgs e)
        {
            Moves(button20, 20);   
        }
        private void button21_Click(object sender, EventArgs e)
        {
            Moves(button21, 21);
        }
        private void button22_Click(object sender, EventArgs e)
        {
            Moves(button22, 22);
        }
        private void button23_Click(object sender, EventArgs e)
        {
            Moves(button23, 23);
        }
        private void button24_Click(object sender, EventArgs e)
        {
            Moves(button24, 24);
        }
        private void button25_Click(object sender, EventArgs e)
        {
            Moves(button25, 25);   
        }
        private void button26_Click(object sender, EventArgs e)
        {
            Moves(button26, 26);
        }
        private void button27_Click(object sender, EventArgs e)
        {
            Moves(button27, 27);
        }
        private void button28_Click(object sender, EventArgs e)
        {
            Moves(button28, 28);
        }
        private void button29_Click(object sender, EventArgs e)
        {
            Moves(button29, 29);
        }
        private void button30_Click(object sender, EventArgs e)
        {
            Moves(button30, 30);
        }
        private void button31_Click(object sender, EventArgs e)
        {
            Moves(button31, 31);
        }
        private void button32_Click(object sender, EventArgs e)
        {
            Moves(button32, 32);
        }
        private void button33_Click(object sender, EventArgs e)
        {
            Moves(button33, 33);
        }
        private void button34_Click(object sender, EventArgs e)
        {
            Moves(button34, 34);
        }
        private void button35_Click(object sender, EventArgs e)
        {
            Moves(button35, 35);
        }
        private void button36_Click(object sender, EventArgs e)
        {
            Moves(button36, 36);
        }
        int player = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            
            if (check.time <= 0)
            {
                timer1.Enabled = false;
                check.queue = 0;
                textBox1.Text = check.queue == 1 ? "Blue Player Losses" : "Red Player Losses";
            }
            else
            {
                check.time--;
                label1.Text = check.time.ToString();
            }
            if (check.AI)
            {
                
                if (player == 2 && check.queue == 1 && check.ban == false)
                {
                    int number = Cost(0);
                    int select = check.position;
                    if (select != 0 && number != 0)
                    { Moves(Off(select,0), select); Moves(Off(number,0), number); }
                }

                if (player == 1 && check.queue == 2 && check.ban == false)
                {
                    int number = Cost(0);
                    int select = check.position;
                    if (select != 0 && number != 0)
                    { Moves(Off(select,0), select); Moves(Off(number,0), number); }
                }
                if (player == 2 && check.queue == 2 && check.ban == true)
                {
                    check.queue = 1;
                    int number = Cost(check.position);
                    int select = check.position;
                    check.queue = 2;
                    if (select != 0 && number != 0)
                    { Moves(Off(select, 1), select); Moves(Off(number, 1), number); }
                }
                if (player == 1 && check.queue == 1 && check.ban == true)
                {
                    check.queue = 2;
                    int number = Cost(check.position);
                    int select = check.position;
                    check.queue = 1;
                    if (select != 0 && number != 0)
                    { Moves(Off(select, 1), select); Moves(Off(number, 1), number); }
                }
 
            }
        }
        int count = 0;
        private void button37_Click(object sender, EventArgs e)
        {
            if (count == 0)
            {
                timer1.Enabled = true;
                if (radioButton1.Checked)
                {
                    check.queue = 1;
                    player = 1;
                    textBox1.Text = "Blue Player Turn";
                }
                else
                {
                    check.queue = 2;
                    player = 2;
                    textBox1.Text = "Red Player Turn";
                }
                if (checkBox1.Checked)
                    check.AI = true;
                count++;
            }
        }

        private void button38_Click(object sender, EventArgs e)
        {
            
            this.Close();
        }
    }
    public class Check
    {
        public int[] Qeens = { 2, 5, 7, 12, 25, 30, 32, 35 };
        public int[] Red = { 25, 30, 32, 35 };
        public int[] Blue = { 2, 5, 7, 12 };
        public int[] Baned = new int[28];
        public int time = 30;
        public int queue = 0;
        public int position = 0;
        public bool select = false;
        public bool ban = false;
        public int banPos = 0;
        public bool AI = false;
        
    }
}
