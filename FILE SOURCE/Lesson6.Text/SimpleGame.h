//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

#include "DirectXBase.h"
#include "SampleText.h"

ref class SimpleGame : public DirectXBase
{
internal:
    virtual void CreateDeviceResources() override;
    virtual void Render() override;

private:
	SampleText^		m_sampleText;
};
