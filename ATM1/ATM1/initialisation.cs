using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ATM1
{
    class initialisation
    {
        public void whatisid(string id_1)
        {
            
            
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
            
        }
    }
}

