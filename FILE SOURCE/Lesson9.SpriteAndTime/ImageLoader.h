#pragma once

using namespace Microsoft::WRL;
using namespace D2D1;

inline void LoadImage(
	_In_ ComPtr<ID2D1DeviceContext> d2dContext,
	_In_ ComPtr<ID2D1Bitmap>        &d2dBitmap,
	_In_ ComPtr<IWICImagingFactory> wicFactory,
	_In_ LPCWSTR                    imageFileName
	)
{
	ComPtr<IWICBitmapDecoder> wicBitmapDecoder;
	DX::ThrowIfFailed(
		wicFactory->CreateDecoderFromFilename(
			imageFileName,
			nullptr,
			GENERIC_READ,
			WICDecodeMetadataCacheOnDemand,
			&wicBitmapDecoder
			)
		);

	ComPtr<IWICBitmapFrameDecode> wicBitmapFrame;
	DX::ThrowIfFailed(
		wicBitmapDecoder->GetFrame(0, &wicBitmapFrame)
		);

	// Convert the image format to 32bppPBGRA
	// (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
	ComPtr<IWICFormatConverter> wicFormatConverter;
	DX::ThrowIfFailed(
		wicFactory->CreateFormatConverter(&wicFormatConverter)
		);

	DX::ThrowIfFailed(
		wicFormatConverter->Initialize(
			wicBitmapFrame.Get(),
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			nullptr,
			0.0,
			WICBitmapPaletteTypeCustom  // the BGRA format has no palette so this value is ignored
			)
		);

	double dpiX = 96.0f;
	double dpiY = 96.0f;
	DX::ThrowIfFailed(
		wicFormatConverter->GetResolution(&dpiX, &dpiY)
		);

	DX::ThrowIfFailed(
		d2dContext->CreateBitmapFromWicBitmap(
		wicFormatConverter.Get(),
		BitmapProperties(
			PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
			static_cast<float>(dpiX),
			static_cast<float>(dpiY)
			),
		&d2dBitmap
	    )
	);
}
