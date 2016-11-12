#include "vec4.h"

#include <algorithm>

namespace VM {

///Constructors
vec4::vec4() {}

vec4::vec4(const float x, const float y, const float z, const float w): x(x), y(y), z(z), w(w) {}

vec4::vec4(const float* coords): x(coords[0]), y(coords[1]), z(coords[2]), w(coords[3]) {}

vec4::vec4(const vec4 &v): x(v.x), y(v.y), z(v.z), w(v.w) {}

vec4::vec4(const vec3 &v, const float w): x(v.x), y(v.y), z(v.z), w(w) {}

///Operators
vec4 vec4::operator+(const vec4 &v) const {
    return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

vec4 vec4::operator-(const vec4 &v) const {
    return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

vec4 vec4::operator-() const {
    return vec4(-x, -y, -z, -w);
}

vec4 vec4::operator*(const vec4 &v) const {
    return vec4(x * v.x, y * v.y, z * v.z, w * v.w);
}

vec4 vec4::operator/(const vec4 &v) const {
    return vec4(x / v.x, y / v.y, z / v.z, w / v.w);
}

vec4 vec4::operator+=(const vec4 &v) {
    return (*this) = (*this) + v;
}

vec4 vec4::operator-=(const vec4 &v) {
    return (*this) = (*this) - v;
}

vec4 vec4::operator*=(const vec4 &v) {
    return (*this) = (*this) * v;
}

vec4 vec4::operator/=(const vec4 &v) {
    return (*this) = (*this) / v;
}

vec4 vec4::operator*(const float k) const {
    return vec4(x * k, y * k, z * k, w * k);
}

vec4 vec4::operator/(const float k) const {
    return vec4(x / k, y / k, z / k, w / k);
}

vec4 vec4::operator/=(const float k) {
    return (*this) = (*this) / k;
}

vec4 vec4::operator*=(const float k) {
    return (*this) = (*this) * k;
}

float& vec4::operator[](const uint index) {
    if (index >= 4) throw "Too big index for vec4";
    if (index == 0) return x;
    if (index == 1) return y;
    if (index == 2) return z;
    return w;
}

const float& vec4::operator[](const uint index) const {
    if (index >= 4) throw "Too big index for vec4";
    if (index == 0) return x;
    if (index == 1) return y;
    if (index == 2) return z;
    return w;
}

bool vec4::operator==(const vec4 &v) const {
    return std::abs(x - v.x) < VEC_EPS && std::abs(y - v.y) < VEC_EPS &&
           std::abs(z - v.z) < VEC_EPS && std::abs(w - v.w) < VEC_EPS;
}

bool vec4::operator!=(const vec4 &v) const {
    return ! ((*this) == v);
}

std::ostream& operator<<(std::ostream& os, const vec4& v) {
    os << "(" << v.x << "; " << v.y << "; " << v.z << "; " << v.w << ")";
    return os;
}

vec3 vec4::xyz() const {
    return vec3(x, y, z);
}

vec4 min(const vec4& v1, const vec4& v2) {
    return vec4(std::min(v1.x, v2.x), std::min(v1.y, v2.y), std::min(v1.z, v2.z), std::min(v1.w, v2.w));
}

vec4 max(const vec4& v1, const vec4& v2) {
    return vec4(std::max(v1.x, v2.x), std::max(v1.y, v2.y), std::max(v1.z, v2.z), std::max(v1.w, v2.w));
}

float min(const vec4& v) {
    return std::min(std::min(v.x, v.y), std::min(v.z, v.w));
}

float max(const vec4& v) {
    return std::max(std::max(v.x, v.y), std::max(v.z, v.w));
}

vec4 normalize(const vec4& v) {
    float len = length(v);
    if (len < VEC_EPS) throw "Null-length vector normalization.";
    return v / len;
}

float length(const vec4 &v) {
    return sqrt(dot(v, v));
}

///Dot production
float dot(const vec4 &v, const vec4 &w) {
    return v.x * w.x + v.y * w.y + v.z * w.z + v.w * w.w;
}

///Cross production
vec3 cross(const vec4 &v, const vec4 &w) {
    return cross(v.xyz(), w.xyz());
}


}
