#ifndef EIO_ENGINE_HPP
#define EIO_ENGINE_HPP

#include "Input.hpp"
#include "Display.hpp"
#include "Physics.hpp"
#include "Widget.hpp"
#include "Imaging.hpp"

struct Engine: public WNDCLASSEX {
public:
    static constexpr TCHAR WndClassName[] = _T("EIO");
    static constexpr TCHAR WndTitle[] = _T("EIO");

    static LRESULT CALLBACK WndProc(
        HWND hWnd,
        UINT message,
        WPARAM wParam,
        LPARAM lParam);

    Engine(HINSTANCE hInst);

    void create_resources();
    void create_window(bool nCmdShow);
    void load_dependent();
    void release_dependent();

    int run();
    void mouse_move(UINT x, UINT y);
    void button_down();
    void button_up();
    void render();

    ID2D1Factory* directFactory;

    std::vector<IWidget*> widgets;
    Display display;
    Input input;
    Physics physics;
    Imaging imaging;

    ~Engine();
};

#endif // !EIO_ENGINE_HPP
