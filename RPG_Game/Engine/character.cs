using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Engine
{

    public class character
    {
        //Global Static Variables
       static int MAX_HEALTH = 100;
       static int MIN_HEALTH = 0;
        //Private Member Values
        private int _total_hit_points;
        private int _current_hit_points;
        private int _gold;
        //Properties
        public int total_hit_points
        {
            get
            {
                return _total_hit_points;
            }

            set
            {

                if (value > MAX_HEALTH)
                {
                    _total_hit_points = MAX_HEALTH;
                }

                else
                {
                    _total_hit_points = value;
                }
            }
        }
        public int current_hit_points
        {
            get
            {
                return _current_hit_points;
            }

            set
            {
                if (value < MIN_HEALTH)
                {
                    _current_hit_points = 0;
                }

                else if (value > _total_hit_points)
                {
                    _current_hit_points = _total_hit_points;
                }

                else
                {
                    _current_hit_points = value;
                }
            }
        }
        public int gold
        {
            get
            {
                return _gold;
            }

            set
            {
                _gold = value;
            }
        }
        //Constructors
        public character()
        {
            total_hit_points = MAX_HEALTH;
            current_hit_points = MAX_HEALTH;
            gold = 0;
        }
    }

    public class npc : character
    {
        //Private Member Variables
        private int _ID;
        private int _exp_gain;
        private int _min_dmg;
        private int _max_dmg;

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

        //Constructors
        public npc()
        {
            ID = 0;
            min_dmg = 0;
            max_dmg = 0;
            exp_gain = 0;
        }
    }
}
