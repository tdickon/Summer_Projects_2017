using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Engine
{
    public class weapon : item
    {
        //Private Member Values
        private int _min_dmg;
        private int _max_dmg;

        //Public Properties
        public int min_dmg
        {
            get
            {
                return _min_dmg;
            }

            set
            {
                _min_dmg = value;
            }
        }
        public int max_dmg
        {
            get
            {
                return _max_dmg;
            }

            set
            {
                _max_dmg = value;
            }
        }

        //Constructors
        public weapon()
        {
            min_dmg = 0;
            max_dmg = 0;
        }
    }
}
