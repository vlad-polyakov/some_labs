using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ATM1
{
    public class Data
    {
        private string id, pin, money;
        private const int pin_q = 4, id_q = 2;
        public void Reading_id(string t)
        {

            if (!File.Exists(t))
            {
                Environment.Exit(0);
            }
            StreamReader str = new StreamReader(t, Encoding.Default);
            string p = str.ReadLine();
            int q = p.Length;
            id = p.Substring(0, id_q);
            pin = p.Substring(id_q + 1, pin_q);
            money = p.Substring(id_q + pin_q + 2);
            str.Close();
        }

        public string Id
        {
            get
            {
                return id;
            }
            set
            {
                id = value;
            }
        }
        public string PIN
        {
            get
            {
                return pin;
            }
            set
            {
                pin = value;
            }
        }

        public string MONEY
        {
            get
            {
                return money;
            }
            set
            {
                money = value;
            }
        }
    }

}

