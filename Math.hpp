#ifndef EIO_MATH_HPP
#define EIO_MATH_HPP

#include <cmath>
#include <d2d1.h>
#include <d2d1_1helper.h>

constexpr float pi = (float)M_PI;
constexpr float deg2rad = pi / 180;
constexpr float rad2deg = 180 / pi;

inline D2D1_VECTOR_2F operator+(D2D1_VECTOR_2F a, D2D1_VECTOR_2F b) {
    return { a.x + b.x, a.y + b.y };
}

inline D2D1_POINT_2F operator-(D2D1_VECTOR_2F a, D2D1_VECTOR_2F b) {
    return { a.x - b.x, a.y - b.y };
}

inline D2D1_VECTOR_2F operator-(D2D1_VECTOR_2F a) {
    return { -a.x, -a.y };
}

inline D2D1_VECTOR_2F operator*(D2D1_VECTOR_2F a, float m) {
    return { m * a.x, m * a.y };
}

inline D2D1_VECTOR_2F operator/(D2D1_VECTOR_2F a, float m) {
    return { m / a.x, m / a.y };
}

inline D2D1_VECTOR_2F operator*(float m, D2D1_VECTOR_2F a) {
    return { m * a.x, m * a.y };
}

inline D2D1_VECTOR_2F operator/(float m, D2D1_VECTOR_2F a) {
    return { m / a.x, m / a.y };
}

inline D2D1_VECTOR_2F& operator+=(D2D1_VECTOR_2F& a, D2D1_VECTOR_2F b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline D2D1_VECTOR_2F& operator-=(D2D1_VECTOR_2F& a, D2D1_VECTOR_2F b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

inline D2D1_VECTOR_2F& operator*=(D2D1_VECTOR_2F& a, float m) {
    a.x *= m;
    a.y *= m;
    return a;
}

inline D2D1_VECTOR_2F& operator/=(D2D1_VECTOR_2F& a, float m) {
    a.x /= m;
    a.y /= m;
    return a;
}

inline D2D1_POINT_2F operator+(D2D1_POINT_2F a, D2D1_VECTOR_2F b) {
    return { a.x + b.x, a.y + b.y };
}

inline D2D1_POINT_2F operator-(D2D1_POINT_2F a, D2D1_VECTOR_2F b) {
    return { a.x - b.x, a.y - b.y };
}

inline D2D1_VECTOR_2F operator-(D2D1_POINT_2F a, D2D1_POINT_2F b) {
    return { a.x - b.x, a.y - b.y };
}

inline D2D1_POINT_2F operator+(D2D1_VECTOR_2F b, D2D1_POINT_2F a) {
    return { a.x + b.x, a.y + b.y };
}

inline D2D1_VECTOR_2F operator+(D2D1_POINT_2F p) {
    return { p.x, p.y };
}

inline D2D1_POINT_2F operator+(D2D1_VECTOR_2F p) {
    return { p.x, p.y };
}

inline D2D1_POINT_2F operator-(D2D1_VECTOR_2F a, D2D1_POINT_2F b) {
    return { a.x - b.x, a.y - b.y };
}

inline D2D1_POINT_2F& operator+=(D2D1_POINT_2F& a, D2D1_VECTOR_2F b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline D2D1_POINT_2F& operator-=(D2D1_POINT_2F& a, D2D1_VECTOR_2F b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

inline float abs(D2D1_VECTOR_2F v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

inline D2D1_VECTOR_2F& normalize(D2D1_VECTOR_2F& a) {
    return a /= abs(a);
}

inline D2D1_VECTOR_2F right_perpendicular(D2D1_VECTOR_2F v) {
    return { v.y, -v.x }; // return [v x up]
}

inline D2D1_POINT_2F nearest(const D2D1_RECT_F& r, D2D1_POINT_2F p) {
    if (p.x < r.left) {
        p.x = r.left;
    }
    else if (p.x > r.right) {
        p.x = r.right;
    }

    if (p.y < r.top) {
        p.y = r.top;
    }
    else if (p.y > r.bottom) {
        p.y = r.bottom;
    }

    return p;
}

#endif // !EIO_MATH_HPP
