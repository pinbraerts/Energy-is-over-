#ifndef EIO_PHYSICS_HPP
#define EIO_PHYSICS_HPP

#include "includes.hpp"

struct IBody;

struct Physics {
    float delta_time = 0.1f;
    float current_time = 0.0f;

    std::vector<IBody*> objects;
};

struct IBody {
    D2D1_VECTOR_2F speed = { 0, 0 };

    // virtual bool check_collision(const IBody& other) = 0;
};

#endif // !EIO_PHYSICS_HPP
