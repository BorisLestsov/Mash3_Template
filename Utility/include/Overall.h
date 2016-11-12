#ifndef UTILITY_OVERALL_H
#define UTILITY_OVERALL_H

#include <string>
#include <fstream>
#include <streambuf>

const float VEC_EPS = 1e-5f;

///Convenient typedefs for long typenames
typedef unsigned uint;

///Convenient small functions
template <typename T>
inline T sqr(T t) {
    return t * t;
}

std::string LoadSource(const std::string& filename);

#endif
