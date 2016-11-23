#include "Flower.h"


Flower::Flower(DXTexture *pTexture, D3DXVECTOR2 position)
	:DynamicObject(pTexture, position)
{
	this->_OType = EObjectName::FLOWER_OBJECT;

	this->_direction = NONE;
	this->_velocity = D3DXVECTOR2(0,0);

	this->_width = this->_texture->GetWidth() / 4;
	this->_height = this->_texture->GetHeight();
}

void Flower::Update(GameTime *gameTime)
{
	if (!_isDead)
	{
		DynamicObject::Update(gameTime);
	}
}

void Flower::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_isDead)
		return;

	DynamicObject::Draw(pDXGame, pCamera);
}

void Flower::UpdateObjectState(GameTime *gameTime)
{}

void Flower::UpdateAnimation()
{
	if (!_isDead)
	{
		if (_time >= 500)
		{
			_time = 0;
			_offset_X++;
			if (_offset_X > 3)
			{
				_offset_X = 0;
			}
		}

		DynamicObject::UpdateAnimation();
	}
}

void Flower::HasCollision()
{
	_isDead = true;
}