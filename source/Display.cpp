#include "../include/Display.hpp"

#include "../include/Engine.hpp"

void Display::create_window(Engine & e, int nCmdShow) {
#if 1
    left = 0;
    top = 0;
    right = (float)GetSystemMetrics(SM_CXSCREEN);
    bottom = (float)GetSystemMetrics(SM_CYSCREEN);
#else
    left = 500;
    top = 100;
    right = left + 600;
    bottom = top + 800;
#endif

    handle = CreateWindow(
        Engine::WndClassName,
        Engine::WndTitle,
        WS_POPUP | WS_MAXIMIZE,
        (int)left, (int)top,
        (int)width(), (int)height(),
        nullptr, nullptr,
        e.hInstance, &e
    );
    if (handle == nullptr)
        throw std::runtime_error("Call to CreateWindow failed!");
    ShowWindow(handle, nCmdShow);
    e.input.mouse = { left + centerX(), top + centerY() };
    SetCursorPos((int)e.input.mouse.x, (int)e.input.mouse.y);
    UpdateWindow(handle);
    // SetWindowPos(handle, nullptr, left, top, width(), height(), SWP_FRAMECHANGED);
}
