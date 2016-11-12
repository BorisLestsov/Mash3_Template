#include "uvec3.h"

#include <algorithm>

namespace VM {

///Constructors
uvec3::uvec3() {}

uvec3::uvec3(const uint x, const uint y, const uint z): x(x), y(y), z(z) {}

uvec3::uvec3(const uint x): x(x), y(x), z(x) {}

uvec3::uvec3(const uint* coords): x(coords[0]), y(coords[1]), z(coords[2]) {}

uvec3::uvec3(const uvec3 &v): x(v.x), y(v.y), z(v.z) {}

///Operators
uvec3 uvec3::operator+(const uvec3 &v) const {
    return uvec3(x + v.x, y + v.y, z + v.z);
}

uvec3 uvec3::operator-(const uvec3 &v) const {
    return uvec3(x - v.x, y - v.y, z - v.z);
}

uvec3 uvec3::operator-() const {
    return uvec3(-x, -y, -z);
}

uvec3 uvec3::operator*(const uvec3 &v) const {
    return uvec3(x * v.x, y * v.y, z * v.z);
}

uvec3 uvec3::operator*(const uint k) const {
    return uvec3(x * k, y * k, z * k);
}

uvec3 uvec3::operator+=(const uvec3 &v) {
    return (*this) = (*this) + v;
}

uvec3 uvec3::operator-=(const uvec3 &v) {
    return (*this) = (*this) - v;
}

uvec3 uvec3::operator*=(const uint k) {
    return (*this) = (*this) * k;
}

uvec3 uvec3::operator/(const uint k) const {
    return uvec3(x / k, y / k, z / k);
}

uint& uvec3::operator[](const uint index) {
    if (index >= 3) throw "Too big index for uvec3";
    if (index == 0) return x;
    if (index == 1) return y;
    return z;
}

const uint& uvec3::operator[](const uint index) const {
    if (index >= 3) throw "Too big index for uvec3";
    if (index == 0) return x;
    if (index == 1) return y;
    return z;
}

bool uvec3::operator==(const uvec3 &v) const {
    return std::abs(x - v.x) < VEC_EPS && std::abs(y - v.y) < VEC_EPS && std::abs(z - v.z) < VEC_EPS;
}

std::ostream& operator<<(std::ostream& os, const uvec3& v)
{
    os << "(" << v.x << "; " << v.y << "; " << v.z << ")";
    return os;
}

uint min(const uvec3& v) {
    return std::min(std::min(v.x, v.y), v.z);
}

uint max(const uvec3& v) {
    return std::max(std::max(v.x, v.y), v.z);
}

uvec3 min(const uvec3& v, const uvec3& w) {
    return uvec3(std::min(v.x, w.x), std::min(v.y, w.y), std::min(v.z, w.z));
}

uvec3 max(const uvec3& v, const uvec3& w) {
    return uvec3(std::max(v.x, w.x), std::max(v.y, w.y), std::max(v.z, w.z));
}

uvec3 normalize(const uvec3& v) {
    uint len = length(v);
    if (len == 0.0f) throw "Null-length vector normalization.";
    return v / len;
}

uint length(const uvec3 &v) {
    return sqrt(dot(v, v));
}

///Dot production
uint dot(const uvec3 &v, const uvec3 &w) {
    return v.x * w.x + v.y * w.y + v.z * w.z;
}

///Cross production
uvec3 cross(const uvec3 &v, const uvec3 &w) {
    return uvec3(v[1] * w[2] - v[2] * w[1],
                v[2] * w[0] - v[0] * w[2],
                v[0] * w[1] - v[1] * w[0]);
}

///Cosine between two vectors
uint cos(const uvec3 &v, const uvec3 &w) {
    return dot(v, w) / length(v) / length(w);

}

}
