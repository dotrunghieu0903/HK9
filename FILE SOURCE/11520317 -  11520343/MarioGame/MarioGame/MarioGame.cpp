#include "MarioGame.h"


MarioGame::MarioGame() : DXGame()
{}

bool MarioGame::Init(HINSTANCE hInstance)
{
	if (!Init_Window(hInstance))
	{
		(Logger::GetLogger("MarioGame::Init(HINSTANCE)").Error("Can't Init Window"));
		return false;
	}

	if (!Init_Direct3D())
	{
		(Logger::GetLogger("MarioGame::Init(HINSTANCE)").Error("Can't Init DirectX"));
		return false;
	}

	if (!Init_Input())
	{
		(Logger::GetLogger("MarioGame::Init(HINSTANCE)").Error("Can't Init Input"));
		return false;
	}

	if (!Init_KeyboardDevice())
	{
		(Logger::GetLogger("MarioGame::Init(HINSTANCE)").Error("Can't Init Keyboard"));
		return false;
	}

	if (!InitDirectSound(_hWnd))
	{
		//log
		return false;
	}

	Initialize();

	return true;
}

void MarioGame::Run()
{
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				return;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			PollKeyboard();
			if (gameTime->CanCreateNewFrame())
			{
				Update();

				if (this->BeginScene())
				{
					// draw surface background
					//this->DrawSurface(background);

					this->Clear();

					this->SpriteHandler_Begin();

					Draw();

					this->SpriteHandler_End();

					this->EndScene();
				}

				this->Present();
			}
		}
	}
}

void MarioGame::End()
{
	DeleteWindow();
	DeleteDirect3D();
	DeleteWindow();
	ShutdownDirectSound();
}

void MarioGame::Initialize()
{
	gameTime = new GameTime();

	// texture
	textureManagement = TextureManagement::GetInstance();
	textureManagement->AddAll(this->_d3dDevice);

	// sound
	soundManagement = SoundManagement::GetInstance();
	soundManagement->AddAll(this->_pDS);
	// state
	stateManagement = StateManagement::GetInstance();
	stateManagement->Init();
	stateManagement->PushState(BeginState::GetInstance());
}

void MarioGame::Update()
{
	stateManagement->HandleEvents(this);
	stateManagement->Update(gameTime);
}

void MarioGame::Draw()
{
	stateManagement->Draw(this);
}