#include "SoundManagement.h"


SoundManagement SoundManagement::_instance = SoundManagement();

void SoundManagement::AddAll(LPDIRECTSOUND8 pDS)
{
	this->Add(pDS, EOSound::BACKMUSIC_SOUND, "BackMusic.wav");
	this->Add(pDS, EOSound::BONUSAPPEAR_SOUND, "BonusAppear.wav");
	this->Add(pDS, EOSound::BRICKBROKEN_SOUND, "BrickBroken.wav");
	this->Add(pDS, EOSound::BULLETBREAK_SOUND, "BulletBreak.wav");
	this->Add(pDS, EOSound::DYING_SOUND, "Dying.wav");
	this->Add(pDS, EOSound::ENEMYDIE_SOUND, "EnemyDie.wav");
	this->Add(pDS, EOSound::EXTRALIFE_SOUND, "ExtraLife.wav");
	this->Add(pDS, EOSound::FINISHMAP_SOUND, "FinishMap.wav");
	this->Add(pDS, EOSound::GAMEOVER_SOUND, "GameOver.wav");
	this->Add(pDS, EOSound::GETCOIN_SOUND, "GetCoin.wav");
	this->Add(pDS, EOSound::HEADSHOOT_SOUND, "HeadShoot.wav");
	this->Add(pDS, EOSound::JUMP_SOUND, "Jump.wav");
	this->Add(pDS, EOSound::LEVELUP_SOUND, "LevelUp.wav");
	this->Add(pDS, EOSound::MENUCHANGE_SOUND, "MenuChange.wav");
	this->Add(pDS, EOSound::MENUMUSIC_SOUND, "MenuMusic.wav");
	this->Add(pDS, EOSound::PAUSE_SOUND, "Pause.wav");
	this->Add(pDS, EOSound::PIPE_SOUND, "Pipe.wav");
	this->Add(pDS, EOSound::SHOOT_SOUND, "Shoot.wav");
	this->Add(pDS, EOSound::SMALLER_SOUND, "Smaller.wav");
	this->Add(pDS, EOSound::STANDUP_SOUND, "StandUp.wav");
	this->Add(pDS, EOSound::WIN_SOUND, "Win.wav");
}

void SoundManagement::Add(LPDIRECTSOUND8 pDS, EOSound type, std::string wavFilename)
{
	DXSoundBuffer* sound = new DXSoundBuffer(pDS);
	sound->LoadWaveToSoundBuffer(wavFilename);
	sound->getSoundBuffer()->SetVolume(_volume);
	_ListSound[type] = sound;
}

DXSoundBuffer* SoundManagement::Get(EOSound type)
{
	map<EOSound, DXSoundBuffer*>::iterator i;
	i = _ListSound.find(type);
	if (i == _ListSound.end())
	{
		return NULL;
	}

	return i->second;
}

void SoundManagement::SetVolume(long value)
{
	// gh am thanh
	if (value < -10000)
	{
		value = -10000;
	}
	else if (value > 0)
	{
		value = 0;
	}

	_volume = value;

	map<EOSound, DXSoundBuffer *>::iterator i;
	for (i = _ListSound.begin(); i != _ListSound.end(); i++)
	{
		i->second->getSoundBuffer()->SetVolume(_volume);
	}
}

long SoundManagement::GetVolume()
{
	return this->_volume;
}

void SoundManagement::SetMute(bool value)
{
	this->_mute = value;
	if (_mute == true)
	{
		map<EOSound, DXSoundBuffer *>::iterator i;
		for (i = _ListSound.begin(); i != _ListSound.end(); i++)
		{
			i->second->getSoundBuffer()->SetVolume(-10000);
		}
	}
	else
	{
		this->SetVolume(_volume);
	}
}

bool SoundManagement::GetMute()
{
	return this->_mute;
}

void SoundManagement::VolumeUp()
{
	if (_volume < -900)
	{
		_volume = -900;
	}
	else
	{
		_volume += 100;
		if (_volume > 0)
			_volume = 0;
	}

	this->SetVolume(_volume);
}

void SoundManagement::VolumeDown()
{
	_volume -= 100;
	if (_volume < -900)
		_volume = -10000;

	this->SetVolume(_volume);
}