using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;

namespace MapEditor
{
    public class Node
    {
        private string id;
        private Rectangle rec;
        private List<Objects> listObjects;
        private Node LeftTop;
        private Node RightTop;
        private Node LeftBot;
        private Node RightBot;

        public Node(string _id, Rectangle _rec)
        {
            this.id = _id;
            this.rec = _rec;
            listObjects = new List<Objects>();
            LeftTop = null;
            RightTop = null;
            LeftBot = null;
            RightBot = null;
        }

        public bool IsEmpty 
        { 
            get 
            {
                if (LeftBot == null && listObjects.Count == 0)
                    return true;
                return false;
            } 
        }

        public string Id { get { return id; } }

        public RectangleF Rec { get { return rec; } }

        public int Count
        {
            get
            {
                int count = 0;

                if (LeftBot!=null)
                {
                    count += LeftTop.Count;
                    count += RightTop.Count;
                    count += LeftBot.Count;
                    count += RightBot.Count;
                }
                count += this.listObjects.Count;

                return count;
            }
        }

        public List<Objects> ListObjects { get { return listObjects; } }

        public List<Objects> SubTreeObjects
        {
            get
            {
                List<Objects> results = new List<Objects>();

                if (LeftBot != null)
                {
                    results.AddRange(LeftTop.SubTreeObjects);
                    results.AddRange(RightTop.SubTreeObjects);
                    results.AddRange(LeftBot.SubTreeObjects);
                    results.AddRange(RightBot.SubTreeObjects);
                }

                results.AddRange(this.listObjects);
                return results;
            }
        }

        public void Insert(Objects _obj)
        {
            Rectangle r = new Rectangle(_obj.Point, _obj.Size);

            if (LeftBot == null)
                CreateSubNodes();

            if (LeftTop != null && LeftTop.rec.Contains(r))
            {
                LeftTop.Insert(_obj);
                return;
            }
            if (RightTop != null && RightTop.rec.Contains(r))
            {
                RightTop.Insert(_obj);
                return;
            }
            if (LeftBot != null && LeftBot.rec.Contains(r))
            {
                LeftBot.Insert(_obj);
                return;
            }
            if (RightBot != null && RightBot.rec.Contains(r))
            {
                RightBot.Insert(_obj);
                return;
            } 
            
            this.listObjects.Add(_obj);
        }

        private void CreateSubNodes()
        {
            if (rec.Width <= 640 || rec.Height < 176)
                return;

            int halfWidth = rec.Width / 2;
            int halfHeight = rec.Height / 2;

            LeftTop  = new Node(this.id + "0" ,new Rectangle(rec.Location, new Size(halfWidth, halfHeight)));
            RightTop = new Node(this.id + "1" ,new Rectangle(new Point(rec.Left + halfWidth, rec.Top), new Size(halfWidth, halfHeight)));
            LeftBot  = new Node(this.id + "2" ,new Rectangle(new Point(rec.Left, rec.Top + halfHeight), new Size(halfWidth, halfHeight)));
            RightBot = new Node(this.id + "3", new Rectangle(new Point(rec.Left + halfWidth, rec.Top + halfHeight), new Size(halfWidth, halfHeight)));
        }

        public List<Objects> Query(Rectangle queryArea)
        {
            // create a list of the items that are found
            List<Objects> results = new List<Objects>();

            // this quad contains items that are not entirely contained by
            // it's four sub-quads. Iterate through the items in this quad 
            // to see if they intersect.
            foreach (Objects obj in this.listObjects)
            {
                Rectangle r = new Rectangle(obj.Point, obj.Size);
                if (queryArea.IntersectsWith(r))
                    results.Add(obj);
            }

            if (LeftTop!=null)
            {
                if (LeftTop.rec.Contains(queryArea))
                    results.AddRange(LeftTop.Query(queryArea));

                if (queryArea.Contains(LeftTop.rec))
                    results.AddRange(LeftTop.SubTreeObjects);

                if (LeftTop.rec.IntersectsWith(queryArea))
                    results.AddRange(LeftTop.Query(queryArea));
            }

            if (RightTop != null)
            {
                if (RightTop.rec.Contains(queryArea))
                    results.AddRange(RightTop.Query(queryArea));

                if (queryArea.Contains(RightTop.rec))
                    results.AddRange(RightTop.SubTreeObjects);

                if (RightTop.rec.IntersectsWith(queryArea))
                    results.AddRange(RightTop.Query(queryArea));
            }

            if (LeftBot != null)
            {
                if (LeftBot.rec.Contains(queryArea))
                    results.AddRange(LeftTop.Query(queryArea));

                if (queryArea.Contains(LeftBot.rec))
                    results.AddRange(LeftBot.SubTreeObjects);

                if (LeftBot.rec.IntersectsWith(queryArea))
                    results.AddRange(LeftBot.Query(queryArea));
            }

            if (RightBot != null)
            {
                if (RightBot.rec.Contains(queryArea))
                    results.AddRange(RightBot.Query(queryArea));

                if (queryArea.Contains(RightBot.rec))
                    results.AddRange(RightBot.SubTreeObjects);

                if (RightBot.rec.IntersectsWith(queryArea))
                    results.AddRange(RightBot.Query(queryArea));
            }


            return results;
        }

        public void Save(StreamWriter sw)
        {
            int subnode = 0;
            if (LeftTop != null)
                subnode = 4;
            sw.Write(rec.X.ToString("00000") + "\t\t" + rec.Y.ToString("00000") + "\t\t" + rec.Width.ToString("00000") + "\t\t" + rec.Height.ToString("00000") + "\t\t" + subnode + "\t\t\t" + listObjects.Count + "\t\t\t");
            if (listObjects.Count > 0)
                foreach (Objects o in listObjects)
                    sw.Write(o.Id + "\t");
            sw.WriteLine();
            if (LeftTop !=null)
            {
                LeftTop.Save(sw);
                RightTop.Save(sw);
                LeftBot.Save(sw);
                RightBot.Save(sw);
            }
        }

        public void Load(StreamReader rd, List<Objects> l_Obj)
        {
            string str = rd.ReadLine();
            str = str.Replace("\t\t\t", "\t");
            str = str.Replace("\t\t", "\t");
            string[] s = str.Split('\t');

            int x = int.Parse(s[0]);
            int y = int.Parse(s[1]);
            int w = int.Parse(s[2]);
            int h = int.Parse(s[3]);
            int n_c = int.Parse(s[4]);
            int o_c = int.Parse(s[5]);

            this.rec.X = x;
            this.rec.Y = y;
            this.rec.Width = w;
            this.rec.Height = h;
            this.listObjects.Clear();

            for (int i = 0; i < o_c; i++ )
            {
                int k = int.Parse(s[6+i]);
                listObjects.Add(l_Obj[k]);
            }

            if (n_c == 4)
            {
                CreateSubNodes();
                if (LeftTop != null)
                {
                    LeftTop.Load(rd, l_Obj);
                    RightTop.Load(rd, l_Obj);
                    LeftBot.Load(rd, l_Obj);
                    RightBot.Load(rd, l_Obj);
                }
            }
        }
    }

}
