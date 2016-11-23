using System.Drawing;
namespace MapEditor
{
    partial class MapEditor
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
            this.btNewMap = new System.Windows.Forms.Button();
            this.btLoad = new System.Windows.Forms.Button();
            this.btSave = new System.Windows.Forms.Button();
            this.pnCommand = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.lbCurrentPos = new System.Windows.Forms.Label();
            this.tbStateY = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.tbStateX = new System.Windows.Forms.TextBox();
            this.cbbState = new System.Windows.Forms.ComboBox();
            this.btAddState = new System.Windows.Forms.Button();
            this.cbRandomItm = new System.Windows.Forms.CheckBox();
            this.btClear = new System.Windows.Forms.Button();
            this.cbAutoAlign = new System.Windows.Forms.CheckBox();
            this.cbShowTiles = new System.Windows.Forms.CheckBox();
            this.tbPosY = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tbPosX = new System.Windows.Forms.TextBox();
            this.pnMapViewer = new System.Windows.Forms.Panel();
            this.tcObjects = new System.Windows.Forms.TabControl();
            this.tpGround = new System.Windows.Forms.TabPage();
            this.ground_death = new System.Windows.Forms.PictureBox();
            this.ground_go_in_castle = new System.Windows.Forms.PictureBox();
            this.ground_hidden_brick = new System.Windows.Forms.PictureBox();
            this.ground_stair_down = new System.Windows.Forms.PictureBox();
            this.ground_stair_up = new System.Windows.Forms.PictureBox();
            this.ground_brick = new System.Windows.Forms.PictureBox();
            this.ground_trap = new System.Windows.Forms.PictureBox();
            this.ground_moving_brick = new System.Windows.Forms.PictureBox();
            this.ground_lockdoor = new System.Windows.Forms.PictureBox();
            this.ground_opendoor = new System.Windows.Forms.PictureBox();
            this.ground_firetower = new System.Windows.Forms.PictureBox();
            this.ground_firecandle = new System.Windows.Forms.PictureBox();
            this.tpEnemy = new System.Windows.Forms.TabPage();
            this.enemy_ghost = new System.Windows.Forms.PictureBox();
            this.enemy_bonepillar = new System.Windows.Forms.PictureBox();
            this.enemy_medusahead = new System.Windows.Forms.PictureBox();
            this.enemy_spearguard = new System.Windows.Forms.PictureBox();
            this.enemy_merman = new System.Windows.Forms.PictureBox();
            this.enemy_bat = new System.Windows.Forms.PictureBox();
            this.enemy_panther = new System.Windows.Forms.PictureBox();
            this.enemy_zombie = new System.Windows.Forms.PictureBox();
            this.tpBoss = new System.Windows.Forms.TabPage();
            this.simon = new System.Windows.Forms.PictureBox();
            this.boss_medusa = new System.Windows.Forms.PictureBox();
            this.boss_bat = new System.Windows.Forms.PictureBox();
            this.tpItem = new System.Windows.Forms.TabPage();
            this.item_none = new System.Windows.Forms.PictureBox();
            this.item_double_shot = new System.Windows.Forms.PictureBox();
            this.item_spirit_ball = new System.Windows.Forms.PictureBox();
            this.item_rosary = new System.Windows.Forms.PictureBox();
            this.item_roast = new System.Windows.Forms.PictureBox();
            this.item_money_bag = new System.Windows.Forms.PictureBox();
            this.item_big_heart = new System.Windows.Forms.PictureBox();
            this.item_small_heart = new System.Windows.Forms.PictureBox();
            this.item_morning_star = new System.Windows.Forms.PictureBox();
            this.item_holy_water = new System.Windows.Forms.PictureBox();
            this.item_axe = new System.Windows.Forms.PictureBox();
            this.item_knife = new System.Windows.Forms.PictureBox();
            this.item_stop_watch = new System.Windows.Forms.PictureBox();
            this.item_cross = new System.Windows.Forms.PictureBox();
            this.gbProp = new System.Windows.Forms.GroupBox();
            this.tbVar3 = new System.Windows.Forms.TextBox();
            this.lbVar3 = new System.Windows.Forms.Label();
            this.tbVar2 = new System.Windows.Forms.TextBox();
            this.lbVar2 = new System.Windows.Forms.Label();
            this.tbVar1 = new System.Windows.Forms.TextBox();
            this.lbVar1 = new System.Windows.Forms.Label();
            this.ptbCurrentItem = new System.Windows.Forms.PictureBox();
            this.ptbCurrentObj = new System.Windows.Forms.PictureBox();
            this.pnCommand.SuspendLayout();
            this.tcObjects.SuspendLayout();
            this.tpGround.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ground_death)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_go_in_castle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_hidden_brick)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_stair_down)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_stair_up)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_brick)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_trap)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_moving_brick)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_lockdoor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_opendoor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_firetower)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_firecandle)).BeginInit();
            this.tpEnemy.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_ghost)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_bonepillar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_medusahead)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_spearguard)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_merman)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_bat)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_panther)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_zombie)).BeginInit();
            this.tpBoss.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.simon)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.boss_medusa)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.boss_bat)).BeginInit();
            this.tpItem.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.item_none)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_double_shot)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_spirit_ball)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_rosary)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_roast)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_money_bag)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_big_heart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_small_heart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_morning_star)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_holy_water)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_axe)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_knife)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_stop_watch)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_cross)).BeginInit();
            this.gbProp.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ptbCurrentItem)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptbCurrentObj)).BeginInit();
            this.SuspendLayout();
            // 
            // btNewMap
            // 
            this.btNewMap.Location = new System.Drawing.Point(10, 8);
            this.btNewMap.Name = "btNewMap";
            this.btNewMap.Size = new System.Drawing.Size(91, 40);
            this.btNewMap.TabIndex = 0;
            this.btNewMap.Text = "New";
            this.btNewMap.UseVisualStyleBackColor = true;
            this.btNewMap.Click += new System.EventHandler(this.btNewMap_Click);
            // 
            // btLoad
            // 
            this.btLoad.Location = new System.Drawing.Point(10, 54);
            this.btLoad.Name = "btLoad";
            this.btLoad.Size = new System.Drawing.Size(91, 40);
            this.btLoad.TabIndex = 1;
            this.btLoad.Text = "Load";
            this.btLoad.UseVisualStyleBackColor = true;
            this.btLoad.Click += new System.EventHandler(this.btLoad_Click);
            // 
            // btSave
            // 
            this.btSave.Location = new System.Drawing.Point(10, 100);
            this.btSave.Name = "btSave";
            this.btSave.Size = new System.Drawing.Size(91, 40);
            this.btSave.TabIndex = 2;
            this.btSave.Text = "Save";
            this.btSave.UseVisualStyleBackColor = true;
            this.btSave.Click += new System.EventHandler(this.btSave_Click);
            // 
            // pnCommand
            // 
            this.pnCommand.Controls.Add(this.label6);
            this.pnCommand.Controls.Add(this.label5);
            this.pnCommand.Controls.Add(this.lbCurrentPos);
            this.pnCommand.Controls.Add(this.tbStateY);
            this.pnCommand.Controls.Add(this.label3);
            this.pnCommand.Controls.Add(this.label4);
            this.pnCommand.Controls.Add(this.tbStateX);
            this.pnCommand.Controls.Add(this.cbbState);
            this.pnCommand.Controls.Add(this.btAddState);
            this.pnCommand.Controls.Add(this.cbRandomItm);
            this.pnCommand.Controls.Add(this.btClear);
            this.pnCommand.Controls.Add(this.cbAutoAlign);
            this.pnCommand.Controls.Add(this.cbShowTiles);
            this.pnCommand.Controls.Add(this.btNewMap);
            this.pnCommand.Controls.Add(this.btSave);
            this.pnCommand.Controls.Add(this.btLoad);
            this.pnCommand.Dock = System.Windows.Forms.DockStyle.Left;
            this.pnCommand.Location = new System.Drawing.Point(0, 0);
            this.pnCommand.Name = "pnCommand";
            this.pnCommand.Size = new System.Drawing.Size(111, 560);
            this.pnCommand.TabIndex = 3;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label6.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.label6.Location = new System.Drawing.Point(7, 377);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(80, 30);
            this.label6.TabIndex = 37;
            this.label6.Text = "Hold SHIFT\r\nto delete";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(163)));
            this.label5.ForeColor = System.Drawing.Color.Green;
            this.label5.Location = new System.Drawing.Point(7, 337);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(76, 30);
            this.label5.TabIndex = 36;
            this.label5.Text = "Hold CTRL\r\nto add";
            // 
            // lbCurrentPos
            // 
            this.lbCurrentPos.AutoSize = true;
            this.lbCurrentPos.Location = new System.Drawing.Point(12, 295);
            this.lbCurrentPos.Name = "lbCurrentPos";
            this.lbCurrentPos.Size = new System.Drawing.Size(23, 26);
            this.lbCurrentPos.TabIndex = 35;
            this.lbCurrentPos.Text = "X:  \r\nY:";
            // 
            // tbStateY
            // 
            this.tbStateY.Location = new System.Drawing.Point(61, 265);
            this.tbStateY.Name = "tbStateY";
            this.tbStateY.Size = new System.Drawing.Size(40, 20);
            this.tbStateY.TabIndex = 34;
            this.tbStateY.Leave += new System.EventHandler(this.tbState_Leave);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 268);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(32, 13);
            this.label3.TabIndex = 33;
            this.label3.Text = "Row:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(9, 243);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(25, 13);
            this.label4.TabIndex = 32;
            this.label4.Text = "Col:";
            // 
            // tbStateX
            // 
            this.tbStateX.Location = new System.Drawing.Point(61, 240);
            this.tbStateX.Name = "tbStateX";
            this.tbStateX.Size = new System.Drawing.Size(40, 20);
            this.tbStateX.TabIndex = 31;
            this.tbStateX.Leave += new System.EventHandler(this.tbState_Leave);
            // 
            // cbbState
            // 
            this.cbbState.FormattingEnabled = true;
            this.cbbState.Location = new System.Drawing.Point(12, 213);
            this.cbbState.Name = "cbbState";
            this.cbbState.Size = new System.Drawing.Size(89, 21);
            this.cbbState.TabIndex = 9;
            this.cbbState.SelectedIndexChanged += new System.EventHandler(this.cbbState_SelectedIndexChanged);
            // 
            // btAddState
            // 
            this.btAddState.Location = new System.Drawing.Point(10, 167);
            this.btAddState.Name = "btAddState";
            this.btAddState.Size = new System.Drawing.Size(91, 40);
            this.btAddState.TabIndex = 8;
            this.btAddState.Text = "Add State";
            this.btAddState.UseVisualStyleBackColor = true;
            this.btAddState.Click += new System.EventHandler(this.btAddState_Click);
            // 
            // cbRandomItm
            // 
            this.cbRandomItm.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.cbRandomItm.AutoSize = true;
            this.cbRandomItm.Checked = true;
            this.cbRandomItm.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbRandomItm.Location = new System.Drawing.Point(12, 472);
            this.cbRandomItm.Name = "cbRandomItm";
            this.cbRandomItm.Size = new System.Drawing.Size(89, 17);
            this.cbRandomItm.TabIndex = 7;
            this.cbRandomItm.Text = "Random Item";
            this.cbRandomItm.UseVisualStyleBackColor = true;
            // 
            // btClear
            // 
            this.btClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btClear.Location = new System.Drawing.Point(10, 495);
            this.btClear.Name = "btClear";
            this.btClear.Size = new System.Drawing.Size(91, 49);
            this.btClear.TabIndex = 6;
            this.btClear.Text = "Clear";
            this.btClear.UseVisualStyleBackColor = true;
            this.btClear.Click += new System.EventHandler(this.btClear_Click);
            // 
            // cbAutoAlign
            // 
            this.cbAutoAlign.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.cbAutoAlign.AutoSize = true;
            this.cbAutoAlign.Checked = true;
            this.cbAutoAlign.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbAutoAlign.Location = new System.Drawing.Point(12, 448);
            this.cbAutoAlign.Name = "cbAutoAlign";
            this.cbAutoAlign.Size = new System.Drawing.Size(74, 17);
            this.cbAutoAlign.TabIndex = 5;
            this.cbAutoAlign.Text = "Auto Align";
            this.cbAutoAlign.UseVisualStyleBackColor = true;
            // 
            // cbShowTiles
            // 
            this.cbShowTiles.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.cbShowTiles.AutoSize = true;
            this.cbShowTiles.Checked = true;
            this.cbShowTiles.CheckState = System.Windows.Forms.CheckState.Checked;
            this.cbShowTiles.Location = new System.Drawing.Point(12, 425);
            this.cbShowTiles.Name = "cbShowTiles";
            this.cbShowTiles.Size = new System.Drawing.Size(78, 17);
            this.cbShowTiles.TabIndex = 4;
            this.cbShowTiles.Text = "Show Tiles";
            this.cbShowTiles.UseVisualStyleBackColor = true;
            this.cbShowTiles.CheckedChanged += new System.EventHandler(this.cbShowTiles_CheckedChanged);
            // 
            // tbPosY
            // 
            this.tbPosY.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbPosY.Location = new System.Drawing.Point(59, 50);
            this.tbPosY.Name = "tbPosY";
            this.tbPosY.Size = new System.Drawing.Size(40, 20);
            this.tbPosY.TabIndex = 30;
            this.tbPosY.Leave += new System.EventHandler(this.tbProp_Leave);
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(21, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 29;
            this.label2.Text = "PosY:";
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 28;
            this.label1.Text = "PosX:";
            // 
            // tbPosX
            // 
            this.tbPosX.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbPosX.Location = new System.Drawing.Point(59, 19);
            this.tbPosX.Name = "tbPosX";
            this.tbPosX.Size = new System.Drawing.Size(40, 20);
            this.tbPosX.TabIndex = 27;
            this.tbPosX.Leave += new System.EventHandler(this.tbProp_Leave);
            // 
            // pnMapViewer
            // 
            this.pnMapViewer.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pnMapViewer.AutoScroll = true;
            this.pnMapViewer.BackColor = System.Drawing.Color.Black;
            this.pnMapViewer.Location = new System.Drawing.Point(117, 8);
            this.pnMapViewer.Name = "pnMapViewer";
            this.pnMapViewer.Size = new System.Drawing.Size(891, 389);
            this.pnMapViewer.TabIndex = 4;
            this.pnMapViewer.Scroll += new System.Windows.Forms.ScrollEventHandler(this.pnMapViewer_Scroll);
            // 
            // tcObjects
            // 
            this.tcObjects.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tcObjects.Controls.Add(this.tpGround);
            this.tcObjects.Controls.Add(this.tpEnemy);
            this.tcObjects.Controls.Add(this.tpBoss);
            this.tcObjects.Controls.Add(this.tpItem);
            this.tcObjects.Location = new System.Drawing.Point(118, 403);
            this.tcObjects.Name = "tcObjects";
            this.tcObjects.SelectedIndex = 0;
            this.tcObjects.Size = new System.Drawing.Size(446, 150);
            this.tcObjects.TabIndex = 5;
            // 
            // tpGround
            // 
            this.tpGround.Controls.Add(this.ground_death);
            this.tpGround.Controls.Add(this.ground_go_in_castle);
            this.tpGround.Controls.Add(this.ground_hidden_brick);
            this.tpGround.Controls.Add(this.ground_stair_down);
            this.tpGround.Controls.Add(this.ground_stair_up);
            this.tpGround.Controls.Add(this.ground_brick);
            this.tpGround.Controls.Add(this.ground_trap);
            this.tpGround.Controls.Add(this.ground_moving_brick);
            this.tpGround.Controls.Add(this.ground_lockdoor);
            this.tpGround.Controls.Add(this.ground_opendoor);
            this.tpGround.Controls.Add(this.ground_firetower);
            this.tpGround.Controls.Add(this.ground_firecandle);
            this.tpGround.Location = new System.Drawing.Point(4, 22);
            this.tpGround.Name = "tpGround";
            this.tpGround.Padding = new System.Windows.Forms.Padding(3);
            this.tpGround.Size = new System.Drawing.Size(438, 124);
            this.tpGround.TabIndex = 0;
            this.tpGround.Text = "Ground";
            this.tpGround.UseVisualStyleBackColor = true;
            // 
            // ground_death
            // 
            this.ground_death.Image = global::MapEditor.Properties.Resources.ground_death;
            this.ground_death.Location = new System.Drawing.Point(164, 16);
            this.ground_death.Name = "ground_death";
            this.ground_death.Size = new System.Drawing.Size(42, 42);
            this.ground_death.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_death.TabIndex = 16;
            this.ground_death.TabStop = false;
            // 
            // ground_go_in_castle
            // 
            this.ground_go_in_castle.Image = global::MapEditor.Properties.Resources.ground_go_in_castle;
            this.ground_go_in_castle.Location = new System.Drawing.Point(233, 16);
            this.ground_go_in_castle.Name = "ground_go_in_castle";
            this.ground_go_in_castle.Size = new System.Drawing.Size(42, 74);
            this.ground_go_in_castle.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_go_in_castle.TabIndex = 15;
            this.ground_go_in_castle.TabStop = false;
            // 
            // ground_hidden_brick
            // 
            this.ground_hidden_brick.Image = global::MapEditor.Properties.Resources.ground_hidden_brick;
            this.ground_hidden_brick.Location = new System.Drawing.Point(62, 16);
            this.ground_hidden_brick.Name = "ground_hidden_brick";
            this.ground_hidden_brick.Size = new System.Drawing.Size(42, 42);
            this.ground_hidden_brick.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_hidden_brick.TabIndex = 14;
            this.ground_hidden_brick.TabStop = false;
            // 
            // ground_stair_down
            // 
            this.ground_stair_down.Image = global::MapEditor.Properties.Resources.ground_stair_down;
            this.ground_stair_down.Location = new System.Drawing.Point(62, 74);
            this.ground_stair_down.Name = "ground_stair_down";
            this.ground_stair_down.Size = new System.Drawing.Size(42, 42);
            this.ground_stair_down.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_stair_down.TabIndex = 13;
            this.ground_stair_down.TabStop = false;
            // 
            // ground_stair_up
            // 
            this.ground_stair_up.Image = global::MapEditor.Properties.Resources.ground_stair_up;
            this.ground_stair_up.Location = new System.Drawing.Point(11, 74);
            this.ground_stair_up.Name = "ground_stair_up";
            this.ground_stair_up.Size = new System.Drawing.Size(42, 42);
            this.ground_stair_up.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_stair_up.TabIndex = 12;
            this.ground_stair_up.TabStop = false;
            // 
            // ground_brick
            // 
            this.ground_brick.Image = global::MapEditor.Properties.Resources.ground_brick;
            this.ground_brick.Location = new System.Drawing.Point(11, 16);
            this.ground_brick.Name = "ground_brick";
            this.ground_brick.Size = new System.Drawing.Size(42, 42);
            this.ground_brick.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_brick.TabIndex = 11;
            this.ground_brick.TabStop = false;
            // 
            // ground_trap
            // 
            this.ground_trap.Image = global::MapEditor.Properties.Resources.ground_trap;
            this.ground_trap.Location = new System.Drawing.Point(113, 72);
            this.ground_trap.Name = "ground_trap";
            this.ground_trap.Size = new System.Drawing.Size(74, 46);
            this.ground_trap.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_trap.TabIndex = 10;
            this.ground_trap.TabStop = false;
            // 
            // ground_moving_brick
            // 
            this.ground_moving_brick.Image = global::MapEditor.Properties.Resources.ground_moving_brick;
            this.ground_moving_brick.Location = new System.Drawing.Point(258, 92);
            this.ground_moving_brick.Name = "ground_moving_brick";
            this.ground_moving_brick.Size = new System.Drawing.Size(74, 26);
            this.ground_moving_brick.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_moving_brick.TabIndex = 7;
            this.ground_moving_brick.TabStop = false;
            // 
            // ground_lockdoor
            // 
            this.ground_lockdoor.Image = global::MapEditor.Properties.Resources.ground_lockdoor;
            this.ground_lockdoor.Location = new System.Drawing.Point(338, 16);
            this.ground_lockdoor.Name = "ground_lockdoor";
            this.ground_lockdoor.Size = new System.Drawing.Size(42, 100);
            this.ground_lockdoor.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_lockdoor.TabIndex = 6;
            this.ground_lockdoor.TabStop = false;
            // 
            // ground_opendoor
            // 
            this.ground_opendoor.Image = global::MapEditor.Properties.Resources.ground_opendoor;
            this.ground_opendoor.Location = new System.Drawing.Point(387, 16);
            this.ground_opendoor.Name = "ground_opendoor";
            this.ground_opendoor.Size = new System.Drawing.Size(42, 100);
            this.ground_opendoor.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_opendoor.TabIndex = 5;
            this.ground_opendoor.TabStop = false;
            // 
            // ground_firetower
            // 
            this.ground_firetower.Image = global::MapEditor.Properties.Resources.ground_firetower;
            this.ground_firetower.Location = new System.Drawing.Point(290, 16);
            this.ground_firetower.Name = "ground_firetower";
            this.ground_firetower.Size = new System.Drawing.Size(42, 74);
            this.ground_firetower.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_firetower.TabIndex = 4;
            this.ground_firetower.TabStop = false;
            // 
            // ground_firecandle
            // 
            this.ground_firecandle.Image = global::MapEditor.Properties.Resources.ground_firecandle;
            this.ground_firecandle.Location = new System.Drawing.Point(113, 16);
            this.ground_firecandle.Name = "ground_firecandle";
            this.ground_firecandle.Size = new System.Drawing.Size(42, 42);
            this.ground_firecandle.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ground_firecandle.TabIndex = 3;
            this.ground_firecandle.TabStop = false;
            // 
            // tpEnemy
            // 
            this.tpEnemy.Controls.Add(this.enemy_ghost);
            this.tpEnemy.Controls.Add(this.enemy_bonepillar);
            this.tpEnemy.Controls.Add(this.enemy_medusahead);
            this.tpEnemy.Controls.Add(this.enemy_spearguard);
            this.tpEnemy.Controls.Add(this.enemy_merman);
            this.tpEnemy.Controls.Add(this.enemy_bat);
            this.tpEnemy.Controls.Add(this.enemy_panther);
            this.tpEnemy.Controls.Add(this.enemy_zombie);
            this.tpEnemy.Location = new System.Drawing.Point(4, 22);
            this.tpEnemy.Name = "tpEnemy";
            this.tpEnemy.Padding = new System.Windows.Forms.Padding(3);
            this.tpEnemy.Size = new System.Drawing.Size(438, 124);
            this.tpEnemy.TabIndex = 1;
            this.tpEnemy.Text = "Enemy";
            this.tpEnemy.UseVisualStyleBackColor = true;
            // 
            // enemy_ghost
            // 
            this.enemy_ghost.Image = global::MapEditor.Properties.Resources.enemy_ghost;
            this.enemy_ghost.Location = new System.Drawing.Point(227, 62);
            this.enemy_ghost.Name = "enemy_ghost";
            this.enemy_ghost.Size = new System.Drawing.Size(42, 42);
            this.enemy_ghost.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_ghost.TabIndex = 8;
            this.enemy_ghost.TabStop = false;
            // 
            // enemy_bonepillar
            // 
            this.enemy_bonepillar.Image = global::MapEditor.Properties.Resources.enemy_bonepillar;
            this.enemy_bonepillar.Location = new System.Drawing.Point(170, 12);
            this.enemy_bonepillar.Name = "enemy_bonepillar";
            this.enemy_bonepillar.Size = new System.Drawing.Size(42, 74);
            this.enemy_bonepillar.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_bonepillar.TabIndex = 7;
            this.enemy_bonepillar.TabStop = false;
            // 
            // enemy_medusahead
            // 
            this.enemy_medusahead.Image = global::MapEditor.Properties.Resources.enemy_medusahead;
            this.enemy_medusahead.Location = new System.Drawing.Point(283, 12);
            this.enemy_medusahead.Name = "enemy_medusahead";
            this.enemy_medusahead.Size = new System.Drawing.Size(42, 42);
            this.enemy_medusahead.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_medusahead.TabIndex = 6;
            this.enemy_medusahead.TabStop = false;
            // 
            // enemy_spearguard
            // 
            this.enemy_spearguard.Image = global::MapEditor.Properties.Resources.enemy_spearguard;
            this.enemy_spearguard.Location = new System.Drawing.Point(117, 12);
            this.enemy_spearguard.Name = "enemy_spearguard";
            this.enemy_spearguard.Size = new System.Drawing.Size(42, 74);
            this.enemy_spearguard.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_spearguard.TabIndex = 5;
            this.enemy_spearguard.TabStop = false;
            // 
            // enemy_merman
            // 
            this.enemy_merman.Image = global::MapEditor.Properties.Resources.enemy_merman;
            this.enemy_merman.Location = new System.Drawing.Point(63, 12);
            this.enemy_merman.Name = "enemy_merman";
            this.enemy_merman.Size = new System.Drawing.Size(42, 74);
            this.enemy_merman.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_merman.TabIndex = 4;
            this.enemy_merman.TabStop = false;
            // 
            // enemy_bat
            // 
            this.enemy_bat.Image = global::MapEditor.Properties.Resources.enemy_bat;
            this.enemy_bat.Location = new System.Drawing.Point(227, 12);
            this.enemy_bat.Name = "enemy_bat";
            this.enemy_bat.Size = new System.Drawing.Size(42, 42);
            this.enemy_bat.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_bat.TabIndex = 3;
            this.enemy_bat.TabStop = false;
            // 
            // enemy_panther
            // 
            this.enemy_panther.Image = global::MapEditor.Properties.Resources.enemy_panther;
            this.enemy_panther.Location = new System.Drawing.Point(283, 62);
            this.enemy_panther.Name = "enemy_panther";
            this.enemy_panther.Size = new System.Drawing.Size(58, 42);
            this.enemy_panther.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_panther.TabIndex = 2;
            this.enemy_panther.TabStop = false;
            // 
            // enemy_zombie
            // 
            this.enemy_zombie.Image = global::MapEditor.Properties.Resources.enemy_zombie;
            this.enemy_zombie.Location = new System.Drawing.Point(12, 12);
            this.enemy_zombie.Name = "enemy_zombie";
            this.enemy_zombie.Size = new System.Drawing.Size(42, 74);
            this.enemy_zombie.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.enemy_zombie.TabIndex = 1;
            this.enemy_zombie.TabStop = false;
            // 
            // tpBoss
            // 
            this.tpBoss.Controls.Add(this.simon);
            this.tpBoss.Controls.Add(this.boss_medusa);
            this.tpBoss.Controls.Add(this.boss_bat);
            this.tpBoss.Location = new System.Drawing.Point(4, 22);
            this.tpBoss.Name = "tpBoss";
            this.tpBoss.Padding = new System.Windows.Forms.Padding(3);
            this.tpBoss.Size = new System.Drawing.Size(438, 124);
            this.tpBoss.TabIndex = 2;
            this.tpBoss.Text = "Boss";
            this.tpBoss.UseVisualStyleBackColor = true;
            // 
            // simon
            // 
            this.simon.Image = global::MapEditor.Properties.Resources.simon;
            this.simon.Location = new System.Drawing.Point(190, 12);
            this.simon.Name = "simon";
            this.simon.Size = new System.Drawing.Size(42, 74);
            this.simon.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.simon.TabIndex = 4;
            this.simon.TabStop = false;
            // 
            // boss_medusa
            // 
            this.boss_medusa.Image = global::MapEditor.Properties.Resources.boss_medusa;
            this.boss_medusa.Location = new System.Drawing.Point(100, 12);
            this.boss_medusa.Name = "boss_medusa";
            this.boss_medusa.Size = new System.Drawing.Size(74, 74);
            this.boss_medusa.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.boss_medusa.TabIndex = 3;
            this.boss_medusa.TabStop = false;
            // 
            // boss_bat
            // 
            this.boss_bat.Image = global::MapEditor.Properties.Resources.boss_bat;
            this.boss_bat.Location = new System.Drawing.Point(12, 12);
            this.boss_bat.Name = "boss_bat";
            this.boss_bat.Size = new System.Drawing.Size(74, 60);
            this.boss_bat.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.boss_bat.TabIndex = 2;
            this.boss_bat.TabStop = false;
            // 
            // tpItem
            // 
            this.tpItem.Controls.Add(this.item_none);
            this.tpItem.Controls.Add(this.item_double_shot);
            this.tpItem.Controls.Add(this.item_spirit_ball);
            this.tpItem.Controls.Add(this.item_rosary);
            this.tpItem.Controls.Add(this.item_roast);
            this.tpItem.Controls.Add(this.item_money_bag);
            this.tpItem.Controls.Add(this.item_big_heart);
            this.tpItem.Controls.Add(this.item_small_heart);
            this.tpItem.Controls.Add(this.item_morning_star);
            this.tpItem.Controls.Add(this.item_holy_water);
            this.tpItem.Controls.Add(this.item_axe);
            this.tpItem.Controls.Add(this.item_knife);
            this.tpItem.Controls.Add(this.item_stop_watch);
            this.tpItem.Controls.Add(this.item_cross);
            this.tpItem.Location = new System.Drawing.Point(4, 22);
            this.tpItem.Name = "tpItem";
            this.tpItem.Padding = new System.Windows.Forms.Padding(3);
            this.tpItem.Size = new System.Drawing.Size(438, 124);
            this.tpItem.TabIndex = 3;
            this.tpItem.Text = "Item";
            this.tpItem.UseVisualStyleBackColor = true;
            // 
            // item_none
            // 
            this.item_none.Image = global::MapEditor.Properties.Resources.item_none;
            this.item_none.Location = new System.Drawing.Point(302, 63);
            this.item_none.Name = "item_none";
            this.item_none.Size = new System.Drawing.Size(42, 42);
            this.item_none.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_none.TabIndex = 17;
            this.item_none.TabStop = false;
            // 
            // item_double_shot
            // 
            this.item_double_shot.BackColor = System.Drawing.Color.Transparent;
            this.item_double_shot.Image = global::MapEditor.Properties.Resources.item_double_shot;
            this.item_double_shot.Location = new System.Drawing.Point(302, 12);
            this.item_double_shot.Name = "item_double_shot";
            this.item_double_shot.Size = new System.Drawing.Size(42, 42);
            this.item_double_shot.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_double_shot.TabIndex = 16;
            this.item_double_shot.TabStop = false;
            // 
            // item_spirit_ball
            // 
            this.item_spirit_ball.Image = global::MapEditor.Properties.Resources.item_spirit_ball;
            this.item_spirit_ball.Location = new System.Drawing.Point(253, 63);
            this.item_spirit_ball.Name = "item_spirit_ball";
            this.item_spirit_ball.Size = new System.Drawing.Size(42, 42);
            this.item_spirit_ball.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_spirit_ball.TabIndex = 15;
            this.item_spirit_ball.TabStop = false;
            // 
            // item_rosary
            // 
            this.item_rosary.Image = global::MapEditor.Properties.Resources.item_rosary;
            this.item_rosary.Location = new System.Drawing.Point(205, 63);
            this.item_rosary.Name = "item_rosary";
            this.item_rosary.Size = new System.Drawing.Size(42, 42);
            this.item_rosary.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_rosary.TabIndex = 14;
            this.item_rosary.TabStop = false;
            // 
            // item_roast
            // 
            this.item_roast.Image = global::MapEditor.Properties.Resources.item_roast;
            this.item_roast.Location = new System.Drawing.Point(157, 63);
            this.item_roast.Name = "item_roast";
            this.item_roast.Size = new System.Drawing.Size(42, 42);
            this.item_roast.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_roast.TabIndex = 13;
            this.item_roast.TabStop = false;
            // 
            // item_money_bag
            // 
            this.item_money_bag.Image = global::MapEditor.Properties.Resources.item_money_bag;
            this.item_money_bag.Location = new System.Drawing.Point(109, 63);
            this.item_money_bag.Name = "item_money_bag";
            this.item_money_bag.Size = new System.Drawing.Size(42, 42);
            this.item_money_bag.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_money_bag.TabIndex = 12;
            this.item_money_bag.TabStop = false;
            // 
            // item_big_heart
            // 
            this.item_big_heart.Image = global::MapEditor.Properties.Resources.item_big_heart;
            this.item_big_heart.Location = new System.Drawing.Point(60, 63);
            this.item_big_heart.Name = "item_big_heart";
            this.item_big_heart.Size = new System.Drawing.Size(42, 42);
            this.item_big_heart.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_big_heart.TabIndex = 11;
            this.item_big_heart.TabStop = false;
            // 
            // item_small_heart
            // 
            this.item_small_heart.Image = global::MapEditor.Properties.Resources.item_small_heart;
            this.item_small_heart.Location = new System.Drawing.Point(12, 63);
            this.item_small_heart.Name = "item_small_heart";
            this.item_small_heart.Size = new System.Drawing.Size(42, 42);
            this.item_small_heart.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_small_heart.TabIndex = 10;
            this.item_small_heart.TabStop = false;
            // 
            // item_morning_star
            // 
            this.item_morning_star.Image = global::MapEditor.Properties.Resources.item_morning_star;
            this.item_morning_star.Location = new System.Drawing.Point(253, 12);
            this.item_morning_star.Name = "item_morning_star";
            this.item_morning_star.Size = new System.Drawing.Size(42, 42);
            this.item_morning_star.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_morning_star.TabIndex = 9;
            this.item_morning_star.TabStop = false;
            // 
            // item_holy_water
            // 
            this.item_holy_water.Image = global::MapEditor.Properties.Resources.item_holy_water;
            this.item_holy_water.Location = new System.Drawing.Point(157, 13);
            this.item_holy_water.Name = "item_holy_water";
            this.item_holy_water.Size = new System.Drawing.Size(42, 42);
            this.item_holy_water.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_holy_water.TabIndex = 8;
            this.item_holy_water.TabStop = false;
            // 
            // item_axe
            // 
            this.item_axe.Image = global::MapEditor.Properties.Resources.item_axe;
            this.item_axe.Location = new System.Drawing.Point(12, 12);
            this.item_axe.Name = "item_axe";
            this.item_axe.Size = new System.Drawing.Size(42, 42);
            this.item_axe.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_axe.TabIndex = 7;
            this.item_axe.TabStop = false;
            // 
            // item_knife
            // 
            this.item_knife.Image = global::MapEditor.Properties.Resources.item_knife;
            this.item_knife.Location = new System.Drawing.Point(109, 12);
            this.item_knife.Name = "item_knife";
            this.item_knife.Size = new System.Drawing.Size(42, 42);
            this.item_knife.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_knife.TabIndex = 6;
            this.item_knife.TabStop = false;
            // 
            // item_stop_watch
            // 
            this.item_stop_watch.Image = global::MapEditor.Properties.Resources.item_stop_watch;
            this.item_stop_watch.Location = new System.Drawing.Point(205, 13);
            this.item_stop_watch.Name = "item_stop_watch";
            this.item_stop_watch.Size = new System.Drawing.Size(42, 42);
            this.item_stop_watch.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_stop_watch.TabIndex = 5;
            this.item_stop_watch.TabStop = false;
            // 
            // item_cross
            // 
            this.item_cross.Image = global::MapEditor.Properties.Resources.item_cross;
            this.item_cross.Location = new System.Drawing.Point(60, 12);
            this.item_cross.Name = "item_cross";
            this.item_cross.Size = new System.Drawing.Size(42, 42);
            this.item_cross.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.item_cross.TabIndex = 4;
            this.item_cross.TabStop = false;
            // 
            // gbProp
            // 
            this.gbProp.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.gbProp.Controls.Add(this.tbVar3);
            this.gbProp.Controls.Add(this.lbVar3);
            this.gbProp.Controls.Add(this.tbVar2);
            this.gbProp.Controls.Add(this.lbVar2);
            this.gbProp.Controls.Add(this.tbVar1);
            this.gbProp.Controls.Add(this.lbVar1);
            this.gbProp.Controls.Add(this.tbPosX);
            this.gbProp.Controls.Add(this.label1);
            this.gbProp.Controls.Add(this.tbPosY);
            this.gbProp.Controls.Add(this.label2);
            this.gbProp.Location = new System.Drawing.Point(658, 419);
            this.gbProp.Name = "gbProp";
            this.gbProp.Size = new System.Drawing.Size(350, 134);
            this.gbProp.TabIndex = 32;
            this.gbProp.TabStop = false;
            this.gbProp.Text = "Properties";
            // 
            // tbVar3
            // 
            this.tbVar3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbVar3.Location = new System.Drawing.Point(222, 83);
            this.tbVar3.Name = "tbVar3";
            this.tbVar3.Size = new System.Drawing.Size(42, 20);
            this.tbVar3.TabIndex = 36;
            this.tbVar3.Text = "1";
            this.tbVar3.Leave += new System.EventHandler(this.tbProp_Leave);
            // 
            // lbVar3
            // 
            this.lbVar3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lbVar3.AutoSize = true;
            this.lbVar3.Location = new System.Drawing.Point(157, 86);
            this.lbVar3.Name = "lbVar3";
            this.lbVar3.Size = new System.Drawing.Size(35, 13);
            this.lbVar3.TabIndex = 35;
            this.lbVar3.Text = "PosX:";
            // 
            // tbVar2
            // 
            this.tbVar2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbVar2.Location = new System.Drawing.Point(222, 51);
            this.tbVar2.Name = "tbVar2";
            this.tbVar2.Size = new System.Drawing.Size(42, 20);
            this.tbVar2.TabIndex = 34;
            this.tbVar2.Text = "1";
            this.tbVar2.Leave += new System.EventHandler(this.tbProp_Leave);
            // 
            // lbVar2
            // 
            this.lbVar2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lbVar2.AutoSize = true;
            this.lbVar2.Location = new System.Drawing.Point(157, 54);
            this.lbVar2.Name = "lbVar2";
            this.lbVar2.Size = new System.Drawing.Size(35, 13);
            this.lbVar2.TabIndex = 33;
            this.lbVar2.Text = "PosX:";
            // 
            // tbVar1
            // 
            this.tbVar1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbVar1.Location = new System.Drawing.Point(222, 19);
            this.tbVar1.Name = "tbVar1";
            this.tbVar1.Size = new System.Drawing.Size(42, 20);
            this.tbVar1.TabIndex = 32;
            this.tbVar1.Text = "1";
            this.tbVar1.Leave += new System.EventHandler(this.tbProp_Leave);
            // 
            // lbVar1
            // 
            this.lbVar1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lbVar1.AutoSize = true;
            this.lbVar1.Location = new System.Drawing.Point(157, 22);
            this.lbVar1.Name = "lbVar1";
            this.lbVar1.Size = new System.Drawing.Size(35, 13);
            this.lbVar1.TabIndex = 31;
            this.lbVar1.Text = "PosX:";
            // 
            // ptbCurrentItem
            // 
            this.ptbCurrentItem.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.ptbCurrentItem.Location = new System.Drawing.Point(580, 514);
            this.ptbCurrentItem.Name = "ptbCurrentItem";
            this.ptbCurrentItem.Size = new System.Drawing.Size(62, 32);
            this.ptbCurrentItem.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ptbCurrentItem.TabIndex = 31;
            this.ptbCurrentItem.TabStop = false;
            // 
            // ptbCurrentObj
            // 
            this.ptbCurrentObj.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.ptbCurrentObj.Location = new System.Drawing.Point(580, 425);
            this.ptbCurrentObj.Name = "ptbCurrentObj";
            this.ptbCurrentObj.Size = new System.Drawing.Size(62, 83);
            this.ptbCurrentObj.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ptbCurrentObj.TabIndex = 26;
            this.ptbCurrentObj.TabStop = false;
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1014, 560);
            this.Controls.Add(this.gbProp);
            this.Controls.Add(this.ptbCurrentItem);
            this.Controls.Add(this.tcObjects);
            this.Controls.Add(this.pnMapViewer);
            this.Controls.Add(this.pnCommand);
            this.Controls.Add(this.ptbCurrentObj);
            this.KeyPreview = true;
            this.Name = "MapEditor";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Castle Vania MapEditor";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MapEditor_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.MapEditor_KeyUp);
            this.pnCommand.ResumeLayout(false);
            this.pnCommand.PerformLayout();
            this.tcObjects.ResumeLayout(false);
            this.tpGround.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ground_death)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_go_in_castle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_hidden_brick)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_stair_down)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_stair_up)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_brick)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_trap)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_moving_brick)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_lockdoor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_opendoor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_firetower)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ground_firecandle)).EndInit();
            this.tpEnemy.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.enemy_ghost)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_bonepillar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_medusahead)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_spearguard)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_merman)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_bat)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_panther)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.enemy_zombie)).EndInit();
            this.tpBoss.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.simon)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.boss_medusa)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.boss_bat)).EndInit();
            this.tpItem.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.item_none)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_double_shot)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_spirit_ball)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_rosary)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_roast)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_money_bag)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_big_heart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_small_heart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_morning_star)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_holy_water)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_axe)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_knife)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_stop_watch)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.item_cross)).EndInit();
            this.gbProp.ResumeLayout(false);
            this.gbProp.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ptbCurrentItem)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptbCurrentObj)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btNewMap;
        private System.Windows.Forms.Button btLoad;
        private System.Windows.Forms.Button btSave;
        private System.Windows.Forms.Panel pnCommand;
        private System.Windows.Forms.CheckBox cbShowTiles;
        private System.Windows.Forms.Button btClear;
        private System.Windows.Forms.CheckBox cbAutoAlign;
        private System.Windows.Forms.Panel pnMapViewer;
        private System.Windows.Forms.TextBox tbPosY;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbPosX;
        private System.Windows.Forms.PictureBox ptbCurrentObj;
        private System.Windows.Forms.TabControl tcObjects;
        private System.Windows.Forms.TabPage tpGround;
        private System.Windows.Forms.TabPage tpEnemy;
        private System.Windows.Forms.TabPage tpBoss;
        private System.Windows.Forms.PictureBox ground_trap;
        private System.Windows.Forms.PictureBox ground_moving_brick;
        private System.Windows.Forms.PictureBox ground_lockdoor;
        private System.Windows.Forms.PictureBox ground_opendoor;
        private System.Windows.Forms.PictureBox ground_firetower;
        private System.Windows.Forms.PictureBox ground_firecandle;
        private System.Windows.Forms.PictureBox enemy_ghost;
        private System.Windows.Forms.PictureBox enemy_bonepillar;
        private System.Windows.Forms.PictureBox enemy_medusahead;
        private System.Windows.Forms.PictureBox enemy_spearguard;
        private System.Windows.Forms.PictureBox enemy_merman;
        private System.Windows.Forms.PictureBox enemy_bat;
        private System.Windows.Forms.PictureBox enemy_panther;
        private System.Windows.Forms.PictureBox enemy_zombie;
        private System.Windows.Forms.PictureBox boss_bat;
        private System.Windows.Forms.PictureBox simon;
        private System.Windows.Forms.PictureBox boss_medusa;
        private System.Windows.Forms.TabPage tpItem;
        private System.Windows.Forms.PictureBox item_cross;
        private System.Windows.Forms.PictureBox item_double_shot;
        private System.Windows.Forms.PictureBox item_spirit_ball;
        private System.Windows.Forms.PictureBox item_rosary;
        private System.Windows.Forms.PictureBox item_roast;
        private System.Windows.Forms.PictureBox item_money_bag;
        private System.Windows.Forms.PictureBox item_big_heart;
        private System.Windows.Forms.PictureBox item_small_heart;
        private System.Windows.Forms.PictureBox item_morning_star;
        private System.Windows.Forms.PictureBox item_holy_water;
        private System.Windows.Forms.PictureBox item_axe;
        private System.Windows.Forms.PictureBox item_knife;
        private System.Windows.Forms.PictureBox item_stop_watch;
        private System.Windows.Forms.PictureBox ptbCurrentItem;
        private System.Windows.Forms.CheckBox cbRandomItm;
        private System.Windows.Forms.ComboBox cbbState;
        private System.Windows.Forms.Button btAddState;
        private System.Windows.Forms.TextBox tbStateY;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox tbStateX;
        private System.Windows.Forms.Label lbCurrentPos;
        private System.Windows.Forms.PictureBox ground_brick;
        private System.Windows.Forms.PictureBox ground_stair_down;
        private System.Windows.Forms.PictureBox ground_stair_up;
        private System.Windows.Forms.GroupBox gbProp;
        private System.Windows.Forms.TextBox tbVar3;
        private System.Windows.Forms.Label lbVar3;
        private System.Windows.Forms.TextBox tbVar2;
        private System.Windows.Forms.Label lbVar2;
        private System.Windows.Forms.TextBox tbVar1;
        private System.Windows.Forms.Label lbVar1;
        private System.Windows.Forms.PictureBox ground_go_in_castle;
        private System.Windows.Forms.PictureBox ground_hidden_brick;
        private System.Windows.Forms.PictureBox item_none;
        private System.Windows.Forms.PictureBox ground_death;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
    }
}

