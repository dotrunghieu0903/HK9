#ifndef _BUILD_H_
#define _BUILD_H_


#include "TextureManagement.h"

#include "Map.h"
#include "QuadTree.h"
#include "MarioPlayer.h"
#include "Enemy.h"
#include "Turtle.h"
#include "Turtle2.h"
#include "Brick.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Flower.h"
#include "Grass.h"
#include "Cloud.h"
#include "CarnivorousFlower.h"
#include "Bar.h"
#include "SecretBlock.h"
#include "Pipe.h"
#include "OtherObj.h"
#include "Star.h"
#include "Machine.h"
#include "Spring.h"


enum EQuadTreeType
{
	DRAW,
	UPDATE
};


static BaseObject* MakeObject(EObjectName type, D3DXVECTOR2 pos)
{
	TextureManagement *tm = TextureManagement::GetInstance();
	BaseObject *obj = NULL;
	switch (type)
	{
		// enemy
	case EObjectName::ENEMY_OBJECT: 
		obj = new Enemy(tm->Get(EOTexture::ENEMY_TEXTURE), pos);
		break;
	case EObjectName::TURTLE_OBJECT: 
		obj = new Turtle(tm->Get(EOTexture::TURTLE_TEXTURE), pos, NORMAL_TURTLE);
		break;
	case EObjectName::FLYING_TURTLE_OBJECT:
		obj = new Turtle(tm->Get(EOTexture::TURTLE_TEXTURE), pos, FLYING_TURTLE);
		break;
	case EObjectName::TURTLE2_OBJECT:
		obj = new Turtle2(tm->Get(EOTexture::TURTLE2_TEXTURE), pos);
		break;
			
	case EObjectName::MUSHROOM_OBJECT:
		obj = new Mushroom(tm->Get(EOTexture::MUSHROOM_TEXTURE), pos, ETypeOfMushroom::NORMAL_MUSHROOM);
		break;
	case EObjectName::MUSHROOM_BLOCK_OBJECT:
		obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::MUSHROOM_TEXTURE), ETypefOfSecretBlock::NORMAL_MUSHROOM_SECRET_BLOCK);
		break;
	case EObjectName::FLOWER_OBJECT:
		obj = new Flower(tm->Get(EOTexture::FLOWER_TEXTURE), pos);
		break;
	case EObjectName::FLOWER_BLOCK_OBJECT:
		obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::FLOWER_TEXTURE), ETypefOfSecretBlock::FLOWER_SECRET_BLOCK);
		break;
	case EObjectName::LIFE_MUSHROOM_OBJECT:
		obj = new Mushroom(tm->Get(EOTexture::MUSHROOM_TEXTURE), pos, ETypeOfMushroom::LIFE_MUSHROOM);
		break;
	case EObjectName::LIFE_MUSHROOM_BLOCK_OBJECT:
		obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::MUSHROOM_TEXTURE), ETypefOfSecretBlock::LIFE_MUSHROOM_SECRET_BLOCK);
		break;
	case EObjectName::COIN_OBJECT:
		obj = new Coin(tm->Get(EOTexture::COIN_TEXTURE), pos);
		break;
	case EObjectName::COIN_BRICK_OBJECT:
		obj = new Brick(tm->Get(EOTexture::BRICK_TEXTURE), tm->Get(EOTexture::EXPLOREDBRICK_TEXTURE), pos, tm->Get(EOTexture::COIN_TEXTURE), true);
		break;
	case EObjectName::COIN_BLOCK_OBJECT:
		obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::COIN_TEXTURE), ETypefOfSecretBlock::COIN_SECRET_BLOCK);
		break;
	case EObjectName::STAR_OBJECT:
		obj = new Star(tm->Get(EOTexture::STAR_TEXTURE), pos);
		break;
	case EObjectName::STAR_BLOCK_OBJECT:
		obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::STAR_TEXTURE), ETypefOfSecretBlock::STAR_SECRET_BLOCK);
		break;

	case EObjectName::BLOCK_OBJECT:
		obj = new Block(tm->Get(EOTexture::BLOCK_TEXTURE), pos);
		break;
	case EObjectName::BRICK_OBJECT:
		obj = new Brick(tm->Get(EOTexture::BRICK_TEXTURE), tm->Get(EOTexture::EXPLOREDBRICK_TEXTURE), pos, tm->Get(EOTexture::COIN_TEXTURE), false);
		break;
	case EObjectName::CLOUD_OBJECT:
		obj = new Cloud(tm->Get(EOTexture::CLOUD_TEXTURE), pos);
		break;
	case EObjectName::BAR_OBJECT:
		obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, NORMAL_BAR);
		break;
	case EObjectName::GODOWN_BAR_OBJECT:
		obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, GODOWN_BAR);
		break;
	case EObjectName::GOUP_BAR_OBJECT:
		obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, GOUP_BAR);
		break;
	case EObjectName::HORIZONTAL_BAR_OBJECT:
		obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, HORIZONTAL_BAR);
		break;
	case EObjectName::CARNIVOROUSFLOWER_OBJECT:
		obj = new CarnivorousFlower(tm->Get(EOTexture::CARNIVOROUSFLOWER_TEXTURE), pos);
		break;
	case EObjectName::CARNIVOROUSFLOWER_PIPE_OBJECT:
		obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::NONE_ENTRY, tm->Get(EOTexture::CARNIVOROUSFLOWER_TEXTURE));
		break;
	case EObjectName::PIPE_OBJECT:
		obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos);
		break;
	case EObjectName::CREEP_PIPE_OBJECT_1:
		obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::FIRST_ENTRY);
		break;
	case EObjectName::CREEP_PIPE_OBJECT_2:
		obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::SECOND_ENTRY);
		break;
	case EObjectName::CREEP_UP_PIPE_OBJECT_1:
		obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::FIRST_EXIT);
		break;
	case EObjectName::CREEP_UP_PIPE_OBJECT_2:
		obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::SECOND_EXIT);
		break;
	case EObjectName::HORIZONTAL_PIPE_OBJECT_1:
		obj = new Pipe(tm->Get(EOTexture::HORIZONTALPIPE_TEXTURE), pos, EntryNumber::SUB_FIRST_ENTRY);
		break;
	case EObjectName::HORIZONTAL_PIPE_OBJECT_2:
		obj = new Pipe(tm->Get(EOTexture::HORIZONTALPIPE_TEXTURE), pos, EntryNumber::SUB_SECOND_ENTRY);
		break;
	case EObjectName::LEFT_LAND_OBJECT:
		obj = new Land(tm->Get(EOTexture::LAND_TEXTURE), pos, TypeOfLand::LEFT_LAND);
		break;
	case EObjectName::LAND_OBJECT:
		obj = new Land(tm->Get(EOTexture::LAND_TEXTURE), pos);
		break;
	case EObjectName::RIGHT_LAND_OBJECT:
		obj = new Land(tm->Get(EOTexture::LAND_TEXTURE), pos, TypeOfLand::RIGHT_LAND);
		break;
			
	case EObjectName::FENCE_OBJECT:
		obj = new Scene(tm->Get(EOTexture::FENCE_TEXTURE), pos, ESceneObject::FENCE);
		break;

	case EObjectName::GRASS_OBJECT:
		obj = new Grass(tm->Get(EOTexture::GRASS_TEXTURE), pos);
		break;
			
	case EObjectName::MOUNTAIN_OBJECT:
		obj = new Scene(tm->Get(EOTexture::MOUNTAIN_TEXTURE), pos, ESceneObject::MOUNTAIN);
		break;

	case EObjectName::SIGN_OBJECT:
		obj = new Scene(tm->Get(EOTexture::SIGN_TEXTURE), pos, ESceneObject::SIGN);
		break;

	case EObjectName::LAMP_OBJECT:
		obj = new Scene(tm->Get(EOTexture::LAMP_TEXTURE), pos, ESceneObject::LAMP);
		break;

	case EObjectName::TREE_OBJECT:
		obj = new Scene(tm->Get(EOTexture::TREE_TEXTURE), pos, ESceneObject::TREE);
		break;

	case EObjectName::BIG_TREE_OBJECT:
		obj = new Scene(tm->Get(EOTexture::TREE2_TEXTURE), pos, ESceneObject::BIG_TREE);
		break;

	case EObjectName::TOWER_OBJECT:
		obj = new Tower(tm->Get(EOTexture::TOWER_TEXTURE), pos);
		break;

	case EObjectName::MACHINE_OBJECT:
		obj = new Machine(tm->Get(EOTexture::MACHINE_TEXTURE), pos, tm->Get(EOTexture::MACHINEBULLET_TEXTURE));
		break;
	case EObjectName::SPRING_OBJECT:
		obj = new Spring(tm->Get(EOTexture::SPRING_TEXTURE), pos);
		break;
	default:
		break;
	}

	return obj;
}

// khởi tạo các đối tượng
static map<int, BaseObject *>* BuildObjectsMap(Map *m, MarioPlayer *&mario, map<int, D3DXVECTOR2 *> &creepPos, list<D3DXVECTOR2 *> &flagPos)
{
	TextureManagement *tm = TextureManagement::GetInstance();
	map<int, BaseObject *> *listObjects = new map<int, BaseObject *>();

	// khởi tạo các đối tượng, đưa vào list
	for (list<GameObject *>::iterator i = m->GetGameObjects().begin(); i != m->GetGameObjects().end(); i++)
	{
		BaseObject *obj = NULL;
		D3DXVECTOR2 pos;

		pos = D3DXVECTOR2((*i)->GetX(), (*i)->GetY());

		switch ((EObjectName)(*i)->GetType())
		{
			// enemy
		case EObjectName::ENEMY_OBJECT: 
			obj = new Enemy(tm->Get(EOTexture::ENEMY_TEXTURE), pos);
			break;
		case EObjectName::TURTLE_OBJECT: 
			obj = new Turtle(tm->Get(EOTexture::TURTLE_TEXTURE), pos, NORMAL_TURTLE);
			break;
		case EObjectName::FLYING_TURTLE_OBJECT:
			obj = new Turtle(tm->Get(EOTexture::TURTLE_TEXTURE), pos, FLYING_TURTLE);
			break;
		case EObjectName::TURTLE2_OBJECT:
			obj = new Turtle2(tm->Get(EOTexture::TURTLE2_TEXTURE), pos);
			break;
			
		case EObjectName::MUSHROOM_OBJECT:
			obj = new Mushroom(tm->Get(EOTexture::MUSHROOM_TEXTURE), pos, ETypeOfMushroom::NORMAL_MUSHROOM);
			break;
		case EObjectName::MUSHROOM_BLOCK_OBJECT:
			obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::MUSHROOM_TEXTURE), ETypefOfSecretBlock::NORMAL_MUSHROOM_SECRET_BLOCK);
			break;
		case EObjectName::FLOWER_OBJECT:
			obj = new Flower(tm->Get(EOTexture::FLOWER_TEXTURE), pos);
			break;
		case EObjectName::FLOWER_BLOCK_OBJECT:
			obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::FLOWER_TEXTURE), ETypefOfSecretBlock::FLOWER_SECRET_BLOCK);
			break;
		case EObjectName::LIFE_MUSHROOM_OBJECT:
			obj = new Mushroom(tm->Get(EOTexture::MUSHROOM_TEXTURE), pos, ETypeOfMushroom::LIFE_MUSHROOM);
			break;
		case EObjectName::LIFE_MUSHROOM_BLOCK_OBJECT:
			obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::MUSHROOM_TEXTURE), ETypefOfSecretBlock::LIFE_MUSHROOM_SECRET_BLOCK);
			break;
		case EObjectName::COIN_OBJECT:
			obj = new Coin(tm->Get(EOTexture::COIN_TEXTURE), pos);
			break;
		case EObjectName::COIN_BRICK_OBJECT:
			obj = new Brick(tm->Get(EOTexture::BRICK_TEXTURE), tm->Get(EOTexture::EXPLOREDBRICK_TEXTURE), pos, tm->Get(EOTexture::COIN_TEXTURE), true);
			break;
		case EObjectName::COIN_BLOCK_OBJECT:
			obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::COIN_TEXTURE), ETypefOfSecretBlock::COIN_SECRET_BLOCK);
			break;
		case EObjectName::STAR_OBJECT:
			obj = new Star(tm->Get(EOTexture::STAR_TEXTURE), pos);
			break;
		case EObjectName::STAR_BLOCK_OBJECT:
			obj = new SecretBlock(tm->Get(EOTexture::SECRETBLOCK_TEXTURE), pos, tm->Get(EOTexture::STAR_TEXTURE), ETypefOfSecretBlock::STAR_SECRET_BLOCK);
			break;

		case EObjectName::BLOCK_OBJECT:
			obj = new Block(tm->Get(EOTexture::BLOCK_TEXTURE), pos);
			break;
		case EObjectName::BRICK_OBJECT:
			obj = new Brick(tm->Get(EOTexture::BRICK_TEXTURE), tm->Get(EOTexture::EXPLOREDBRICK_TEXTURE), pos, tm->Get(EOTexture::COIN_TEXTURE), false);
			break;
		case EObjectName::CLOUD_OBJECT:
			obj = new Cloud(tm->Get(EOTexture::CLOUD_TEXTURE), pos);
			break;
		case EObjectName::BAR_OBJECT:
			obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, NORMAL_BAR);
			break;
		case EObjectName::GODOWN_BAR_OBJECT:
			obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, GODOWN_BAR);
			break;
		case EObjectName::GOUP_BAR_OBJECT:
			obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, GOUP_BAR);
			break;
		case EObjectName::HORIZONTAL_BAR_OBJECT:
			obj = new Bar(tm->Get(EOTexture::BAR_TEXTURE), pos, HORIZONTAL_BAR);
			break;
		case EObjectName::CARNIVOROUSFLOWER_OBJECT:
			obj = new CarnivorousFlower(tm->Get(EOTexture::CARNIVOROUSFLOWER_TEXTURE), pos);
			break;
		case EObjectName::CARNIVOROUSFLOWER_PIPE_OBJECT:
			obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::NONE_ENTRY, tm->Get(EOTexture::CARNIVOROUSFLOWER_TEXTURE));
			break;
		case EObjectName::PIPE_OBJECT:
			obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos);
			break;
		case EObjectName::CREEP_PIPE_OBJECT_1:
			obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::FIRST_ENTRY);
			break;
		case EObjectName::CREEP_PIPE_OBJECT_2:
			obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::SECOND_ENTRY);
			break;
		case EObjectName::CREEP_UP_PIPE_OBJECT_1:
			obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::FIRST_EXIT);
			creepPos[0] = new D3DXVECTOR2(obj->_position.x, obj->_rect.top);
			break;
		case EObjectName::CREEP_UP_PIPE_OBJECT_2:
			obj = new Pipe(tm->Get(EOTexture::PIPE_TEXTURE), pos, EntryNumber::SECOND_EXIT);
			creepPos[1] = new D3DXVECTOR2(obj->_position.x, obj->_rect.top);
			break;
		case EObjectName::HORIZONTAL_PIPE_OBJECT_1:
			obj = new Pipe(tm->Get(EOTexture::HORIZONTALPIPE_TEXTURE), pos, EntryNumber::SUB_FIRST_ENTRY);
			break;
		case EObjectName::HORIZONTAL_PIPE_OBJECT_2:
			obj = new Pipe(tm->Get(EOTexture::HORIZONTALPIPE_TEXTURE), pos, EntryNumber::SUB_SECOND_ENTRY);
			break;
		case EObjectName::LEFT_LAND_OBJECT:
			obj = new Land(tm->Get(EOTexture::LAND_TEXTURE), pos, TypeOfLand::LEFT_LAND);
			break;
		case EObjectName::LAND_OBJECT:
			obj = new Land(tm->Get(EOTexture::LAND_TEXTURE), pos);
			break;
		case EObjectName::RIGHT_LAND_OBJECT:
			obj = new Land(tm->Get(EOTexture::LAND_TEXTURE), pos, TypeOfLand::RIGHT_LAND);
			break;
			
		case EObjectName::FENCE_OBJECT:
			obj = new Scene(tm->Get(EOTexture::FENCE_TEXTURE), pos, ESceneObject::FENCE);
			break;

		case EObjectName::GRASS_OBJECT:
			obj = new Grass(tm->Get(EOTexture::GRASS_TEXTURE), pos);
			break;
			
		case EObjectName::MOUNTAIN_OBJECT:
			obj = new Scene(tm->Get(EOTexture::MOUNTAIN_TEXTURE), pos, ESceneObject::MOUNTAIN);
			break;

		case EObjectName::SIGN_OBJECT:
			obj = new Scene(tm->Get(EOTexture::SIGN_TEXTURE), pos, ESceneObject::SIGN);
			break;

		case EObjectName::LAMP_OBJECT:
			obj = new Scene(tm->Get(EOTexture::LAMP_TEXTURE), pos, ESceneObject::LAMP);
			break;

		case EObjectName::TREE_OBJECT:
			obj = new Scene(tm->Get(EOTexture::TREE_TEXTURE), pos, ESceneObject::TREE);
			break;

		case EObjectName::BIG_TREE_OBJECT:
			obj = new Scene(tm->Get(EOTexture::TREE2_TEXTURE), pos, ESceneObject::BIG_TREE);
			break;

		case EObjectName::TOWER_OBJECT:
			obj = new Tower(tm->Get(EOTexture::TOWER_TEXTURE), pos);
			break;

		case EObjectName::MACHINE_OBJECT:
			obj = new Machine(tm->Get(EOTexture::MACHINE_TEXTURE), pos, tm->Get(EOTexture::MACHINEBULLET_TEXTURE));
			break;
		case EObjectName::SPRING_OBJECT:
			obj = new Spring(tm->Get(EOTexture::SPRING_TEXTURE), pos);
			break;

		case EObjectName::FLAG_POSITION_OBJECT:
			flagPos.push_back(new D3DXVECTOR2(pos.x, pos.y));
			break;

		case EObjectName::MARIO_OBJECT:
			if (mario == NULL)
			{
				mario = new MarioPlayer(
					tm->Get(EOTexture::SMALLMARIO_TEXTURE), 
					tm->Get(EOTexture::HEIGHTMARIO_TEXTURE), 
					tm->Get(EOTexture::SUPERMATIO_TEXTURE), 
					tm->Get(EOTexture::BULLET_TEXTURE), 
					pos,
					MarioType::SMALL_MARIO);
			}
			break;
		default:
			break;
		}

		if (obj != NULL)
		{
			pair<int, BaseObject *> p((*i)->GetID(), obj);
			listObjects->insert(p);
		}
	}

	return listObjects;
}

// khởi tạo các qnode
static map<int, QNode *>* BuildQNodesMap(Map *m, map<int, BaseObject *> *listObjects, EQuadTreeType type)
{
	map<int, QNode *> *qNodes = new map<int, QNode *>();
	list<Node *> listNodes;
	if (type == EQuadTreeType::DRAW)
	{
		listNodes = m->GetNodes();
	}
	else if (type == EQuadTreeType::UPDATE)
	{
		listNodes = m->GetUpdateNodes();
	}

	RECT *rect;
	list<BaseObject *> *objectsInNode;
	BaseObject *bo;
	QNode *subNode = NULL;
	for (list<Node *>::iterator iNode = listNodes.begin(); iNode != listNodes.end(); iNode++)
	{
		// HCN bound
		rect = new RECT();
		rect->left = (*iNode)->GetX();
		rect->right = rect->left + (*iNode)->GetWidth();
		rect->top = (*iNode)->GetY();
		rect->bottom = rect->top - (*iNode)->GetHeight();

		// tham chiếu tới list các đối tượng trong node
		objectsInNode = new list<BaseObject *>();
		list<GameObject *>::iterator iObject;
		list<GameObject *> list = (*iNode)->GetGameObjects();
		for (iObject = (*iNode)->GetGameObjects().begin(); iObject != (*iNode)->GetGameObjects().end(); iObject++)
		{
			for (map<int, BaseObject *>::iterator iRealObject = listObjects->begin(); iRealObject != listObjects->end(); iRealObject++)
			{
				if ((*iObject)->GetID() == iRealObject->first)
				{
					objectsInNode->push_back(iRealObject->second);
				}
			}
		}

		subNode = new QNode((*iNode)->GetID(), *rect);
		subNode->InsertObjects(objectsInNode);
		qNodes->insert(pair<int, QNode *>(subNode->GetID(), subNode));
	}

	return qNodes;
}

// xây dựng cây
static QuadTree* BuildQuadTree(map<int, QNode *> *listQNode)
{
	QuadTree *quadTree;

	map<int, QNode *>::iterator iQNode;
	QNode *root;
	QNode* q;
	iQNode = listQNode->begin();
	root = iQNode->second;
	for (iQNode++; iQNode != listQNode->end(); iQNode++)
	{
		int parentID = iQNode->second->GetParentID();
		q = listQNode->at(parentID);
		q->AddChildNode(iQNode->second);
	}

	quadTree = new QuadTree(root);
	return quadTree;
}

static QuadTree* BuildQuadTree(Map *m, map<int, BaseObject *> *listObjects, EQuadTreeType type, map<int, QNode *> *&qNodes)
{
	qNodes = BuildQNodesMap(m, listObjects, type);
	return BuildQuadTree(qNodes);
}

static bool RemoveDeadObjects(map<int, BaseObject *> &_listObjects, QuadTree *_quadTree, QuadTree *_updateQuadTree, BaseObject *obj)
{
	map<int, BaseObject *>::iterator iter;
	for (iter = _listObjects.begin(); iter != _listObjects.end(); iter++)
	{
		if (iter->second == obj)
			break;
	}

	if (iter == _listObjects.end())
		return false;

	switch (iter->second->GetType())
	{
	case EObjectName::BAR_OBJECT:
	case EObjectName::BULLET_OBJECT:
	case EObjectName::CARNIVOROUSFLOWER_OBJECT:
	case EObjectName::COIN_OBJECT:
	case EObjectName::FLOWER_OBJECT:
	case EObjectName::MACHINE_BULLET_OBJECT:
	case EObjectName::MUSHROOM_OBJECT:
	case EObjectName::LIFE_MUSHROOM_OBJECT:
	case EObjectName::STAR_OBJECT:
		if ( ((DynamicObject *)iter->second)->_isDead == true )
		{
			_quadTree->RemoveObj(iter->second, _quadTree->GetRootNode());
			_updateQuadTree->RemoveObj(iter->second, _updateQuadTree->GetRootNode());
			delete iter->second;
			iter = _listObjects.erase(iter);
			return true;
		}
		break;

	case EObjectName::ENEMY_OBJECT:
	case EObjectName::TURTLE_OBJECT:
	case EObjectName::TURTLE2_OBJECT:
		if ( ((Enemy *)iter->second)->_isDisappear == true )
		{
			_quadTree->RemoveObj(iter->second, _quadTree->GetRootNode());
			_updateQuadTree->RemoveObj(iter->second, _updateQuadTree->GetRootNode());
 			delete iter->second;
			iter = _listObjects.erase(iter);
			return true;
		}
		break;

	case EObjectName::BRICK_OBJECT:
		if ( ((Brick *)iter->second)->_isDisappear == true )
		{
			_quadTree->RemoveObj(iter->second, _quadTree->GetRootNode());
			_updateQuadTree->RemoveObj(iter->second, _updateQuadTree->GetRootNode());
			delete iter->second;
			iter = _listObjects.erase(iter);
			return true;
		}
		break;

	default:
		break;
	}

	return false;
}

#endif