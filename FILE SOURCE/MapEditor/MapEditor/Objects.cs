using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace MapEditor
{
    public class Objects
    {
        private int id;

        public int Id
        {
            get { return id; }
            set { id = value; }
        }

        private int type;

        public int Type
        {
            get { return type; }
            set { type = value; }
        }

        private int item;

        public int Item
        {
            get { return item; }
            set { item = value; }
        }

        private Point point;

        public Point Point
        {
            get { return point; }
            set { point = value; }
        }

        private Size size;

        public Size Size
        {
            get { return size; }
            set { size = value; }
        }

        private int value_1;

        public int Value_1
        {
            get { return value_1; }
            set 
            { 
                value_1 = value;
                if (type == 1)
                    this.size = new Size(value_1 * 32, value_2 * 32);
                if (type == 2 || type == 3)
                    this.size = new Size(value_1 * 32, value_1 * 32);
                if (type == 22)
                    this.size = new Size(value_1 * 32, value_2 * 32);
            }
        }

        private int value_2;

        public int Value_2
        {
            get { return value_2; }
            set
            {
                value_2 = value;
                if (type == 1)
                    this.size = new Size(value_1 * 32, value_2 * 32);
                if (type == 22)
                    this.size = new Size(value_1 * 32, value_2 * 32);
            }
        }

        private int value_3;

        public int Value_3
        {
            get { return value_3; }
            set { value_3 = value; }
        }

        public Objects(int id, string type, string item,int var1, int var2, int var3, Point point)
        {
            this.id = id;
            this.type = getTypeIDByName(type);
            this.point = point;
            this.item = getItemIDByName(item);
            this.value_1 = var1;
            this.value_2 = var2;
            this.value_3 = var3;
            Bitmap image = getImageByType();

            this.size = new Size(image.Width, image.Height);
        }

        public Objects(int id, int type, int item, int var1, int var2, int var3, Point point)
        {
            this.id = id;
            this.type = type;
            this.point = point;
            this.item = item;
            this.value_1 = var1;
            this.value_2 = var2;
            this.value_3 = var3;
            Bitmap image = getImageByType();

            this.size = new Size(image.Width, image.Height);
        }

        public Bitmap getImageByType()
        {
            Bitmap img = new Bitmap(32, 32);
            switch (type)
            {
                case 1:
                    img = new Bitmap(32 * value_1 + 1, 32 * value_2 + 1);
                    using (Graphics g = Graphics.FromImage(img))
                    {
                        Bitmap tmpBM = global::MapEditor.Properties.Resources.ground_brick;
                        for (int i = 0; i < value_1; i++)
                            for (int j = 0; j < value_2; j++)
                            {
                                g.DrawImage(tmpBM, new Point(i * 32, j * 32));
                            }
                    }

                    break;
                case 2:
                    img = new Bitmap(32 * value_1 + 1, 32 * value_1 + 1);
                    using (Graphics g = Graphics.FromImage(img))
                    {
                        Bitmap tmpBM = global::MapEditor.Properties.Resources.ground_stair_up;
                        for (int i = 0; i < value_1; i++)
                            g.DrawImage(tmpBM, new Rectangle(i * 32, (value_1 - 1 - i) * 32, 32, 32));
                    }
                    break;
                case 3:
                    img = new Bitmap(32 * value_1 + 1, 32 * value_1 + 1);
                    using (Graphics g = Graphics.FromImage(img))
                    {
                        Bitmap tmpBM = global::MapEditor.Properties.Resources.ground_stair_down;
                        for (int i = 0; i < value_1; i++)
                            g.DrawImage(tmpBM, new Rectangle(i * 32, i * 32, 32, 32));
                    }
                    break;
                case 4:
                    img = global::MapEditor.Properties.Resources.ground_firecandle;
                    break;
                case 5:
                    img = global::MapEditor.Properties.Resources.ground_firetower;
                    break;
                case 6:
                    img = global::MapEditor.Properties.Resources.ground_lockdoor;
                    break;
                case 7:
                    img = global::MapEditor.Properties.Resources.ground_moving_brick;
                    break;
                case 8:
                    img = global::MapEditor.Properties.Resources.ground_opendoor;
                    break;
                case 9:
                    img = global::MapEditor.Properties.Resources.ground_trap;
                    break;
                case 10:
                    img = global::MapEditor.Properties.Resources.enemy_bat;
                    break;
                case 11:
                    img = global::MapEditor.Properties.Resources.enemy_bonepillar;
                    break;
                case 12:
                    img = global::MapEditor.Properties.Resources.enemy_ghost;
                    break;
                case 13:
                    img = global::MapEditor.Properties.Resources.enemy_medusahead;
                    break;
                case 14:
                    img = global::MapEditor.Properties.Resources.enemy_merman;
                    break;
                case 15:
                    img = global::MapEditor.Properties.Resources.enemy_panther;
                    break;
                case 16:
                    img = global::MapEditor.Properties.Resources.enemy_spearguard;
                    break;
                case 17:
                    img = global::MapEditor.Properties.Resources.enemy_zombie;
                    break;
                case 18:
                    img = global::MapEditor.Properties.Resources.boss_bat;
                    break;
                case 19:
                    img = global::MapEditor.Properties.Resources.boss_medusa;
                    break;
                case 20:
                    img = global::MapEditor.Properties.Resources.ground_hidden_brick;
                    break;
                case 21:
                    img = global::MapEditor.Properties.Resources.ground_go_in_castle;
                    break;
                case 22:
                    img = new Bitmap(32 * value_1 + 1, 32 * value_2 + 1);
                    using (Graphics g = Graphics.FromImage(img))
                    {
                        Bitmap tmpBM = global::MapEditor.Properties.Resources.ground_death;
                        for (int i = 0; i < value_1; i++)
                            for (int j = 0; j < value_2; j++)
                            {
                                g.DrawImage(tmpBM, new Point(i * 32, j * 32));
                            }
                    }
                    break;
                default:
                    img = global::MapEditor.Properties.Resources.simon;
                    break;
            } 

            return img;
        }

        public int getTypeIDByName(string name)
        {
            switch (name)
            {
                case "ground_brick":
                    return 1;
                case "ground_stair_up":
                    return 2;
                case "ground_stair_down":
                    return 3;
                case "ground_firecandle":
                    return 4;
                case "ground_firetower":
                    return 5;
                case "ground_lockdoor":
                    return 6;
                case "ground_moving_brick":
                    return 7;
                case "ground_opendoor":
                    return 8;
                case "ground_trap":
                    return 9;
                case "enemy_bat":
                    return 10;
                case "enemy_bonepillar":
                    return 11;
                case "enemy_ghost":
                    return 12;
                case "enemy_medusahead":
                    return 13;
                case "enemy_merman":
                    return 14;
                case "enemy_panther":
                    return 15;
                case "enemy_spearguard":
                    return 16;
                case "enemy_zombie":
                    return 17;
                case "boss_bat":
                    return 18;
                case "boss_medusa":
                    return 19;
                case "ground_hidden_brick":
                    return 20;
                case "ground_go_in_castle":
                    return 21;
                case "ground_death":
                    return 22;
                default:
                    return 0;
            }
        }

        public string getTypeNameById()
        {
            switch (type)
            {
                case 1:
                    return "ground_brick";
                case 2:
                    return "ground_stair_up";
                case 3:
                    return "ground_stair_down";
                case 4:
                    return "ground_firecandle";
                case 5:
                    return "ground_firetower";
                case 6:
                    return "ground_lockdoor";
                case 7:
                    return "ground_moving_brick";
                case 8:
                    return "ground_opendoor";
                case 9:
                    return "ground_trap";
                case 10:
                    return "enemy_bat";
                case 11:
                    return "enemy_bonepillar";
                case 12:
                    return "enemy_ghost";
                case 13:
                    return "enemy_medusahead";
                case 14:
                    return "enemy_merman";
                case 15:
                    return "enemy_panther";
                case 16:
                    return "enemy_spearguard";
                case 17:
                    return "enemy_zombie";
                case 18:
                    return "boss_bat";
                case 19:
                    return "boss_medusa";
                case 20:
                    return "ground_hidden_brick";
                case 21:
                    return "ground_go_in_castle";
                case 22:
                    return "ground_death";
                default:
                    return "simon";
            }
        }

        public Image getImageByItem()
        {
            Image img = new Bitmap(32, 32);
            switch (item)
            {
                case 1:
                    img = global::MapEditor.Properties.Resources.item_axe;
                    break;
                case 2:
                    img = global::MapEditor.Properties.Resources.item_big_heart;
                    break;
                case 3:
                    img = global::MapEditor.Properties.Resources.item_cross;
                    break;
                case 4:
                    img = global::MapEditor.Properties.Resources.item_double_shot;
                    break;
                case 5:
                    img = global::MapEditor.Properties.Resources.item_holy_water;
                    break;
                case 6:
                    img = global::MapEditor.Properties.Resources.item_knife;
                    break;
                case 7:
                    img = global::MapEditor.Properties.Resources.item_money_bag;
                    break;
                case 8:
                    img = global::MapEditor.Properties.Resources.item_morning_star;
                    break;
                case 9:
                    img = global::MapEditor.Properties.Resources.item_roast;
                    break;
                case 10:
                    img = global::MapEditor.Properties.Resources.item_rosary;
                    break;
                case 11:
                    img = global::MapEditor.Properties.Resources.item_spirit_ball;
                    break;
                case 12:
                    img = global::MapEditor.Properties.Resources.item_stop_watch;
                    break;
                case 13:
                    img = global::MapEditor.Properties.Resources.item_none;
                    break;
                default:
                    img = global::MapEditor.Properties.Resources.item_small_heart;
                    break;
            }

            return img;
        }

        public int getItemIDByName(string name)
        {
            switch (name)
            {
                case "item_axe":
                    return 1;
                case "item_big_heart":
                    return 2;
                case "item_cross":
                    return 3;
                case "item_double_shot":
                    return 4;
                case "item_holy_water":
                    return 5;
                case "item_knife":
                    return 6;
                case "item_money_bag":
                    return 7;
                case "item_morning_star":
                    return 8;
                case "item_roast":
                    return 9;
                case "item_rosary":
                    return 10;
                case "item_spirit_ball":
                    return 11;
                case "item_stop_watch":
                    return 12;
                case "item_none":
                    return 13;
                default:
                    return 0;
            }
        }

        public string getItemNameById()
        {
            switch (item)
            {
                case 1:
                    return "item_axe";
                case 2:
                    return "item_big_heart";
                case 3:
                    return "item_cross";
                case 4:
                    return "item_double_shot";
                case 5:
                    return "item_holy_water";
                case 6:
                    return "item_knife";
                case 7:
                    return "item_money_bag";
                case 8:
                    return "item_morning_star";
                case 9:
                    return "item_roast";
                case 10:
                    return "item_rosary";
                case 11:
                    return "item_spirit_ball";
                case 12:
                    return "item_stop_watch";
                case 13:
                    return "item_none";
                default:
                    return "item_small_heart";
            }
        }
        
    }
}
