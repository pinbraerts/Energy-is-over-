#include "Text.hpp"

Text::Text(std::wistream & s) {
    s >> left >> top >> right >> bottom >> color >> std::ws;
    std::getline(s, text);
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
    D2D1::Matrix3x2F tr;
    target.GetTransform(&tr); // to use truly text size
    target.SetTransform(D2D1::Matrix3x2F::Identity());
    target.DrawText(
        text.c_str(),
        (UINT32)text.size(),
        format,
        *this, 
        b
    );
    target.SetTransform(tr);
}

void Text::Release() {
    release(format);
}

IWidget* factory(std::wistream & s) {
    return new Text(s);
}
