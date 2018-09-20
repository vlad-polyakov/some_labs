using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ATM1
{
    class inpin: Data
    {
        private int k = 0;
        public void pin_kod(string pin_1)
        {
            while (true)
            {
              
                Reading_id("info.txt");
                string pin11 = PIN;
                k++;
                if (!pin_1.Equals(pin11))
                {
                    if (k == 3)
                    {
                        Console.WriteLine("Карта заблокирована (нажмите Enter, чтобы продолжить)");
                        File.Delete("info.txt");
                        Environment.Exit(0);
                        break;
                    }
                    Console.WriteLine("Неверный пин-код! У вас осталось " + (3 - k) + " попытки");
                }
                else
                {
                    break;
                }
            }

        }
    }
}

