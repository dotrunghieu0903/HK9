//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

#include "DirectXBase.h"
#include "Tree.h"
#include "Rock.h"

ref class SimpleGame : public DirectXBase
{
internal:
	SimpleGame();
    virtual void CreateDeviceResources() override;
    virtual void Render() override;

private:
	Tree^                      m_tree1;
	Tree^                      m_tree2;
	Rock^					   m_rock;
};
