#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../include/Engine.hpp"
#include "../include/Widget.hpp"
#include "../include/Imaging.hpp"

struct Image: IWidget, D2D1_RECT_F {
    ID2D1Bitmap* bmp;

    std::wstring name;

    Image(std::wistream& s);

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

IWidget* factory(std::wistream& s);

#endif // !IMAGE_HPP
