#ifndef VEC4_H
#define VEC4_H

#include "vec3.h"

namespace VM {

class vec4 {
public:
    ///Coordinates
    float x, y, z, w;

    ///Constructors
    vec4();
    vec4(const float x, const float y, const float z, const float w);
    vec4(const float* coords);
    vec4(const vec4 &v);
    vec4(const vec3 &v, const float w);

    ///Operators
    vec4 operator+(const vec4 &v) const;
    vec4 operator-(const vec4 &v) const;
    vec4 operator-() const;
    vec4 operator*(const vec4 &v) const;
    vec4 operator/(const vec4 &v) const;
    vec4 operator+=(const vec4 &v);
    vec4 operator-=(const vec4 &v);
    vec4 operator*=(const vec4 &v);
    vec4 operator/=(const vec4 &v);
    vec4 operator*(const float k) const;
    vec4 operator/(const float k) const;
    vec4 operator/=(const float k);
    vec4 operator*=(const float k);
    float& operator[](const uint index);
    const float& operator[](const uint index) const;
    bool operator==(const vec4 &v) const;
    bool operator!=(const vec4 &v) const;

    friend std::ostream& operator<<(std::ostream& os, const vec4& v);

    vec3 xyz() const;
};

vec4 min(const vec4& v1, const vec4& v2);

vec4 max(const vec4& v1, const vec4& v2);

float min(const vec4& v);

float max(const vec4& v);

///Length of vector for similarity to openGL syntax
float length(const vec4 &v);

vec4 normalize(const vec4& v);

///Dot production
float dot(const vec4 &v, const vec4 &w);

vec3 cross(const vec4 &v, const vec4 &w);

}
#endif // VEC4_H
