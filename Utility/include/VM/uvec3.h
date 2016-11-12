#ifndef Uuvec3_H
#define UVEC3_H

#include <iostream>

#include "Overall.h"

namespace VM {

class uvec3 {
public:
    ///Coordinates
    uint x, y, z;

    ///Constructors
    uvec3();
    uvec3(const uint x, const uint y, const uint z);
    uvec3(const uint x);
    uvec3(const uint* coords);
    uvec3(const uvec3 &v);

    ///Operators
    uvec3 operator+(const uvec3 &v) const;
    uvec3 operator-(const uvec3 &v) const;
    uvec3 operator-() const;
    uvec3 operator*(const uvec3 &v) const;
    uvec3 operator*(const uint k) const;
    uvec3 operator/(const uint k) const;
    uvec3 operator*=(const uint k);
    uvec3 operator+=(const uvec3 &v);
    uvec3 operator-=(const uvec3 &v);
    uint& operator[](const uint index);
    const uint& operator[](const uint index) const;
    bool operator==(const uvec3 &v) const;

    friend std::ostream& operator<<(std::ostream& os, const uvec3& v);
};

uint min(const uvec3& v);

uint max(const uvec3& v);

uvec3 min(const uvec3& v, const uvec3& w);

uvec3 max(const uvec3& v, const uvec3& w);

///Length of vector for similarity to openGL syntax
uint length(const uvec3 &v);

uvec3 normalize(const uvec3 &v);

///Dot production
uint dot(const uvec3 &v, const uvec3 &w);

///Cross production
uvec3 cross(const uvec3 &v, const uvec3 &w);

///Cosine between two vectors
uint cos(const uvec3 &v, const uvec3 &w);

}
#endif // UVEC3_H
