#include "SoundMenu.h"


SoundMenu::SoundMenu(DXTexture *pTexture, DXTexture *pSoundTexture, DXTexture *pVolumeTexture, D3DXVECTOR2 position)
	: BaseInfo(pTexture, position)
{
	_changeSound = new BaseInfo(pSoundTexture, D3DXVECTOR2(_position.x + _width + 50, _position.y + 10));
	_changeSound->_height /= 2;

	_changeVolume = new BaseInfo(pVolumeTexture, D3DXVECTOR2(_position.x + _width + 50, _position.y + _height / 1.5f));

	_isSoundOn = true;
	_volumePercent = 100;

	_selection = SoundSelection::SOUND;
	_colorSelection = D3DXCOLOR(1.0, 0.0, 1.0, 1.0);
}

void SoundMenu::GoNext()
{
	if (_selection == SoundSelection::VOLUME)
	{
		_selection = SoundSelection::SOUND;
	}
	else
	{
		_selection = SoundSelection::VOLUME;
	}
}

void SoundMenu::GoBack()
{
	if (_selection == SoundSelection::VOLUME)
	{
		_selection = SoundSelection::SOUND;
	}
	else
	{
		_selection = SoundSelection::VOLUME;
	}
}

void SoundMenu::DecreaseValue()
{
	if (_selection == SoundSelection::SOUND)
	{
		this->SetSoundOn(!this->IsSoundOn());
	}
	else
	{
		this->SetVolume(this->GetVolume() - 0.1f);
	}
}

void SoundMenu::IncreaseValue()
{
	if (_selection == SoundSelection::SOUND)
	{
		this->SetSoundOn(!this->IsSoundOn());
		
	}
	else
	{
		this->SetVolume(this->GetVolume() + 0.1f);
	}
}

bool SoundMenu::IsSoundOn()
{
	return this->_isSoundOn;
}

float SoundMenu::GetVolume()
{
	return _volumePercent;
}

void SoundMenu::SetSoundOn(bool on)
{
	this->_isSoundOn = on;
	if (_isSoundOn)
	{
		_changeSound->_offset_Y = 0;
	}
	else
	{
		_changeSound->_offset_Y = 1;
	}
}

void SoundMenu::SetVolume(float value)
{
	if (value > 1.0)
	{
		value = 1.0;
	}
	else if (value < 0.0)
	{
		value = 0.0;
	}

	this->_volumePercent = value;
	_changeVolume->_width = this->_volumePercent * _changeVolume->_texture->GetWidth();
}

SoundSelection SoundMenu::GetSelection()
{
	return this->_selection;
}

void SoundMenu::Draw(DXGame *pDXGame, D3DCOLOR color)
{
	// label
	BaseInfo::Draw(pDXGame, color);

	if (_selection == SoundSelection::SOUND)
	{
		_changeSound->Draw(pDXGame, _colorSelection);
		_changeVolume->Draw(pDXGame, color);
	}
	else
	{
		_changeSound->Draw(pDXGame, color);
		_changeVolume->Draw(pDXGame, _colorSelection);
	}
}

