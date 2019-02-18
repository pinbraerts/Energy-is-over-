#ifndef IMAGE_HPP
#define IMAGIEHPP

#include "../include/Engine.hpp"
#include "../include/Widget.hpp"
#include "../include/Imaging.hpp"

struct Image: IWidget, D2D1_RECT_F {
    ID2D1Bitmap* bmp;

    std::string name;

    Image(std::istream& s);

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

IWidget* factory(std::istream& s);

#endif // !IMAGE_HPP
