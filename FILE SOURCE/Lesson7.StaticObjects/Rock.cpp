#include "pch.h"
#include "Rock.h"

Rock::Rock(
	_In_ int                  id,
	_In_ D2D1_POINT_2F        position,
	_In_ ID2D1Device*         d2dDevice,
	_In_ ID2D1DeviceContext*  d2dContext,
	_In_ IWICImagingFactory*  wicFactory
	)
{
	m_id = id;
	m_type = "rock";
	m_imageFileName = L"rock.png";
	m_position = position;
	m_alpha = 5.0f;
	Initialize(d2dDevice, d2dContext, wicFactory);
}
