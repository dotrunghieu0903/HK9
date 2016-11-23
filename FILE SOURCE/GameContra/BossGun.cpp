#include "BossGun.h"



BossGun::BossGun()
{

}

BossGun::BossGun(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID) 
	: DynamicObject(_position, _direction, _objectID)
{
}

void BossGun::Initialize()
{
	m_AttackCounter = 1;
	m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
	sprite_alive = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_GUN_BOSS));
	sprite_dead = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_EXPLOISION));
	m_Sprite = sprite_alive;
	m_Position.z = 0.4f;
	isShoot = false;
}

void BossGun::Shoot()
{
	float disX = this->m_Position.x - CGlobal::Rambo_X;
	float disY = this->m_Position.y - CGlobal::Rambo_Y;

	if(disX < 0)
		disX = -disX;

	if(disY < 0)
		disY = -disY;

	if(disX < 224)
	{
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_BOSS1, this->m_Position, D3DXVECTOR2(-2.0f, 4.0f));
	}
	else if(disX > 224 && disX < 448)
	{
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_BOSS1, this->m_Position, D3DXVECTOR2(-3.0f, 4.0f));
	}
}

D3DXVECTOR3 BossGun::GetStartPositionOfBullet()
{
	return D3DXVECTOR3(m_Position.x - 20, m_Position.y, m_Position.z);
}


void BossGun::UpdateAnimation()
{	
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE: // cant be attack by rambo bullet
		//m_Sprite->UpdateAnimation(1000);
		break;
	case STATE_SHOOTING:
		break;
	case STATE_BEFORE_DEATH:
		if(!isDead)
		{
			isDead = true;
			m_Sprite = sprite_dead;
		}
		m_Sprite->UpdateAnimation(250);
		break;
	case STATE_DEATH:
		break;
	default:
		break;
	}	
}


void BossGun::UpdateCollision(Object* checkingObject)
{
	if (isDead == false)
	{
		if (checkingObject->getID() == eObjectID::BULLET_RAMBO)
		{
			IDDirection collideDirection = this->m_Collision->CheckCollision(this, checkingObject);
			if (collideDirection != IDDirection::DIR_NONE)
			{
				Bullet* tempBullet = (Bullet*) (checkingObject);
				if (tempBullet->getTypeBullet() == eIDTypeBullet::DEFAULT_BULLET_OF_RAMBO)
				{
					if (m_AttackCounter > 0)
					{
						SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_attacked_sfx)->Play();
						--m_AttackCounter;
					}
				}
				else if (tempBullet->getTypeBullet() == eIDTypeBullet::RED_BULLET_OF_RAMBO)
				{
					checkingObject->setObjectState(eObjectState::STATE_DEATH);
					if (m_AttackCounter >= 2)
					{
						SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_attacked_sfx)->Play();
						m_AttackCounter -= 2;
					}
				}
				else if (tempBullet->getTypeBullet() == eIDTypeBullet::FIRE_BULLET_OF_RAMBO)
				{
					if (m_AttackCounter >= 4)
					{
						m_AttackCounter -= 4;
					}
				}

				if (m_AttackCounter <= 0)
				{
					m_ObjectState = eObjectState::STATE_BEFORE_DEATH;
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_dead_sfx)->Play();
					//this->isDead = true;
				}
				//checkingObject->setObjectState(eObjectState::STATE_DEATH);
			}
		}
	}
}

void BossGun:: UpdateMovement()
{
}
void BossGun::Update()
{
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
		/*m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
		if(m_TimeChangeState > 800)
		{
			m_TimeChangeState = 0;
			m_ObjectState = eObjectState::STATE_SHOOTING;
			isShoot = true;
		}*/
		if(isShoot == false)
		{
			if(m_Sprite->getAnimationAction()->getCurrentIndex() == 0)
			{
				m_ObjectState = eObjectState::STATE_SHOOTING;
				isShoot = true;
			}
		}
		break;
	case STATE_SHOOTING:
		if(isShoot == true)
		{
			Shoot();
			isShoot = false;
		}
		else
		{
			m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if(m_TimeChangeState > 1000)
			{
				m_TimeChangeState = 0;
				m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
			}
		}
		break;
	case STATE_BEFORE_DEATH:
		if (isDead)
		{
			m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if (m_TimeChangeState > 1000)
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
void BossGun::Render(SPRITEHANDLE spriteHandle)
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


void BossGun::Release()
{
	m_Sprite = 0;
	if (sprite_alive)
	{
		sprite_alive->Release();
	}
	SAFE_DELETE(sprite_alive);
	if (sprite_dead)
	{
		sprite_dead->Release();
	}
	SAFE_DELETE(sprite_dead);
}

BossGun::~BossGun()
{

}