#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#include <map>
#include <set>

#include "GL.h"

#include "ShaderProgram.h"

namespace GL {

void bindTexture(GLuint program, const std::string& name, GLuint texture, GLint unit=0);

}

#endif // GL_TEXTURE_H
