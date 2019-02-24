#ifndef EIO_TEXTING_HPP
#define EIO_TEXTING_HPP

#include "includes.hpp"

struct Texting {
    IDWriteFactory* factory;

    Texting() {
        DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&factory));
    }

    ~Texting() {
        release(factory);
    }
};

#endif // !EIO_TEXTING_HPP