#ifndef SHADER_H
#define SHADER_H

#include <cmath>
#include <iostream>

#include "GL.h"
#include "Overall.h"

namespace GL {

GLuint CompileShaderProgram(const std::string& shadername);

}
#endif // SHADER_H
