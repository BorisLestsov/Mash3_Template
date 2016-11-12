#ifndef MAT4_H
#define MAT4_H

#include <array>

#include "vec4.h"

namespace VM {

class mat4 {
protected:
    ///Rows
    vec4 rows[4];
public:

    ///Constructors
    mat4();
    mat4(const float diagNum);
    mat4(const float* elements);
    mat4(const float** elements);
    mat4(const mat4 &m);

    ///Operators
    vec4 operator*(const vec4 &v) const;
    mat4 operator*(const mat4 &m) const;
    mat4 operator+(const mat4 &m) const;
    mat4 operator+=(const mat4 &m);
    mat4 operator*=(const mat4 &m);
    vec4& operator[](const uint index);
    const vec4& operator[](const uint index) const;

    friend std::ostream& operator<<(std::ostream& os, const mat4& v);

    ///Other methods
    vec4 col(const uint index) const;
    mat4 unmatrixN3() const;
    std::array<float, 16> data() const;
};

///Transpose matrix
mat4 transpose(const mat4& m);

}

#endif // MAT4_H
