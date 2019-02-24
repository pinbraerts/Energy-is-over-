#ifndef EIO_DISPLAY_HPP
#define EIO_DISPLAY_HPP

#include "includes.hpp"

struct Display: D2D1_RECT_F {
    HWND handle;
    ID2D1HwndRenderTarget* renderTarget = nullptr;

    inline float width() const { return right - left; }
    inline float height() const { return bottom - top; }
    inline float centerX() const { return width() / 2; }
    inline float centerY() const { return height() / 2; }
    inline D2D1_SIZE_F size() const { return { width(), height() }; }
    inline D2D1_RECT_F& client_rect() { return *this; }
    inline const D2D1_RECT_F& client_rect() const { return *this; }

    void create_window(Engine& e, int nCmdShow);
};

#endif // !EIO_DISPLAY_HPP
