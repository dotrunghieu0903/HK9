//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#include "pch.h"
#include "SimpleGame.h"

using namespace D2D1;

void SimpleGame::CreateDeviceResources()
{
    DirectXBase::CreateDeviceResources();

	m_explosion = ref new Explosion(
		1,
		Point2F(600.0f, 300.0f),
		m_d2dDevice.Get(),
		m_d2dContext.Get(),
		m_wicFactory.Get()
	  );
}

void SimpleGame::Render()
{
    m_d3dContext->OMSetRenderTargets(
        1,
        m_d3dRenderTargetView.GetAddressOf(),
        nullptr
        );

    m_d3dContext->ClearRenderTargetView(
        m_d3dRenderTargetView.Get(),
        reinterpret_cast<float*>(&D2D1::ColorF(D2D1::ColorF::MidnightBlue))
        );

    // Render the explosion sprite.
	m_explosion->Render();
}

