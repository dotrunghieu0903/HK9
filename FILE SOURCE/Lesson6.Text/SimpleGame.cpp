//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#include "pch.h"
#include "SimpleGame.h"

using namespace Windows::System;

void SimpleGame::CreateDeviceResources()
{
    DirectXBase::CreateDeviceResources();

	m_sampleText = ref new SampleText();
	m_sampleText->Initialize(
		m_d2dContext.Get(),	
		m_dwriteFactory.Get(),
		"Nhâòp môn phaìt triêÒn game"
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

    // Render the text.
	m_sampleText->Render();
}

