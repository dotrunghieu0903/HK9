#include "MarioGame.h"

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR	 lpCmdLine,
				   int		 nCmdShow)
{
	MarioGame *_game = new MarioGame();
	if (_game->Init(hInstance) == false)
	{
		_game->End();
		return 0;
	}

	_game->Run();
	_game->End();
	return 1;
}