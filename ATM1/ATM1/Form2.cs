using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ATM1
{
    public partial class Form2 : Form
    {
        public string pin_1;
        private int k = 0;
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            pin_1 = Console.ReadLine();
            pin_1 = richTextBox1.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Data temp = new Data();
           

                temp.Reading_id("info.txt");
                string pin11 = temp.PIN;
                k++;
                if (!pin_1.Equals(pin11))
                {
                    if (k == 3)
                    {
                        File.Delete("info.txt");
                        Environment.Exit(0);
                       
                    }
                    Form3 f3 = new Form3();
                f3.Show();
                   

                }
                else
                {
                   
                
            }
        }
    }
}
