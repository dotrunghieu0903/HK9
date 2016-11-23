#include "Turtle2.h"


Turtle2::Turtle2(DXTexture *pTexture, D3DXVECTOR2 position, Direction direction, D3DXVECTOR2 velocity)
	: Enemy(pTexture, position, direction, velocity)
{
	this->_OType = EObjectName::TURTLE2_OBJECT;

	this->_width = _texture->GetWidth() / 4;
	this->_height = _texture->GetHeight();
}

void Turtle2::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Turtle2::Draw(DXGame *pDXGame, Camera *pCamera)
{
	LivingObject::Draw(pDXGame, pCamera);
}

void Turtle2::UpdateObjectState(GameTime *gameTime)
{
	Enemy::UpdateObjectState(gameTime);
}

void Turtle2::UpdateAnimation()
{
	if (!_isDisappear) // Sống
	{
		if (_time >= 400)
		{
			_time = 0;
			_offset_X++;
			if (_direction == LEFT)
			{
				if (_offset_X > 1)
				{
					_offset_X = 0;
				}
			}
			else if (_direction == RIGHT)
			{
				if (_offset_X > 3)
				{
					_offset_X = 2;
				}
			}
		}

		return;
	}
}

void Turtle2::CollisionWithMario()
{
	// Empty
}

void Turtle2::CollisionWithBullet()
{
	Enemy::CollisionWithBullet();
}

