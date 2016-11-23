#include "AboutState.h"


AboutState AboutState::_instance;

void AboutState::Init()
{
	this->_backGround = new BaseInfo(
		TextureManagement::GetInstance()->Get(EOTexture::ABOUTBACKGROUND_TEXTURE),
		D3DXVECTOR2(0,0)
		);

	SoundManagement::GetInstance()->Get(EOSound::MENUMUSIC_SOUND)->PlayLoop();
}

void AboutState::Cleanup()
{
	SoundManagement::GetInstance()->Get(EOSound::MENUMUSIC_SOUND)->Stop();
}

void AboutState::Pause()
{
	SoundManagement::GetInstance()->Get(EOSound::MENUMUSIC_SOUND)->Stop();
}

void AboutState::Resume()
{
	SoundManagement::GetInstance()->Get(EOSound::MENUMUSIC_SOUND)->PlayLoop();
}


void AboutState::HandleEvents(DXGame *pDXGame)
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
}


void AboutState::Update(GameTime* gameTime)
{
}

void AboutState::Draw(DXGame *pDXGame)
{
	this->_backGround->Draw(pDXGame);
}