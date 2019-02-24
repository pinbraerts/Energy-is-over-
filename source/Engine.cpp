#include "../include/Engine.hpp"

LRESULT Engine::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    Engine* sys = (Engine*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
    if (sys == nullptr) {
        CREATESTRUCT* cs = (CREATESTRUCT*)lParam;
        if (cs != nullptr) {
            sys = (Engine*)cs->lpCreateParams;
            SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)sys);
        }
        else return DefWindowProc(hWnd, message, wParam, lParam);
    }

    switch (message) {
    case WM_DISPLAYCHANGE:
        InvalidateRect(hWnd, nullptr, false);
        break;
    case WM_PAINT:
        sys->render();
        ValidateRect(hWnd, nullptr);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        sys->release_dependent();
        break;
    case WM_MOUSEMOVE:
        sys->mouse_move(LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_LBUTTONDOWN:
        sys->button_down();
        break;
    case WM_LBUTTONUP:
        sys->button_up();
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    InvalidateRect(hWnd, nullptr, false);

    return 0;
}

void Engine::create_resources() {
    HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &directFactory);
    CHECK;
#if 0 // for pictures
    hr = CoCreateInstance(CLSID_WICImagingFactory,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&imagingFactory)
    );
    CHECK;
#endif
}

void Engine::create_window(bool nCmdShow) {
    display.create_window(*this, nCmdShow);
}

void Engine::load_dependent() {
    if (display.renderTarget != nullptr)
        return;

    HRESULT hr = directFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(
            display.handle,
            D2D1::SizeU((unsigned)display.width(), (unsigned)display.height())
        ),
        &display.renderTarget
    );
    CHECK;

    float dx, dy;
    display.renderTarget->GetDpi(&dx, &dy);
    meter2dip *= (96 + 96) / (dx + dy);

    thikness /= meter2dip;

    for (auto& widget : widgets)
        widget->load(*this);
}

void Engine::release_dependent() {
    if (display.renderTarget != nullptr) {
        release(display.renderTarget);
        for (auto& widget : widgets)
            widget->Release();
    }
}

Engine::Engine(HINSTANCE hInst) : WNDCLASSEX{
    sizeof(WNDCLASSEX),
    CS_HREDRAW | CS_VREDRAW,
    WndProc,
    0,
    sizeof(this),
    hInst,
    nullptr,
    LoadCursor(NULL, IDC_ARROW),
    nullptr,
    0,
    WndClassName,
    nullptr,
} {
    create_resources();

    if (!RegisterClassEx(this))
        throw std::runtime_error("Call to RegisterCLassEx failed!");
}

int Engine::run() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

void Engine::mouse_move(UINT x, UINT y) {
    input = screen2world.TransformPoint({ (float)x, (float)y });
}
void Engine::button_down() {
    input.button = true;
}
void Engine::button_up() {
    input.button = false;
}

void Engine::render() {
    auto start = std::chrono::system_clock::now();

    load_dependent();
    auto& target = *display.renderTarget;

    target.BeginDraw();
    screen2world = D2D1::Matrix3x2F::Scale(meter2dip, meter2dip);
    target.SetTransform(screen2world);
    screen2world.Invert();
    target.Clear(D2D1::ColorF(D2D1::ColorF::White));

    try {
        for (auto& widget : widgets)
            widget->render(*this);
        // draw children here

        HRESULT hr;
        hr = target.EndDraw();

        if (hr == D2DERR_RECREATE_TARGET)
            release_dependent();
        else CHECK;
    }
    catch (Quit) {
        release_dependent();
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<float> dur = end - start;
    physics.delta_time = dur.count();
    physics.current_time += physics.delta_time;
}

void Engine::quit() {
    PostQuitMessage(0);
    throw Quit{};
}

Engine::~Engine() {
    release_dependent();
    for (auto& widget : widgets)
        delete widget;
    release(directFactory);
    // release(imagingFactory);
}
