#include "../include/Engine.hpp"
#include "../include/Resources.hpp"

int CALLBACK _tWinMain(
    HINSTANCE hInst,
    HINSTANCE hPrevInt,
    LPTSTR lpCmdLine,
    int nCmdShow
) {
    int res;
    CoInitialize(nullptr);
    try {
        std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>());
        std::locale::global(loc);

        Engine e(hInst);

        Resources r;
        r.load(L"game.data", e.widgets);

        e.create_window(nCmdShow);

        res = e.run();
    }
    catch (const Error& err) {
        MessageBox(nullptr, err.message.c_str(), L"EIO", MB_ICONEXCLAMATION | MB_OK);
        res = err.err_no;
    }
    CoUninitialize();
    return res;
}
