#include "SettingState.h"


SettingState SettingState::_instance;

void SettingState::Init()
{
	_backGround = new BaseInfo(
		TextureManagement::GetInstance()->Get(EOTexture::SETTINGBACKGROUND_TEXTURE),
		D3DXVECTOR2(0,0)
		);

	_soundMenu = new SoundMenu(
		TextureManagement::GetInstance()->Get(EOTexture::SOUNDLABEL_TEXTURE),
		TextureManagement::GetInstance()->Get(EOTexture::SOUNDOPTION_TEXTURE),
		TextureManagement::GetInstance()->Get(EOTexture::VOLUME_TEXTURE),
		D3DXVECTOR2(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 100)
		);
}

void SettingState::Cleanup()
{

}

void SettingState::Pause()
{

}

void SettingState::Resume()
{

}


void SettingState::HandleEvents(DXGame *pDXGame)
{
	if (pDXGame->IsKeyDown(DIK_ESCAPE) && !_lastESCKey)
	{
		_lastESCKey = true;
		this->ChangeState(StateManagement::GetInstance(), BeginState::GetInstance());
	}
	else if (pDXGame->IsKeyUp(DIK_ESCAPE))
	{
		_lastESCKey = false;
	}

	if (pDXGame->IsKeyDown(DIK_LEFT) && !_lastLeftKey)
	{
		_lastLeftKey = true;
		_soundMenu->DecreaseValue();
		if (_soundMenu->GetSelection() == SoundSelection::SOUND)
		{
			SoundManagement::GetInstance()->SetMute(!_soundMenu->IsSoundOn());
		}
		else
		{
			SoundManagement::GetInstance()->VolumeDown();
		}

		if (_soundMenu->IsSoundOn())
		{
			SoundManagement::GetInstance()->Get(EOSound::GETCOIN_SOUND)->Play();
		}
	}
	else if (pDXGame->IsKeyUp(DIK_LEFT))
	{
		_lastLeftKey = false;
	}
	
	if (pDXGame->IsKeyDown(DIK_RIGHT) && !_lastRightKey)
	{
		_lastRightKey = true;
		_soundMenu->IncreaseValue();
		if (_soundMenu->GetSelection() == SoundSelection::SOUND)
		{
			SoundManagement::GetInstance()->SetMute(!_soundMenu->IsSoundOn());
		}
		else
		{
			SoundManagement::GetInstance()->VolumeUp();
		}

		if (_soundMenu->IsSoundOn())
		{
			SoundManagement::GetInstance()->Get(EOSound::GETCOIN_SOUND)->Play();
		}
	}
	else if (pDXGame->IsKeyUp(DIK_RIGHT))
	{
		_lastRightKey = false;
	}

	if (pDXGame->IsKeyDown(DIK_UP) && !_lastUpKey)
	{
		_lastUpKey = true;
		_soundMenu->GoBack();
		SoundManagement::GetInstance()->Get(EOSound::GETCOIN_SOUND)->Play();
	}
	else if (pDXGame->IsKeyUp(DIK_UP))
	{
		_lastUpKey = false;
	}
	
	if (pDXGame->IsKeyDown(DIK_DOWN) && !_lastDownKey)
	{
		_lastDownKey = true;
		_soundMenu->GoNext();
		SoundManagement::GetInstance()->Get(EOSound::GETCOIN_SOUND)->Play();
	}
	else if (pDXGame->IsKeyUp(DIK_DOWN))
	{
		_lastDownKey = false;
	}
}


void SettingState::Update(GameTime* gameTime)
{
}

void SettingState::Draw(DXGame *pDXGame)
{
	_backGround->Draw(pDXGame);
	_soundMenu->Draw(pDXGame);
}