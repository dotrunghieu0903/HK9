namespace MapEditor
{
    partial class AddState
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
            this.pnImage = new System.Windows.Forms.Panel();
            this.bt_Load = new System.Windows.Forms.Button();
            this.rtb_set = new System.Windows.Forms.RichTextBox();
            this.pb_tiles = new System.Windows.Forms.PictureBox();
            this.pgB_Status = new System.Windows.Forms.ProgressBar();
            this.btAdd = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pb_tiles)).BeginInit();
            this.SuspendLayout();
            // 
            // pnImage
            // 
            this.pnImage.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pnImage.AutoScroll = true;
            this.pnImage.BackColor = System.Drawing.SystemColors.ControlText;
            this.pnImage.Location = new System.Drawing.Point(6, 6);
            this.pnImage.Name = "pnImage";
            this.pnImage.Size = new System.Drawing.Size(930, 202);
            this.pnImage.TabIndex = 8;
            // 
            // bt_Load
            // 
            this.bt_Load.Location = new System.Drawing.Point(6, 216);
            this.bt_Load.Name = "bt_Load";
            this.bt_Load.Size = new System.Drawing.Size(78, 48);
            this.bt_Load.TabIndex = 10;
            this.bt_Load.Text = "Load BG";
            this.bt_Load.UseVisualStyleBackColor = true;
            this.bt_Load.Click += new System.EventHandler(this.bt_Load_Click);
            // 
            // rtb_set
            // 
            this.rtb_set.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.rtb_set.BackColor = System.Drawing.SystemColors.ControlText;
            this.rtb_set.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.rtb_set.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.rtb_set.ForeColor = System.Drawing.SystemColors.Menu;
            this.rtb_set.Location = new System.Drawing.Point(90, 216);
            this.rtb_set.Name = "rtb_set";
            this.rtb_set.ReadOnly = true;
            this.rtb_set.Size = new System.Drawing.Size(600, 218);
            this.rtb_set.TabIndex = 11;
            this.rtb_set.Text = "";
            this.rtb_set.WordWrap = false;
            // 
            // pb_tiles
            // 
            this.pb_tiles.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.pb_tiles.BackColor = System.Drawing.SystemColors.ControlText;
            this.pb_tiles.Location = new System.Drawing.Point(696, 216);
            this.pb_tiles.Name = "pb_tiles";
            this.pb_tiles.Size = new System.Drawing.Size(240, 218);
            this.pb_tiles.TabIndex = 12;
            this.pb_tiles.TabStop = false;
            // 
            // pgB_Status
            // 
            this.pgB_Status.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pgB_Status.Location = new System.Drawing.Point(6, 445);
            this.pgB_Status.Maximum = 1000;
            this.pgB_Status.Name = "pgB_Status";
            this.pgB_Status.Size = new System.Drawing.Size(930, 23);
            this.pgB_Status.TabIndex = 13;
            // 
            // btAdd
            // 
            this.btAdd.Location = new System.Drawing.Point(6, 270);
            this.btAdd.Name = "btAdd";
            this.btAdd.Size = new System.Drawing.Size(78, 48);
            this.btAdd.TabIndex = 14;
            this.btAdd.Text = "Add";
            this.btAdd.UseVisualStyleBackColor = true;
            this.btAdd.Click += new System.EventHandler(this.btSave_Click);
            // 
            // AddState
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(942, 471);
            this.Controls.Add(this.btAdd);
            this.Controls.Add(this.pgB_Status);
            this.Controls.Add(this.pb_tiles);
            this.Controls.Add(this.rtb_set);
            this.Controls.Add(this.bt_Load);
            this.Controls.Add(this.pnImage);
            this.Name = "AddState";
            this.Text = "Add State";
            ((System.ComponentModel.ISupportInitialize)(this.pb_tiles)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnImage;
        private System.Windows.Forms.Button bt_Load;
        private System.Windows.Forms.RichTextBox rtb_set;
        private System.Windows.Forms.PictureBox pb_tiles;
        private System.Windows.Forms.ProgressBar pgB_Status;
        private System.Windows.Forms.Button btAdd;
    }
}