#pragma once

#include "Sprite.h"

ref class Explosion: public Sprite
{
internal:
	Explosion(
		_In_ int                  id,
		_In_ D2D1_POINT_2F        position,
		_In_ ID2D1Device*         d2dDevice,
		_In_ ID2D1DeviceContext*  d2dContext,
		_In_ IWICImagingFactory*  wicFactory
	   );
	virtual void Render() override;
	void StartTimer();
	void UpdateTimer();
	void IncreaseFrame();
private:
	int           m_frameRate;
	LARGE_INTEGER m_frequency;	
	LARGE_INTEGER m_startTime;
	LARGE_INTEGER m_currentTime;
	LARGE_INTEGER m_elapsedMicroseconds;

};

