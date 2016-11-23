//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#include "pch.h"
#include "DirectXApp.h"

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

DirectXApp::DirectXApp() :
    m_windowClosed(false),
    m_windowVisible(true)
{
}

// The first method called when the IFrameworkView is being created.
void DirectXApp::Initialize(
	_In_ CoreApplicationView^ applicationView
	)
{
	// Register event handlers for app lifecycle. This example includes Activated, so that we
	// can make the CoreWindow active and start rendering on the window.
	applicationView->Activated +=
		ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &DirectXApp::OnActivated);

	CoreApplication::Suspending +=
		ref new EventHandler<SuspendingEventArgs^>(this, &DirectXApp::OnSuspending);

	CoreApplication::Resuming +=
		ref new EventHandler<Platform::Object^>(this, &DirectXApp::OnResuming);
}

// Called when the CoreWindow object is created (or re-created).
void DirectXApp::SetWindow(
    _In_ CoreWindow^ window
    )
{
    window->PointerCursor = ref new CoreCursor(CoreCursorType::Arrow, 0);

    window->SizeChanged +=
        ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &DirectXApp::OnWindowSizeChanged);

    window->VisibilityChanged +=
        ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &DirectXApp::OnVisibilityChanged);

    window->Closed +=
        ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &DirectXApp::OnWindowClosed);

	window->Activated +=
		ref new TypedEventHandler<CoreWindow^, WindowActivatedEventArgs^>(this, &DirectXApp::OnWindowActivated);


	DisplayInformation^ currentDisplayInformation = DisplayInformation::GetForCurrentView();

	currentDisplayInformation->DpiChanged +=
		ref new TypedEventHandler<DisplayInformation^, Platform::Object^>(this, &DirectXApp::OnDpiChanged);

	currentDisplayInformation->OrientationChanged +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXApp::OnOrientationChanged);

	DisplayInformation::DisplayContentsInvalidated +=
		ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXApp::OnDisplayContentsInvalidated);

	window->KeyDown +=
		ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &DirectXApp::OnKeyDown);

	window->KeyUp +=
		ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &DirectXApp::OnKeyUp);

    // Disable all pointer visual feedback for better performance when touching.
    auto pointerVisualizationSettings = PointerVisualizationSettings::GetForCurrentView();
    pointerVisualizationSettings->IsContactFeedbackEnabled = false;
    pointerVisualizationSettings->IsBarrelButtonFeedbackEnabled = false;
}

// Initializes scene resources, or loads a previously saved app state.
void DirectXApp::Load(
    _In_ Platform::String^ entryPoint
    )
{
}

// This method is called after the window becomes active.
void DirectXApp::Run()
{
    while (!m_windowClosed)
    {
        if (m_windowVisible)
        {
            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
        }
        else
        {
			// The window is hidden. Block until a UI event occurs.
            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
        }
    }
}

// Required for IFrameworkView.
// Terminate events do not cause Uninitialize to be called. It will be called if your IFrameworkView
// class is torn down while the app is in the foreground.
void DirectXApp::Uninitialize()
{
}

// Application lifecycle event handlers.
void DirectXApp::OnActivated(
	_In_ CoreApplicationView^ applicationView,
	_In_ IActivatedEventArgs^ args
	)
{
	// Run() won't start until the CoreWindow is activated.
	CoreWindow::GetForCurrentThread()->Activate();
}

void DirectXApp::OnSuspending(
	_In_ Platform::Object^ sender,
	_In_ SuspendingEventArgs^ args
	)
{
	// Hint to the driver that the app is entering an idle state and that its memory
	// can be temporarily used for other apps.
}

void DirectXApp::OnResuming(
	_In_ Object^ sender, 
	_In_ Object^ args
	)
{
	// Restore any data or state that was unloaded on suspend. By default, data
	// and state are persisted when resuming from suspend. Note that this event
	// does not occur if the app was previously terminated.
}

// Window event handlers.
void DirectXApp::OnWindowSizeChanged(
	_In_ CoreWindow^ sender,
	_In_ WindowSizeChangedEventArgs^ args
	)
{
}

void DirectXApp::OnVisibilityChanged(
	_In_ CoreWindow^ sender,
	_In_ VisibilityChangedEventArgs^ args
	)
{
	m_windowVisible = args->Visible;
}

void DirectXApp::OnWindowClosed(
	_In_ CoreWindow^ sender,
	_In_ CoreWindowEventArgs^ args
	)
{
	m_windowClosed = true;
}

void DirectXApp::OnWindowActivated(
	_In_ CoreWindow^ sender, 
	_In_ WindowActivatedEventArgs^ args
	)
{
}

// DisplayInformation event handlers.
void DirectXApp::OnDpiChanged(
	_In_ DisplayInformation^ sender, 
	_In_ Platform::Object^ args
	)
{
}

void DirectXApp::OnOrientationChanged(
	_In_ DisplayInformation^ sender, 
	_In_ Object^ args
	)
{
}

void DirectXApp::OnDisplayContentsInvalidated(
	_In_ DisplayInformation^ sender, 
	_In_ Object^ args
	)
{
}

// Input event handlers.
void DirectXApp::OnKeyDown(
	_In_ CoreWindow^ sender, 
	_In_ KeyEventArgs^ args
	)
{
}

void DirectXApp::OnKeyUp(
	_In_ CoreWindow^ sender, 
	_In_ KeyEventArgs^ args
	)
{	
}

IFrameworkView^ DirectXAppSource::CreateView()
{
	return ref new DirectXApp();
}

// The main function is only used to initialize our IFrameworkView class.
[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
    auto directXAppSource = ref new DirectXAppSource();
    CoreApplication::Run(directXAppSource);
    return 0;
}
