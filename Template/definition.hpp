#ifndef EIO_$safeprojectname$_HPP
#define EIO_$safeprojectname$_HPP

#include "../include/Engine.hpp"

IWidget* factory(std::wistream& s);

struct $safeprojectname$: IWidget {
    D2D1::ColorF color = D2D1::ColorF::Black;

    ID2D1Brush* brush = nullptr;

    $safeprojectname$(std::wistream& s);

    void load(Engine& e) override;
    void render(Engine& e) override;
    void Release() override;
};

#endif // !EIO_$safeprojectname$_HPP
