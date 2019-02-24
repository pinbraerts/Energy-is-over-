#ifndef EIO_INPUT_HPP
#define EIO_INPUT_HPP

#include "includes.hpp"

struct Input: D2D1_POINT_2F {
    bool button = false;

    using D2D1_POINT_2F::operator=;
};

#endif // !EIO_INPUT_HPP
