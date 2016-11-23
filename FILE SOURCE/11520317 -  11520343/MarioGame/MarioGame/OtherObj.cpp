#include "OtherObj.h"


Land::Land(DXTexture *pTexture, D3DXVECTOR2 position, TypeOfLand type)
	:StaticObject(pTexture, position)
{
	this->_width = this->_texture->GetWidth() / 3;
	this->_height = this->_texture->GetHeight();	
	BaseObject::Update(NULL);
	
	if (type == MIDDLE_LAND)
	{
		this->_offset_X = 1;
		this->_OType = EObjectName::LAND_OBJECT;
	}
	else if (type == LEFT_LAND)
	{
		this->_offset_X = 0;
		this->_OType = EObjectName::LEFT_LAND_OBJECT;
	}
	else
	{
		this->_offset_X = 2;
		this->_OType = EObjectName::RIGHT_LAND_OBJECT;
	}
}


Tower::Tower(DXTexture *pTexture, D3DXVECTOR2 position)
	:StaticObject(pTexture, position)
{
	this->_OType = EObjectName::TOWER_OBJECT;

	_rect.left = _position.x - _width / 4;
	_rect.right = _position.x + _width / 4;
	_rect.top = _position.y - _height / 4;
	_rect.bottom = _position.y - _height / 2;
}

Block::Block(DXTexture *ptexture, D3DXVECTOR2 position)
	:StaticObject(ptexture, position)
{
	this->_OType = EObjectName::BLOCK_OBJECT;
}


Scene::Scene(DXTexture *ptexture, D3DXVECTOR2 position, ESceneObject type)
	:StaticObject(ptexture, position)
{
	this->_rect.top = 0;
	this->_rect.left = 0;
	this->_rect.right = 0;
	this->_rect.bottom = 0;

	if (type == ESceneObject::FENCE)
	{
		this->_OType = EObjectName::FENCE_OBJECT;
	}
	else if (type == ESceneObject::MOUNTAIN)
	{
		this->_OType = EObjectName::MOUNTAIN_OBJECT;
	}
	else if (type == ESceneObject::SIGN)
	{
		this->_OType = EObjectName::SIGN_OBJECT;
	}
	else if (type == ESceneObject::LAMP)
	{
		this->_OType = EObjectName::LAMP_OBJECT;
	}
	else if (type == ESceneObject::TREE)
	{
		this->_OType = EObjectName::TREE_OBJECT;
	}
	else
	{
		this->_OType = EObjectName::BIG_TREE_OBJECT;
	}
}