#include "Star.h"


Star::Star(DXTexture *pTexture, D3DXVECTOR2 position, D3DXVECTOR2 velocity, D3DXVECTOR2 a)
	: LivingObject(pTexture, position, NONE, velocity)
{
	this->_OType = EObjectName::STAR_OBJECT;

	this->_width = _texture->GetWidth() / 4;
	this->_height = _texture->GetHeight();

	this->_isMoveUp = false;
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
}

void Star::Update(GameTime *gameTime)
{
	if (!_isDead)
	{
		DynamicObject::Update(gameTime);
	}
}

void Star::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_isDead)
		return;

	LivingObject::Draw(pDXGame, pCamera);
}

void Star::UpdateObjectState(GameTime *gameTime)
{
	if (!_isDead) // sống
	{
		_velocity.y += _a.y * _deltaTime;

		_position.x += _velocity.x * _deltaTime;
		_position.y += _velocity.y * _deltaTime;
	}
}

void Star::UpdateAnimation()
{
	if (!_isDead)
	{
		if (_time > 200)
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


void Star::BeginToCheckCollisions()
{
	if (_isMoveUp)
		return;

	Collision::BeginToCheckCollisions();
}

void Star::TopCol(BaseObject *obj)
{
	Collision::TopCol(obj);
}

void Star::BottomCol(BaseObject *obj)
{
	Collision::BottomCol(obj);
}

void Star::LeftCol(BaseObject *obj)
{
	Collision::LeftCol(obj);
}

void Star::RightCol(BaseObject *obj)
{
	Collision::RightCol(obj);
}

CollisionDirection Star::CheckCollisions(BaseObject *obj)
{
	return Collision::CheckCollisions(this, obj);
}

void Star::ResponseCollisions()
{
	if (_isDead)
		return;

	if (_isMoveUp)
		return;

	if (_flagCollisionY == 1)
	{
		_velocity.y = _maxV.y;
	}
	else if (_flagCollisionY == -1)
	{
		_velocity.y = 0;
	}
	
	if (_flagCollisionX == -1)
	{
		if (_velocity.x > 0)
		{
			_velocity.x *= -1;
		}
	}
	else if (_flagCollisionX == 1)
	{
		if (_velocity.x < 0)
		{
			_velocity.x *= -1;
		}
	}
}