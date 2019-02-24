#include "Text.hpp"

Text::Text(std::istream & s) {
    s >> left >> top >> right >> bottom >> color >> std::ws;
    std::string cs;
    std::getline(s, cs);
    text = stows(cs);
}

void Text::load(Engine & e) {
    e.texting.factory->CreateTextFormat(
        L"Gabriola",
        nullptr,
        DWRITE_FONT_WEIGHT_REGULAR,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        36,
        L"en-us",
        &format
    );

    e.display.renderTarget->CreateSolidColorBrush(color, (ID2D1SolidColorBrush**)&b);
}

void Text::render(Engine& e) {
    auto& target = *e.display.renderTarget;
    //target.DrawBitmap(bmp, *this);
    target.DrawText(
        text.c_str(),
        (UINT32)text.size(),
        format,
        *this, 
        b
    );
}

void Text::Release() {
    release(format);
}

IWidget* factory(std::istream & s) {
    return new Text(s);
}
