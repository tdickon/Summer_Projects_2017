using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Engine
{
    public class location
    {
        //Private Member Variables
        private int _ID;
        private string _loc_ID;
        private string _loc_name;
        private string _loc_description;
        private int _x_cord;
        private int _y_cord;

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
        public string loc_ID
        {
            get
            {
                return _loc_ID;
            }

            set
            {
                _loc_ID = value;
            }
        }
        public string loc_name
        {
            get
            {
                return _loc_name;
            }

            set
            {
                _loc_name = value;
            }
        }
        public string loc_description
        {
            get
            {
                return _loc_description;
            }

            set
            {
                _loc_description = value;
            }
        }
        public int x_cord
        {
            get
            {
                return _x_cord;
            }

            set
            {
                _x_cord = value;
            }
        }
        public int y_cord
        {
            get
            {
                return _y_cord;
            }

            set
            {
                _y_cord = value;
            }
        }

        //Constructors
        public location()
        {
            ID = 0;
            loc_ID = "\0";
            loc_name = "\0";
            loc_description = "\0";
            x_cord = 0;
            y_cord = 0;
        }
    }
}
