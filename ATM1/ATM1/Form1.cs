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
    public partial class Form1 : Form
    {
        public string id_1;
        private bool del;
        public Form1()
        {
            InitializeComponent();
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {            
            id_1 = Console.ReadLine();
            id_1 = richTextBox1.Text;
            }

        private void button1_Click(object sender, EventArgs e)
        {
            del = !del;
            if (id_1.Length != 2)
            {
                Environment.Exit(0);
            }
            StreamReader str = new StreamReader("id.txt", Encoding.Default);
            string st = str.ReadLine();
            while (st != null)
            {
                if (st.StartsWith(id_1))
                {
                    StreamWriter dop = new StreamWriter("info.txt", true, Encoding.Default);
                    dop.WriteLine(st);
                    dop.Close();
                    break;
                }
                else st = str.ReadLine();
            }
            str.Close();
            Form2 f2 = new Form2();
            f2.Show();
            this.Hide();

        }

        private void label1_Click(object sender, EventArgs e)
        {
            
        }
    }
    }
    

