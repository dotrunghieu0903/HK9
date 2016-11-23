#ifndef _SOUNDMANAGEMENT_H_
#define _SOUNDMANAGEMENT_H_

#include "DirectXGame.h"
#include <map>

enum EOSound
{
	BACKMUSIC_SOUND,
	BONUSAPPEAR_SOUND,
	BRICKBROKEN_SOUND,
	BULLETBREAK_SOUND,
	DYING_SOUND,
	ENEMYDIE_SOUND,
	EXTRALIFE_SOUND,
	FINISHMAP_SOUND,
	GAMEOVER_SOUND,
	GETCOIN_SOUND,
	HEADSHOOT_SOUND,
	JUMP_SOUND,
	LEVELUP_SOUND,
	MENUCHANGE_SOUND,
	MENUMUSIC_SOUND,
	PAUSE_SOUND,
	PIPE_SOUND,
	SHOOT_SOUND,
	SMALLER_SOUND,
	STANDUP_SOUND,
	WIN_SOUND
};
class SoundManagement
{
private:
	map<EOSound, DXSoundBuffer*> _ListSound;
	long _volume;
	bool _mute;
	
	static SoundManagement _instance;
	SoundManagement() { _volume = 0; _mute = false; };
public:
	static SoundManagement* GetInstance()
	{
		return &_instance;
	};
	void Add(LPDIRECTSOUND8, EOSound, std::string);
	void AddAll(LPDIRECTSOUND8);
	DXSoundBuffer* Get(EOSound);
	void SetVolume(long);
	long GetVolume();
	void SetMute(bool);
	bool GetMute();
	void VolumeUp();
	void VolumeDown();
};
#endif
