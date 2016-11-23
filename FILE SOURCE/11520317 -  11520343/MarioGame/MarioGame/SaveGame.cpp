#include "SaveGame.h"

using namespace std;

void SaveGame::Save(GameWorld *world)
{
	char *filename = "SaveGame";
	char file[300];
	char tmpFilename[50];
	
	// Draw
	strcpy(tmpFilename, filename);
	strcat(tmpFilename, ".xml");

	GetCurrentDirectoryA(sizeof(file), file);
	file[sizeof(file) - 1] = '\0';
	strcat(file, "\\");
	strcat(file, tmpFilename);
	
	CreateSaveFile(file,
		world->_quadTree,
		world->_listNodes,
		&world->_listObjects,
		world->mario,
		world);



	// Update
	strcpy(tmpFilename, filename);
	strcat(tmpFilename, "Update.xml");

	GetCurrentDirectoryA(sizeof(file), file);
	file[sizeof(file) - 1] = '\0';
	strcat(file, "\\");
	strcat(file, tmpFilename);

	CreateSaveFile(file,
		world->_updateQuadTree,
		world->_listUpdateNodes,
		&world->_listObjects,
		world->mario,
		world);
}

void SaveGame::CreateSaveFile(char *filename, 
							  QuadTree *quadTree, 
							  map<int, QNode *> *listNodes, 
							  map<int, BaseObject *> *listObjects, 
							  MarioPlayer *mario, GameWorld *world)
{
	xml = new CMarkup();
	// size map
	RECT sizemap = quadTree->GetRootNode()->GetBound();
	xml->AddElem("SaveData");
	xml->IntoElem();
	xml->AddElem("Width", sizemap.right - sizemap.left);
	xml->AddElem("Height", sizemap.top - sizemap.bottom);


	// info
	xml->AddElem("GameInfo");
	xml->SetAttrib("IsSubWorld", world->_IsSubWorld);
	xml->SetAttrib("nWorld", world->_nWorld);

	if (world->_ListSubWorld[0] != NULL)
	{
		xml->SetAttrib("SubWorld1", world->_ListSubWorld[0]->_map->_Filename);
	}
	else
	{
		xml->SetAttrib("SubWorld1", "");
	}
	if (world->_ListSubWorld[1] != NULL)
	{
		xml->SetAttrib("SubWorld2", world->_ListSubWorld[1]->_map->_Filename);
	}
	else
	{
		xml->SetAttrib("SubWorld2", "");
	}

	if (world->_CreepUpPos[0] != NULL)
	{
		xml->SetAttrib("CreepUpPos1_X", world->_CreepUpPos[0]->x);
		xml->SetAttrib("CreepUpPos1_Y", world->_CreepUpPos[0]->y);
	}
	else
	{
		xml->SetAttrib("CreepUpPos1_X", 0);
		xml->SetAttrib("CreepUpPos1_Y", 0);
	}
	if (world->_CreepUpPos[1] != NULL)
	{
		xml->SetAttrib("CreepUpPos2_X", world->_CreepUpPos[1]->x);
		xml->SetAttrib("CreepUpPos2_Y", world->_CreepUpPos[1]->y);
	}
	else
	{
		xml->SetAttrib("CreepUpPos2_X", 0);
		xml->SetAttrib("CreepUpPos2_Y", 0);
	}

	if (world->_TheNextWorld != NULL)
	{
		xml->SetAttrib("TheNextWorld", world->_TheNextWorld->_map->_Filename);
	}
	else
	{
		xml->SetAttrib("TheNextWorld", "");
	}

	xml->SetAttrib("OriMarioPos_X", world->_oriMarioPos.x);
	xml->SetAttrib("OriMarioPos_Y", world->_oriMarioPos.y);

	xml->SetAttrib("Score", world->_gameInfo->GetScore());
	xml->SetAttrib("Life", world->_gameInfo->GetLife());
	xml->SetAttrib("World", world->_gameInfo->GetWorld());


	// mario
	xml->AddElem("Mario");
	xml->SetAttrib("Type", (int)mario->_Type);
	xml->SetAttrib("X", (int)mario->_position.x);
	xml->SetAttrib("Y", (int)mario->_position.y);
	xml->SetAttrib("SMoveLeft", mario->_SMoveLeft);
	xml->SetAttrib("SMoveRight", mario->_SMoveRight);
	xml->SetAttrib("SJump", mario->_SJump);
	xml->SetAttrib("SFall", mario->_SFall);
	xml->SetAttrib("SDie", mario->_SDie);
	xml->SetAttrib("IsImmortality", mario->_IsImmortality);
	xml->SetAttrib("EatMushroom", mario->_EatMushroom);
	xml->SetAttrib("EatFlower", mario->_EatFlower);
	xml->SetAttrib("IsSmaller", mario->_IsSmaller);


	// add nodes
	xml->AddElem("Nodes");
	xml->SavePos("Nodes");
	xml->IntoElem();
	for (map<int, QNode *>::iterator iQNode = listNodes->begin(); iQNode != listNodes->end(); iQNode++)
	{
		QNode *node = iQNode->second;
		RECT bound = node->GetBound();
		xml->AddElem("Node");
		xml->SavePos("Node");
		xml->SetAttrib("ID", node->GetID());
		xml->SetAttrib("X", bound.left);
		xml->SetAttrib("Y", bound.top);
		xml->SetAttrib("Width", bound.right - bound.left);
		xml->SetAttrib("Height", bound.top - bound.bottom);
		xml->IntoElem();
		list<BaseObject *> ListObjects = node->GetListObjects();
		if (!ListObjects.empty())
		{
			xml->AddElem("GameObjects");
			xml->SavePos("GameObjects");
			xml->IntoElem();
			for(list<BaseObject*>::iterator k = ListObjects.begin(); k != ListObjects.end(); k++)
			{
				int id = -1;

				// lấy id
				for (map<int, BaseObject *>::iterator i = listObjects->begin(); i != listObjects->end(); i++)
				{
					if ((*k) == i->second)
					{
						id = i->first;
						break;
					}
				}

				Direction dir = NONE;
				bool isExplored, isCollision, hasSubObject;

				isExplored = isCollision = hasSubObject = false;
				xml->AddElem("GameObject");
				switch ((*k)->GetType())
				{
				case EObjectName::BRICK_OBJECT:
				case EObjectName::COIN_BRICK_OBJECT:
					isExplored = ((Brick *)(*k))->_isExplored;
					if ( ((Brick *)(*k))->_coin != NULL )
					{
						hasSubObject = true;
					}
					break;

				case EObjectName::ENEMY_OBJECT:
				case EObjectName::TURTLE_OBJECT:
				case EObjectName::TURTLE2_OBJECT:
					dir = ((Enemy *)(*k))->_direction;
					isCollision = ((Enemy *)(*k))->_isCollisionWithMario;
					break;

				case EObjectName::MUSHROOM_OBJECT:
				case EObjectName::LIFE_MUSHROOM_OBJECT:
					dir = ((Mushroom *)(*k))->_direction;
					break;

				case EObjectName::COIN_BLOCK_OBJECT:
				case EObjectName::MUSHROOM_BLOCK_OBJECT:
				case EObjectName::LIFE_MUSHROOM_BLOCK_OBJECT:
				case EObjectName::STAR_BLOCK_OBJECT:
				case EObjectName::FLOWER_BLOCK_OBJECT:
					isCollision = ((SecretBlock *)(*k))->_isCollision;
					if (((SecretBlock *)(*k))->_object != NULL)
					{
						hasSubObject = true;
					}
					break;

				default:
					
					break;
				};

				xml->SetAttrib("ID", id);
				xml->SetAttrib("Type", (int)(*k)->GetType());
				xml->SetAttrib("X", (*k)->_position.x);
				xml->SetAttrib("Y", (*k)->_position.y);
				
				xml->SetAttrib("dir", (int)dir);
				xml->SetAttrib("isExplored", isExplored);
				xml->SetAttrib("isCollision", isCollision);
				xml->SetAttrib("hasSubObject", hasSubObject);
				
			}
			xml->RestorePos("GameObjects");
		}
		else
		{
			xml->AddSubDoc("<GameObjects />\r\n");
		}
		xml->RestorePos("Node");
	}
	xml->RestorePos("Nodes");

	xml->Save(filename);
}