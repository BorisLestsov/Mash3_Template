#ifndef GL_H_INCLUDED
#define GL_H_INCLUDED

#include "GL/glew.h"
#include "GL/freeglut.h"

#include <GL/gl.h>
#include <string>
#include <cstdio>
#include <map>

namespace GL {

void ThrowExceptionOnGLError(int line, const char *file);

GLint ShaderStatus(GLuint shader, GLenum param);

GLint ShaderProgramStatus(GLuint program, GLenum param);

#define CHECK_GL_ERRORS GL::ThrowExceptionOnGLError(__LINE__,__FILE__);

#define OPENGL_CHECK_FOR_ERRORS() \
    { GLenum g_OpenGLError; \
    if ((g_OpenGLError = glGetError()) != GL_NO_ERROR) { \
        fprintf(stderr, "OpenGL error 0x%X\n", (unsigned)g_OpenGLError); \
            exit(1); \
    } \
    }


}

#endif // GL_H_INCLUDED
