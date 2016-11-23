using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;

namespace MapEditor
{
    public class State
    {
        public Point position;
        public int cols;
        public int rows;

        public int[,] setArr;
    }

    public class WorldMap
    {
        private List<State> listState;
        private List<Objects> listObject;
        public List<Bitmap> tilesList;

        public List<State> ListState
        {
            get { return listState; }
            set { listState = value; }
        }

        internal List<Objects> ListObject
        {
            get { return listObject; }
            set { listObject = value; }
        }

        public WorldMap()
        {
            listState = new List<State>();
            listObject = new List<Objects>();
            tilesList = new List<Bitmap>();
        }

        public void saveMap(string dir, Node root_node)
        {
            int height = (1 + this.tilesList.Count / 20) * 16;
            Bitmap set = new Bitmap(320, height);
            set.SetResolution(72.0F, 72.0F);

            foreach (Bitmap bm in this.tilesList)
            {
                int i = this.tilesList.IndexOf(bm) % 20;
                int j = this.tilesList.IndexOf(bm) / 20;

                using (Graphics g = Graphics.FromImage(set))
                {
                    g.InterpolationMode = InterpolationMode.NearestNeighbor;
                    g.DrawImage(bm, i * 16, j * 16, 17, 17);
                }
            }

            string name = dir.Split('.')[0];
            set.Save(name + ".bmp", ImageFormat.Bmp);

            using (FileStream fs = new FileStream(name + ".txt", FileMode.Create, FileAccess.Write))
            {
                StreamWriter sw = new StreamWriter(fs);
                sw.AutoFlush = true;
                sw.WriteLine("HEADER");
                sw.WriteLine("Map Info");
                sw.WriteLine("State_Num" + "\t" + "Tiles_Num" + "\t" + "Tiles_pRow" + "\t" + "Object_Num");
                sw.WriteLine(listState.Count + "\t\t\t" + tilesList.Count + "\t\t\t" + "20" + "\t\t\t" + listObject.Count);
                sw.WriteLine("\nState Info");
                sw.WriteLine("Pos_X" + "\t\t" + "Pos_Y" + "\t\t" + "Col_Num" + "\t\t" + "Row_Num");
                foreach(State st in this.listState)
                    sw.WriteLine(st.position.X.ToString("00000") + "\t\t" + st.position.Y.ToString("00000") + "\t\t" + st.cols + "\t\t\t" + st.rows);
                sw.WriteLine("END_HEADER\n");

                sw.WriteLine("STATE_SET");
                foreach(State st in this.listState)
                {
                    sw.WriteLine("State "+ (listState.IndexOf(st) + 1));
                    for(int i = 0; i<st.rows;i++)
                    {
                        for (int j = 0; j < st.cols; j++)
                            sw.Write(st.setArr[i, j] + "\t");
                        sw.WriteLine();
                    }     
                }
                sw.WriteLine("END_STATE_SET\n");

                sw.WriteLine("OBJECT_LIST");
                sw.WriteLine("ID" + "\t\t" + "Type" + "\t" + "Item" + "\t" + "Pos_X" + "\t\t" + "Pos_Y" + "\t\t" + "Var1" + "\t" + "Var2" + "\t" + "Var3");
                foreach (Objects o in this.listObject)
                {
                    sw.WriteLine(o.Id + "\t\t" + o.Type + "\t\t" + o.Item + "\t\t" +
                                 o.Point.X.ToString("00000") + "\t\t" + o.Point.Y.ToString("00000") + "\t\t" + o.Value_1 + "\t\t" + o.Value_2 + "\t\t" + o.Value_3);
                }
                sw.WriteLine("END_OBJECT_LIST\n");

                sw.WriteLine("QUAD_TREE");
                sw.WriteLine("Pos_X" + "\t\t" + "Pos_Y" + "\t\t" + "Width" + "\t\t" + "Height" + "\t\t" + "Node_Num" + "\t" + "Objs_Num" + "\t" + "List_Obj");
                root_node.Save(sw);
                sw.WriteLine("END_QUAD_TREE");
                sw.Close();
                fs.Close();
            }
        }

        public void loadMap(string dir, Node root_node)
        {
            using (FileStream fs = new FileStream(dir, FileMode.Open, FileAccess.Read))
            {
                StreamReader rd = new StreamReader(fs);

                string rs = rd.ReadLine(); //HEADER
                if (rs != "HEADER")
                    throw new Exception("Invalid Map");

                rd.ReadLine(); //Map Info
                rd.ReadLine(); //"State_Num" + "\t" + "Tiles_Num" + "\t" + "Tiles_pRow" + "\t" + "Object_Num"
                string[] s = rd.ReadLine().Split('\t');
                int state_Num = int.Parse(s[0]);
                int tiles_Num = int.Parse(s[3]);
                int objec_Num = int.Parse(s[9]);

                rd.ReadLine(); //State Info
                rd.ReadLine(); //Space
                rd.ReadLine(); //"Pos_X" + "\t\t" + "Pos_Y" + "\t\t" + "Col_Num" + "\t\t" + "Row_Num"

                listState.Clear();
                for (int i = 0; i < state_Num;i++ )
                {
                    string str = rd.ReadLine();
                    str = str.Replace("\t\t\t", "\t");
                    str = str.Replace("\t\t", "\t");
                    s = str.Split('\t');
                    State st = new State();
                    int x = int.Parse(s[0]);
                    int y = int.Parse(s[1]);
                    st.position = new Point(x, y);
                    st.cols = int.Parse(s[2]);
                    st.rows = int.Parse(s[3]);
                    st.setArr = new int[st.rows, st.cols];
                    listState.Add(st);
                }
                rd.ReadLine(); //END_HEADER
                rd.ReadLine(); //Space
                rd.ReadLine(); //STATE_SET
                foreach (State st in this.listState)
                {
                    rd.ReadLine(); //State Num
                    for (int i = 0; i < st.rows; i++)
                    {
                        s = rd.ReadLine().Split('\t');
                        for (int j = 0; j < st.cols; j++)
                            st.setArr[i, j] = int.Parse(s[j]);
                    }
                }
                rd.ReadLine(); //END_STATE_SET
                rd.ReadLine(); //Space
                rd.ReadLine(); //OBJECT_LIST
                rd.ReadLine(); //"ID" + "\t\t" + "Type" + "\t" + "Item" + "\t" + "Pos_X" + "\t\t" + "Pos_Y" + "\t\t" + "Var1" + "\t" + "Var2" + "\t" + "Var3"

                for (int i = 0; i < objec_Num; i++)
                {
                    string str = rd.ReadLine();
                    str = str.Replace("\t\t\t", "\t");
                    str = str.Replace("\t\t", "\t");
                    s = str.Split('\t');
                    int id = int.Parse(s[0]);
                    int type = int.Parse(s[1]);
                    int item = int.Parse(s[2]);
                    int x = int.Parse(s[3]);
                    int y = int.Parse(s[4]);
                    int v1 = int.Parse(s[5]);
                    int v2 = int.Parse(s[6]);
                    int v3 = int.Parse(s[7]);
                    Objects o = new Objects(id, type, item, v1, v2, v3, new Point(x,y));
                    this.listObject.Add(o);
                }

                rd.ReadLine(); //END_OBJECT_LIST
                rd.ReadLine(); //Space
                rd.ReadLine(); //QUAD_TREE
                rd.ReadLine(); //(....)

                root_node.Load(rd, this.listObject);

                rd.ReadLine(); //END_QUAD_TREE

                rd.Close();
                fs.Close();

                string tiles_dir = dir.Split('.')[0] + ".bmp";
                Bitmap background = new Bitmap(tiles_dir);

                float scale = 160.0f / background.Width;
                Rectangle rect = new Rectangle(0, 0, (int)(background.Width * scale), (int)(background.Height * scale));
                Bitmap bm = background.Clone(rect, background.PixelFormat);
                using (Graphics g = Graphics.FromImage(bm))
                {
                    g.InterpolationMode = InterpolationMode.NearestNeighbor;
                    g.DrawImage(background, 0, 0, (int)(background.Width * scale), (int)(background.Height * scale));
                    background = bm;
                }

                for (int k = 0; k < tiles_Num; k++ )
                {
                    Rectangle r2 = new Rectangle(k % 20 *8, k / 20 *8, 8, 8);
                    Bitmap b = background.Clone(r2, background.PixelFormat);
                    tilesList.Add(b);
                }
            } 
        }
    }
}
