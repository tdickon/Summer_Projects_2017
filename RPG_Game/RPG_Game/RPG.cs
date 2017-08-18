using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Engine;

namespace RPG_Game
{
    public partial class RPG : Form
    {
        private player _player = new player();  
            
        public RPG()
        {
            InitializeComponent();

            //Establishing The player's current values.
            lbl_hit_points.Text = _player.current_hit_points.ToString();
            lbl_gold.Text = _player.gold.ToString();
            lbl_experience.Text = _player.current_exp.ToString();
            lbl_level.Text = _player.current_level.ToString();

        }

        private void RPG_Load(object sender, EventArgs e)
        {

        }

    }
}
