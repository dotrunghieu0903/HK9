#include "SecretBlock.h"


SecretBlock::SecretBlock(DXTexture *pTexture, D3DXVECTOR2 position, DXTexture *pOTexture, ETypefOfSecretBlock type)
	: DynamicObject(pTexture, position)
{
	this->_width = _texture->GetWidth() / 3;
	this->_height = _texture->GetHeight();

	this->_type = type;
	if (_type == COIN_SECRET_BLOCK) // đồng xu
	{
		_object = new Coin(pOTexture, _position);
		this->_OType = EObjectName::COIN_BLOCK_OBJECT;
	}
	else if (_type == NORMAL_MUSHROOM_SECRET_BLOCK) // nấm lớn
	{
		_object = new Mushroom(pOTexture, _position, NORMAL_MUSHROOM, JUMP);
		this->_OType = EObjectName::MUSHROOM_BLOCK_OBJECT;
	}
	else if (_type == LIFE_MUSHROOM_SECRET_BLOCK) // nấm tăng mạng
	{
		_object = new Mushroom(pOTexture, _position, LIFE_MUSHROOM, JUMP);
		this->_OType = EObjectName::LIFE_MUSHROOM_BLOCK_OBJECT;
	}
	else if (_type == FLOWER_SECRET_BLOCK) // hoa
	{
		_object = new Flower(pOTexture, _position);
		this->_OType = EObjectName::FLOWER_BLOCK_OBJECT;
	}
	else if (_type == STAR_SECRET_BLOCK)
	{
		_object = new Star(pOTexture, _position);
		this->_OType = EObjectName::STAR_BLOCK_OBJECT;
	}

	this->_isCollision = false;
	this->_isOutOf = false;
	this->_justCollision = false;
}

void SecretBlock::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void SecretBlock::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_isCollision)
	{
		_object->Draw(pDXGame, pCamera);
	}

	DynamicObject::Draw(pDXGame, pCamera);
}

void SecretBlock::UpdateObjectState(GameTime *gameTime)
{
	//DynamicObject::UpdateObjectState(gameTime);

	if (!_isOutOf)
	{
		if (_isCollision)
		{
			if (_object->GetType() == EObjectName::COIN_OBJECT)
			{
				if (_object->_position.y - _object->_height / 2.0f < _position.y + _height / 2.0f + 20)
				{
					_object->_position.y += 2;
				}
				else
				{
					((Coin *)_object)->_isDead = true;
					_justCollision = false;
				}
			}
			else if (_object->GetType() == EObjectName::FLOWER_OBJECT)
			{
				if (_object->_position.y - _object->_height / 2.0f < _position.y + _height / 2.0f)
				{
					_object->_position.y += 2;
				}
				else
				{
					_justCollision = false;
				}
			}
			else
			{
				//_object->Update(gameTime);
				if (_object->_position.y - _object->_height / 2.0f > _position.y + _height / 2.0f + 20)
				{
					_object->_velocity.x = _vel_X;
					_object->_direction = RIGHT;
					_isOutOf = true;
					_justCollision = false;

					if (_object->GetType() == EObjectName::MUSHROOM_OBJECT
						|| _object->GetType() == EObjectName::LIFE_MUSHROOM_OBJECT)
					{
						((Mushroom *)_object)->_isMoveUp = false;	
					}
					else if (_object->GetType() == EObjectName::STAR_OBJECT)
					{
						((Star *)_object)->_isMoveUp = false;
					}
				}
			}
		}
	}
	else
	{
	}
}

void SecretBlock::UpdateAnimation()
{
	if (!_isCollision)
	{
		if (_time >= 300)
		{
			_time = 0;
			_offset_X++;
			if (_offset_X > 1)
			{
				_offset_X = 0;
			}
		}
	}
	else
	{
		_offset_X = 2;
	}	
}

void SecretBlock::HasCollision(list<BaseObject *> &l)
{
	if (!_isCollision)
	{
		_isCollision = true;
		_justCollision = true;

		if (_object->GetType() == EObjectName::MUSHROOM_OBJECT
						|| _object->GetType() == EObjectName::LIFE_MUSHROOM_OBJECT)
		{
			((Mushroom *)_object)->_isMoveUp = true;	
		}
		else if (_object->GetType() == EObjectName::STAR_OBJECT)
		{
			((Star *)_object)->_isMoveUp = true;
		}

		_object->_position.y += 20;
		_object->_direction = JUMP;
		_vel_X = _object->_velocity.x;
		_object->_velocity.y += 20;
		_object->_velocity.x = 0;
		l.push_back(_object);
	}
}