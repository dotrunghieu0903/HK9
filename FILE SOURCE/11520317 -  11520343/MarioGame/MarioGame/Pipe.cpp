#include "Pipe.h"


Pipe::Pipe(DXTexture *pTexture, D3DXVECTOR2 position, EntryNumber entryNumber, DXTexture *pFlowerTexture)
	: DynamicObject(pTexture, position, JUMP)
{
	this->_width = this->_texture->GetWidth();
	this->_height = this->_texture->GetHeight();

	this->_entryNumber = entryNumber;
	this->_flower = NULL;

	if (pFlowerTexture != NULL)
	{
		this->_OType = EObjectName::CARNIVOROUSFLOWER_PIPE_OBJECT;
		D3DXVECTOR2 tmpPos; // vị trí của hoa ban đầu
		tmpPos.x = _position.x;
		tmpPos.y = (_position.y + _height / 2);
		this->_flower = new CarnivorousFlower(pFlowerTexture, tmpPos, JUMP);
	}
	else if (_entryNumber == FIRST_ENTRY)
	{
		this->_OType = EObjectName::CREEP_PIPE_OBJECT_1;
	}
	else if(_entryNumber == SECOND_ENTRY)
	{
		this->_OType = EObjectName::CREEP_PIPE_OBJECT_2;
	}
	else if (_entryNumber == SUB_FIRST_ENTRY)
	{
		this->_OType = EObjectName::HORIZONTAL_PIPE_OBJECT_1;
	}
	else if (_entryNumber == SUB_SECOND_ENTRY)
	{
		this->_OType = EObjectName::HORIZONTAL_PIPE_OBJECT_2;
	}
	else if (_entryNumber == FIRST_EXIT)
	{
		this->_OType = EObjectName::CREEP_UP_PIPE_OBJECT_1;
	}
	else if (_entryNumber == SECOND_EXIT)
	{
		this->_OType = EObjectName::CREEP_UP_PIPE_OBJECT_2;
	}
	else
	{
		this->_OType = EObjectName::PIPE_OBJECT;
	}
}

void Pipe::Update(GameTime *gameTime)
{
	if (_flower != NULL)
	{
		if (_flower->_isDead == true)
		{
 			delete _flower;
			_flower = NULL;
		}
		else
		{
			DynamicObject::Update(gameTime);
		}
	}
}

void Pipe::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_flower != NULL)
	{
		_flower->Draw(pDXGame, pCamera);
	}

	DynamicObject::Draw(pDXGame, pCamera);
}

void Pipe::UpdateObjectState(GameTime *gameTime)
{
	DynamicObject::UpdateObjectState(gameTime);

	if (_OType == EObjectName::CARNIVOROUSFLOWER_PIPE_OBJECT) // thẳng đứng có hoa ăn thịt
	{
		if ( (_flower->_position.y + _flower->_height / 2) - _flower->_height > (this->_position.y + this->_height / 2) - 2 )
		{
			if (_flower->_direction != FALL) // khởi tạo thời gian delay
			{
				_flower->_direction = FALL;
				_time = 0;
				_flower->_isDelayMove = true;
			}
			else if (_time > TIME_DELAY_OF_CARNIVOROUS_FLOWER) // thời gian delay kết thúc
			{
				_flower->_isDelayMove = false;
			}
		}
		else if ( (_flower->_position.y + _flower->_height / 2) + _flower->_height / 2 < (this->_position.y + this->_height / 2) - 2 )
		{
			if (_flower->_direction != JUMP) // khởi tạo thời gian delay
			{
				_flower->_direction = JUMP;
				_time = 0;
				_flower->_isDelayMove = true;
			}
			if (_time > TIME_DELAY_OF_CARNIVOROUS_FLOWER) // thời gian delay kết thúc
			{
				_flower->_isDelayMove = false;
			}
		}

		_flower->Update(gameTime);
	}
}

CarnivorousFlower* Pipe::GetFlowerObj()
{
	if (_OType != EObjectName::CARNIVOROUSFLOWER_PIPE_OBJECT)
		return NULL;

	return _flower;
}

Pipe::~Pipe()
{
	if (_flower != NULL)
	{
		delete _flower;
		_flower = NULL;
	}
}