#ifndef EIO_INCLUDES_HPP
#define EIO_INCLUDES_HPP

#include <tchar.h>
#include <Windows.h>
#include <d2d1.h>
#include <d2d1_1helper.h>
#include <wincodec.h>
#include <comdef.h>
#pragma comment(lib, "d2d1")

#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <map>

#include "Math.hpp"

#define CHECK if(FAILED(hr)) throw std::runtime_error((char*)_com_error(hr).ErrorMessage())

struct IWidget;

using Factory = IWidget* (*)(std::istream&);
using Info = const char* (*)();

#ifdef USE_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif // EIO_MODULE

template<class T>
void release(T*& i) {
    if (i != nullptr) {
        i->Release();
        i = nullptr;
    }
}

static std::wstring stows(std::string s) {
    std::wstring res(s.begin(), s.end());
    return res;
}

struct Engine;

#endif // !EIO_INCLUDES_HPP
