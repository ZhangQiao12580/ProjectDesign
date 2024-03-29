﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace unit_10
{
    class ReadeXML
    {
        public void ReadXML()
        {
            XmlNodeReader reader = null;
            String filename = "../../unit_10_1.xml";
            try
            {
                XmlDocument doc = new XmlDocument();
                doc.Load(filename);
                reader = new XmlNodeReader(doc);

                while (reader.Read())
                {
                    switch (reader.NodeType)
                    {
                        case XmlNodeType.Element:
                            Console.WriteLine("<{0}>", reader.Name);
                            break;
                        case XmlNodeType.Text:
                            Console.WriteLine(reader.Value);
                            break;
                        case XmlNodeType.CDATA:
                            Console.WriteLine(reader.Value);
                            break;
                        case XmlNodeType.Document:
                            break;
                        case XmlNodeType.EndElement:
                            Console.WriteLine("</{0}>", reader.Name);
                            break;
                    }
                }
            }

            finally
            {
                if (reader != null)
                    reader.Close();
            }
        }
    }
}
