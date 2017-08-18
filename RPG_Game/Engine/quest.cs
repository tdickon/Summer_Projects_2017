using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Engine
{
    public class quest
    {
        //Private Member Values
        private int _ID;
        private string _quest_ID;
        private string _quest_name;
        private string _quest_description;
        private int _exp_gain;
        private int _gold_gain;

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
        public string quest_ID
        {
            get
            {
                return _quest_ID;
            }

            set
            {
                _quest_ID = value;
            }
        }
        public string quest_name
        {
            get
            {
                return _quest_name;
            }

            set
            {
                _quest_name = value;
            }
        }
        public string quest_description
        {
            get
            {
                return _quest_description;
            }

            set
            {
                _quest_description = value;
            }
        }
        public int exp_gain
        {
            get
            {
                return _exp_gain;
            }

            set
            {
                _exp_gain = value;
            }
        }
        public int gold_gain
        {
            get
            {
                return _gold_gain;
            }

            set
            {
                _gold_gain = value;
            }
        }        

        //Constructors
        public quest()
        {
            ID = 0;
            quest_ID = "\0";
            quest_name = "\0";
            quest_description = "\0";
            exp_gain = 0;
            gold_gain = 0;
        }
    }
}
