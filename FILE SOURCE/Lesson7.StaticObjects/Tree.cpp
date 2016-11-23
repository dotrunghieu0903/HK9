#include "pch.h"
#include "Tree.h"

Tree::Tree(
	_In_ int                  id,
	_In_ D2D1_POINT_2F        position,
	_In_ ID2D1Device*         d2dDevice,
	_In_ ID2D1DeviceContext*  d2dContext,
	_In_ IWICImagingFactory*  wicFactory
	)
{
	m_id = id;
	m_type = "tree";
	m_imageFileName = L"tree.png";
	m_position = position; 
	m_alpha = 1.0f;
	Initialize(d2dDevice, d2dContext, wicFactory);
}
