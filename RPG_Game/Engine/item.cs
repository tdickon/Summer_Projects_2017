using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Engine
{
    public class item
    {
        //Private Member Variables
        private int _ID;
        private string _item_name;
        private string _item_name_plural;
        private int _item_cost;

        //Public Properties
        public int ID
        {
            get
            {
                return _ID;
            }

            set
            {
                _ID = value;
            }
        }
        public string item_name
        {
            get
            {
                return _item_name; 
            }

            set
            {
                _item_name = value;
            }
        }
        public string item_name_plural
        {
            get
            {
                return _item_name_plural;
            }

            set
            {
                _item_name_plural = value;
            }
        }
        public int item_cost
        {
            get
            {
                return _item_cost;
            }

            set
            {
                _item_cost = value;  
            }
        }

        //Constructors
        public item()
        {
            ID = 0;
            item_name = "\0";
            item_name_plural = "\0";
            item_cost = 0;
        }
    }
}
