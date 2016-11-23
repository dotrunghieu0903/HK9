#include "Grass.h"


Grass::Grass(DXTexture *pTexture, D3DXVECTOR2 position)
	:DynamicObject(pTexture, position)
{
	this->_OType = EObjectName::GRASS_OBJECT;

	this->_direction = NONE;
	this->_velocity = D3DXVECTOR2(0,0);

	this->_width = this->_texture->GetWidth() / 3;
	this->_height = this->_texture->GetHeight();
}

void Grass::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Grass::Draw(DXGame *pDXGame, Camera *pCamera)
{
	DynamicObject::Draw(pDXGame, pCamera);
}

void Grass::UpdateObjectState(GameTime *gameTime)
{}

void Grass::UpdateAnimation()
{
	if (_time >= 500)
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