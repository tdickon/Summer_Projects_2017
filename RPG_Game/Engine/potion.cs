using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Engine
{
    //The Potion Class will serve as the main parent class to all our subset potions
    //Potions will have various affects on the stats that can affect the player
    //Or outside enviroments, such as NPCs, Monsters, etc.

   public class potion
    {
        //Private Member Values
        private int _ID;
        private string _potion_ID;
        private string _potion_name;
        private string _potion_name_plural;
        private int _potion_effect;
        //Things to note, I would like to add specification that takes into account what type of spell and who it affects.

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
        public string potion_ID
        {
            get
            {
                return _potion_ID;
            }

            set
            {
                string num_id = _ID.ToString();
                //In future versions, I will be adding a way to detect the type of potion, plus its ID number.
                //_potion_ID = type + num_id;

                _potion_ID = num_id;
            }
        }
        public string potion_name
        {
            get
            {
                return _potion_name;
            }

            set
            {
                _potion_name = value;
            }
        }
        public string potion_name_plural
        {
            get
            {
                return _potion_name_plural;
            }
            
            set
            {
                _potion_name_plural = value;
            }
        }
        public int potion_effect
        {
            get
            {
                return _potion_effect;
            }

            set
            {
                _potion_effect = value;
            }
        }

        //Constructors
        public potion()
        {
            ID = 0;
            potion_ID = "\0";
            potion_name = "\0";
            potion_name_plural = "\0";
            potion_effect = 0;
        }
    }
}
