﻿#include "BigGunRotating.h"

BigGunRotating::BigGunRotating()
{

}

BigGunRotating::BigGunRotating(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID) 
	: DynamicObject(_position, _direction, _objectID)
{
}

void BigGunRotating::Initialize()
{
	m_ObjectState = eObjectState::STATE_POPUP;
	sprite_alive = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_BIG_GUN_ROATING));
	sprite_dead = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_EXPLOISION));
	sprite_popup = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_BIG_GUN_ROTAING_POPUP));
	m_Sprite = sprite_popup;
	_isShoot = false;
	countBullet = 0;
	_isAddBullet = false;
	m_Position.z = 1.0f;
	m_AttackCounter = 8;
	_timeAnimation = 0;
}

void BigGunRotating::Shoot()
{

	switch (m_DirectAttack)
	{
	case NINE_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-1.0f, 0.0f), 0);
		break;
	case TEN_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-1.0f, 0.0f), -1);
		break;
	case ELEVEN_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-0.5f, 0.0f), -3.7f);		
		break;
	default:
		break;
	}
}

D3DXVECTOR3 BigGunRotating::GetStartPositionOfBullet()
{
	switch (m_DirectAttack)
	{
	case NINE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 30, m_Position.y, 1);
	case TEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 30, m_Position.y + 20, 1);
	case ELEVEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 20, m_Position.y + 30, 1);
	default:
		break;	
	}
	return D3DXVECTOR3();
}

void BigGunRotating::UpdateAnimation()
{
	switch (m_ObjectState)
	{
	case STATE_POPUP:
		m_Sprite->UpdateAnimation(500);
		if (m_Sprite->getAnimationAction()->getCurrentIndex() == 5)
		{
			m_Sprite = sprite_alive;
			m_ObjectState = STATE_ALIVE_IDLE;
		}
		break;
	case STATE_SHUTDOWN:
		break;
	case STATE_ALIVE_IDLE:
		if (m_Sprite != sprite_alive)
		{
			m_Sprite = sprite_alive;
		}
		_distance_X = (int)(CGlobal::Rambo_X - m_Position.x);
		_distance_Y = (int)(CGlobal::Rambo_Y - m_Position.y);
		if(_distance_X > -250)
		{
			_isAddBullet = true;
			if (abs(_distance_Y) < 50)
			{
#pragma region MidAttack
				if (lastDirectAttack != eDirectAttack::NINE_CLOCK_DIRECTION)
				{
					m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
					if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
					{
						m_Sprite->getAnimationAction()->setIndexStart(0);
						m_Sprite->getAnimationAction()->setIndexEnd(2);
						m_DirectAttack = eDirectAttack::NINE_CLOCK_DIRECTION;
						m_TimeChangeDirectAttack = 0;
						lastDirectAttack = m_DirectAttack;
					}
				}
				else
				{
					m_Sprite->UpdateAnimation(500);
					m_TimeChangeDirectAttack = 0;
				}
#pragma endregion MidAttack
			}
			else
			{
				if (_distance_X < 0 && _distance_Y > 0)
				{
#pragma region TopLeftAttack
					if (_distance_X + _distance_Y > 0)
					{
						if (lastDirectAttack != eDirectAttack::ELEVEN_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::ELEVEN_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setIndexStart(6);
								m_Sprite->getAnimationAction()->setIndexEnd(8);
								m_TimeChangeDirectAttack = 0;
								lastDirectAttack = m_DirectAttack;
							}
						}
						else
						{
							m_Sprite->UpdateAnimation(500);
							m_TimeChangeDirectAttack = 0;
						}
					}
					else
					{
						if (lastDirectAttack != eDirectAttack::TEN_CLOCK_DIRECTION)
						{
							m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
							if (m_TimeChangeDirectAttack > DELAY_TIME_GUN_ROTATE)
							{
								m_DirectAttack = eDirectAttack::TEN_CLOCK_DIRECTION;
								m_Sprite->getAnimationAction()->setIndexStart(3);
								m_Sprite->getAnimationAction()->setIndexEnd(5);
								m_TimeChangeDirectAttack = 0;
								lastDirectAttack = m_DirectAttack;
							}
						}
						else
						{
							m_Sprite->UpdateAnimation(500);
							m_TimeChangeDirectAttack = 0;
						}
					}
#pragma endregion TopLeftAttack
				}
			}
		}
		break;
	case STATE_SHOOTING:
		// !need animation shoot
		break;
	case STATE_BEFORE_DEATH:
		if (!isDead)
		{
			m_TimeChangeState = 0;
			m_Sprite = sprite_dead;
			isDead = true;
		}
		m_Sprite->UpdateAnimation(250);
		break;
	case STATE_DEATH:
		break;
	default:
		break;
	}	
}


void BigGunRotating::UpdateCollision(Object* checkingObject)
{
	if(!isDead) 
	{
		IDDirection collideDirection = this->m_Collision->CheckCollision(this, checkingObject);

		if(collideDirection != IDDirection::DIR_NONE)
		{
			if(checkingObject->getID() == eObjectID::BULLET_RAMBO)
			{
				Bullet* tempBullet = (Bullet*)(checkingObject);
				if(tempBullet->getTypeBullet() == eIDTypeBullet::DEFAULT_BULLET_OF_RAMBO)
				{
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_attacked_sfx)->Play();
					--m_AttackCounter;
				}
				else if(tempBullet->getTypeBullet() == eIDTypeBullet::RED_BULLET_OF_RAMBO)
				{
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_attacked_sfx)->Play();
					m_AttackCounter -= 2;
				}
				else if(tempBullet->getTypeBullet() == eIDTypeBullet::FIRE_BULLET_OF_RAMBO)
				{
					// L Bullet
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_attacked_sfx)->Play();
					m_AttackCounter -= 4;
				}
				else if(tempBullet->getTypeBullet() == eIDTypeBullet::LAZER_BULLET_OF_RAMBO)
				{
					// L Bullet
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_attacked_sfx)->Play();
					m_AttackCounter -= 5;
				}

				if(m_AttackCounter == 0)
				{
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_dead_sfx)->Play();
					m_ObjectState = eObjectState::STATE_BEFORE_DEATH;
				}
				checkingObject->setObjectState(eObjectState::STATE_DEATH);
			}
		}
	}
}

void BigGunRotating:: UpdateMovement()
{}
void BigGunRotating::Update()
{
	if (CGlobal::Rambo_X - m_Position.x > 100)
	{ 
		if (m_ObjectState != STATE_SHUTDOWN)
		{
			m_Sprite = sprite_popup;
			m_Sprite->getAnimationAction()->setCurrentFrame(5);
			m_ObjectState = STATE_SHUTDOWN;
		}
	}

	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
		if(_isAddBullet == true)
		{
			m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if (m_TimeChangeState > 3000)
			{
				m_TimeChangeState = 0;
				m_ObjectState = eObjectState::STATE_SHOOTING;
				_isShoot = true;
			}
		}
		break;
	case STATE_SHOOTING:
		if(_isShoot == true && _isAddBullet == true)
		{
			m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if(m_TimeChangeState > 500)
			{
				countBullet += 1;
				m_TimeChangeState = 0;
				Shoot();
			}
			if(countBullet == 3)
			{
				countBullet = 0;
				_isShoot = false;
			}
		}
		else
		{
			m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
		}
		break;
	case STATE_SHUTDOWN:
		_timeAnimation += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
		if (_timeAnimation > 250)
		{
			_timeAnimation = 0;
			int index = m_Sprite->getAnimationAction()->getCurrentIndex() - 1;
			if (index < 0)
			{
				m_ObjectState = STATE_DEATH;
			}
			else
			{
				m_Sprite->getAnimationAction()->setCurrentFrame(index);
			}
		}
		break;
	case STATE_BEFORE_DEATH:
		if (isDead)
		{
			m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if (m_TimeChangeState > 1500)
			{
				m_ObjectState = eObjectState::STATE_DEATH;
				m_TimeChangeState = 0;
			}
		}
		break;
	case STATE_DEATH:
		this->Release();
		break;
	default:
		break;
	}
}
void BigGunRotating::Render(SPRITEHANDLE spriteHandle)
{
	if(m_Sprite != 0)
	{
		m_Sprite->Render(spriteHandle, 
						getPositionVec2(), 
						m_Sprite->getSpriteEffect(), 
						m_Sprite->getRotate(), 
						m_Sprite->getScale(), 
						m_Position.z);
	}
}


void BigGunRotating::Release()
{
	m_Sprite = 0;
	sprite_alive->Release();
	sprite_dead->Release();
	SAFE_DELETE(sprite_alive);
	SAFE_DELETE(sprite_dead);
}

BigGunRotating::~BigGunRotating()
{

}