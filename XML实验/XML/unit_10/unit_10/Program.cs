using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace unit_10
{
    class Program
    {
        static void Main(string[] args)
        {
            ReadeXML readxml = new ReadeXML();
            WriteXML writexml = new WriteXML();
            //readxml.ReadXML();
            if (writexml.write() == 1)
            {
                Console.WriteLine("写入成功!");
            }

            Console.ReadKey();
        }
    }
}
