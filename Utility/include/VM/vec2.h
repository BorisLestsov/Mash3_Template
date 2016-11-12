#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cassert>
#include <cmath>

#include "Overall.h"

namespace VM {

class vec2 {
    public:
        ///Coordinates
        float x, y;

        ///Constructors
        vec2();
        vec2(const float x, const float y);
        vec2(const float x);
        vec2(const float* coords);
        vec2(const vec2 &v);

        ///Operators
        float& operator[](const uint index);
        const float& operator[](const uint index) const;
        vec2 operator-(const vec2 &v) const;
        vec2 operator+(const vec2 &v) const;
        vec2 operator*(const vec2 &v) const;
        vec2 operator*(const double k) const;
        vec2 operator/(const double k) const;
        vec2 operator*=(const vec2 &v);
        vec2 operator+=(const vec2 &v);
        vec2 operator/=(const float k);

        friend std::ostream& operator<<(std::ostream& os, const vec2& v);
};

vec2 min(const vec2& v1, const vec2& v2);

vec2 max(const vec2& v1, const vec2& v2);

vec2 normalize(const vec2& v);

float length(const vec2 &v);

float dot(const vec2 &v, const vec2 &w);

}
#endif // VEC2_H
