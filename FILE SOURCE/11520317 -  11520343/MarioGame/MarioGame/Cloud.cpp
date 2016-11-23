#include "Cloud.h"


Cloud::Cloud(DXTexture *pTexture, D3DXVECTOR2 position)
	:DynamicObject(pTexture, position)
{
	this->_OType = EObjectName::CLOUD_OBJECT;

	this->_direction = NONE;
	this->_velocity = D3DXVECTOR2(0,0);

	this->_width = this->_texture->GetWidth() / 3;
	this->_height = this->_texture->GetHeight();
}

void Cloud::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Cloud::Draw(DXGame *pDXGame, Camera *pCamera)
{
	DynamicObject::Draw(pDXGame, pCamera);
}

void Cloud::UpdateObjectState(GameTime *gameTime)
{
	// Empty
}

void Cloud::UpdateAnimation()
{
	if (_time >= 1000)
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