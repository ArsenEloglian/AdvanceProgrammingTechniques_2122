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
            
            button2.BackgroundImage = Amazons.Properties.Resources._1;
            button5.BackgroundImage = Amazons.Properties.Resources._1;
            button7.BackgroundImage = Amazons.Properties.Resources._1;
            button12.BackgroundImage = Amazons.Properties.Resources._1;
            button25.BackgroundImage = Amazons.Properties.Resources._1;
            button30.BackgroundImage = Amazons.Properties.Resources._1;
            button32.BackgroundImage = Amazons.Properties.Resources._1;
            button35.BackgroundImage = Amazons.Properties.Resources._1;

        }
        public void Off(int position)
        {
            switch (position)
            {
                case 1:
                    button1.BackgroundImage = null;
                    break;
                case 2:
                    button2.BackgroundImage = null;
                    break;
                case 3:
                    button3.BackgroundImage = null;
                    break;
                case 4:
                    button4.BackgroundImage = null;
                    break;
                case 5:
                    button5.BackgroundImage = null;
                    break;
                case 6:
                    button6.BackgroundImage = null;
                    break;
                case 7:
                    button7.BackgroundImage = null;
                    break;
                case 8:
                    button8.BackgroundImage = null;
                    break;
                case 9:
                    button9.BackgroundImage = null;
                    break;
                case 10:
                    button10.BackgroundImage = null;
                    break;
                case 11:
                    button11.BackgroundImage = null;
                    break;
                case 12:
                    button12.BackgroundImage = null;
                    break;
                case 13:
                    button13.BackgroundImage = null;
                    break;
                case 14:
                    button14.BackgroundImage = null;
                    break;
                case 15:
                    button15.BackgroundImage = null;
                    break;
                case 16:
                    button16.BackgroundImage = null;
                    break;
                case 17:
                    button17.BackgroundImage = null;
                    break;
                case 18:
                    button18.BackgroundImage = null;
                    break;
                case 19:
                    button19.BackgroundImage = null;
                    break;
                case 20:
                    button20.BackgroundImage = null;
                    break;
                case 21:
                    button21.BackgroundImage = null;
                    break;
                case 22:
                    button22.BackgroundImage = null;
                    break;
                case 23:
                    button23.BackgroundImage = null;
                    break;
                case 24:
                    button24.BackgroundImage = null;
                    break;
                case 25:
                    button25.BackgroundImage = null;
                    break;
                case 26:
                    button26.BackgroundImage = null;
                    break;
                case 27:
                    button27.BackgroundImage = null;
                    break;
                case 28:
                    button28.BackgroundImage = null;
                    break;
                case 29:
                    button29.BackgroundImage = null;
                    break;
                case 30:
                    button30.BackgroundImage = null;
                    break;
                case 31:
                    button31.BackgroundImage = null;
                    break;
                case 32:
                    button32.BackgroundImage = null;
                    break;
                case 33:
                    button33.BackgroundImage = null;
                    break;
                case 34:
                    button34.BackgroundImage = null;
                    break;
                case 35:
                    button35.BackgroundImage = null;
                    break;
                case 36:
                    button36.BackgroundImage = null;
                    break;
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
        public bool Posible(int position)
        {
            bool result = false;
            for (int i = check.position; i <= (check.position / 6 + 1) * 6 + 1; ++i)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
                if (i % 6 == 0)
                    break;
            }
            for (int i = check.position; i > (check.position % 6 == 0 ? (check.position / 6 - 1) * 6 : (check.position / 6) * 6) && i > 0; i--)
            {
                if(i!=check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
            }
            if (result)
                return result;
            for (int i = check.position; i <= 36; i+=5)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
            }
            if (result)
                return result;
            for (int i = check.position; i <= 36; i += 6)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
            }
            if (result)
                return result;
            for (int i = check.position; i > 0; i -= 6)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
            }
            if (result)
                return result;
            for (int i = check.position; i > 0; i -= 5)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
            }
            if (result)
                return result;
            for (int i = check.position; i > 0; i -= 7)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
            }
            if (result)
                return result;
            for (int i = check.position; i <= 36; i += 7)
            {
                if (i != check.position)
                    if (!Qeens(i))
                        break;
                if (i == position)
                {
                    result = true;
                    break;
                }
            }
            return result;
        }
        public void Moves(Button button, int number)
        {
            if (check.select)
            {
                if (Posible(number))
                {
                    Off(check.position);
                    button.BackgroundImage = Amazons.Properties.Resources._1;
                    for (int i = 0; i < check.Qeens.Length; i++)
                    {
                        if (check.Qeens[i] == check.position)
                        {
                            check.Qeens[i] = number;
                            check.select = false;
                            check.position = number;
                            break;
                        }
                    }
                }
                else
                {
                    check.select = false;
                }

            }
            else
            {
                for (int i = 0; i < check.Qeens.Length; i++)
                {
                    if (check.Qeens[i] == number)
                    {
                        check.select = true;
                        check.position = number;
                        break;
                    }
                    else
                        check.select = false;
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
    }
    public class Check
    {
        public int[] Qeens = { 2, 5, 7, 12, 25, 30, 32, 35 };
        public int position = 0;
        public bool select = false;
        
    }
}
