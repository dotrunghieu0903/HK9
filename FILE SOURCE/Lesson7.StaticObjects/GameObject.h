#pragma once

#include "DirectXSample.h"
#include "D2d1_1.h"
#include "Wincodec.h"

ref class GameObject
{
internal:
	GameObject();
	void Initialize(
		_In_ ID2D1Device*         d2dDevice,
		_In_ ID2D1DeviceContext*  d2dContext,
		_In_ IWICImagingFactory*  wicFactory
		);

	void ResetDirectXResources();      //Load image file for the object

	void UpdateForWindowSizeChange();

	virtual void Render(); //Render object image

protected private:
	int												m_id;            // Object id
	Platform::String^								m_type;		     // Object type
	D2D1_SIZE_F                                     m_imageSize;
	LPCWSTR                                         m_imageFileName; 
	D2D1_POINT_2F                                   m_position;
	float											m_alpha;         // Alpha channel, transparent color 

	Microsoft::WRL::ComPtr<ID2D1Device>             m_d2dDevice;
	Microsoft::WRL::ComPtr<ID2D1DeviceContext>      m_d2dContext;
	Microsoft::WRL::ComPtr<ID2D1Bitmap>             m_d2dBitmap;
	Microsoft::WRL::ComPtr<ID2D1Factory1>           m_d2dFactory;
	Microsoft::WRL::ComPtr<IWICImagingFactory>      m_wicFactory;
	Microsoft::WRL::ComPtr<ID2D1DrawingStateBlock>  m_stateBlock;

	bool                                            m_drawOverlay;
};

