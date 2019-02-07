#ifndef EIO_OBJECTS_HPP
#define EIO_OBJECTS_HPP

#include "../Engine.hpp"
#include "../Widget.hpp"

const char _classes[] = "Rectangle\0Rounded\0Player\0Magnetic\0";

struct Rect : IWidget, D2D1_RECT_F {
    using D2D1_RECT_F::D2D1_RECT_F;

    Rect(std::istream& s);

    D2D1::ColorF color;
    ID2D1Brush* b = nullptr;

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

struct RoundedRect : IWidget, D2D1_ROUNDED_RECT {
    using D2D1_ROUNDED_RECT::D2D1_ROUNDED_RECT;

    RoundedRect(std::istream& s);

    D2D1::ColorF color = D2D1::ColorF::Black;
    ID2D1Brush* b = nullptr;

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

struct Player : IWidget, D2D1_POINT_2F, IBody {
    float radius;
    float energy = 1;

    Player(std::istream& s);

    D2D1::ColorF color = D2D1::ColorF::Black;
    ID2D1Brush* b = nullptr;
    ID2D1Brush* a = nullptr;

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;

    void check_collisions(Engine& e, const IWidget& other);
};

struct Magnetic: IWidget, D2D1_RECT_F {
    constexpr static float Constant = 0.5f;

    float field;

    Magnetic(std::istream& s);

    D2D1::ColorF color = D2D1::ColorF::Black;
    ID2D1Brush* b = nullptr;

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

IWidget* factoryRectangle(std::istream& s);
IWidget* factoryRounded(std::istream& s);
IWidget* factoryPlayer(std::istream& s);
IWidget* factoryMagnetic(std::istream& s);
const char* info();

#endif // !EIO_OBJECTS_HPP
