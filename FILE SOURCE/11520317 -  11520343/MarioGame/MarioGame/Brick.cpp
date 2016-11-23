#include "Brick.h"


Brick::Brick(DXTexture *pTexture, DXTexture *pExploredTexture, D3DXVECTOR2 position, DXTexture *pCoinTexture, bool hasCoin)
	:DynamicObject(pTexture, position, JUMP)
{
	this->_width = pTexture->GetWidth() / 2;
	this->_height = pTexture->GetHeight();

	this->_hasCoin = hasCoin;
	if (_hasCoin)
	{
		_coin = new Coin(pCoinTexture, _position);
		_pFraments[0] = NULL;
		_pFraments[1] = NULL;
		_pFraments[2] = NULL;
		_pFraments[3] = NULL;

		this->_OType = EObjectName::COIN_BRICK_OBJECT;
	}
	else
	{
		_coin = NULL;

		_pFraments[0] = new DynamicObject(pExploredTexture, D3DXVECTOR2(_position.x, _position.y), NONE, D3DXVECTOR2(0, 700)); // trên trái
		_pFraments[1] = new DynamicObject(pExploredTexture, D3DXVECTOR2(_position.x + _width / 2, _position.y), NONE, D3DXVECTOR2(0, 700)); // trên phải
		_pFraments[2] = new DynamicObject(pExploredTexture, D3DXVECTOR2(_position.x, _position.y - _height / 2), NONE, D3DXVECTOR2(0, 400)); // dưới trái
		_pFraments[3] = new DynamicObject(pExploredTexture, D3DXVECTOR2(_position.x + _width / 2, _position.y - _height / 2), NONE, D3DXVECTOR2(0, 400)); // dưới phải

		_a = D3DXVECTOR2(700, -2000);

		this->_OType = EObjectName::BRICK_OBJECT;
	}

	this->_origin_Y = _position.y;
	this->_time = 0;
	this->_isMovedUp = false;
	this->_isCollision = false;
	this->_isExplored = false;
	this->_isDisappear = false;
	this->_isColFirst = false;
}

void Brick::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);
}

void Brick::Draw(DXGame *pDXGame, Camera *pCamera)
{
	if (_hasCoin)
	{
		if (!_isExplored) // chưa bị đội
		{
			_coin->Draw(pDXGame, pCamera);
		}

		DynamicObject::Draw(pDXGame, pCamera);
	}
	else // k có coin
	{
		if (!_isExplored)
		{
			DynamicObject::Draw(pDXGame, pCamera);
		}
		else
		{
			if (!_isDisappear)
			{
				for (int i = 0; i < 4; i++)
				{
					_pFraments[i]->Draw(pDXGame, pCamera);
				}
			}
		}
	}
}

void Brick::UpdateObjectState(GameTime *gameTime)
{
	DynamicObject::UpdateObjectState(gameTime);

	if (!_hasCoin) // thường
	{
		if (!_isExplored) // chưa bị nổ
		{
			if (_isMovedUp) // bị Mario đội, di chuyển lên
			{
				_position.y += _velocity.y * _deltaTime;
				if (_position.y - _origin_Y > MAX_HEIGHT_MOVE_UP_OF_BRICK)
				{
					_isMovedUp = false;
				}
			}
			else if (_position.y > _origin_Y) // di chuyển xuống sau khi bị đội
			{
				_position.y -= _velocity.y * _deltaTime;
				if (_position.y < _origin_Y)
				{
					_position.y = _origin_Y;
				}
			}
		}
		else // nổ
		{
			if (!_isDisappear)
			{
				for (int i = 0; i < 4; i++)
				{
					if (i == 0 || i == 2) // mảnh bên trái
					{
						_pFraments[i]->_position.x -= 1.5f;
					}
					else
					{
						_pFraments[i]->_position.x += 1.5f;
					}

					_pFraments[i]->_velocity.y += _a.y * _deltaTime;
					_pFraments[i]->_position.y += _pFraments[i]->_velocity.y * _deltaTime;
				}

				if (_pFraments[0]->_position.y < -_height) // mảnh trên <-> _pFraments[1]
				{
					_isDisappear = true;
				}
			}
			else
			{
			}
		}
	}
	else // gạch loại chứa Coin
	{
		if (_isCollision && !_isExplored) // va chạm và chưa thành block
		{
			_time += gameTime->GetElapsedTimePerFrameMiliSeconds();
			if (_time >= TIME_OF_LIVING_OF_COINS)
			{
				_isCollision = false;
				_isExplored = true;
				_position.y = _origin_Y;
				_coin->_position.y = _position.y;
			}

			if (_isMovedUp) // bị Mario đội, di chuyển lên
			{
				_position.y += _velocity.y * _deltaTime;
				if (_position.y - _origin_Y > MAX_HEIGHT_MOVE_UP_OF_BRICK)
				{
					_isMovedUp = false;
				}
			
				_coin->_position.y += _velocity.y * 2 * _deltaTime;

			}
			else if (_position.y > _origin_Y) // di chuyển xuống sau khi bị đội
			{
				_position.y -= _velocity.y * _deltaTime;
				if (_position.y < _origin_Y)
				{
					_position.y = _origin_Y;
				}

				_coin->_position.y += _velocity.y * 2 * _deltaTime;
			}
			else // Reset Coin cho biểu hiện lần sau
			{
				_coin->_position.y = _position.y;
			}

			_coin->Update(gameTime);
		}
		else if (_isExplored)
		{
			/*
			if (_coin != NULL)
			{
				delete _coin;
				_coin = NULL;
			}
			*/
		}
	}
}

void Brick::UpdateAnimation()
{
	if (!_hasCoin)
	{
		_offset_X = 0;
	}
	else
	{
		if (!_isExplored)
		{
			_offset_X = 0;
		}
		else
		{
			_offset_X = 1;
		}
	}

	DynamicObject::UpdateAnimation();
}

Brick::~Brick()
{
	if (_coin != NULL)
	{
		delete _coin;
		_coin = NULL;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (_pFraments[i] != NULL)
		{
			delete _pFraments[i];
			_pFraments[i] = NULL;
		}
	}
}

void Brick::HasCollision(MarioType type)
{
	if (!_hasCoin)
	{
		if (type == SMALL_MARIO)
		{
			_isMovedUp = true;
		}
		else
		{
			_isExplored = true;
		}
	}
	else // có đồng xu chứa bên trong
	{
		if (!_isExplored)
		{
			if (!_isColFirst)
			{
				_isColFirst = true;
				_time = 0;
			}
			_isCollision = true;
			_isMovedUp = true;
			_coin->_position.y = _position.y;
		}
	}
}