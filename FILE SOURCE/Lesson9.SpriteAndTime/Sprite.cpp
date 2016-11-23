//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#include "pch.h"
#include "Sprite.h"
#include "ImageLoader.h"

using namespace Windows::UI::Core;
using namespace Microsoft::WRL;
using namespace D2D1;

void Sprite::Initialize(
		_In_ ID2D1Device*         d2dDevice,
	    _In_ ID2D1DeviceContext*  d2dContext,
	    _In_ IWICImagingFactory*  wicFactory
	    )
{
	GameObject::Initialize(d2dDevice, d2dContext, wicFactory);

	int rowPerImage = (m_lastFrame / m_framePerRow) + 1;

	m_frameSize.width = m_imageSize.width / m_framePerRow;
	m_frameSize.height = m_imageSize.height / rowPerImage;
}

void Sprite::Render()
{
	if (m_drawOverlay)
	{
		m_d2dContext->SaveDrawingState(m_stateBlock.Get());

		m_d2dContext->BeginDraw();
		m_d2dContext->SetTransform(D2D1::Matrix3x2F::Identity());

		// Caculate row and column of current frame
		int row = m_currentFrame / m_framePerRow;
		int column = m_currentFrame % m_framePerRow;

		// Caculate position of current frame
		D2D1_POINT_2F framePos;
		framePos.x = column * m_frameSize.width;
		framePos.y = row * m_frameSize.height;

		// Draw current frame
		m_d2dContext->DrawBitmap(
			m_d2dBitmap.Get(),
			D2D1::RectF(m_position.x, m_position.y,
			m_position.x + m_frameSize.width, m_position.y + m_frameSize.height),
			m_alpha,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
			D2D1::RectF(framePos.x, framePos.y,
			framePos.x + m_frameSize.width, framePos.y + m_frameSize.height)
			);

		// We ignore D2DERR_RECREATE_TARGET here. This error indicates that the device
		// is lost. It will be handled during the next call to Present.
		HRESULT hr = m_d2dContext->EndDraw();
		if (hr != D2DERR_RECREATE_TARGET)
		{
			DX::ThrowIfFailed(hr);
		}

		m_d2dContext->RestoreDrawingState(m_stateBlock.Get());
	}    
}
