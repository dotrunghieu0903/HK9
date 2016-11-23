#include "Mushroom.h"


Mushroom::Mushroom(DXTexture *pTexture, D3DXVECTOR2 position, ETypeOfMushroom type, Direction direction, D3DXVECTOR2 velocity)
	: LivingObject(pTexture, position, direction, velocity)
{
	this->_width = this->_texture->GetWidth() / 2;
	this->_height = this->_texture->GetHeight();

	_type = type;
	if (_type == ETypeOfMushroom::NORMAL_MUSHROOM)
	{
		this->_OType = EObjectName::MUSHROOM_OBJECT;
	}
	else
	{
		this->_OType = EObjectName::LIFE_MUSHROOM_OBJECT;
	}

	this->_isMoveUp = false;
	this->_SFreeFall = true;
	this->_maxV = _velocity;
	if (_maxV.y > 0)
	{
		_maxV.y *= -1;
	}
}

void Mushroom::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Mushroom::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_isDead)
		return;

	LivingObject::Draw(pDXGame, pCamera);
}

void Mushroom::UpdateObjectState(GameTime *gameTime)
{
	DynamicObject::UpdateObjectState(gameTime);

	if (!_isDead) // sống
	{
		_position.x += _velocity.x * _deltaTime;
		_position.y += _velocity.y * _deltaTime;
		return;
	}
}

void Mushroom::UpdateAnimation()
{
	if (_type == NORMAL_MUSHROOM) // nấm lớn
	{
		_offset_X = 0;
	}
	else // nấm tăng mạng
	{
		_offset_X = 1;
	}
}

void Mushroom::SetMovingDirection(Direction dir)
{

}


void Mushroom::BeginToCheckCollisions()
{
	if (_isMoveUp)
		return;

	_SFreeFall = true;
	Collision::BeginToCheckCollisions();
}

void Mushroom::TopCol(BaseObject *obj)
{
	Collision::TopCol(obj);
}

void Mushroom::BottomCol(BaseObject *obj)
{
	Collision::BottomCol(obj);
}

void Mushroom::LeftCol(BaseObject *obj)
{
	Collision::LeftCol(obj);
}

void Mushroom::RightCol(BaseObject *obj)
{
	Collision::RightCol(obj);
}

CollisionDirection Mushroom::CheckCollisions(BaseObject *obj)
{
	return Collision::CheckCollisions(this, obj);
}

void Mushroom::ResponseCollisions()
{
	if (_isDead)
		return;

	if (_isMoveUp)
		return;

	Collision::TransferPosition(_position);

	if (_flagCollisionX == -1)
	{
		_direction = LEFT;
	}
	else if (_flagCollisionX == 1)
	{
		_direction = RIGHT;
	}

	if (_flagCollisionY == 1)
	{
		_SFreeFall = false;
	}
	else if (_flagCollisionY == -1)
	{
		_direction = FALL;
	}


	if (_SFreeFall == false)
	{
		_velocity.y = 0;
	}
	else
	{
		_velocity.y = _maxV.y;
		_direction = FALL;
	}

	if (_velocity.y != 0)
	{
		if (_velocity.x > 0)
		{
			_velocity.x = 100;
			_direction = RIGHT;
		}
		else
		{
			_velocity.x = -100;
			_direction = LEFT;
		}
	}
	else
	{
		_velocity.x = _maxV.x;
	}
}