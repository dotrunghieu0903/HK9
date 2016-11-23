#ifndef _SOUNDMENU_H_H
#define _SOUNDMENU_H_H


#include "BaseInfo.h"


enum SoundSelection
{
	SOUND,
	VOLUME
};


class SoundMenu : public BaseInfo
{
private:
	BaseInfo *_changeSound;
	bool _isSoundOn;

	BaseInfo *_changeVolume;
	float _volumePercent;

	SoundSelection _selection;
	D3DXCOLOR _colorSelection;
public:
	SoundMenu(DXTexture *, DXTexture *, DXTexture *, D3DXVECTOR2);
	virtual void GoNext(); // xuống
	virtual void GoBack(); // lên
	virtual void DecreaseValue();
	virtual void IncreaseValue();
	virtual bool IsSoundOn();
	virtual float GetVolume();
	virtual void SetSoundOn(bool);
	virtual void SetVolume(float);
	virtual SoundSelection GetSelection();
	virtual void Draw(DXGame *, D3DCOLOR color = D3DCOLOR_XRGB(255,255,255)); // Vẽ Object co dinh
};



#endif