#pragma once

#include "GameObject.h"

ref class Rock: public GameObject
{
internal:
	Rock(
		_In_ int                  id,
		_In_ D2D1_POINT_2F        position,
		_In_ ID2D1Device*         d2dDevice,
		_In_ ID2D1DeviceContext*  d2dContext,
		_In_ IWICImagingFactory*  wicFactory
		);
};

