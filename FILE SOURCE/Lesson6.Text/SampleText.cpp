//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#include "pch.h"
#include "SampleText.h"

using namespace Windows::UI::Core;
using namespace Microsoft::WRL;
using namespace D2D1;

SampleText::SampleText() :
    m_drawOverlay(true)
{
}

void SampleText::Initialize(
    _In_ ID2D1DeviceContext*  d2dContext,
    _In_ IDWriteFactory*      dwriteFactory,
    _In_ Platform::String^    text
    )
{
    m_dwriteFactory = dwriteFactory;
    m_sampleString = text;
    m_d2dContext = d2dContext;
	m_position = Point2F(0.0f, 0.0f);
	m_textSize = SizeF(0.0f, 0.0f);

    ResetDirectXResources();
}

void SampleText::ResetDirectXResources()
{
    DX::ThrowIfFailed(
        m_d2dContext->CreateSolidColorBrush(ColorF(ColorF::White), &m_whiteBrush)
        );

    ComPtr<IDWriteTextFormat> nameTextFormat;
    DX::ThrowIfFailed(
        m_dwriteFactory->CreateTextFormat(
            L"Segoe UI",
            nullptr,
            DWRITE_FONT_WEIGHT_LIGHT,
            DWRITE_FONT_STYLE_NORMAL,
            DWRITE_FONT_STRETCH_NORMAL,
            36.0f,
            L"en-US",
            &nameTextFormat
            )
        );

    DX::ThrowIfFailed(
        nameTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING)
        );

    DX::ThrowIfFailed(
        nameTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR)
        );

    DX::ThrowIfFailed(
        m_dwriteFactory->CreateTextLayout(
            m_sampleString->Data(),
            m_sampleString->Length(),
            nameTextFormat.Get(),
            4096.0f,
            4096.0f,
            &m_textLayout
            )
        );

    DWRITE_TEXT_METRICS metrics = {0};
    DX::ThrowIfFailed(
        m_textLayout->GetMetrics(&metrics)
        );

	m_textSize = SizeF(metrics.width, metrics.height);

    UpdateForWindowSizeChange();
}

void SampleText::UpdateForWindowSizeChange()
{
	// Get screen size
	Windows::Foundation::Rect windowBounds = CoreWindow::GetForCurrentThread()->Bounds;

	m_position.x = (windowBounds.Width - m_textSize.width) / 2;
	m_position.y = (windowBounds.Height - m_textSize.height) / 2;

	if (windowBounds.Width < m_textSize.width)
    {
        m_drawOverlay = false;
    }
    else
    {
        m_drawOverlay = true;
    }
}

void SampleText::Render()
{
    if (m_drawOverlay)
    {
        m_d2dContext->BeginDraw();
        m_d2dContext->SetTransform(D2D1::Matrix3x2F::Identity());

		m_d2dContext->DrawTextLayout(
			m_position,
            m_textLayout.Get(),
            m_whiteBrush.Get()
            );

        // We ignore D2DERR_RECREATE_TARGET here. This error indicates that the device
        // is lost. It will be handled during the next call to Present.
        HRESULT hr = m_d2dContext->EndDraw();
        if (hr != D2DERR_RECREATE_TARGET)
        {
            DX::ThrowIfFailed(hr);
        }
    }
}

