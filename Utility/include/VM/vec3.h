#ifndef VEC3_H
#define VEC3_H

#include <iostream>

#include "Overall.h"

namespace VM {

class vec3 {
public:
    ///Coordinates
    float x, y, z;

    ///Constructors
    vec3();
    vec3(const float x, const float y, const float z);
    vec3(const float x);
    vec3(const float* coords);
    vec3(const vec3 &v);

    ///Operators
    vec3 operator+(const vec3 &v) const;
    vec3 operator-(const vec3 &v) const;
    vec3 operator-() const;
    vec3 operator*(const vec3 &v) const;
    vec3 operator*(const float k) const;
    vec3 operator/(const float k) const;
    vec3 operator*=(const float k);
    vec3 operator+=(const vec3 &v);
    vec3 operator-=(const vec3 &v);
    float& operator[](const uint index);
    const float& operator[](const uint index) const;
    bool operator==(const vec3 &v) const;

    friend std::ostream& operator<<(std::ostream& os, const vec3& v);
};

float min(const vec3& v);

float max(const vec3& v);

vec3 min(const vec3& v, const vec3& w);

vec3 max(const vec3& v, const vec3& w);

///Length of vector for similarity to openGL syntax
float length(const vec3 &v);

vec3 normalize(const vec3 &v);

///Dot production
float dot(const vec3 &v, const vec3 &w);

///Cross production
vec3 cross(const vec3 &v, const vec3 &w);

///Cosine between two vectors
float cos(const vec3 &v, const vec3 &w);


}
#endif // VEC3_H
