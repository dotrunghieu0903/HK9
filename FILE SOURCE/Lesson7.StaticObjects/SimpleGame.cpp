//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#include "pch.h"
#include "SimpleGame.h"

using namespace D2D1;

SimpleGame::SimpleGame()
{
}

void SimpleGame::CreateDeviceResources()
{
    DirectXBase::CreateDeviceResources();

	m_tree1 = ref new Tree(
		1,
		Point2F(50.0f, 390.0f),
		m_d2dDevice.Get(),
		m_d2dContext.Get(),
		m_wicFactory.Get()
		);

	m_tree2 = ref new Tree(
		2,
		Point2F(1100.0f, 390.0f),
		m_d2dDevice.Get(),
		m_d2dContext.Get(),
		m_wicFactory.Get()
		);

	m_rock = ref new Rock(
		3,
		Point2F(700.0f, 370.0f),
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

	// Render static objects
	m_tree1->Render();
	m_tree2->Render();
	m_rock->Render();
}