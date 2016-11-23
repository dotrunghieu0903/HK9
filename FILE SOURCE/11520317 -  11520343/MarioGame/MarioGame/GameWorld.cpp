#include "GameWorld.h"


GameWorld::GameWorld(DXTexture *backGround)
{
	this->mario = NULL;
	_camera = new Camera();
	this->_backGround = new BaseInfo(backGround, D3DXVECTOR2(0,0));

	this->_isInstance = false;
	this->_IsSubWorld = false;
	this->_isPause = false;
	this->_nWorld = 0;
	this->_isWaitingSwitch = false;
	this->_timeWaiting = 0.0f;
	this->_isFinish = false;
	this->_isGameOver = false;
	this->_isReset = false;
	this->_TheNextWorld = NULL;
}

GameWorld::GameWorld(const char *filemap, DXTexture *backGround, MarioPlayer *&mario, GameInfo *&gameInfo)
{
	this->mario = mario;
	this->_gameInfo = gameInfo;
	this->_backGround = new BaseInfo(backGround, D3DXVECTOR2(0,0));
	_map = new Map(filemap);
	//strcpy(_mapFile, filemap);
	//_map->_Filename = filemap;
	_camera = new Camera();

	this->_isInstance = false;
	this->_IsSubWorld = false;
	this->_isPause = false;
	this->_nWorld = 0;
	this->_isWaitingSwitch = false;
	this->_timeWaiting = 0.0f;
	this->_isFinish = false;
	this->_isGameOver = false;
	this->_isReset = false;
	this->_TheNextWorld = NULL;
}

bool GameWorld::IsInstance()
{
	return this->_isInstance;
}

void GameWorld::Init()
{
	_map->LoadMap();

	_listObjects = *BuildObjectsMap(_map, mario, _CreepUpPos, _flagPosition);
	_quadTree = BuildQuadTree(_map, &_listObjects, EQuadTreeType::DRAW, _listNodes);
	_updateQuadTree = BuildQuadTree(_map, &_listObjects, EQuadTreeType::UPDATE, _listUpdateNodes);

	this->_isInstance = true;
	this->_oriMarioPos = mario->_position;
}



void GameWorld::Cleanup()
{

}

void GameWorld::Pause()
{
	_isPause = true;
}

void GameWorld::Resume()
{
	_isPause = false;
}


void GameWorld::HandleEvents(DXGame *pDXGame)
{
	if (_isPause)
		return;

	if (!_last_F1 && pDXGame->IsKeyDown(DIK_F1))
	{
		_last_F1 = true;
		SoundManagement::GetInstance()->VolumeDown();
	}
	else if (pDXGame->IsKeyUp(DIK_F1))
	{
		_last_F1 = false;
	}

	if (!_last_F2 && pDXGame->IsKeyDown(DIK_F2))
	{
		_last_F2 = true;
		SoundManagement::GetInstance()->VolumeUp();
	}
	else if (pDXGame->IsKeyUp(DIK_F2))
	{
		_last_F2 = false;
	}
	/*
	if (pDXGame->IsKeyDown(DIK_1))
	{
		mario->_IsSmaller = true;
	}
	else if (pDXGame->IsKeyDown(DIK_2))
	{
		mario->EatMushroom();
	}
	else if (pDXGame->IsKeyDown(DIK_3))
	{
		mario->EatFlower();
	}
	*/

	if (pDXGame->IsKeyDown(DIK_RIGHT))
	{
		mario->MoveRight();
	}
	else if (pDXGame->IsKeyDown(DIK_LEFT))
	{
		mario->MoveLeft();
	}
	else
	{
		mario->NoneMove();
	}

	if (pDXGame->IsKeyDown(DIK_DOWN))
	{
		mario->Sit();
	}
	else
	{
		mario->NoneSit();
	}

	if (pDXGame->IsKeyDown(DIK_SPACE))
	{
		if (mario->_SJump == false && mario->_SFall == false)
		{
			SoundManagement::GetInstance()->Get(EOSound::JUMP_SOUND)->Play();
		}
		mario->Jump();
	}

	if (pDXGame->IsKeyDown(DIK_A))
	{
		mario->Run();
	}
	else
	{
		mario->NoneRun();
	}

	// bắn đạn
	if (!_last_B && pDXGame->IsKeyDown(DIK_B))
	{
		if (mario->_Type == SUPER_MARIO)
		{
			mario->ThrowBullet(_listFreeObjects);
			_last_B = true;
			SoundManagement::GetInstance()->Get(EOSound::SHOOT_SOUND)->Play();
		}
	}
	else if (pDXGame->IsKeyUp(DIK_B))
	{
		_last_B = false;
	}

	if (!_last_ArrowUp && pDXGame->IsKeyDown(DIK_UP))
	{
		_last_ArrowUp = true;
	}
	else if (pDXGame->IsKeyUp(DIK_UP))
	{
		_last_ArrowUp = false;
	}
}


void GameWorld::Update(GameTime* gameTime)
{
	if (_isPause || _isReset || _isGameOver)
		return;
	
	if (_isWaitingSwitch)
	{
		_timeWaiting += gameTime->GetElapsedTimePerFrameMiliSeconds();
		if (_timeWaiting > TIME_OF_WAITING_WORLD)
		{
			_isFinish = true;
			if (_TheNextWorld != NULL)
			{
				_gameInfo->WorldUp();
				/*
				mario->_position = _TheNextWorld->_oriMarioPos;
				_TheNextWorld->SetMario(mario);
				_TheNextWorld->SetGameInfo(_gameInfo);
				*/
			}
		}
		else
		{
			SoundManagement::GetInstance()->Get(EOSound::FINISHMAP_SOUND)->Play();
		}

		return;
	}
	
	// --------------------------------------- REMOVE ---------------------------------------//
	for (list<BaseObject *>::iterator i = _listDeadObjects.begin(); i != _listDeadObjects.end();)
	{
		RemoveDeadObjects(_listObjects, _quadTree, _updateQuadTree, *i);
		i = _listDeadObjects.erase(i);
	}

	list<BaseObject *>::iterator i;
	// ---------UPDATE-----------------------------------------------------------------------//
	// ----------- MARIO --------------------.//
	mario->Update(gameTime);
	
	if (mario->_SDie == true)
	{
		SoundManagement::GetInstance()->Get(EOSound::DYING_SOUND)->Play();
		if (mario->_Type != SMALL_MARIO)
		{
			mario->_IsSmaller = true;
		}

		if (mario->IsDead())
		{
			_gameInfo->LifeDown();
			if (_gameInfo->GetLife() == 0)
			{
				_isGameOver = true;
			}
			else
			{
				_isReset = true;
			}
		}
	}

	// ----------- OTHER ------------//
	_camera->Update(mario->_position);

	//------------- FREE OBJECTs------------------//
	for (i = _listFreeObjects.begin(); i != _listFreeObjects.end();)
	{
		if ( ((DynamicObject *)(*i))->IsDead() )
		{
			i = _listFreeObjects.erase(i); // remove object
			continue;
		}

		(*i)->Update(gameTime);
		i++;
	}

	// --------- ALL OBJECTs in QUADTREE------//
	_quadTree->InsertListObjInView(_camera->_rect, _quadTree->GetRootNode());
	for (i = _quadTree->GetListObjectsInView().begin(); i != _quadTree->GetListObjectsInView().end(); i++)
	{
		if ((*i)->GetType() == EObjectName::MACHINE_OBJECT)
		{
			((Machine *)(*i))->ShootBullet(mario->_position, _listFreeObjects); 
		}
		
		(*i)->Update(gameTime);
	}

	// --------------------END UPDATE---------------------------------------------------------//



	// ----------------- BEGIN COLLISION --------------------//
	//----------------- MARIO -------------------//
	mario->BeginToCheckCollisions();

	// ---------------- FREE OBJECTs------------//
	
	for (i = _listFreeObjects.begin(); i != _listFreeObjects.end(); i++)
	{
		if ( ((DynamicObject *)(*i))->IsDead() == false )
		{
			switch ((*i)->GetType())
			{
			case EObjectName::MUSHROOM_OBJECT:
			case EObjectName::LIFE_MUSHROOM_OBJECT:
			case EObjectName::STAR_OBJECT:
				((LivingObject *)(*i))->BeginToCheckCollisions();
				break;
				
			case EObjectName::MACHINE_BULLET_OBJECT:
				((MachineBullet *)(*i))->BeginToCheckCollisions();
				break;

			case EObjectName::BULLET_OBJECT:
				((Bullet *)(*i))->BeginToCheckCollisions();
				break;

			default:
				break;
			}
		}
	}


	// --------- COLIISION ----------------------------------------------------------------//
	// ----------MARIO -----------------------------------------------//
	// --------- FREE OBJECTs----------//
	
	for (i = _listFreeObjects.begin(); i != _listFreeObjects.end(); i++)
	{
		if ( ((DynamicObject *)(*i))->IsDead() == false && (*i)->GetType() != EObjectName::BULLET_OBJECT)
		{
			if (Intersect(&mario->GetNodeBound(), &((DynamicObject *)(*i))->GetNodeBound()) == false )
				continue;

			CollisionDirection dir = mario->CheckCollisions(*i);
			if (dir != CollisionDirection::NONE_COL)
			{
				switch ((*i)->GetType())
				{
				// nấm
				case EObjectName::MUSHROOM_OBJECT: // ok
					mario->EatMushroom();
					((LivingObject *)(*i))->Die();
					mario->ResponseAsNoCollision(*i, dir);
					SoundManagement::GetInstance()->Get(EOSound::LEVELUP_SOUND)->Play();
					break;

				case EObjectName::LIFE_MUSHROOM_OBJECT: // ok
					((LivingObject *)(*i))->Die();
					_gameInfo->LifeUp();
					mario->ResponseAsNoCollision(*i, dir);
					SoundManagement::GetInstance()->Get(EOSound::EXTRALIFE_SOUND)->Play();
					break;

				case EObjectName::FLOWER_OBJECT: // ok
					((Flower *)(*i))->HasCollision();
					mario->EatFlower();
					mario->ResponseAsNoCollision(*i, dir);
					SoundManagement::GetInstance()->Get(EOSound::LEVELUP_SOUND)->Play();
					break;

				case EObjectName::STAR_OBJECT: // ok
					mario->Immortality();
					((LivingObject *)(*i))->Die();
					mario->ResponseAsNoCollision(*i, dir);
					SoundManagement::GetInstance()->Get(EOSound::LEVELUP_SOUND)->Play();
					break;

				case EObjectName::MACHINE_BULLET_OBJECT:
					if (dir != CollisionDirection::TOP_COL)
					{
						if (mario->_IsImmortality == false)
						{
							mario->ResponseCollisionsWithEnemy();
							mario->ResponseAsNoCollision(*i, dir);
						}
						else
						{
							((MachineBullet *)(*i))->HasTopCollision();
						}
					}
					else
					{
						((MachineBullet *)(*i))->HasTopCollision();
						_gameInfo->AddScore(500);
						SoundManagement::GetInstance()->Get(EOSound::HEADSHOOT_SOUND)->Play();
					}
					break;

				default:
					break;
				}
			}
		}
	}
	

	// ---------- OBJ in UPDATE QUADTREE---------//
	_updateQuadTree->InsertListObjInView(mario->GetNodeBound(), _updateQuadTree->GetRootNode());
	for (i = _updateQuadTree->GetListObjectsInView().begin(); i != _updateQuadTree->GetListObjectsInView().end(); i++)
	{
		Box *b;
		if (IsMovableObject(*i))
		{
			b = &((DynamicObject *)(*i))->GetBoardBox();
		}
		else
		{
			b = &(*i)->GetObjectBox();
		}

		if (AABBCheck(mario->GetBoardBox(), *b))
		{
			CollisionDirection dir;

			// đối tượng có thể di chuyển
			if (IsMovableLivingObject(*i))
			{
				if ( ((LivingObject *)(*i))->_isDead == true)
				{
					_listDeadObjects.push_back(*i); 
					continue;
				}

				dir = mario->CheckCollisions(*i);
				switch ((*i)->GetType())
				{
					// quái
				case EObjectName::ENEMY_OBJECT: // OK
				case EObjectName::TURTLE_OBJECT: // OK
				case EObjectName::FLYING_TURTLE_OBJECT: // OK
					// va chạm vs mario
					if (dir != CollisionDirection::NONE_COL)
					{
						if (mario->_IsImmortality)
						{
							((Enemy *)(*i))->CollisionWithBullet();
							_listDeadObjects.push_back(*i);
							if ((*i)->GetType() == EObjectName::ENEMY_OBJECT)
							{
								_gameInfo->AddScore(200);
							}
							else if ((*i)->GetType() == EObjectName::TURTLE_OBJECT)
							{
								_gameInfo->AddScore(400);
							}
							else
							{
								_gameInfo->AddScore(500);
							}
							mario->ResponseAsNoCollision(*i, dir);
							SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
							continue;
						}
						else if (mario->IsChangingType())
						{
							mario->ResponseAsNoCollision(*i, dir);
							continue;
						}

						// special
						if ((*i)->GetType() == EObjectName::TURTLE_OBJECT)
						{
							if (((Turtle *)(*i))->CheckMidTopCollisions(mario, dir) == false)
							{
								mario->ResponseCollisionsWithEnemy();
								SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
							}
							else
							{
								if (dir == CollisionDirection::TOP_COL)
								{
									mario->PopUp();
									if (((Turtle *)(*i))->_isDead == true)
									{
										_gameInfo->AddScore(400);
										_listDeadObjects.push_back(*i);
									}
									SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
								}
							}
						}
						else
						{
						// chung
							if (dir == CollisionDirection::TOP_COL)
							{
								((Enemy *)(*i))->CollisionWithMario();
								mario->PopUp();
								if (((Enemy *)(*i))->_isDead == true)
								{
									if ((*i)->GetType() == EObjectName::ENEMY_OBJECT)
									{
										_gameInfo->AddScore(200);
									}
									else
									{
										_gameInfo->AddScore(500);
									}
									_listDeadObjects.push_back(*i);
								}
								SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
							}
							else
							{
								mario->ResponseCollisionsWithEnemy();
							}
						}
					}

					/*
					// va chạm vs đạn
					if (mario->CheckBulletsCollision(*i))
					{
						((Enemy *)(*i))->CollisionWithBullet();
						if ((*i)->GetType() == EObjectName::ENEMY_OBJECT)
						{
							_gameInfo->AddScore(200);
						}
						else if ((*i)->GetType() == EObjectName::TURTLE_OBJECT)
						{
							_gameInfo->AddScore(400);
						}
						else
						{
							_gameInfo->AddScore(500);
						}
						SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
					}
					*/
					break;

					// rùa gai
				case EObjectName::TURTLE2_OBJECT: // ok
					if (dir != CollisionDirection::NONE_COL)
					{
						if (mario->_IsImmortality)
						{
							((Enemy *)(*i))->CollisionWithBullet();
							_gameInfo->AddScore(500);
							mario->ResponseAsNoCollision(*i, dir);
							SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
							continue;
						}
						else if (mario->IsChangingType())
						{
							mario->ResponseAsNoCollision(*i, dir);
							continue;
						}

						mario->ResponseCollisionsWithEnemy();
					}
					break;

					// nấm
				case EObjectName::MUSHROOM_OBJECT: // ok
					mario->EatMushroom();
					((LivingObject *)(*i))->Die();
					mario->ResponseAsNoCollision(*i, dir);
					SoundManagement::GetInstance()->Get(EOSound::LEVELUP_SOUND)->Play();
					break;

					/// can chinh lai
				case EObjectName::LIFE_MUSHROOM_OBJECT:
					((LivingObject *)(*i))->Die();
					// cộng số mạng
					mario->ResponseAsNoCollision(*i, dir);
					SoundManagement::GetInstance()->Get(EOSound::EXTRALIFE_SOUND)->Play();
					break;

				case EObjectName::STAR_OBJECT: // ok
					mario->Immortality();
					((LivingObject *)(*i))->Die();
					mario->ResponseAsNoCollision(*i, dir);
					SoundManagement::GetInstance()->Get(EOSound::LEVELUP_SOUND)->Play();
					break;

				default:
					break;
				}
			}
			else // đối tượng k thể di chuyển
			{
				if ((*i)->GetType() == EObjectName::TOWER_OBJECT)
				{
					if (_last_ArrowUp && !_isWaitingSwitch && AABBCheck(mario->GetObjectBox(), (*i)->GetObjectBox()))
					{
						_isWaitingSwitch = true;
						_timeWaiting = 0.0f;
						_gameInfo->AddScore(5000);
					}
					continue;
				}
				else if ((*i)->GetType() == EObjectName::BRICK_OBJECT && ((Brick *)(*i))->_isExplored == true)
				{
					continue;
				}

				CarnivorousFlower *c;
				GameWorld *w;
				dir = mario->CheckCollisions(*i);

				if (dir != CollisionDirection::NONE_COL)
				{
					switch ((*i)->GetType())
					{
					case EObjectName::BAR_OBJECT: // ok
						if (dir == CollisionDirection::TOP_COL)
						{
							((Bar *)(*i))->HasCollision();
							_listDeadObjects.push_back(*i);
							SoundManagement::GetInstance()->Get(EOSound::HEADSHOOT_SOUND)->Play();
						}
						break;

					case EObjectName::BRICK_OBJECT: // ok
						if (dir == CollisionDirection::BOTTOM_COL)
						{
							((Brick *)(*i))->HasCollision(mario->_Type);
							if (mario->_Type != SMALL_MARIO) // mario lớn mới có thể làm bể gạch -> gachj vỡ
							{
								_listDeadObjects.push_back(*i);
							}
							SoundManagement::GetInstance()->Get(EOSound::BRICKBROKEN_SOUND)->Play();
						}
						break;

					case EObjectName::COIN_BRICK_OBJECT: // ok
						if (dir == CollisionDirection::BOTTOM_COL)
						{
							((Brick *)(*i))->HasCollision(mario->_Type);
							if ( ((Brick *)(*i))->_isExplored == false )
							{
								_gameInfo->AddScore(100);
								SoundManagement::GetInstance()->Get(EOSound::GETCOIN_SOUND)->Play();
							}
						}
						break;

					case EObjectName::CARNIVOROUSFLOWER_OBJECT: // ok
						if (mario->_IsImmortality)
						{
							((CarnivorousFlower *)(*i))->HasCollision();
							_listDeadObjects.push_back(*i);
							mario->ResponseAsNoCollision(*i, dir);
							_gameInfo->AddScore(100);
							SoundManagement::GetInstance()->Get(EOSound::HEADSHOOT_SOUND)->Play();
						}
						else
						{
							mario->ResponseCollisionsWithEnemy();
							mario->ResponseAsNoCollision(*i, dir);
						}
						break;

					case EObjectName::COIN_OBJECT: // ok
						((Coin *)(*i))->HasCollision();
						mario->ResponseAsNoCollision(*i, dir);
						_gameInfo->AddScore(100);
						_listDeadObjects.push_back(*i);
						SoundManagement::GetInstance()->Get(EOSound::GETCOIN_SOUND)->Play();
						break;

					case EObjectName::FLOWER_OBJECT: // ok
						((Flower *)(*i))->HasCollision();
						mario->EatFlower();
						mario->ResponseAsNoCollision(*i, dir);
						_listDeadObjects.push_back(*i);
						SoundManagement::GetInstance()->Get(EOSound::LEVELUP_SOUND)->Play();
						break;

					case EObjectName::COIN_BLOCK_OBJECT:
					case EObjectName::MUSHROOM_BLOCK_OBJECT:
					case EObjectName::LIFE_MUSHROOM_BLOCK_OBJECT:
					case EObjectName::STAR_BLOCK_OBJECT:
					case EObjectName::FLOWER_BLOCK_OBJECT:
						if (dir == CollisionDirection::BOTTOM_COL)
						{
							if ((*i)->GetType() == EObjectName::COIN_BLOCK_OBJECT && ((SecretBlock *)(*i))->_isCollision == false)
							{
								_gameInfo->AddScore(100);
							}
							((SecretBlock *)(*i))->HasCollision(_listFreeObjects);
							if ( ((SecretBlock *)(*i))->_justCollision == true )
							{
								if ((*i)->GetType() == EObjectName::COIN_BLOCK_OBJECT)
								{
									SoundManagement::GetInstance()->Get(EOSound::GETCOIN_SOUND)->Play();
								}
								else
								{
									SoundManagement::GetInstance()->Get(EOSound::BONUSAPPEAR_SOUND)->Play();
								}
							}
						}
						break;

					case EObjectName::SPRING_OBJECT: // ok
						if (dir == CollisionDirection::TOP_COL)
						{
							((Spring *)(*i))->HasCollision();
							mario->Jump( ((Spring *)(*i))->GetSwingForce() );
							SoundManagement::GetInstance()->Get(EOSound::STANDUP_SOUND)->Play();
						}
						break;

					case EObjectName::CREEP_PIPE_OBJECT_1:
						if (dir == CollisionDirection::TOP_COL && mario->_Sit == true)
						{
							// chuyển qua map con 1
							if (this->_ListSubWorld[0] != NULL && this->_CreepUpPos[0] != NULL)
							{
								w = WorldManagement::GetInstance()->PushSubWorld(this->_ListSubWorld.at(0));
								mario->_position = w->_oriMarioPos; // set Lại tọa độ cho mario trong world mới
								w->SetMario(mario);
								w->SetGameInfo(_gameInfo);
								SoundManagement::GetInstance()->Get(EOSound::PIPE_SOUND)->Play();
							}
						}
						break;

					case EObjectName::CREEP_PIPE_OBJECT_2:
						if (dir == CollisionDirection::TOP_COL && mario->_Sit == true)
						{
							// chuyển qua map con 2
							if (this->_ListSubWorld[1] != NULL && this->_CreepUpPos[1] != NULL)
							{
								w = WorldManagement::GetInstance()->PushSubWorld(this->_ListSubWorld.at(1));
								mario->_position = w->_oriMarioPos; // set Lại tọa độ cho mario trong world mới
								w->SetMario(mario);
								w->SetGameInfo(_gameInfo);
								SoundManagement::GetInstance()->Get(EOSound::PIPE_SOUND)->Play();
							}
						}
						break;

					case EObjectName::HORIZONTAL_PIPE_OBJECT_1:
						if (dir == CollisionDirection::LEFT_COL)
						{
							// chuyển qua map cha
							if (this->_IsSubWorld == true)
							{
								w = WorldManagement::GetInstance()->PopSubWorld();
								mario->_position = *w->_CreepUpPos.at(0);
								w->SetMario(mario);
								w->SetGameInfo(_gameInfo);
								SoundManagement::GetInstance()->Get(EOSound::PIPE_SOUND)->Play();
							}
						}
						break;

					case EObjectName::HORIZONTAL_PIPE_OBJECT_2:
						if (dir == CollisionDirection::LEFT_COL)
						{
							// chuyển qua map cha
							if (this->_IsSubWorld == true)
							{
								w = WorldManagement::GetInstance()->PopSubWorld();
								mario->_position = *w->_CreepUpPos.at(1);
								w->SetMario(mario);
								w->SetGameInfo(_gameInfo);
								SoundManagement::GetInstance()->Get(EOSound::PIPE_SOUND)->Play();
							}
						}
						break;

					case EObjectName::CARNIVOROUSFLOWER_PIPE_OBJECT:
						c = ((Pipe *)(*i))->GetFlowerObj();
						if (c == NULL)
							continue;

						dir = mario->CheckCollisions(c);
						if (dir != CollisionDirection::NONE_COL)
						{
							if (mario->_IsImmortality)
							{
								c->HasCollision();
								mario->ResponseAsNoCollision(*i, dir);
								_gameInfo->AddScore(100);
								SoundManagement::GetInstance()->Get(EOSound::BULLETBREAK_SOUND)->Play();
							}
							else
							{
								mario->ResponseCollisionsWithEnemy();
							}
						}

						break;

					case EObjectName::PIPE_OBJECT:
					case EObjectName::LAND_OBJECT:
					case EObjectName::LEFT_LAND_OBJECT:
					case EObjectName::RIGHT_LAND_OBJECT:
						// k lam gi ca
						break;

					default:
						break;
					}
				}
			}
		}
	}
	

	
	// ----------- LIVING OBJECT - UPDATING OBJECTs------------------------------//
	list<BaseObject *>::iterator j;
	for (i = _quadTree->GetListObjectsInView().begin(); i != _quadTree->GetListObjectsInView().end(); i++)
	{
		// đối tượng sống
		if (IsMovableLivingObject(*i))
		{
			LivingObject *obj = (LivingObject *)(*i);

			// BEGIN COLLISION
			obj->BeginToCheckCollisions();


			// COLLISION
			// xét va chạm vs các đối tượng xung quanh
			_updateQuadTree->InsertListObjInView(obj->GetNodeBound(), _updateQuadTree->GetRootNode());
			for (j = _updateQuadTree->GetListObjectsInView().begin(); j != _updateQuadTree->GetListObjectsInView().end(); j++)
			{
				if ((*i) == (*j))
					continue;

				Box *b;
				if (IsMovableObject(*j))
				{
					b = &((DynamicObject *)(*j))->GetBoardBox();
				}
				else
				{
					b = &(*j)->GetObjectBox();
				}

				// kiểm tra va chạm
				if (AABBCheck(obj->GetBoardBox(), *b))
				{
					CollisionDirection dir;

					// dối tượng sống
					if (IsMovableLivingObject(*j))
					{
						if ( ((LivingObject *)(*j))->_isDead == true )
						{
							_listDeadObjects.push_back(*j);
							continue;
						}
						else
						{
							dir = obj->CheckCollisions(*j);

							if ( (*i)->GetType() == EObjectName::TURTLE_OBJECT )
							{
								if ( ((Turtle *)(*i))->_isCollisionWithMario )
								{
									if ( (*j)->GetType() == EObjectName::ENEMY_OBJECT
										|| (*j)->GetType() == EObjectName::TURTLE2_OBJECT )
									{
										((Enemy *)(*j))->CollisionWithBullet();
										_gameInfo->AddScore(100);
										_listDeadObjects.push_back(*j);
										SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
									}
								}
							}
						}
					}
					else
					{
						if ((*j)->GetType() == EObjectName::TOWER_OBJECT)
						{
							continue;
						}
						else if ((*j)->GetType() == EObjectName::BRICK_OBJECT)
						{
							if (((Brick *)(*j))->_isExplored == false)
							{
								dir = obj->CheckCollisions(*j);
								if ( ((Brick *)(*j))->_isMovedUp )
								{
									if (dir == CollisionDirection::TOP_COL) // va chạm trên vs gạch
									{
										if ( (*i)->GetType() == EObjectName::TURTLE_OBJECT 
											|| (*i)->GetType() == EObjectName::ENEMY_OBJECT
											|| (*i)->GetType() == EObjectName::TURTLE2_OBJECT
											)
										{
											((Enemy *)(*i))->CollisionWithBullet();
											if ((*i)->GetType() == EObjectName::TURTLE_OBJECT )
											{
												_gameInfo->AddScore(400);
											}
											else if ((*i)->GetType() == EObjectName::TURTLE2_OBJECT )
											{
												_gameInfo->AddScore(500);
											}
											else
											{
												_gameInfo->AddScore(200);
											}
											SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
										}
									}
								}
							}
						}
						else
						{
							dir = obj->CheckCollisions(*j);

							if ( ((*j)->GetType() == EObjectName::COIN_BLOCK_OBJECT
								|| (*j)->GetType() == EObjectName::MUSHROOM_BLOCK_OBJECT
								|| (*j)->GetType() == EObjectName::LIFE_MUSHROOM_BLOCK_OBJECT
								|| (*j)->GetType() == EObjectName::FLOWER_BLOCK_OBJECT
								|| (*j)->GetType() == EObjectName::STAR_BLOCK_OBJECT)
								&& ((SecretBlock *)(*j))->_justCollision)
							{
								if (dir == CollisionDirection::TOP_COL) // va chạm trên vs gạch
								{
									if ( (*i)->GetType() == EObjectName::TURTLE_OBJECT 
										|| (*i)->GetType() == EObjectName::ENEMY_OBJECT
										|| (*i)->GetType() == EObjectName::TURTLE2_OBJECT
										)
									{
										((Enemy *)(*i))->CollisionWithBullet();
										if ((*i)->GetType() == EObjectName::TURTLE_OBJECT )
										{
											_gameInfo->AddScore(400);
										}
										else if ((*i)->GetType() == EObjectName::TURTLE2_OBJECT )
										{
											_gameInfo->AddScore(500);
										}
										else
										{
											_gameInfo->AddScore(200);
										}
										SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
									}
								}
							}
						}
					}
				}
			}

			// RESPONSE COLLISIONs
			obj->ResponseCollisions();
		}
		else
		{
			// do nothing
		}
	}

	// -- free - in quadtree
	for (i = _listFreeObjects.begin(); i != _listFreeObjects.end(); i++)
	{
		DynamicObject *obj = (DynamicObject *)(*i);

		_updateQuadTree->InsertListObjInView(obj->GetNodeBound(), _updateQuadTree->GetRootNode());
		for (j = _updateQuadTree->GetListObjectsInView().begin(); j != _updateQuadTree->GetListObjectsInView().end(); j++)
		{
			if ((*j)->GetType() == EObjectName::BRICK_OBJECT && ((Brick *)(*j))->_isExplored == true)
			{
				continue;
			}
			else if ((*j)->GetType() == EObjectName::TOWER_OBJECT)
			{
				continue;
			}

			if ( obj->IsDead() == false )
			{
				CollisionDirection dir;
				CarnivorousFlower *c;

				if (IsMovableLivingObject(*j) == true)
				{
					dir = ((LivingObject *)(*j))->CheckCollisions(obj);
					((LivingObject *)(*j))->ResponseCollisions();
				}

				// xử lý obj
				switch (obj->GetType())
				{
				case EObjectName::MUSHROOM_OBJECT:
				case EObjectName::LIFE_MUSHROOM_OBJECT:
				case EObjectName::STAR_OBJECT:
					dir = ((LivingObject *)obj)->CheckCollisions(*j);
					// do nothing
					break;
				
				case EObjectName::MACHINE_BULLET_OBJECT:
					dir = ((MachineBullet *)obj)->CheckCollisions(*j);
					if (IsMovableLivingObject(*j) == false) // chỉ là các đối tượng k sống
					{
						if (dir == CollisionDirection::TOP_COL)
						{
							((MachineBullet *)obj)->_isDead = true;
							SoundManagement::GetInstance()->Get(EOSound::BULLETBREAK_SOUND)->Play();
						}
					}
					else
					{
						if (dir != CollisionDirection::NONE_COL)
						{
							if ((*j)->GetType() == EObjectName::ENEMY_OBJECT
								|| (*j)->GetType() == EObjectName::TURTLE_OBJECT
								|| (*j)->GetType() == EObjectName::TURTLE2_OBJECT
								|| (*j)->GetType() == EObjectName::FLYING_TURTLE_OBJECT)
							{
								((Enemy *)(*j))->CollisionWithBullet();
								_listDeadObjects.push_back(*j);
								SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
							}
						}
					}
					break;

				case EObjectName::BULLET_OBJECT:
					dir = ((Bullet *)obj)->CheckCollisions(*j);
					if (dir != CollisionDirection::NONE_COL)
					{
						if ((*j)->GetType() == EObjectName::ENEMY_OBJECT
							|| (*j)->GetType() == EObjectName::TURTLE_OBJECT
							|| (*j)->GetType() == EObjectName::TURTLE2_OBJECT
							|| (*j)->GetType() == EObjectName::FLYING_TURTLE_OBJECT)
						{
							if (((Enemy *)(*j))->_isDead)
								continue;

							((Enemy *)(*j))->CollisionWithBullet();
							_listDeadObjects.push_back(*j);
							if ((*i)->GetType() == EObjectName::TURTLE_OBJECT )
							{
								_gameInfo->AddScore(400);
							}
							else if ((*i)->GetType() == EObjectName::TURTLE2_OBJECT
								|| (*i)->GetType() == EObjectName::FLYING_TURTLE_OBJECT)
							{
								_gameInfo->AddScore(500);
							}
							else
							{
								_gameInfo->AddScore(200);
							}
							SoundManagement::GetInstance()->Get(EOSound::ENEMYDIE_SOUND)->Play();
						}
						else
						{
							if ((*j)->GetType() == EObjectName::CARNIVOROUSFLOWER_OBJECT)
							{
								((CarnivorousFlower *)(*j))->HasCollision();
								_listDeadObjects.push_back(*j);
								_gameInfo->AddScore(100);
								SoundManagement::GetInstance()->Get(EOSound::BULLETBREAK_SOUND)->Play();
							}
							else if ((*j)->GetType() == EObjectName::CARNIVOROUSFLOWER_PIPE_OBJECT)
							{
								c = ((Pipe *)(*j))->GetFlowerObj();
								if (c == NULL)
									continue;

								dir = ((Bullet *)obj)->CheckCollisions(c);
								if (dir != CollisionDirection::NONE_COL)
								{
									c->HasCollision();
									_gameInfo->AddScore(100);
									SoundManagement::GetInstance()->Get(EOSound::BULLETBREAK_SOUND)->Play();
								}
							}
						}
					}
					break;

				default:
					break;
				}
			}
		}

		// -------------
		for (j = _listFreeObjects.begin(); j != _listFreeObjects.end(); j++)
		{
			if ((*i) == (*j) 
				|| (*i)->GetType() == EObjectName::FLOWER_OBJECT || (*i)->GetType() == EObjectName::COIN_OBJECT
				|| (*i)->GetType() == EObjectName::BULLET_OBJECT || (*i)->GetType() == EObjectName::MACHINE_OBJECT
				|| (*j)->GetType() == EObjectName::BULLET_OBJECT || (*j)->GetType() == EObjectName::MACHINE_OBJECT)
				continue;

			if ( Intersect(&((DynamicObject *)(*i))->GetNodeBound(), &((DynamicObject *)(*j))->GetNodeBound()) == false )
				continue;

			if (((LivingObject *)(*i))->_isDead == false)
			{
				((LivingObject *)(*i))->CheckCollisions(*j);
			}
		}
	}


	// ------------ RESPONSE COLLISIONS-----------------------------------------/
	// ------------- MARIO --------------------//
	mario->ResponseCollisions();

	// ---------------- FREE OBJECTs------------//
	for (i = _listFreeObjects.begin(); i != _listFreeObjects.end(); i++)
	{
		if ( ((DynamicObject *)(*i))->IsDead() == false )
		{
			switch ((*i)->GetType())
			{
			case EObjectName::MUSHROOM_OBJECT:
			case EObjectName::LIFE_MUSHROOM_OBJECT:
			case EObjectName::STAR_OBJECT:
				((LivingObject *)(*i))->ResponseCollisions();
				break;
				
			case EObjectName::MACHINE_BULLET_OBJECT:
				((MachineBullet *)(*i))->ResponseCollisions();
				break;

			case EObjectName::BULLET_OBJECT:
				((Bullet *)(*i))->ResponseCollisions();
				break;

			default:
				break;
			}
		}
	}
}

void GameWorld::Draw(DXGame *pDXGame)
{	
	this->_backGround->Draw(pDXGame);

	if (_isPause || _isReset)
		return;

	// -------------QUADTREE----------------//
	list<BaseObject *>::iterator i;
	for (i = _quadTree->GetListObjectsInView().begin(); i != _quadTree->GetListObjectsInView().end(); i++)
	{
		(*i)->Draw(pDXGame, _camera);
	}

	// --------------FREE OBJECTs-----------//
	for (i = _listFreeObjects.begin(); i != _listFreeObjects.end(); i++)
	{
		(*i)->Draw(pDXGame, _camera);
	}

	//-----------------MARIO----------------//
	if (!_timeWaiting)
	{
		mario->Draw(pDXGame, _camera);
	}

	_gameInfo->Draw(pDXGame, D3DCOLOR_XRGB(255,255,0));
}

bool GameWorld::IsReset()
{
	return _isReset;
}

void GameWorld::SetReset(bool value)
{
	_isReset = value;
}

D3DXVECTOR2 GameWorld::GetResetPosition()
{
	if (!_flagPosition.empty())
	{
		int maxX = _oriMarioPos.x;
		D3DXVECTOR2 *maxPos = &_oriMarioPos;
		for (list<D3DXVECTOR2 *>::iterator i = _flagPosition.begin(); i != _flagPosition.end(); i++)
		{
			if ((*i)->x < mario->_position.x)
			{
				if (maxX < (*i)->x)
				{
					maxX = (*i)->x;
					maxPos = *i;
				}
			}
		}

		return *maxPos;
	}
	else
	{
		return _oriMarioPos;
	}
}

void GameWorld::ResetMarioPosition()
{
	mario->_velocity.y = 0;
	mario->_velocity.x = 0;
	mario->_isDead = false;
	mario->_SDie = false;
	mario->_IsSmaller = false;
	mario->_EatMushroom = false;
	mario->_EatFlower = false;
	mario->_position = this->GetResetPosition();
}

bool GameWorld::IsFinish()
{
	return _isFinish;
}

bool GameWorld::IsGameOver()
{
	return _isGameOver;
}

void GameWorld::AddSubWorld(GameWorld *world)
{
	world->_IsSubWorld = true;
	this->_ListSubWorld[_nWorld++] = world;
}



GameWorld* GameWorld::GetSubWorld(int n)
{
	if (_nWorld == 0)
		return NULL;

	if (n < 0)
	{
		n = 0;
	}
	else if (n >= _nWorld)
	{
		n = _nWorld - 1;
	}

	return this->_ListSubWorld[n];
}

void GameWorld::RemoveAllSubWorld()
{
	_nWorld = 0;

	if (this->_ListSubWorld[0] != NULL)
	{
		delete this->_ListSubWorld[0];
		this->_ListSubWorld[0] = NULL;
	}

	if (this->_ListSubWorld[1] != NULL)
	{
		delete this->_ListSubWorld[1];
		this->_ListSubWorld[1] = NULL;
	}
}

void GameWorld::AddTheNextWorld(GameWorld *world)
{
	_TheNextWorld = world;
}

void GameWorld::SetMario(MarioPlayer *&mario)
{
	this->mario = mario;
}

MarioPlayer* GameWorld::GetMario()
{
	return this->mario;
}

void GameWorld::SetGameInfo(GameInfo *&gameInfo)
{
	this->_gameInfo = gameInfo;
}

GameInfo* GameWorld::GetGameInfo()
{
	return this->_gameInfo;
}

bool GameWorld::HasTheNextWorld()
{
	if (_TheNextWorld != NULL)
		return true;

	return false;
}

GameWorld* GameWorld::GetTheNextWorld()
{
	return _TheNextWorld;
}

