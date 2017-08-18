using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Engine
{
    public class monster
    {
        //Private Member Variables
        private string _monst_name;
       
        //Public Constructors
        public string monst_name
        {
            get
            {
                return _monst_name;
            }
            
            set
            {
                _monst_name = value;
            }
        }

        //Constructors
        public monster()
        {
            monst_name = "\0";
        }
    }
}
