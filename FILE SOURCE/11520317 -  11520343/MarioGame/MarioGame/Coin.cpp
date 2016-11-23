#include "Coin.h"

Coin::Coin(DXTexture *pTexture, D3DXVECTOR2 position, Direction direction, D3DXVECTOR2 velocity)
	: DynamicObject(pTexture, position, direction, velocity)
{
	this->_OType = EObjectName::COIN_OBJECT;

	this->_width = this->_texture->GetWidth() / 2;
	this->_height = this->_texture->GetHeight();

	this->_direction = NONE;
	this->_velocity = D3DXVECTOR2(0,0);
}

void Coin::Update(GameTime *gameTime)
{
	if (!_isDead)
	{
		DynamicObject::Update(gameTime);
	}
}

void Coin::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (!_isDead)
	{
		DynamicObject::Draw(pDXGame, pCamera);
	}
}

void Coin::UpdateObjectState(GameTime *gameTime)
{
	// Empty
}

void Coin::UpdateAnimation()
{
	if (!_isDead)
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

		DynamicObject::UpdateAnimation();
	}
}

void Coin::HasCollision()
{
	this->_isDead = true;
}