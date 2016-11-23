#include "pch.h"
#include "GameObject.h"
#include "ImageLoader.h"

using namespace Windows::UI::Core;

GameObject::GameObject():
m_drawOverlay(true)
{
}


void GameObject::Initialize(
	_In_ ID2D1Device*         d2dDevice,
	_In_ ID2D1DeviceContext*  d2dContext,
	_In_ IWICImagingFactory*  wicFactory
	)
{
	m_wicFactory = wicFactory;
	m_d2dDevice = d2dDevice;
	m_d2dContext = d2dContext;

	ComPtr<ID2D1Factory> factory;
	d2dDevice->GetFactory(&factory);

	DX::ThrowIfFailed(
		factory.As(&m_d2dFactory)
		);

	ResetDirectXResources();

	m_imageSize = m_d2dBitmap->GetSize();
}

void GameObject::ResetDirectXResources()
{
	LoadImage(
		m_d2dContext,
		m_d2dBitmap,
		m_wicFactory,
		m_imageFileName
		);

	DX::ThrowIfFailed(
		m_d2dFactory->CreateDrawingStateBlock(&m_stateBlock)
		);

	UpdateForWindowSizeChange();
}

void GameObject::UpdateForWindowSizeChange()
{
	if (CoreWindow::GetForCurrentThread()->Bounds.Width < m_imageSize.width)
	{
		m_drawOverlay = false;
	}
	else
	{
		m_drawOverlay = true;
	}
}

void GameObject::Render()
{
	if (m_drawOverlay)
	{
		m_d2dContext->SaveDrawingState(m_stateBlock.Get());

		m_d2dContext->BeginDraw();
		m_d2dContext->SetTransform(D2D1::Matrix3x2F::Identity());

		m_d2dContext->DrawBitmap(
				m_d2dBitmap.Get(),
				D2D1::RectF(
				m_position.x, m_position.y,
				m_position.x + m_imageSize.width, m_position.y + m_imageSize.height)
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