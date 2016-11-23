using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class MapEditor : Form
    {
        List<PictureBox> listObj;
        List<PictureBox> listItm;

        PictureBox selection_Obj;
        PictureBox selection_Itm;
        PictureBox pb_background;

        Objects currentObj;

        WorldMap worldmap;
        Node root_node;

        int y_Axis = 352;
        int x_Axis = 0;

        Rectangle rect;

        Point last_Croll;

        private Point startPoint;

        public MapEditor()
        {
            InitializeComponent();
            init_ObjList();
            last_Croll = new Point(0, 0);
            currentObj = null;
        }

        private void init_ObjList()
        {
            listObj = new List<PictureBox>();
            listObj.Add(ground_brick);
            listObj.Add(ground_hidden_brick);
            listObj.Add(ground_go_in_castle);
            listObj.Add(ground_stair_up);
            listObj.Add(ground_stair_down);
            listObj.Add(ground_firecandle);
            listObj.Add(ground_firetower);
            listObj.Add(ground_trap);
            listObj.Add(ground_moving_brick);
            listObj.Add(ground_lockdoor);
            listObj.Add(ground_opendoor);
            listObj.Add(ground_death);
            listObj.Add(enemy_zombie);
            listObj.Add(enemy_merman);
            listObj.Add(enemy_spearguard);
            listObj.Add(enemy_bonepillar);
            listObj.Add(enemy_bat);
            listObj.Add(enemy_medusahead);
            listObj.Add(enemy_ghost);
            listObj.Add(enemy_panther);
            listObj.Add(boss_bat);
            listObj.Add(boss_medusa);
            listObj.Add(simon);

            foreach (PictureBox p in listObj)
                p.Click += Obj_Click;

            listItm = new List<PictureBox>();
            listItm.Add(item_axe);
            listItm.Add(item_cross);
            listItm.Add(item_knife);
            listItm.Add(item_holy_water);
            listItm.Add(item_stop_watch);
            listItm.Add(item_morning_star);
            listItm.Add(item_double_shot);
            listItm.Add(item_small_heart);
            listItm.Add(item_big_heart);
            listItm.Add(item_money_bag);
            listItm.Add(item_roast);
            listItm.Add(item_rosary);
            listItm.Add(item_spirit_ball);
            listItm.Add(item_none);
            foreach (PictureBox p in listItm)
                p.Click += Itm_Click;

            selection_Obj = listObj[0];
            selection_Itm = listItm[0];

            change_Obj(listObj[1].Name);
        }

        private void Obj_Click(object sender, EventArgs e)
        {
            change_Obj((sender as PictureBox).Name);
            switch ((sender as PictureBox).Name)
            {
                case "ground_brick":
                case "ground_death":
                    tbVar1.Text = "2";
                    tbVar2.Text = "1";
                    tbVar3.Text = "0";
                    break;
                case "ground_stair_up":
                case "ground_stair_down":
                    tbVar1.Text = "2";
                    tbVar2.Text = "0";
                    tbVar3.Text = "0";
                    break;
                case "ground_firecandle":
                case "ground_firetower":
                    tbVar1.Text = "1";
                    tbVar2.Text = "0";
                    tbVar3.Text = "0";
                    break;
                case "ground_lockdoor":
                case "ground_opendoor":
                case "ground_trap":
                    tbVar1.Text = "0";
                    tbVar2.Text = "0";
                    tbVar3.Text = "0";
                    break;
                case "ground_moving_brick":
                    tbVar1.Text = "1";
                    tbVar2.Text = "0";
                    tbVar3.Text = "0";
                    break;
                case "enemy_bat":
                    tbVar1.Text = "1";
                    tbVar2.Text = "1";
                    tbVar3.Text = "16";
                    break;
                case "enemy_ghost":
                    tbVar1.Text = "4";
                    tbVar2.Text = "1";
                    tbVar3.Text = "6";
                    break;
                case "enemy_medusahead":
                    tbVar1.Text = "1";
                    tbVar2.Text = "1";
                    tbVar3.Text = "12";
                    break;
                case "enemy_merman":
                    tbVar1.Text = "2";
                    tbVar2.Text = "1";
                    tbVar3.Text = "6";
                    break;
                case "enemy_panther":
                case "enemy_zombie":
                    tbVar1.Text = "1";
                    tbVar2.Text = "1";
                    tbVar3.Text = "6";
                    break;
                case "enemy_bonepillar":
                    tbVar1.Text = "6";
                    tbVar2.Text = "1";
                    tbVar3.Text = "6";
                    break;
                case "enemy_spearguard":
                    tbVar1.Text = "2";
                    tbVar2.Text = "1";
                    tbVar3.Text = "2";
                    break;
                case "boss_bat":
                case "boss_medusa":
                    tbVar1.Text = "16";
                    tbVar2.Text = "2";
                    tbVar3.Text = "0";
                    break;
                default:
                    tbVar1.Text = "16";
                    tbVar2.Text = "2";
                    tbVar3.Text = "0";
                    break;
            }
        }

        private void change_Obj(string name)
        {
            PictureBox new_Obj = (from pt in listObj
                                  where pt.Name == name
                                  select pt).First();

            if (new_Obj != null && selection_Obj != new_Obj)
            {
                selection_Obj.BackColor = Color.Transparent;
                selection_Obj = new_Obj;
                selection_Obj.BackColor = SystemColors.MenuHighlight;

                ptbCurrentObj.Image = selection_Obj.Image;
                if (isNoItmObj(selection_Obj.Name))
                    ptbCurrentItem.Image = null;
                else
                    ptbCurrentItem.Image = selection_Itm.Image;


            }
            
            switch (name)
            {
                case "ground_brick":
                case "ground_death":
                    lbVar1.Text = "Cols:";
                    lbVar2.Text = "Rows:";
                    lbVar3.Text = "None";
                    break;
                case "ground_stair_up":
                case "ground_stair_down":
                    lbVar1.Text = "Steps:";
                    lbVar2.Text = "None";
                    lbVar3.Text = "None";
                    break;
                case "ground_firecandle":
                case "ground_firetower":
                    lbVar1.Text = "HP:";
                    lbVar2.Text = "None";
                    lbVar3.Text = "None";
                    break;
                case "ground_lockdoor":
                case "ground_opendoor":
                case "ground_trap":
                    lbVar1.Text = "None";
                    lbVar2.Text = "None";
                    lbVar3.Text = "None";
                    break;
                case "ground_moving_brick":
                    lbVar1.Text = "Range:";
                    lbVar2.Text = "None";
                    lbVar3.Text = "None";
                    break;
                case "enemy_bat":
                case "enemy_ghost":
                case "enemy_medusahead":
                case "enemy_merman":
                case "enemy_panther":
                case "enemy_spearguard":
                case "enemy_zombie":
                case "enemy_bonepillar":
                    lbVar1.Text = "HP";
                    lbVar2.Text = "Dame";
                    lbVar3.Text = "Range:";
                    break;
                case "boss_bat":
                case "boss_medusa":
                    lbVar1.Text = "HP";
                    lbVar2.Text = "Dame";
                    lbVar3.Text = "None";
                    break;
                default:
                    lbVar1.Text = "HP";
                    lbVar2.Text = "Dame";
                    lbVar3.Text = "None";
                    break;
            }
        }

        private void Itm_Click(object sender, EventArgs e)
        {
            change_Itm((sender as PictureBox).Name);
            if (currentObj != null)
                currentObj.Item = currentObj.getItemIDByName((sender as PictureBox).Name);
            if (pb_background != null)
                pb_background.Invalidate();
        }

        private void change_Itm(string name)
        {
            PictureBox new_Obj = (from pt in listItm
                                  where pt.Name == name
                                  select pt).First();
            if (new_Obj !=null && selection_Itm != new_Obj)
            {
                selection_Itm.BackColor = Color.Transparent;
                selection_Itm = new_Obj;
                selection_Itm.BackColor = SystemColors.Highlight;

                if (isNoItmObj(selection_Obj.Name))
                    ptbCurrentItem.Image = null;
                else
                    ptbCurrentItem.Image = selection_Itm.Image;
            }
        }

        private void btClear_Click(object sender, EventArgs e)
        {
            if(worldmap!=null)
            {
                worldmap.ListObject.Clear();
                pb_background.Invalidate();
            }
        }

        private void btNewMap_Click(object sender, EventArgs e)
        {
            worldmap = new WorldMap();
            pnMapViewer.Controls.Clear();
            btAddState_Click(sender, e);
        }

        private void btAddState_Click(object sender, EventArgs e)
        {
            if(worldmap != null)
            {
                AddState asForm = new AddState(worldmap);
                asForm.ShowDialog();
                DrawWorld();

                this.cbbState.DisplayMember = "Name";
                this.cbbState.ValueMember = "Value";
                this.cbbState.Items.Clear();
                foreach(State st in worldmap.ListState)
                    this.cbbState.Items.Add(new { Name = "State " + worldmap.ListState.IndexOf(st), Value = st });
                this.cbbState.SelectedIndex = this.cbbState.Items.Count - 1;
                
            }
        }

        private void DrawWorld()
        {
            if (worldmap.ListState.Count() == 0)
                return;

            pnMapViewer.Controls.Clear();
            pb_background = new PictureBox();
            pb_background.Location = new Point(0, 0);

            int strX = worldmap.ListState[0].position.X;
            int strY = worldmap.ListState[0].position.Y;
            int endX = 0;
            int endY = 0;

            foreach (State st in worldmap.ListState)
            {
                if (strX > st.position.X)
                    strX = st.position.X;
                if (endX < st.cols * 16 + st.position.X)
                    endX = st.position.X + st.cols * 16;

                if (strY > st.position.Y)
                    strY = st.position.Y;
                if (endY < st.rows * 16 + st.position.Y)
                    endY = st.position.Y + st.rows * 16;
            }
            this.x_Axis = strX;

            if (strX > 0)
                strX = 0;
            y_Axis = endY;

            int w = Math.Abs(endX - strX);
            int h = Math.Abs(endY - strY);

            pb_background.Size = new Size(w + 1, h + 1);
            pnMapViewer.Controls.Add(pb_background);

            pb_background.Click += worldMap_Click;
            pb_background.Paint += worldMap_Paint;
            pb_background.MouseDown += WorldView_MouseDown;
            pb_background.MouseMove += WorldView_MouseMove;
            pnMapViewer.AutoScrollPosition = last_Croll;
        }

        private void worldMap_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            foreach (State st in worldmap.ListState)
            {
                for (int i = 0; i < st.rows; i++)
                {
                    for (int j = 0; j < st.cols; j++)
                    {
                        g.InterpolationMode = InterpolationMode.NearestNeighbor;

                        int index = st.setArr[i, j];
                        g.DrawImage(worldmap.tilesList[index],
                            j * 16 + st.position.X,
                            i * 16 + y_Axis - st.position.Y - st.rows * 16,
                            17, 17);
                    }
                }
            }

            if (cbShowTiles.Checked)
            {
                int col = pb_background.Width / 32;
                int row = pb_background.Height / 32;
                Pen p = new Pen(SystemColors.MenuHighlight, 1.0f);
                p.DashStyle = System.Drawing.Drawing2D.DashStyle.Dot;
                for (int i = 1; i <= row; i++)
                    g.DrawLine(p, new Point(0, i * 32), new Point(col * 32, i * 32));
                for (int i = 0; i < col; i++)
                    g.DrawLine(p, new Point(i * 32, 0), new Point(i * 32, row * 32));

                Pen p2 = new Pen(Color.Red, 2.0f);
                p2.DashStyle = System.Drawing.Drawing2D.DashStyle.Solid;
                g.DrawLine(p2, new Point(0, y_Axis), new Point(col * 32, y_Axis));
                g.DrawLine(p2, new Point(x_Axis, 0), new Point(x_Axis, col * 32));
            }

            foreach (Objects obj in worldmap.ListObject)
            {
                Point p = obj.Point;
                p.Y = y_Axis - p.Y - obj.Size.Height;
                g.InterpolationMode = InterpolationMode.NearestNeighbor;

                Rectangle r = new Rectangle(p, obj.Size);
                g.DrawImage(obj.getImageByType(), r);

                if (!isNoItmObj(obj.getTypeNameById()))
                {
                   Point ip = new Point(p.X, p.Y + r.Height - 16);
                   Rectangle r2 = new Rectangle(ip, new Size(16, 16));
                   g.DrawImage(obj.getImageByItem(), r2);
                }
            }  

 /*           if(qt!=null)
            {
                Rectangle re = new Rectangle(0, 0, 1024, 352);

                re.X = pnMapViewer.HorizontalScroll.Value;
                re.Y = pnMapViewer.VerticalScroll.Value;
                re.Width = pnMapViewer.Width;
                re.Height = pnMapViewer.Height;
                re.Y = y_Axis - re.Height - re.Y;
                List<Objects> l = qt.Query(re);
                foreach (Objects obj in l)
                {
                    Point p = obj.Point;
                    p.Y = y_Axis - p.Y - obj.Size.Height;
                    g.InterpolationMode = InterpolationMode.NearestNeighbor;

                    Rectangle r = new Rectangle(p, obj.Size);
                    g.DrawImage(obj.getImageByType(), r);

                    if (!isNoItmObj(obj.getTypeNameById()))
                    {
                        Point ip = new Point(p.X, p.Y + r.Height - 16);
                        Rectangle r2 = new Rectangle(ip, new Size(16, 16));
                        g.DrawImage(obj.getImageByItem(), r2);
                    }
                } 
            } */
            

            if (rect.Width > 0)
            {
                Pen p2 = new Pen(Color.Yellow, 2.0f);
                g.DrawRectangle(p2, rect);
            }
        }
        private bool isNoItmObj(string s)
        {
            bool b = false;
            switch (s)
            {
                case "ground_brick":
                    b = true;
                    break;
                case "ground_death":
                    b = true;
                    break;
                case "ground_go_in_castle":
                    b = true;
                    break;
                case "ground_stair_up":
                    b = true;
                    break;
                case "ground_stair_down":
                    b = true;
                    break;
                case "ground_moving_brick":
                    b = true;
                    break;
                case "ground_lockdoor":
                    b = true;
                    break;
                case "ground_opendoor":
                    b = true;
                    break;
                case "ground_trap":
                    b = true;
                    break;
                case "simon":
                    b = true;
                    break;
            }
            return b;
        }
        private void worldMap_Click(object sender, EventArgs e)
        {
            try
            {
                MouseEventArgs eM = e as MouseEventArgs;
                if (eM.Button == MouseButtons.Left)
                {
                    Point ip = new Point(eM.X, eM.Y);

                    if (Control.ModifierKeys == Keys.Control)
                    {
                        if (selection_Obj != null)
                        {
                            if (cbAutoAlign.Checked)
                            {
                                ip.X = ip.X / 32 * 32;
                                ip.Y = (ip.Y / 32 + 1) * 32;
                                if (selection_Obj.Image.Height < 32)
                                {
                                    ip.Y -= 32 - selection_Obj.Image.Height;
                                }
                            }
                            else
                            {
                                ip.X -= 16;
                                ip.Y += 16;
                            }
                            ip.Y = y_Axis - ip.Y;

                            Objects tmpObj = getObjectsAtPos(ip.X, ip.Y);
                            if (tmpObj != null)
                            {
                                if (tmpObj.getTypeNameById() == selection_Obj.Name && tmpObj.Point == ip)
                                    return;
                            }
                            add(ip);
                            if (cbRandomItm.Checked)
                            {
                                Random rnd = new Random();
                                int r = rnd.Next(listItm.Count);
                                change_Itm(listItm[r].Name);

                                Bitmap curs = new Bitmap(selection_Obj.Image);
                                if (!isNoItmObj(selection_Obj.Name) && selection_Itm.Image != null)
                                {
                                    using (Graphics g = Graphics.FromImage(curs))
                                    {
                                        Rectangle re = new Rectangle(0, curs.Height - 16, 16, 16);
                                        g.DrawImage((Bitmap)selection_Itm.Image, re);
                                    }
                                }
                                pnMapViewer.Cursor = CustomCursor.CreateCursor(curs, 16, selection_Obj.Image.Height - 16);
                            }
                            
                        }
                    }
                    else if (Control.ModifierKeys == Keys.Shift)
                    {
                        Objects tmpObj = getObjectsAtPos(eM.X, y_Axis - eM.Y);
                        if (tmpObj == null)
                            return;
                        worldmap.ListObject.Remove(tmpObj);
                    }
                    else
                    {
                        Objects tmpObj = getObjectsAtPos(eM.X, y_Axis - eM.Y);
                        if (tmpObj == null)
                            return;
                        if (currentObj != tmpObj)
                        {
                            currentObj = tmpObj;
                            this.tbPosX.Text = currentObj.Point.X.ToString();
                            this.tbPosY.Text = currentObj.Point.Y.ToString();
                            this.tbVar1.Text = currentObj.Value_1.ToString();
                            this.tbVar2.Text = currentObj.Value_2.ToString();
                            this.tbVar3.Text = currentObj.Value_3.ToString();
                            change_Obj(currentObj.getTypeNameById());
                            change_Itm(currentObj.getItemNameById());

                            rect.X = currentObj.Point.X;
                            rect.Y = y_Axis - currentObj.Point.Y - currentObj.Size.Height;
                            rect.Width = currentObj.Size.Width;
                            rect.Height = currentObj.Size.Height;
                        } 
                    }

                    pb_background.Invalidate();
                }
            }
            catch (Exception)
            {
                MessageBox.Show("Nhập số hợp lệ cho các textbox!\n");
            }
        }
        private void add(Point p)
        {
            int id = worldmap.ListObject.Count;
            string name = selection_Obj.Name;
            string item = selection_Itm.Name;
            int var1 = 1;
            int var2 = 1;
            int var3 = 1;
            int.TryParse(tbVar1.Text, out var1);
            int.TryParse(tbVar2.Text, out var2);
            int.TryParse(tbVar3.Text, out var3);
            if (name == "ground_stair_down")
                p.Y -= (var1 - 1) * 32;
            Objects obj = new Objects(id, name, item, var1, var2, var3, p);
            this.worldmap.ListObject.Add(obj);
            currentObj = obj;
        }

        private void WorldView_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left && Control.ModifierKeys == Keys.None)
            {
                Point changePoint = new Point(e.Location.X - startPoint.X, e.Location.Y - startPoint.Y);
                pnMapViewer.AutoScrollPosition = new Point(
                    -pnMapViewer.AutoScrollPosition.X - changePoint.X,
                    -pnMapViewer.AutoScrollPosition.Y - changePoint.Y);

                last_Croll.X = -pnMapViewer.AutoScrollPosition.X - changePoint.X;
                last_Croll.Y = -pnMapViewer.AutoScrollPosition.Y - changePoint.Y;
            }

            int y = y_Axis - e.Location.Y;
            lbCurrentPos.Text = "X: " + e.Location.X + "\nY: " + y;

            if (Control.ModifierKeys == Keys.Control)
            {
                if (selection_Obj != null)
                {
                    Point ip = new Point(e.Location.X, e.Location.Y);
                    if (cbAutoAlign.Checked)
                    {
                        ip.X = ip.X / 32 * 32;
                        ip.Y = (ip.Y / 32 + 1) * 32;
                        if (selection_Obj.Image.Height < 32)
                        {
                            ip.Y -= 32 - selection_Obj.Image.Height;
                        }
                    }
                    else
                    {
                        ip.X -= 16;
                        ip.Y += 16;
                    }

                    ip.Y -= selection_Obj.Image.Height;

                    Size sz = selection_Obj.Image.Size;
                    int col;
                    int row;
                    int.TryParse(tbVar1.Text, out col);
                    int.TryParse(tbVar2.Text, out row);

                    if (selection_Obj.Name == "ground_brick")
                    {                       
                        ip.Y = ip.Y - (row - 1) * 32;
                        sz.Width = col * 32;
                        sz.Height = row * 32;
                    }
                    else if (selection_Obj.Name == "ground_stair_up")
                    {
                        ip.Y = ip.Y - (col - 1) * 32;
                        sz.Width = col * 32;
                        sz.Height = col * 32;
                    }
                    else if (selection_Obj.Name == "ground_stair_down")
                    {
                        ip.Y = ip.Y;
                        sz.Width = col * 32;
                        sz.Height = col * 32;
                    }
                    rect = new Rectangle(ip, sz);
                    pb_background.Invalidate();
                }
            }
            
        }

        private void WorldView_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left && Control.ModifierKeys == Keys.None)
                startPoint = e.Location;
        }

        private void cbbState_SelectedIndexChanged(object sender, EventArgs e)
        {
            int id = cbbState.SelectedIndex;
            State st = worldmap.ListState[id];
            if(st != null)
            {
                tbStateX.Text = ((st as State).position.X /32).ToString();
                tbStateY.Text = ((st as State).position.Y /32).ToString();
            }
        }

        private void tbState_Leave(object sender, EventArgs e)
        {
            int id = cbbState.SelectedIndex;
            State st = worldmap.ListState[id];
            if (st != null)
            {
                int x;
                int y;
                if (int.TryParse(tbStateX.Text, out x) &&
                    int.TryParse(tbStateY.Text, out y))
                {
                    if (st.position.X == x * 32 && st.position.Y == y * 32)
                        return;

                    st.position.X = x *32;
                    st.position.Y = y *32;
                    DrawWorld();
                }
            }
        }

        private void cbShowTiles_CheckedChanged(object sender, EventArgs e)
        {
            if (pb_background != null)
                pb_background.Invalidate();
        }

        private void pnMapViewer_Scroll(object sender, ScrollEventArgs e)
        {
            if(e.ScrollOrientation == ScrollOrientation.HorizontalScroll)
                last_Croll.X = e.NewValue;
            else
                last_Croll.Y = e.NewValue;
        }

        private Objects getObjectsAtPos(int x, int y)
        {
            if (worldmap.ListObject.Count == 0)
                return null;
            foreach(Objects o in worldmap.ListObject)
            {
                Rectangle r = new Rectangle(o.Point, o.Size);
                if (r.Contains(new Point(x, y)))
                {
                    if (o.getTypeNameById() == "ground_stair_up")
                        for (int i = 0; i < o.Value_1;i++)
                        {
                            Rectangle r2 = new Rectangle(o.Point.X + i*32, o.Point.Y + i*32, 32, 32);
                            if(r2.Contains(new Point(x, y)))
                                return o;
                        }
                    else if (o.getTypeNameById() == "ground_stair_down")
                        for (int i = 0; i < o.Value_1; i++)
                        {
                            Rectangle r2 = new Rectangle(o.Point.X + i * 32, o.Point.Y + (o.Value_1- i -1) * 32, 32, 32);
                            if (r2.Contains(new Point(x, y)))
                                return o;
                        }
                    else
                        return o;
                }
            }
            return null;
        }

        private void MapEditor_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.ControlKey)
            {
                Bitmap curs = new Bitmap(selection_Obj.Image);
                if(!isNoItmObj(selection_Obj.Name) && selection_Itm.Image!=null)
                {
                    using (Graphics g = Graphics.FromImage(curs))
                    {
                        Rectangle r = new Rectangle(0, curs.Height - 16, 16, 16);
                        g.DrawImage((Bitmap)selection_Itm.Image, r);
                    }
                }
                pnMapViewer.Cursor = CustomCursor.CreateCursor(curs, 16, selection_Obj.Image.Height - 16);
                if (pb_background != null)
                    pb_background.Invalidate();
            }
            else if (e.KeyCode == Keys.ShiftKey)
            {
                Bitmap bm = (Bitmap)global::MapEditor.Properties.Resources.eraser;
                pnMapViewer.Cursor = CustomCursor.CreateCursor(bm, 16, bm.Height - 16);
                if (pb_background != null)
                    pb_background.Invalidate();
            }
            
        }

        private void MapEditor_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.ControlKey || e.KeyCode == Keys.ShiftKey)
            {
                if (pnMapViewer.Cursor != Cursors.Arrow)
                    pnMapViewer.Cursor = Cursors.Arrow;

                if (currentObj != null)
                {
                    currentObj = null;
                }
                rect = new Rectangle(0, 0, 0, 0);
                if (pb_background != null)
                    pb_background.Invalidate();
            }
        }

        private void tbProp_Leave(object sender, EventArgs e)
        {
            if (currentObj == null)
                return;
            bool hasChange = false;

            int posX;
            int posY;
            int var1;
            int var2;
            int var3;
            int.TryParse(tbPosX.Text, out posX);
            int.TryParse(tbPosY.Text, out posY);
            int.TryParse(tbVar1.Text, out var1);
            int.TryParse(tbVar2.Text, out var2);
            int.TryParse(tbVar3.Text, out var3);

            if (posX != currentObj.Point.X || posY != currentObj.Point.Y)
            {
                currentObj.Point = new Point(posX, posY);
                hasChange = true;
            } 
            if (var1 != currentObj.Value_1)
            {
                hasChange = true;
                currentObj.Value_1 = var1;
            }   
            if (var2 != currentObj.Value_2)
            {
                hasChange = true;
                currentObj.Value_2 = var2;
            } 
            if (var3 != currentObj.Value_3)
            {
                hasChange = true;
                currentObj.Value_3 = var3;
            }
            if (pb_background != null && hasChange)
            {
                rect.X = currentObj.Point.X;
                rect.Y = y_Axis - currentObj.Point.Y - currentObj.Size.Height;
                rect.Width = currentObj.Size.Width;
                rect.Height = currentObj.Size.Height;
                pb_background.Invalidate();
            }
                
        }

        private void btSave_Click(object sender, EventArgs e)
        {
            if (this.worldmap != null)
            {
                SaveFileDialog dlg = new SaveFileDialog();

                dlg.Filter = "map files (*.txt)|*.txt";
                dlg.Title = "Save map";
                dlg.CheckPathExists = true;
                dlg.CheckPathExists = true;
                dlg.ShowDialog();
                if (dlg.FileName != "")
                {
                    Rectangle rrr = new Rectangle(new Point(0, y_Axis - pb_background.Height + 1), pb_background.Size);
                    root_node = new Node("0", rrr);
                    List<Objects> tmplst = new List<Objects>(worldmap.ListObject);
                    worldmap.ListObject.Clear();

                    foreach (Objects o in tmplst)
                    {
                        if (o.Type < 10 || o.Type == 20)
                        {
                            worldmap.ListObject.Add(o);
                        }   
                    }
                    foreach (Objects o in tmplst)
                    {
                        if (o.Type < 10 || o.Type == 20)
                            continue;
                        worldmap.ListObject.Add(o);
                    }

                    foreach (Objects o in worldmap.ListObject)
                    {
                        o.Id = worldmap.ListObject.IndexOf(o);
                        root_node.Insert(o);
                    }

                    worldmap.saveMap(dlg.FileName, root_node);

                    Rectangle re = new Rectangle(new Point(5665, 32), new Size(7200, 352));

                    List<Objects> l = root_node.Query(re);
                }
            }
                
        }

        private void btLoad_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog dg = new OpenFileDialog();
                dg.Filter = "Map Files (txt)|*.txt";
                dg.Multiselect = false;
                if (dg.ShowDialog() == DialogResult.OK)
                {
                    worldmap = new WorldMap();
                    root_node = new Node("0", new Rectangle(0, 0, 0, 0));
                    worldmap.loadMap(dg.FileName, root_node);

                    this.cbbState.DisplayMember = "Name";
                    this.cbbState.ValueMember = "Value";
                    this.cbbState.Items.Clear();
                    foreach (State st in worldmap.ListState)
                        this.cbbState.Items.Add(new { Name = "State " + worldmap.ListState.IndexOf(st), Value = st });
                    this.cbbState.SelectedIndex = this.cbbState.Items.Count - 1;

                    this.DrawWorld();
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show("Error! \n" + ex.Message);
            }
            
        }

    }
}
