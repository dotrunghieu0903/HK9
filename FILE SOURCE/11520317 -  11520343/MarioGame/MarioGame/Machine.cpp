#include "Machine.h"


Machine::Machine(DXTexture *pTexture, D3DXVECTOR2 position, DXTexture *pBulletTexture)
	:DynamicObject(pTexture, position, NONE, D3DXVECTOR2(0,0))
{
	this->_OType = EObjectName::MACHINE_OBJECT;

	this->_width = pTexture->GetWidth();
	this->_height = pTexture->GetHeight();

	this->_bulletTexture = pBulletTexture;
	_bullet = NULL;

	this->UpdateBound();
}

void Machine::Update(GameTime *gameTime)
{
	DynamicObject::Update(gameTime);

	if (_isOutOf == false) // chỉ update khi viên đạn chưa ra khỏi máy
	{
		if (_bullet != NULL)
		{
			_bullet->Update(gameTime);
		}
	}
}

void Machine::ShootBullet(D3DXVECTOR2 pos, list<BaseObject *> &l)
{
	if (_time > TIME_OF_SHOOTING_BULLET_OF_MACHINE || _bullet == NULL)
	{
		_time = 0.0f;
		Direction dir;
		if (pos.x < _position.x)
		{
			dir = LEFT;
		}
		else
		{
			dir = RIGHT;
		}

		_bullet = new MachineBullet(
			_bulletTexture, 
			D3DXVECTOR2(_position.x, _position.y + _height / 4),
			dir
			);
		_isOutOf = false;
		SoundManagement::GetInstance()->Get(EOSound::BULLETBREAK_SOUND)->Play();
	}
	else
	{
		if (_bullet != NULL && _isOutOf == false)
		{
			if (_bullet->_position.x + _bullet->_width / 2.0f + 1 < _position.x - _width / 2.0f
				|| _position.x + _width / 2.0f + 1 < _bullet->_position.x - _bullet->_width / 2.0f)
			{
				l.push_back(_bullet);
				_isOutOf = true;
			}
		}
	}
}

void Machine::Draw(DXGame *pDXGame, Camera *pCamera)
{
	DynamicObject::Draw(pDXGame, pCamera);
	if (_bullet != NULL)
	{
		_bullet->Draw(pDXGame, pCamera);
	}
}