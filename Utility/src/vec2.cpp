#include "vec2.h"

namespace VM {

///Constructors
vec2::vec2() {}

vec2::vec2(const float x, const float y): x(x), y(y) {}

vec2::vec2(const float x): x(x), y(x) {}

vec2::vec2(const float* coords): x(coords[0]), y(coords[1]) {}

vec2::vec2(const vec2 &v): x(v.x), y(v.y) {}

///Operators
float& vec2::operator[](const uint index) {
    if (index >= 2) throw "Too big index for vec2";
    if (index == 0) return x;
    return y;
}

const float& vec2::operator[](const uint index) const {
    if (index >= 2) throw "Too big index for vec2";
    if (index == 0) return x;
    return y;
}

vec2 vec2::operator-(const vec2 &v) const {
    return vec2(x - v.x, y - v.y);
}

vec2 vec2::operator+(const vec2 &v) const {
    return vec2(x + v.x, y + v.y);
}

vec2 vec2::operator*(const double k) const {
    return vec2(x * k, y * k);
}

vec2 vec2::operator*(const vec2 &v) const {
    return vec2(x * v.x, y * v.y);
}

vec2 vec2::operator/(const double k) const {
    return vec2(x / k, y / k);
}

vec2 vec2::operator*=(const vec2 &v) {
    x *= v.x;
    y *= v.y;
    return *this;
}

vec2 vec2::operator+=(const vec2 &v) {
    x += v.x;
    y += v.y;
    return *this;
}

vec2 vec2::operator/=(const float k) {
    x /= k;
    y /= k;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const vec2& v) {
    os << "(" << v.x << "; " << v.y << ")";
    return os;
}

vec2 min(const vec2& v1, const vec2& v2) {
    return vec2(std::min(v1.x, v2.x), std::min(v1.y, v2.y));
}

vec2 max(const vec2& v1, const vec2& v2) {
    return vec2(std::max(v1.x, v2.x), std::max(v1.y, v2.y));
}

float dot(const vec2& v1, const vec2& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

vec2 normalize(const vec2& v) {
    float l = length(v);
    assert(l > 0);
    return v / l;
}

float length(const vec2& v) {
    return std::sqrt(dot(v, v));
}

}
