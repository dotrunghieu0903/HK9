#include "Spring.h"


Spring::Spring(DXTexture *pTexture, D3DXVECTOR2 position, float force)
	: DynamicObject(pTexture, position, NONE)
{
	this->_OType = EObjectName::SPRING_OBJECT;

	this->_width = _texture->GetWidth() / 3;
	this->_height = _texture->GetHeight();

	this->_isCollision = false;
	this->_isSwingDown = false;
	this->_force = force;
}

void Spring::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Spring::Draw(DXGame *pDXGame, Camera *pCamera)
{
	DynamicObject::Draw(pDXGame, pCamera);
}

void Spring::UpdateBound()
{
	if (_offset_X == 0)
	{
		DynamicObject::UpdateBound();
	}
	else if (_offset_X == 1)
	{
		_rect.top = _position.y + _height / 6.0f - 1;
	}
	else
	{
		_rect.top = _position.y - _height / 6.0f - 1;
	}
}

void Spring::UpdateObjectState(GameTime *gameTime)
{
	
}

void Spring::UpdateAnimation()
{
	if (!_isCollision)
	{
		_offset_X = 0;
		return;
	}

	//if (_time > TIME_OF_SPRING)
	if (_time > 100)
	{
		_time = 0;
		if (_isSwingDown)
		{
			_offset_X += 1;
			if (_offset_X > 2)
			{
				_offset_X = 1;
				_isSwingDown = false;
			}
		}
		else
		{
			_offset_X -= 1;
			if (_offset_X == 0)
			{
				_isCollision = false;
			}
		}
	}
}

float Spring::HasCollision()
{
	if (!_isCollision)
	{
		_isCollision = true;
		_isSwingDown = true;
	}
	else
	{
		if (!_isSwingDown)
		{
			return _force;
		}
	}

	return 0.0f;
}

float Spring::GetSwingForce()
{
	if (_isCollision)
	{
		if (!_isSwingDown)
		{
			return _force;
		}
	}

	return 0.0f;
}