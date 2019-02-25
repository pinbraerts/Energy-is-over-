#include "Image.hpp"

Image::Image(std::wistream & s) {
    s >> left >> top >> right >> bottom >> std::ws;
    std::getline(s, name);
}

void Image::load(Engine & e) {
    bmp = ImageBuilder(name, e.imaging.factory)
        .convert().to(e.display.renderTarget);
}

void Image::render(Engine& e) {
    auto& target = *e.display.renderTarget;
    target.DrawBitmap(bmp, *this);
}

void Image::Release() {
    release(bmp);
}

IWidget* factory(std::wistream & s) {
    return new Image(s);
}
