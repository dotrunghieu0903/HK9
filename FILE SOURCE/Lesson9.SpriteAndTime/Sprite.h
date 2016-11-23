//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

#include "GameObject.h"

// This class is loading and render sprite
ref class Sprite : public GameObject
{
internal:
	void Initialize(
	    _In_ ID2D1Device*         d2dDevice,
	    _In_ ID2D1DeviceContext*  d2dContext,
	    _In_ IWICImagingFactory*  wicFactory
	    );

	virtual void Render() override; //Render current frame

protected private:
	int                                             m_currentFrame;
	int                                             m_lastFrame;
	D2D1_SIZE_F                                     m_frameSize;
	int                                             m_framePerRow; // Number of frames per row
};
