#include "SniperStanding.h"

SniperStanding::SniperStanding()
{
}

SniperStanding::SniperStanding(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID)
	: DynamicObject(_position, _direction, _objectID)
{
}

void SniperStanding::Shoot()
{
	switch (m_DirectAttack)
	{
	case ZERO_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(0.0f, 1.0f), 100);
		break;
	case ONE_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(1.0f, 1.0f), 1);
		break;
	case TWO_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(1.5f, 1.0f), 1);
		break;
	case THREE_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(1.0f, 0.0f), 0);
		break;
	case FOUR_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(1.0f, 0.0f), -1);
		break;
	case FIVE_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(1.0f, -1.0f), -1);
		break;
	case SEVEN_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-0.9f, -1.0f), 1);
		break;
	case EIGHT_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-1.0f, 0.0f), 1);
		break;
	case NINE_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-1.0f, 0.0f), 0);
		break;
	case TEN_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-1.5f, 0.0f), -1);
		break;
	case ELEVEN_CLOCK_DIRECTION:
		BulletPoolManager::getInstance()->addBulletIntoList(eIDTypeBullet::BULLET_OF_ENEMY, GetStartPositionOfBullet(), D3DXVECTOR2(-1.0f, 1.0f), -1);
		break;
	default:
		break;	
	}
}

D3DXVECTOR3 SniperStanding::GetStartPositionOfBullet()
{
	switch(m_DirectAttack)
	{
	case ONE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 15, m_Position.y + 30, 1);
	case TWO_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 15, m_Position.y + 30, 1);
	case THREE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 30, m_Position.y + 20, 1);
	case FOUR_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 25, m_Position.y - 5, 1);
	case FIVE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x + 25, m_Position.y - 5, 1);
	case SEVEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 25, m_Position.y - 5 , 1);
	case EIGHT_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 25, m_Position.y - 5, 1);
	case NINE_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 30, m_Position.y + 20, 1);
	case TEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 15, m_Position.y + 30, 1);
	case ELEVEN_CLOCK_DIRECTION:
		return D3DXVECTOR3(m_Position.x - 15, m_Position.y + 30, 1);
	default:
		break;	
	}
	return D3DXVECTOR3(0, 0, 0);
}

void SniperStanding::Initialize()
{
	m_ObjectState = eObjectState::STATE_ALIVE_IDLE;
	sprite_bot = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_SNIPER_STANDING_BOT));
	sprite_top = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_SNIPER_STANDING_TOP));
	sprite_mid = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_SNIPER_STANDING_MID));
	sprite_dead = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_EXPLOISION));
	m_Physic->setVelocity(D3DXVECTOR2(0, 0));
	m_Physic->setAccelerate(D3DXVECTOR2(0, -0.01f));
	m_Sprite = sprite_mid;
	countBullet = 0;
	m_Position.z = 1.0f;
}

void SniperStanding::UpdateAnimation()
{
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:

		_distance_X = (int)(CGlobal::Rambo_X - this->getPositionVec2().x);
		_distance_Y = (int)(CGlobal::Rambo_Y - this->getPositionVec2().y);

#pragma region AttackMid
		if(abs(_distance_Y) < 10)
		{
			m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if(m_TimeChangeDirectAttack > 700)
			{
				m_TimeChangeDirectAttack = 0;

				m_Sprite = sprite_mid;
				if(_distance_X < 0)
				{
					m_DirectAttack = eDirectAttack::NINE_CLOCK_DIRECTION;
					m_Direction = eDirection::LEFT;
				}
				else
				{
					m_DirectAttack = eDirectAttack::THREE_CLOCK_DIRECTION;
					m_Direction = eDirection::RIGHT;
				}
			}
		}
#pragma endregion AttackMid
		else
		{

#pragma region TopLeftAttack
			if(_distance_X < 0 && _distance_Y > 0)
			{
				m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
				if(m_TimeChangeDirectAttack > 700)
				{
					m_TimeChangeDirectAttack = 0;
					m_Sprite = sprite_top;
					m_Direction = eDirection::LEFT;

					if( _distance_X + _distance_Y > 0)
					{
						m_DirectAttack = eDirectAttack::ELEVEN_CLOCK_DIRECTION;
					}
					else
					{
						m_DirectAttack = eDirectAttack::TEN_CLOCK_DIRECTION;
					}
				}
			}
#pragma endregion TopLeftAttack

#pragma region BotLeftAttack
			if(_distance_X < 0 && _distance_Y < 0)
			{
				m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
				if(m_TimeChangeDirectAttack > 700)
				{
					m_TimeChangeDirectAttack = 0;
					m_Sprite = sprite_bot;
					m_Direction = eDirection::LEFT;

					if( _distance_X - _distance_Y < 0)
					{
						m_DirectAttack = eDirectAttack::EIGHT_CLOCK_DIRECTION;
					}
					else
					{
						m_DirectAttack = eDirectAttack::SEVEN_CLOCK_DIRECTION;
					}
				}
			}
#pragma endregion BotLeftAttack

#pragma region BotRightAttack
			if(_distance_X > 0 && _distance_Y < 0)
			{
				m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
				if(m_TimeChangeDirectAttack > 700)
				{
					m_TimeChangeDirectAttack = 0;
					m_Sprite = sprite_bot;
					m_Direction = eDirection::RIGHT;

					if( _distance_X + _distance_Y > 0)
					{
						m_DirectAttack = eDirectAttack::FOUR_CLOCK_DIRECTION;
					}
					else
					{
						m_DirectAttack = eDirectAttack::FIVE_CLOCK_DIRECTION;
					}
				}
			}
#pragma endregion BotRightAttack

#pragma region TopRightAttack 
			if(_distance_X > 0 && _distance_Y > 0)
			{
				m_TimeChangeDirectAttack += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
				if(m_TimeChangeDirectAttack > 700)
				{
					m_Sprite = sprite_top;
					m_Direction = eDirection::RIGHT;

					if( _distance_X - _distance_Y < 0)
					{
						m_DirectAttack = eDirectAttack::ONE_CLOCK_DIRECTION;
					}
					else
					{
						m_DirectAttack = eDirectAttack::TWO_CLOCK_DIRECTION;
					}
					m_TimeChangeDirectAttack = 0;
				}
			}
#pragma endregion TopRightAttack 
		}
		break;
	case STATE_SHOOTING:
		m_Sprite->UpdateAnimation(1000);
		break;
	case STATE_BEFORE_DEATH:
		if(isDead == false)
		{
			isDead = true;
			m_Sprite = sprite_dead;
			m_TimeChangeState = 0;
		}
		m_Sprite->UpdateAnimation(250);
		break;
	case STATE_DEATH:
		break;
	default:
		break;
	}
}
void SniperStanding::UpdateMovement()
{
	m_Physic->UpdateMovement(&m_Position);
}
void SniperStanding::UpdateCollision(Object* checkingObject)
{
	if (!isDead)
	{
		if (checkingObject->getID() == eObjectID::BULLET_RAMBO || checkingObject->getID() == eObjectID::TILE_BASE)
		{
			IDDirection collideDirection = this->m_Collision->CheckCollision(this, checkingObject);

			if (collideDirection != IDDirection::DIR_NONE)
			{
				switch (checkingObject->getID())
				{
				case eObjectID::TILE_BASE:
					if (collideDirection == IDDirection::DIR_TOP)
					{
						/*this->m_Position.y = 
							checkingObject->getPositionVec2().y + 
							(checkingObject->getBound().top - checkingObject->getBound().bottom) / 2 + 
							m_Sprite->getMyTexture()->m_Height / 2;
*/
						this->m_Physic->setVelocityY(0.0f);
					}
					break;
				case eObjectID::BULLET_RAMBO:
					checkingObject->setObjectState(eObjectState::STATE_DEATH);
					m_ObjectState = eObjectState::STATE_BEFORE_DEATH;
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::enemy_dead_sfx)->Play();
					break;
				default:
					break;
				}
			}
		}
	}
}

void SniperStanding::Update()
{
	switch (m_ObjectState)
	{
	case STATE_ALIVE_IDLE:
		m_TimeChangeState += (int)CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
		if(m_TimeChangeState > 3000)
		{
			m_TimeChangeState = 0;
			m_ObjectState = eObjectState::STATE_SHOOTING;
			isShoot = true;
		}
		break;
	case STATE_SHOOTING:
		if(isShoot)
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
				isShoot = false;
			}
		}
		else
		{
			m_ObjectState = STATE_ALIVE_IDLE;
		}
		break;
	case STATE_BEFORE_DEATH:
		if(isDead)
		{
			m_TimeChangeState += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if(m_TimeChangeState > 1500)
			{
				m_TimeChangeState = 0;
				m_ObjectState = eObjectState::STATE_DEATH;
			}
		}
		break;
	case STATE_DEATH:
		this->Release();
		break;
	}
}

void SniperStanding::Render(SPRITEHANDLE spriteHandle)
{
	if(m_Sprite != 0)
	{
		if(m_Direction == eDirection::LEFT)
			m_Sprite->setSpriteEffect(ESpriteEffect::None);
		else
		{
			m_Sprite->setSpriteEffect(ESpriteEffect::Horizontally);
		}
		m_Sprite->Render(spriteHandle, getPositionVec2(), m_Sprite->getSpriteEffect(), m_Sprite->getRotate(), m_Sprite->getScale(), m_Position.z);
	}
}
void SniperStanding::Release()
{
	m_Sprite = 0;
	sprite_bot->Release();
	sprite_dead->Release();
	sprite_top->Release();
	sprite_mid->Release();
	SAFE_DELETE(sprite_bot);
	SAFE_DELETE(sprite_top);
	SAFE_DELETE(sprite_dead);
	SAFE_DELETE(sprite_mid);
}
SniperStanding::~SniperStanding()
{

}