using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace Map_Editor
{
    public enum EObjectName
    {
        NONE = 0,
        MARIO = 1,

        ENEMY,
        TURTLE,
        FLYING_TURTLE,

        MUSHROOM,
        MUSHROOM_BLOCK,
        FLOWER,
        FLOWER_BLOCK,
        LIFE_MUSHROOM,
        LIFE_MUSHROOM_BLOCK,
        COIN,
        COIN_BRICK,
        COIN_BLOCK,
        STAR,
        STAR_BLOCK,

        BLOCK,
        BRICK,
        CLOUD,
        BAR,
        GODOWN_BAR,
        GOUP_BAR,
        HORIZONTAL_BAR,
        CARNIVOROUSFLOWER,
        CARNIVOROUSFLOWER_PIPE,
        PIPE,
        CREEP_PIPE_1,
        CREEP_PIPE_2,
        CREEP_UP_PIPE_1,
        CREEP_UP_PIPE_2,
        HORIZONTAL_PIPE_1,
        HORIZONTAL_PIPE_2,
        LEFT_LAND,
        LAND,
        RIGHT_LAND,
        FENCE,
        GRASS,
        MOUNTAIN,
        SIGN,
        LAMP,
        TREE,
        BIG_TREE,
        TOWER,

        MACHINE,
	    SPRING,
	    TURTLE2,
        FLAG_POSITION,
    }

    public enum ObjectType
    {
        STATIC,
        NON_STATIC
    }

    public class Factory
    {
        // chuyển tới kích thước chuẩn trong game
        public static void ConvertToStandardImage(System.Windows.Controls.Image image, out int width, out int height)
        {
            int id = (int)image.Tag;

            switch ((EObjectName)id)
            {
                case EObjectName.MARIO:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.ENEMY:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.TURTLE:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.FLYING_TURTLE:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.MUSHROOM:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.MUSHROOM_BLOCK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.FLOWER:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.FLOWER_BLOCK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.LIFE_MUSHROOM:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.LIFE_MUSHROOM_BLOCK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.COIN:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.COIN_BRICK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.COIN_BLOCK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.STAR:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.STAR_BLOCK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.BLOCK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.BRICK:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.CLOUD:
                    width = 3 * MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.BAR:
                    width = 4 * MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.GODOWN_BAR:
                    width = 4 * MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.GOUP_BAR:
                    width = 4 * MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.HORIZONTAL_BAR:
                    width = 4 * MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.CARNIVOROUSFLOWER:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.CARNIVOROUSFLOWER_PIPE:
                    width = 2 * MainWindow.OBJECT_WIDTH;
                    height = 3 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.PIPE:
                    width = 2 * MainWindow.OBJECT_WIDTH;
                    height = 3 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.CREEP_PIPE_1:
                case EObjectName.CREEP_PIPE_2:
                case EObjectName.CREEP_UP_PIPE_1:
                case EObjectName.CREEP_UP_PIPE_2:
                    width = 2 * MainWindow.OBJECT_WIDTH;
                    height = 3 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.HORIZONTAL_PIPE_1:
                case EObjectName.HORIZONTAL_PIPE_2:
                    width = 3 * MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.LEFT_LAND:
                    width = MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.LAND:
                    width = MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.RIGHT_LAND:
                    width = MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.FENCE:
                    width = 2 * MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.GRASS:
                    width = 2 * MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.MOUNTAIN:
                    width = 6 * MainWindow.OBJECT_WIDTH;
                    height = 3 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.SIGN:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.LAMP:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.TREE:
                    width = MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.BIG_TREE:
                    width = MainWindow.OBJECT_WIDTH;
                    height = 3 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.TOWER:
                    width = 6 * MainWindow.OBJECT_WIDTH;
                    height = 8 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.MACHINE:
                    width = 2 * MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.SPRING:
                    width = MainWindow.OBJECT_WIDTH;
                    height = 2 * MainWindow.OBJECT_HEIGHT;
                    break;
                case EObjectName.TURTLE2:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
                default:
                    width = MainWindow.OBJECT_WIDTH;
                    height = MainWindow.OBJECT_HEIGHT;
                    break;
            }
        }

        public static BitmapImage GetBitmapImage(EObjectName type)
        {
            BitmapImage bitmap = null;
            switch (type)
            {
                case EObjectName.MARIO:
                    bitmap = new BitmapImage(new Uri(@"\Images\Mario\SmallMario.png", UriKind.Relative));
                    break;
                case EObjectName.ENEMY:
                    bitmap = new BitmapImage(new Uri(@"\Images\Enemy\Enemy.png", UriKind.Relative));
                    break;
                case EObjectName.TURTLE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Enemy\Turtle.png", UriKind.Relative));
                    break;
                case EObjectName.FLYING_TURTLE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Enemy\FlyingTurtle.png", UriKind.Relative));
                    break;
                case EObjectName.MUSHROOM:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\Mushroom.png", UriKind.Relative));
                    break;
                case EObjectName.MUSHROOM_BLOCK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\MushroomBlock.png", UriKind.Relative));
                    break;
                case EObjectName.FLOWER:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\Flower.png", UriKind.Relative));
                    break;
                case EObjectName.FLOWER_BLOCK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\FlowerBlock.png", UriKind.Relative));
                    break;
                case EObjectName.LIFE_MUSHROOM:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\LifeMushroom.png", UriKind.Relative));
                    break;
                case EObjectName.LIFE_MUSHROOM_BLOCK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\LifeMushroomBlock.png", UriKind.Relative));
                    break;
                case EObjectName.COIN:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\Coin.png", UriKind.Relative));
                    break;
                case EObjectName.COIN_BRICK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\CoinBrick.png", UriKind.Relative));
                    break;
                case EObjectName.COIN_BLOCK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\CoinBlock.png", UriKind.Relative));
                    break;
                case EObjectName.STAR:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\Star.png", UriKind.Relative));
                    break;
                case EObjectName.STAR_BLOCK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Bonus\StarBlock.png", UriKind.Relative));
                    break;
                case EObjectName.BLOCK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Block.png", UriKind.Relative));
                    break;
                case EObjectName.BRICK:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Brick.png", UriKind.Relative));
                    break;
                case EObjectName.CLOUD:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Cloud.png", UriKind.Relative));
                    break;
                case EObjectName.BAR:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Bar.png", UriKind.Relative));
                    break;
                case EObjectName.GODOWN_BAR:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\GoDownBar.png", UriKind.Relative));
                    break;
                case EObjectName.GOUP_BAR:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\GoUpBar.png", UriKind.Relative));
                    break;
                case EObjectName.HORIZONTAL_BAR:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\HorizontalBar.png", UriKind.Relative));
                    break;
                case EObjectName.CARNIVOROUSFLOWER:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\CarnivorousFlower.png", UriKind.Relative));
                    break;
                case EObjectName.CARNIVOROUSFLOWER_PIPE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\CarnivorousFlowerPipe.png", UriKind.Relative));
                    break;
                case EObjectName.PIPE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Pipe.png", UriKind.Relative));
                    break;
                case EObjectName.CREEP_PIPE_1:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\CreepPipe1.png", UriKind.Relative));
                    break;
                case EObjectName.CREEP_PIPE_2:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\CreepPipe2.png", UriKind.Relative));
                    break;
                case EObjectName.CREEP_UP_PIPE_1:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\CreepUpPipe1.png", UriKind.Relative));
                    break;
                case EObjectName.CREEP_UP_PIPE_2:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\CreepUpPipe2.png", UriKind.Relative));
                    break;
                case EObjectName.HORIZONTAL_PIPE_1:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\HorizontalPipe1.png", UriKind.Relative));
                    break;
                case EObjectName.HORIZONTAL_PIPE_2:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\HorizontalPipe2.png", UriKind.Relative));
                    break;
                case EObjectName.LEFT_LAND:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\LeftLand.png", UriKind.Relative));
                    break;
                case EObjectName.LAND:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Land.png", UriKind.Relative));
                    break;
                case EObjectName.RIGHT_LAND:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\RightLand.png", UriKind.Relative));
                    break;
                case EObjectName.FENCE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Fence.png", UriKind.Relative));
                    break;
                case EObjectName.GRASS:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Grass.png", UriKind.Relative));
                    break;
                case EObjectName.MOUNTAIN:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Mountain.png", UriKind.Relative));
                    break;
                case EObjectName.SIGN:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Sign.png", UriKind.Relative));
                    break;
                case EObjectName.LAMP:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Lamp.png", UriKind.Relative));
                    break;
                case EObjectName.TREE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Tree.png", UriKind.Relative));
                    break;
                case EObjectName.BIG_TREE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Tree2.png", UriKind.Relative));
                    break;
                case EObjectName.TOWER:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Tower.png", UriKind.Relative));
                    break;
                case EObjectName.MACHINE:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Machine.png", UriKind.Relative));
                    break;
                case EObjectName.TURTLE2:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Turtle2.png", UriKind.Relative));
                    break;
                case EObjectName.SPRING:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\Spring.png", UriKind.Relative));
                    break;
                case EObjectName.FLAG_POSITION:
                    bitmap = new BitmapImage(new Uri(@"\Images\Other\FlagPosition.png", UriKind.Relative));
                    break;
                default:
                    break;
            }

            return bitmap;
        }

        // Chuyển từ QNode -> Node để lưu
        public static List<Node> TransformFromQNodeToNode(List<QNode> listQNodes)
        {
            List<Node> nodes = new List<Node>();

            if (listQNodes.Count == null || listQNodes.Count == 0)
                return null;

            foreach (var item in listQNodes)
            {
                Node tmpNode = new Node();

                // lấy thông tin QNode
                tmpNode.ID = item.ID;
                tmpNode.X = item.Bound.X;
                tmpNode.Y = item.Bound.Y;
                tmpNode.Width = item.Bound.Width;
                tmpNode.Height = item.Bound.Height;

                // lấy thông tin các đối tượng trong QNode
                tmpNode.GameObjects = new GameObject[item.ListObjects.Count];
                if (item.ListObjects.Count > 0)
                {
                    for (int i = 0; i < item.ListObjects.Count; i++)
                    {
                        GameObject go = new GameObject();

                        go.ID = item.ListObjects[i].ID;
                        go.Type = item.ListObjects[i].Type;
                        go.X = item.ListObjects[i].Bound.X + item.ListObjects[i].Bound.Width / 2; // chuyển tọa độ vào tâm
                        go.Y = item.ListObjects[i].Bound.Y - item.ListObjects[i].Bound.Height / 2; // chuyển tọa độ vào tâm

                        tmpNode.GameObjects[i] = go;
                    }
                }

                nodes.Add(tmpNode);
            }

            return nodes;
        }

        // kiểm tra 1 đối tượng là động hay tĩnh <có thể di chuyển được>
        public static ObjectType CheckObjectType(EObjectName obj)
        {
            switch (obj)
            {
                case EObjectName.ENEMY:
                case EObjectName.TURTLE:
                case EObjectName.FLYING_TURTLE:
                case EObjectName.MUSHROOM:
                case EObjectName.MUSHROOM_BLOCK:
                case EObjectName.LIFE_MUSHROOM:
                case EObjectName.LIFE_MUSHROOM_BLOCK:
                case EObjectName.STAR:
                case EObjectName.STAR_BLOCK:
                case EObjectName.BAR:
                case EObjectName.GODOWN_BAR:
                case EObjectName.GOUP_BAR:
                case EObjectName.HORIZONTAL_BAR:
                case EObjectName.MACHINE:
                case EObjectName.TURTLE2:
                    return ObjectType.NON_STATIC;
                default:
                    return ObjectType.STATIC;
            }
        }

        // kiểm tra xem đối tượng có thể xét va chạm đc k
        public static bool CheckObjectCollisionAbility(EObjectName obj)
        {
            switch (obj)
            {
                case EObjectName.CLOUD:
                case EObjectName.FENCE:
                case EObjectName.GRASS:
                case EObjectName.MOUNTAIN:
                case EObjectName.SIGN:
                case EObjectName.LAMP:
                case EObjectName.TREE:
                case EObjectName.BIG_TREE:
                case EObjectName.FLAG_POSITION:
                case EObjectName.MARIO: 
                    return false;
                default:
                    return true;
            }
        }
    }
}
