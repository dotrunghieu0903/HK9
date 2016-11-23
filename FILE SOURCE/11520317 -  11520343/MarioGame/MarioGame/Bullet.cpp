#include "Bullet.h"


Bullet::Bullet(DXTexture *pTexture, D3DXVECTOR2 position, D3DXVECTOR2 velocity, D3DXVECTOR2 a)
	: DynamicObject(pTexture, position, NONE, velocity)
{
	this->_OType = EObjectName::BULLET_OBJECT;

	this->_width = _texture->GetWidth() / 4;
	this->_height = _texture->GetHeight();

	_a = a;
	if (_a.y > 0)
	{
		_a.y *= -1;
	}
	_maxV = velocity;
	if (_maxV.y < 0)
	{
		_maxV.y *= -1;
	}
	_velocity.y = 0;
}

void Bullet::Update(GameTime *gameTime)
{
	if (!_isDead)
	{
		DynamicObject::Update(gameTime);
	}
}

void Bullet::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (!_isDead)
	{
		DynamicObject::Draw(pDXGame, pCamera);
	}
}

void Bullet::UpdateObjectState(GameTime *gameTime)
{
	if (!_isDead) // sống
	{
		_position.x += _velocity.x * _deltaTime;
		_velocity.y += _a.y * _deltaTime;
		_position.y += _velocity.y * _deltaTime;
		
		return;
	}
}

void Bullet::UpdateAnimation()
{
	if (!_isDead)
	{
		if (_time > 400)
		{
			_time = 0;
			_offset_X += 1;
			if (_offset_X > 3)
			{
				_offset_X = 0;
			}
		}
	}
}


void Bullet::BeginToCheckCollisions()
{
	Collision::BeginToCheckCollisions();
}

void Bullet::TopCol(BaseObject *obj)
{
	if (obj->GetType() == EObjectName::ENEMY_OBJECT
		|| obj->GetType() == EObjectName::TURTLE_OBJECT
		|| obj->GetType() == EObjectName::FLYING_TURTLE_OBJECT)
	{
		_isDead = true;
	}
	Collision::TopCol(obj);
}

void Bullet::BottomCol(BaseObject *obj)
{
	Collision::BottomCol(obj);
}

void Bullet::LeftCol(BaseObject *obj)
{
	Collision::LeftCol(obj);
}

void Bullet::RightCol(BaseObject *obj)
{
	Collision::RightCol(obj);
}

CollisionDirection Bullet::CheckCollisions(BaseObject *obj)
{
	return Collision::CheckCollisions(this, obj);
}

void Bullet::ResponseCollisions()
{
	if (_isDead)
		return;

	Collision::TransferPosition(_position);

	if (_flagCollisionY == 1)
	{
		_velocity.y = _maxV.y;
	}
	else if (_flagCollisionY == -1)
	{
		_velocity.y = 0;
	}

	if (_flagCollisionX != 0 && _flagCollisionY == 0)
	{
		_isDead = true;
	}
}