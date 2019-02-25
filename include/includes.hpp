#ifndef EIO_INCLUDES_HPP
#define EIO_INCLUDES_HPP

#include <tchar.h>
#include <Windows.h>
#include <d2d1.h>
#include <d2d1_1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <comdef.h>
#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")

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

using Factory = IWidget* (*)(std::wistream&);
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

struct Error {
    std::wstring message;
    int err_no;

    Error(const std::wstring& msg, int err_number = 1) : message(msg), err_no(err_number) {}
    Error(std::wstring&& msg, int err_number = 1) : message(std::move(msg)), err_no(err_number) {}
    Error(HRESULT hr): Error(_com_error(hr)) {}
    Error(_com_error&& e): message(e.ErrorMessage()), err_no(e.WCode()) {}
    Error(): Error(GetLastError()) {}
};

struct Engine;

#endif // !EIO_INCLUDES_HPP
