#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../include/Engine.hpp"
#include "../include/Widget.hpp"
#include "../include/Imaging.hpp"

struct Text: IWidget, D2D1_RECT_F {
    IDWriteTextFormat* format;
    ID2D1Brush* b;

    D2D1::ColorF color = D2D1::ColorF::Black;
    std::wstring text;

    Text(std::wistream& s);

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

IWidget* factory(std::wistream& s);

#endif // !IMAGE_HPP
