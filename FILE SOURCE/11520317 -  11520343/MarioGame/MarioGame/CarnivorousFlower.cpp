#include "CarnivorousFlower.h"


CarnivorousFlower::CarnivorousFlower(DXTexture *pTexture, D3DXVECTOR2 position, Direction direction, D3DXVECTOR2 velocity)
	:DynamicObject(pTexture, position, direction, velocity)
{
	this->_OType = EObjectName::CARNIVOROUSFLOWER_OBJECT;

	this->_width = this->_texture->GetWidth() / 3;
	this->_height = this->_texture->GetHeight();

	this->_isDelayMove = false;
}

void CarnivorousFlower::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void CarnivorousFlower::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_isDead)
		return;

	DynamicObject::Draw(pDXGame, pCamera);
}

void CarnivorousFlower::UpdateObjectState(GameTime *gameTime)
{
	DynamicObject::UpdateObjectState(gameTime);

	if (!_isDead && !_isDelayMove)
	{
		if (_direction == JUMP || _direction == FALL)
		{
			_position.y += _velocity.y * _deltaTime;
		}
	}
}

void CarnivorousFlower::UpdateAnimation()
{
	if (_time >= 300)
	{
		_time = 0;
		_offset_X++;
		if (_offset_X > 2)
		{
			_offset_X = 0;
		}
	}

	DynamicObject::UpdateAnimation();
}

void CarnivorousFlower::HasCollision()
{
	this->_isDead = true;
}