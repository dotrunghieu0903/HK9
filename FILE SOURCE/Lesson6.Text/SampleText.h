//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

#include "DirectXSample.h"

// This class draw sample text.
ref class SampleText
{
internal:
	SampleText();

    void Initialize(
        _In_ ID2D1DeviceContext*  d2dContext,
        _In_ IDWriteFactory*      dwriteFactory,
        _In_ Platform::String^    text
        );

    void ResetDirectXResources();

    void UpdateForWindowSizeChange();

    void Render();

private:

    Microsoft::WRL::ComPtr<ID2D1DeviceContext>      m_d2dContext;
    Microsoft::WRL::ComPtr<IDWriteFactory>          m_dwriteFactory;
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush>    m_whiteBrush;
    Microsoft::WRL::ComPtr<IDWriteTextLayout>       m_textLayout;

    bool                                            m_drawOverlay;
    Platform::String^                               m_sampleString;
	D2D1_POINT_2F									m_position;
	D2D1_SIZE_F                                     m_textSize;
};
