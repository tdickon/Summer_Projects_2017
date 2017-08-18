using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//The Player Class is a member class of the Engine Namespace, this class keeps track of all of the players data and information throughout the game.
namespace Engine
{
    public class player : character
    {
        private int _current_exp; //the current amount of experience points the player has occured during playing;
        private int _current_level;
        /*MORE DATA TYPES TO ADD IN FUTURE VERSION RELEASES
         * Strength
         * Agility
         * Stealth
         * Charisma
         * Personality
         * Endurance
         * Intelligence
         * race
         * bounty
         * faction standings
         */
        
        //Public Properties     
        public int current_exp
        {
            get
            {
                return _current_exp;
            }

            set
            {
                //Note that we will need to add a feature that will check the player's next level and how much exp is needed 
                //to move to reach that level. 
                
                if(value > 0)
                {
                    _current_exp += value;
                }

                else
                {
                    _current_exp += 0;
                }
            }
        }
        public int current_level
        {
            get
            {
                return _current_level;
            }

            //The Set function will be added at a later time, after figuring out how I want to implement the leveling
            //mechanics to the game. 
        }

        //Constructors
        public player()
        {
            current_exp = 0;
            _current_level = 1;
        }
    }
}
