#ifndef EIO_INPUT_HPP
#define EIO_INPUT_HPP

#include "Gamepad.hpp"

struct Input {
    struct Mouse: D2D1_POINT_2F {
        using D2D1_POINT_2F::operator=;
        
        bool button = false;
    } mouse;

    Gamepad gamepad;
};

#endif // !EIO_INPUT_HPP
