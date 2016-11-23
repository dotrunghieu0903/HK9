#include "Bar.h"


Bar::Bar(DXTexture *pTexture, D3DXVECTOR2 position, ETypeOfBar type, D3DXVECTOR2 velocity)
	:DynamicObject(pTexture, position, NONE, velocity)
{
	this->_width = this->_texture->GetWidth();
	this->_height = this->_texture->GetHeight();

	this->_type = type;
	this->_isCollision = false;
	this->_distance = 0;
	this->_vel_Y = 1000;

	if (_type == NORMAL_BAR)
	{
		this->_OType = BAR_OBJECT;
		_direction = NONE;
		_velocity.x = 0;
		_velocity.y = velocity.y;
	}
	else if (_type == GODOWN_BAR)
	{
		this->_OType = GODOWN_BAR_OBJECT;
		_direction = FALL;
		_velocity.x = 0;
	}
	else if (_type == GOUP_BAR)
	{
		this->_OType = GOUP_BAR_OBJECT;
		_direction = JUMP;
		_velocity.x = 0;
	}
	else
	{
		this->_OType = HORIZONTAL_BAR_OBJECT;
		_direction = RIGHT;
		_origin_X = _position.x;
		_velocity.y = 0;
	}
}

void Bar::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Bar::Draw(DXGame *pDXGame, Camera *pCamera)
{
	DynamicObject::Draw(pDXGame, pCamera);
}

void Bar::UpdateObjectState(GameTime *gameTime)
{
	DynamicObject::UpdateObjectState(gameTime);

	if (_type == NORMAL_BAR && !_isDead) // NORMAL_BAR
	{
		if (_isCollision)
		{
			if (_time > TIME_DELAY_OF_BAR_FALLING)
			{
				_velocity.y = _vel_Y;
				_direction = FALL;

				if (_velocity.y > 0)
				{
					_velocity.y *= -1;
				}
				_position.y += _velocity.y * _deltaTime;
				if (_position.y < -_height)
				{
					_isDead = true;
				}
			}
		}
	}
	else if (_type == GODOWN_BAR) // GODOWN_BAR
	{
		_position.y += _velocity.y * _deltaTime;
		if (_position.y < -_height)
		{
			_position.y = SCREEN_HEIGHT + _height;
		}
	}
	else if (_type == GOUP_BAR)
	{
		_position.y += _velocity.y * _deltaTime;
		if (_position.y > _height + SCREEN_HEIGHT)
		{
			_position.y = -_height;
		}
	}
	else if (_type == HORIZONTAL_BAR) // HORIZONTALMOVING_BAR
	{
		_position.x += _velocity.x * _deltaTime;
		if (_position.x > MAX_DISTANCE_OF_HORIZONTALMOVING_BAR + _origin_X)
		{
			_direction = LEFT;
		}
		else if (_position.x < _origin_X - MAX_DISTANCE_OF_HORIZONTALMOVING_BAR)
		{
			_direction = RIGHT;
		}
	}
}

void Bar::UpdateAnimation()
{
	DynamicObject::UpdateAnimation();
}


void Bar::HasCollision()
{
	if (_type != NORMAL_BAR)
		return;

	if (!_isCollision) // đảm bảm an toàn khi đứng trên bị xem như k va chạm
	{
		_time = 0.0f;
	}
	_isCollision = true;
}