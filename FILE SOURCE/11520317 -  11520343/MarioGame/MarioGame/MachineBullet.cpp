#include "MachineBullet.h"


MachineBullet::MachineBullet(DXTexture *pTexture, D3DXVECTOR2 position, Direction direction, D3DXVECTOR2 velocity)
	: DynamicObject(pTexture, position, direction, velocity)
{
	this->_OType = EObjectName::MACHINE_BULLET_OBJECT;

	this->_width = _texture->GetWidth() / 2;
	this->_height = _texture->GetHeight() / 2;

	this->_distance = 0.0f;
	this->_isCollision = false;
	this->_isTopCol = false;
	if (_velocity.y > 0)
	{
		_velocity.y *= -1;
	}
}

void MachineBullet::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void MachineBullet::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_isDead)
		return;

	DynamicObject::Draw(pDXGame, pCamera);
}

void MachineBullet::UpdateObjectState(GameTime *gameTime)
{
	DynamicObject::UpdateObjectState(gameTime);

	if (!_isDead)
	{
		if (!_isCollision)
		{
			_position.x += _velocity.x * _deltaTime;
			_distance += _velocity.x * _deltaTime;
			if (abs(_distance) > DISTANCE_MAX_OF_MACHINE_BULLET)
			{
				_isCollision = true;
				_distance = 0.0f;
			}
		}
		else
		{
			_position.y += _velocity.y * _deltaTime;
			if (_isTopCol)
			{
				if (_time > 2000)
				{
					_isDead = true;
				}
			}
			else if (_position.y < -_height)
			{
				_isDead = true;
			}
		}
		return;
	}
}

void MachineBullet::UpdateAnimation()
{
	if (!_isDead) // Sống
	{
		if (_direction == LEFT)
		{
			_offset_X = 0;
		}
		else if (_direction == RIGHT)
		{
			_offset_X = 1;
		}

		if (!_isCollision)
		{
			_offset_Y = 0;
		}
		else
		{
			_offset_Y = 1;
		}
	}
}


void MachineBullet::HasCollision()
{
	if (_isDead)
		return;

	if (_isCollision)
		return;

	_position.x -= _velocity.x * _deltaTime;
	_isCollision = true;
	_direction = FALL;
	_distance = 0.0f;
}

void MachineBullet::HasTopCollision()
{
	_isTopCol = true;
	_time = 0.0f;
	this->HasCollision();
}


void MachineBullet::BeginToCheckCollisions()
{
	Collision::BeginToCheckCollisions();
}

void MachineBullet::TopCol(BaseObject *obj)
{
	Collision::TopCol(obj);
}

void MachineBullet::BottomCol(BaseObject *obj)
{
	Collision::BottomCol(obj);
}

void MachineBullet::LeftCol(BaseObject *obj)
{
	Collision::LeftCol(obj);
}

void MachineBullet::RightCol(BaseObject *obj)
{
	Collision::RightCol(obj);
}

CollisionDirection MachineBullet::CheckCollisions(BaseObject *obj)
{
	return Collision::CheckCollisions(this, obj);
}

void MachineBullet::ResponseCollisions()
{
	if (_isDead)
		return;

	if (_isCollision)
		return;

	Collision::TransferPosition(_position);

	if (_flagCollisionX != 0 || _flagCollisionY != 0)
	{
		_position.x -= _velocity.x * _deltaTime;
		_isCollision = true;
		_direction = FALL;
		_distance = 0.0f;
	}
}
