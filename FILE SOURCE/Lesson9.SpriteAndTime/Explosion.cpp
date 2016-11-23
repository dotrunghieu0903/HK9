#include "pch.h"
#include "Explosion.h"

Explosion::Explosion(
	_In_ int                  id,
	_In_ D2D1_POINT_2F        position,
	_In_ ID2D1Device*         d2dDevice,
	_In_ ID2D1DeviceContext*  d2dContext,
	_In_ IWICImagingFactory*  wicFactory
	)
{
	m_id = id;
	m_type = "explosion";
	m_imageFileName = L"Explosion.png";
	m_currentFrame = 0;
	m_lastFrame = 29;
	m_framePerRow = 6;
	m_position = position;
	m_alpha = 1.0f;
	m_frameRate = 17000;

	Initialize(d2dDevice, d2dContext, wicFactory);

	StartTimer();
}

void Explosion::StartTimer()
{
	if (!QueryPerformanceFrequency(&m_frequency))
	{
		throw ref new Platform::FailureException();
	}

	if (!QueryPerformanceCounter(&m_startTime))
	{
		throw ref new Platform::FailureException();
	}
}

void Explosion::UpdateTimer()
{
	if (!QueryPerformanceCounter(&m_currentTime))
	{
		throw ref new Platform::FailureException();
	}

	m_elapsedMicroseconds.QuadPart = m_currentTime.QuadPart - m_startTime.QuadPart;

	// We now have the elapsed number of ticks, along with the
	// number of ticks-per-second. We use these values
	// to convert to the number of elapsed microseconds.
	// To guard against loss-of-precision, we convert
	// to microseconds *before* dividing by ticks-per-second.

	m_elapsedMicroseconds.QuadPart *= 1000000;
	m_elapsedMicroseconds.QuadPart /= m_frequency.QuadPart;
}

void Explosion::Render()
{ 	
	UpdateTimer();

	// delay time
	if (m_elapsedMicroseconds.QuadPart >= m_frameRate)
	{
		m_startTime = m_currentTime;

		IncreaseFrame();
	}

	// render current frame
	Sprite::Render();
}

void Explosion::IncreaseFrame()
{
	if (m_currentFrame == m_lastFrame)
		m_currentFrame = 0;
	else
		m_currentFrame++;
}