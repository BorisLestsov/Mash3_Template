#include "vec3.h"

#include <algorithm>

namespace VM {

///Constructors
vec3::vec3() {}

vec3::vec3(const float x, const float y, const float z): x(x), y(y), z(z) {}

vec3::vec3(const float x): x(x), y(x), z(x) {}

vec3::vec3(const float* coords): x(coords[0]), y(coords[1]), z(coords[2]) {}

vec3::vec3(const vec3 &v): x(v.x), y(v.y), z(v.z) {}

///Operators
vec3 vec3::operator+(const vec3 &v) const {
    return vec3(x + v.x, y + v.y, z + v.z);
}

vec3 vec3::operator-(const vec3 &v) const {
    return vec3(x - v.x, y - v.y, z - v.z);
}

vec3 vec3::operator-() const {
    return vec3(-x, -y, -z);
}

vec3 vec3::operator*(const vec3 &v) const {
    return vec3(x * v.x, y * v.y, z * v.z);
}

vec3 vec3::operator*(const float k) const {
    return vec3(x * k, y * k, z * k);
}

vec3 vec3::operator+=(const vec3 &v) {
    return (*this) = (*this) + v;
}

vec3 vec3::operator-=(const vec3 &v) {
    return (*this) = (*this) - v;
}

vec3 vec3::operator*=(const float k) {
    return (*this) = (*this) * k;
}

vec3 vec3::operator/(const float k) const {
    return vec3(x / k, y / k, z / k);
}

float& vec3::operator[](const uint index) {
    if (index >= 3) throw "Too big index for vec3";
    if (index == 0) return x;
    if (index == 1) return y;
    return z;
}

const float& vec3::operator[](const uint index) const {
    if (index >= 3) throw "Too big index for vec3";
    if (index == 0) return x;
    if (index == 1) return y;
    return z;
}

bool vec3::operator==(const vec3 &v) const {
    return std::abs(x - v.x) < VEC_EPS && std::abs(y - v.y) < VEC_EPS && std::abs(z - v.z) < VEC_EPS;
}

std::ostream& operator<<(std::ostream& os, const vec3& v)
{
    os << "(" << v.x << "; " << v.y << "; " << v.z << ")";
    return os;
}

float min(const vec3& v) {
    return std::min(std::min(v.x, v.y), v.z);
}

float max(const vec3& v) {
    return std::max(std::max(v.x, v.y), v.z);
}

vec3 min(const vec3& v, const vec3& w) {
    return vec3(std::min(v.x, w.x), std::min(v.y, w.y), std::min(v.z, w.z));
}

vec3 max(const vec3& v, const vec3& w) {
    return vec3(std::max(v.x, w.x), std::max(v.y, w.y), std::max(v.z, w.z));
}

vec3 normalize(const vec3& v) {
    float len = length(v);
    if (len == 0.0f) throw "Null-length vector normalization.";
    return v / len;
}

float length(const vec3 &v) {
    return sqrt(dot(v, v));
}

///Dot production
float dot(const vec3 &v, const vec3 &w) {
    return v.x * w.x + v.y * w.y + v.z * w.z;
}

///Cross production
vec3 cross(const vec3 &v, const vec3 &w) {
    return vec3(v[1] * w[2] - v[2] * w[1],
                v[2] * w[0] - v[0] * w[2],
                v[0] * w[1] - v[1] * w[0]);
}

///Cosine between two vectors
float cos(const vec3 &v, const vec3 &w) {
    return dot(v, w) / length(v) / length(w);

}

}
