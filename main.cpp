#include "Engine.hpp"
#include "Resources.hpp"

int CALLBACK _tWinMain(
    HINSTANCE hInst,
    HINSTANCE hPrevInt,
    LPTSTR lpCmdLine,
    int nCmdShow
) {
    int res;
    CoInitialize(nullptr);
    try {
        Engine e(hInst);

        Resources r;
        r.load("game.data", e.widgets);

        e.create_window(nCmdShow);

        res = e.run();
    }
    catch (const std::runtime_error& e) {
        MessageBoxA(nullptr, e.what(), "EIO", 0);
        res = 1;
    }
    CoUninitialize();
    return res;
}
