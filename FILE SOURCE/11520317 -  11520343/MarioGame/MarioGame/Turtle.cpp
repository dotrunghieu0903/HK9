#include "Turtle.h"


Turtle::Turtle(DXTexture *pTexture, D3DXVECTOR2 position, ETypeOfTurtle type, Direction direction, D3DXVECTOR2 velocity)
	: Enemy(pTexture, position, direction, velocity)
{
	this->_width = _texture->GetWidth() / 6;
	this->_height = _texture->GetHeight() / 2;

	this->_angle = 0.0f;
	this->_origin_X = _position.x;
	this->_origin_Y = _position.y;
	this->_distance = 0;

	this->_isMidTopCol = false;
	this->_flagMidCol = false;

	this->_type = type;
	if (_type == NORMAL_TURTLE)
	{
		this->_OType = EObjectName::TURTLE_OBJECT;
		_offset_X = 2;
	}
	else
	{
		this->_OType = EObjectName::FLYING_TURTLE_OBJECT;
		this->_velocity.y /= 2.0f;
	}
	
	this->_isDisappear = false;
	this->_isCollisionWithMario = false;
	this->_isCollisionWithBullet = false;
}

void Turtle::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Turtle::Draw(DXGame *pDXGame, Camera *pCamera)
{
	LivingObject::Draw(pDXGame, pCamera);
}

void Turtle::UpdateObjectState(GameTime *gameTime)
{
	DynamicObject::UpdateObjectState(gameTime);

	if (_type == NORMAL_TURTLE) // rùa thường
	{
		if (!_isDead)
		{
			_position.x += _velocity.x * _deltaTime;
			_position.y += _velocity.y * _deltaTime;

			if (_isMidTopCol)
			{
				if (_time > TIME_DELAY_OF_TURTLE)
				{
					_isMidTopCol = false;
					_flagMidCol = false;
					if (_isCollisionWithMario == true)
					{
						_isCollisionWithMario = false;
						_maxV.x /= 2;
					}
					
				}
			}
		}
		else if (!_isDisappear)
		{
			_position.y += _velocity.y * _deltaTime;
			if (_position.y < -_height)
			{
				_isDisappear = true;
			}
		}
	}
	else // rùa bay
	{
		if (!_isDead)
		{
			_position.x += _velocity.x * _deltaTime; // cập nhật X
			if (_position.x < _origin_X - MAX_DISTANCE_OF_FLYING_TURTLE)
			{
				_direction = RIGHT;
			}
			else if (_position.x > _origin_X + MAX_DISTANCE_OF_FLYING_TURTLE)
			{
				_direction = LEFT;
			}

			// cập nhật Y
			_angle += _velocity.y * _deltaTime / 100.0f;
			if (_angle >= 2 * PI_NUMBER)
			{
				_angle = 0.0f;
			}
			_position.y = _origin_Y + sin(_angle) * RADIUS_MOVING_OF_FLYING_TURTLE;
		}
		else if (!_isDisappear)
		{
			_position.y += _velocity.y * _deltaTime;
			if (_position.y > SCREEN_HEIGHT)
			{
				_isDisappear = true;
			}
		}
	}
}

void Turtle::UpdateAnimation()
{
	if (_type == NORMAL_TURTLE) // rùa thường
	{
		if (!_isDead)
		{
			if (!_isCollisionWithMario && !_isCollisionWithBullet && !_isMidTopCol)
			{
				if (_time >= 400)
				{
					_time = 0;
					_offset_X++;
					if (_offset_X > 3)
					{
						_offset_X = 2;
					}
				}
			}
			else if (_isCollisionWithBullet)
			{
				_offset_X = 5;
			}
			else if (_isCollisionWithMario || _isMidTopCol)
			{
				_offset_X = 4;
			}
		}
		else
		{
			_offset_X = 5;
		}
	}
	else // rùa biết bay
	{
		if (!_isDead)
		{
			if (!_isCollisionWithMario && !_isCollisionWithBullet)
			{
				if (_time >= 400)
				{
					_time = 0;
					_offset_X++;
					if (_offset_X > 1)
					{
						_offset_X = 0;
					}
				}
			}
			else if (_isCollisionWithBullet)
			{
				_offset_X = 5;
			}
			else if (_isCollisionWithMario)
			{
				_offset_X = 4;
			}
		}
		else
		{
			_offset_X = 5;
		}
	}

	if (!_isCollisionWithBullet && !_isDead)
	{
		if (_direction == LEFT)
		{
			_offset_Y = 1;
		}
		else if (_direction == RIGHT)
		{
			_offset_Y = 0;
		}
	}
	else // va chạm với đạn <-> chết
	{
		_offset_Y = 0;
	}

	DynamicObject::UpdateAnimation();
}

void Turtle::CollisionWithMario()
{
	if (this->_isCollisionWithMario == false)
	{
		_isCollisionWithMario = true;

		if (_type == NORMAL_TURTLE)
		{
			_maxV.x *= 2;
			_velocity.x *= 2;
		}
		else
		{
			_velocity.y *= 4;
			_direction = FALL;
			_isDead = true;
		}
	}
}

void Turtle::CollisionWithBullet()
{
	if (_isCollisionWithBullet == false)
	{
		_velocity.y = _maxV.y;
		_isCollisionWithBullet = true;
		_direction = FALL;
		_isDead = true;
	}
}


bool Turtle::CheckMidTopCollisions(BaseObject *obj, CollisionDirection dir)
{
	if (dir == CollisionDirection::TOP_COL)
	{
		if (obj->_position.x > _position.x - _width / 4.0f
			&& obj->_position.x < _position.x + _width / 4.0f)
		{
			if (!_isMidTopCol)
			{
				_isMidTopCol = true;
				_flagMidCol = true;
				_time = 0.0f;

				return true;
			}
			else
			{
				this->CollisionWithBullet();
				_flagMidCol = false;

				return true;
			}
		}
		else
		{
			_isMidTopCol = false;
			_flagMidCol = false;
			this->CollisionWithMario();
			if (obj->_position.x < _position.x - _width / 3.0f) 
			{
				_direction = RIGHT;
				return true;
			}
			else
			{
				_direction = LEFT;
				return true;
			}
		}
	}
	else // va cham ben
	{
		if (_isMidTopCol == true)
		{
			if (dir == CollisionDirection::LEFT_COL)
			{
				_direction = RIGHT;
				_isMidTopCol = false;
				this->CollisionWithMario();
				return true;
			}
			else if (dir == CollisionDirection::RIGHT_COL)
			{
				_direction = LEFT;
				_isMidTopCol = false;
				this->CollisionWithMario();
				return true;
			}
		}
	}

	return false;
}

void Turtle::ResponseCollisions()
{
	if (_isDead)
		return;

	Collision::TransferPosition(_position);

	if (_type == NORMAL_TURTLE)
	{
		if (_isMidTopCol == false)
		{
			if (_flagMidCol)
			{
				_flagMidCol = false;
			}
			else
			{
				Enemy::ResponseCollisions();
			}
		}
		else if (_isMidTopCol == true)
		{
			_velocity.x = 0;
		}
	}
	else
	{
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
			if (_angle > (PI_NUMBER / 2.0f) 
				&& _angle < (PI_NUMBER * 1.5f))
			{
				if (_angle < (PI_NUMBER))
				{
					_angle = PI_NUMBER - _angle;
				}
				else
				{
					_angle = (3 * PI_NUMBER) - _angle;
				}
			}
		}
		else if (_flagCollisionY == -1)
		{
			if (_angle < (PI_NUMBER / 2.0f))
			{
				_angle = PI_NUMBER - _angle;
			}
			else if (_angle > (PI_NUMBER * 1.5f))
			{
				_angle = (3 * PI_NUMBER) - _angle;
			}
		}
	}
}