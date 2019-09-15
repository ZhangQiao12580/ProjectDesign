using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;

namespace unit_10
{
    class WriteXML
    {
        public int write()
        {
            try
            {
                DataSet ds = new DataSet();
                ds.ReadXml("../../unit_10_1.xml");
                ds.WriteXml("../../unit_10_1(2).xml");
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
                return -1;
            }
            return 1;
        }
    }
}
