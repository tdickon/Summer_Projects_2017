namespace RPG_Game
{
    partial class RPG
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.hit_point_text = new System.Windows.Forms.Label();
            this.gold_text = new System.Windows.Forms.Label();
            this.experience_text = new System.Windows.Forms.Label();
            this.level_text = new System.Windows.Forms.Label();
            this.lbl_hit_points = new System.Windows.Forms.Label();
            this.lbl_gold = new System.Windows.Forms.Label();
            this.lbl_experience = new System.Windows.Forms.Label();
            this.lbl_level = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // hit_point_text
            // 
            this.hit_point_text.AutoSize = true;
            this.hit_point_text.Location = new System.Drawing.Point(18, 20);
            this.hit_point_text.Name = "hit_point_text";
            this.hit_point_text.Size = new System.Drawing.Size(55, 13);
            this.hit_point_text.TabIndex = 0;
            this.hit_point_text.Text = "Hit Points:";
            // 
            // gold_text
            // 
            this.gold_text.AutoSize = true;
            this.gold_text.Location = new System.Drawing.Point(18, 46);
            this.gold_text.Name = "gold_text";
            this.gold_text.Size = new System.Drawing.Size(32, 13);
            this.gold_text.TabIndex = 1;
            this.gold_text.Text = "Gold:";
            // 
            // experience_text
            // 
            this.experience_text.AutoSize = true;
            this.experience_text.Location = new System.Drawing.Point(18, 74);
            this.experience_text.Name = "experience_text";
            this.experience_text.Size = new System.Drawing.Size(63, 13);
            this.experience_text.TabIndex = 2;
            this.experience_text.Text = "Experience:";
            // 
            // level_text
            // 
            this.level_text.AutoSize = true;
            this.level_text.Location = new System.Drawing.Point(18, 100);
            this.level_text.Name = "level_text";
            this.level_text.Size = new System.Drawing.Size(36, 13);
            this.level_text.TabIndex = 3;
            this.level_text.Text = "Level:";
            // 
            // lbl_hit_points
            // 
            this.lbl_hit_points.AutoSize = true;
            this.lbl_hit_points.Location = new System.Drawing.Point(110, 19);
            this.lbl_hit_points.Name = "lbl_hit_points";
            this.lbl_hit_points.Size = new System.Drawing.Size(0, 13);
            this.lbl_hit_points.TabIndex = 4;
            // 
            // lbl_gold
            // 
            this.lbl_gold.AutoSize = true;
            this.lbl_gold.Location = new System.Drawing.Point(110, 45);
            this.lbl_gold.Name = "lbl_gold";
            this.lbl_gold.Size = new System.Drawing.Size(0, 13);
            this.lbl_gold.TabIndex = 5;
            // 
            // lbl_experience
            // 
            this.lbl_experience.AutoSize = true;
            this.lbl_experience.Location = new System.Drawing.Point(110, 73);
            this.lbl_experience.Name = "lbl_experience";
            this.lbl_experience.Size = new System.Drawing.Size(0, 13);
            this.lbl_experience.TabIndex = 6;
            // 
            // lbl_level
            // 
            this.lbl_level.AutoSize = true;
            this.lbl_level.Location = new System.Drawing.Point(110, 99);
            this.lbl_level.Name = "lbl_level";
            this.lbl_level.Size = new System.Drawing.Size(0, 13);
            this.lbl_level.TabIndex = 7;
            // 
            // RPG
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(719, 651);
            this.Controls.Add(this.lbl_level);
            this.Controls.Add(this.lbl_experience);
            this.Controls.Add(this.lbl_gold);
            this.Controls.Add(this.lbl_hit_points);
            this.Controls.Add(this.level_text);
            this.Controls.Add(this.experience_text);
            this.Controls.Add(this.gold_text);
            this.Controls.Add(this.hit_point_text);
            this.Name = "RPG";
            this.Text = "RPG Game";
            this.Load += new System.EventHandler(this.RPG_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label hit_point_text;
        private System.Windows.Forms.Label gold_text;
        private System.Windows.Forms.Label experience_text;
        private System.Windows.Forms.Label level_text;
        private System.Windows.Forms.Label lbl_hit_points;
        private System.Windows.Forms.Label lbl_gold;
        private System.Windows.Forms.Label lbl_experience;
        private System.Windows.Forms.Label lbl_level;
    }
}

