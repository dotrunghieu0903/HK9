using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;

namespace MapEditor
{
    public partial class AddState : Form
    {
        BackgroundWorker worker;
        string mapLocation = "lv2.png";
         int[,] setArr;
        Bitmap background;
        Bitmap tiles;
        WorldMap world;
        int cols;
        int rows;

        public AddState(WorldMap wm)
        {
            InitializeComponent();
            this.world = wm;
        }

        private void bt_Load_Click(object sender, EventArgs e)
        {
            OpenFileDialog dg = new OpenFileDialog();
            dg.Filter = "Image Files (bmp, jpg, png)|*.bmp;*.jpg;*.png";
            dg.Multiselect = false;
            if (dg.ShowDialog() == DialogResult.OK)
            {
                mapLocation = dg.FileName;
                this.background = new Bitmap(mapLocation);
                if (background.Height < 176)
                {
                    MessageBox.Show("Invalid background size");
                    return;
                }

                float scale = 176.0f / background.Height;
                Rectangle r = new Rectangle(0, 0, (int)(background.Width * scale), 176);
                Bitmap bm = background.Clone(r, background.PixelFormat);
                using (Graphics g = Graphics.FromImage(bm))
                {
                    g.InterpolationMode = InterpolationMode.NearestNeighbor;
                    g.DrawImage(background, 0, 0, (int)(background.Width * scale), 176);

                    background = bm;
                }

                worker = new BackgroundWorker();
                worker.DoWork += worker_DoWork;
                worker.ProgressChanged += worker_ProgressChanged;
                worker.RunWorkerCompleted += worker_RunWorkerCompleted;
                worker.WorkerReportsProgress = true;

                this.rtb_set.Text = "";
                tiles = new Bitmap(240, 400);
                this.pb_tiles.Image = tiles;
                pnImage.Controls.Clear();

                PictureBox pb_background = new PictureBox();
                pb_background.Image = background;
                pb_background.Location = new Point(0, 0);
                pb_background.SizeMode = PictureBoxSizeMode.AutoSize;
                pnImage.Controls.Add(pb_background);

                if (pnImage.HorizontalScroll.Visible)
                    pnImage.Height = 202;
                else pnImage.Height = 176;

                worker.RunWorkerAsync(); 
            }

        }

        private void bt_create_Click(object sender, EventArgs e)
        {
            tiles = new Bitmap(240, 400);
            this.pb_tiles.Image = tiles;
            this.rtb_set.Text = "";

            worker = new BackgroundWorker();
            worker.DoWork += worker_DoWork;
            worker.ProgressChanged += worker_ProgressChanged;
            worker.RunWorkerCompleted += worker_RunWorkerCompleted;
            worker.WorkerReportsProgress = true;

            worker.RunWorkerAsync(); 
        }

        private void worker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            this.pgB_Status.Value = 1000;
            rtb_set.SelectionStart = rtb_set.Text.Length;
            rtb_set.ScrollToCaret();

            int height = (1 + world.tilesList.Count / 15) * 16;

            foreach (Bitmap bm in world.tilesList)
            {
                int i = world.tilesList.IndexOf(bm) % 15;
                int j = world.tilesList.IndexOf(bm) / 15;

                using (Graphics g = Graphics.FromImage(tiles))
                {
                    g.InterpolationMode = InterpolationMode.NearestNeighbor;
                    g.DrawImage(bm, i * 16, j * 16, 16, 16);
                }
            }
            this.pb_tiles.Image = tiles; 

        }

        private void worker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            this.pgB_Status.Value = e.ProgressPercentage;
            if (e.UserState != null)
            {
                this.rtb_set.AppendText(e.UserState as string);
                if ((e.UserState as string).IndexOf("->") > 0)
                {
                    rtb_set.SelectionStart = rtb_set.Text.Length;
                    rtb_set.ScrollToCaret();
                }
            }
        }

        private void worker_DoWork(object sender, DoWorkEventArgs e)
        {
            DateTime str = DateTime.UtcNow;
            try
            {
                this.background = new Bitmap(mapLocation);

                float scale = 176.0f / background.Height;
                Rectangle rect = new Rectangle(0, 0, (int)(background.Width * scale), 176);
                Bitmap bm = background.Clone(rect, background.PixelFormat);
                using (Graphics g = Graphics.FromImage(bm))
                {
                    g.InterpolationMode = InterpolationMode.NearestNeighbor;
                    g.DrawImage(background, 0, 0, (int)(background.Width * scale), 176);

                    background = bm;
                }

                int colcount = background.Width / 8;
                int rowcount = background.Height / 8;
                this.setArr = new int[rowcount, colcount];

                int p = 0;
                for (int row = 0; row < rowcount; row++)
                {
                    this.worker.ReportProgress(row * 1000 / rowcount, "\n -> ");
                    string s = "";
                    for (int col = 0; col < colcount; col++)
                    {
                        Rectangle r = new Rectangle(col * 8, row * 8, 8, 8);
                        Bitmap pro = background.Clone(r, background.PixelFormat);

                        bool has = false;
                        int k = 0;
                        foreach (Bitmap b in world.tilesList)
                            if (CompareBitmaps(pro, b))
                            {
                                has = true;
                                k = world.tilesList.IndexOf(b);
                                setArr[row, col] = k;
                                break;
                            }
                        if (!has)
                        {
                            world.tilesList.Add(pro);
                            k = world.tilesList.IndexOf(pro);
                            setArr[row, col] = k;
                        }

                        if (k < 10)
                            s += "  ";
                        else if (k < 100)
                            s += " ";
                        s += " " + k;

                        p = ((row * colcount + col) * 1000) / (rowcount * colcount);
                        this.worker.ReportProgress(p);
                    }
                    this.worker.ReportProgress(p, s);
                }

                DateTime end = DateTime.UtcNow;

                string info = "\n\n -->  Total Time  :  " + (end - str).TotalMilliseconds.ToString() + " ms";

                info += "\n      Total Tiles :  " + rowcount * colcount;

                info += "\n      Tiles Num   :  " + world.tilesList.Count;
                info += "\n      Tiles Row   :  " + rowcount;
                info += "\n      Tiles Col   :  " + colcount + "\n\n";

                cols = colcount;
                rows = rowcount;

                this.worker.ReportProgress(1000, info);
            }
            catch(Exception)
            {
                throw;
            }
        }

        private bool CompareBitmaps(Bitmap leftBitmap, Bitmap rightBitmap)
        {
            if (object.Equals(leftBitmap, rightBitmap))
                return true;
            if (leftBitmap == null || rightBitmap == null)
                return false;
            if (!leftBitmap.Size.Equals(rightBitmap.Size) || !leftBitmap.PixelFormat.Equals(rightBitmap.PixelFormat))
                return false;

            #region Optimized code for performance

            int bytes = leftBitmap.Width * leftBitmap.Height * (Image.GetPixelFormatSize(leftBitmap.PixelFormat) / 8);

            bool result = true;
            byte[] b1bytes = new byte[bytes];
            byte[] b2bytes = new byte[bytes];

            BitmapData bmd1 = leftBitmap.LockBits(new Rectangle(0, 0, leftBitmap.Width - 1, leftBitmap.Height - 1), ImageLockMode.ReadOnly, leftBitmap.PixelFormat);
            BitmapData bmd2 = rightBitmap.LockBits(new Rectangle(0, 0, rightBitmap.Width - 1, rightBitmap.Height - 1), ImageLockMode.ReadOnly, rightBitmap.PixelFormat);

            Marshal.Copy(bmd1.Scan0, b1bytes, 0, bytes);
            Marshal.Copy(bmd2.Scan0, b2bytes, 0, bytes);

            for (int n = 0; n <= bytes - 1; n++)
            {
                if (b1bytes[n] != b2bytes[n])
                {
                    result = false;
                    break;
                }
            }

            leftBitmap.UnlockBits(bmd1);
            rightBitmap.UnlockBits(bmd2);

            #endregion

            return result;
        }

        private void btSave_Click(object sender, EventArgs e)
        {
            State st = new State();
            st.cols = cols;
            st.rows = rows;
            st.position = new Point(0, 0);
            st.setArr = setArr;
            world.ListState.Add(st);

            this.Close();
        }

        private void saveToFile()
        {
            int height = (1 + world.tilesList.Count / 15) * 16;
            Bitmap set = new Bitmap(240, height);

            foreach (Bitmap bm in world.tilesList)
            {
                int i = world.tilesList.IndexOf(bm) % 15;
                int j = world.tilesList.IndexOf(bm) / 15;

                using (Graphics g = Graphics.FromImage(set))
                {
                    g.InterpolationMode = InterpolationMode.NearestNeighbor;
                    g.DrawImage(bm, i * 16, j * 16, 17, 17);
                }
            }
            string name = mapLocation.Split('.')[0] + "_tiles";
            set.Save(name + ".bmp", ImageFormat.Bmp);

            using (FileStream fs = new FileStream(name + ".txt", FileMode.Create, FileAccess.Write))
            {
                StreamWriter sw = new StreamWriter(fs);
                sw.AutoFlush = true;
                sw.WriteLine("  " + cols + "  " + rows);
                sw.WriteLine("  " + 10 + "   " + (1 + world.tilesList.Count / 10));

                for (int i = 0; i < rows; i++)
                {
                    sw.WriteLine();
                    for (int j = 0; j < cols; j++)
                    {

                        int k = setArr[i, j];
                        string s = "";

                        if (k < 10)
                            s += "  ";
                        else if (k < 100)
                            s += " ";
                        s += " " + k;
                        sw.Write(s);
                    }
                }
            }
           

        }
    }
}
