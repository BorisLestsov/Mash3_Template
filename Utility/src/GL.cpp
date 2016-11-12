#define GL_CONTEXT_LOST 0x0507
#include "GL.h"

namespace GL {

void ThrowExceptionOnGLError(int line, const char *file) {
    static char errMsg[512];

    GLenum gl_error = glGetError();

    if(gl_error == GL_NO_ERROR)
        return;

    switch(gl_error) {
        case GL_INVALID_ENUM:
            sprintf(errMsg, "GL_INVALID_ENUM file %s line %d\n", file, line);
            break;

        case GL_INVALID_VALUE:
            sprintf(errMsg, "GL_INVALID_VALUE file %s line %d\n",  file, line);
            break;

        case GL_INVALID_OPERATION:
            sprintf(errMsg, "GL_INVALID_OPERATION file %s line %d\n",  file, line);
            break;

        case GL_STACK_OVERFLOW:
            sprintf(errMsg, "GL_STACK_OVERFLOW file %s line %d\n",  file, line);
            break;

        case GL_STACK_UNDERFLOW:
            sprintf(errMsg, "GL_STACK_UNDERFLOW file %s line %d\n",  file, line);
            break;

        case GL_OUT_OF_MEMORY:
            sprintf(errMsg, "GL_OUT_OF_MEMORY file %s line %d\n",  file, line);
            break;

        case GL_INVALID_FRAMEBUFFER_OPERATION:
            sprintf(errMsg, "GL_INVALID_FRAMEBUFFER_OPERATION file %s line %d\n",  file, line);
            break;

        case GL_CONTEXT_LOST:
            sprintf(errMsg, "GL_CONTEXT_LOST file %s line %d\n",  file, line);
            break;

        case GL_TABLE_TOO_LARGE:
            sprintf(errMsg, "GL_TABLE_TOO_LARGE file %s line %d\n",  file, line);
            break;

        case GL_NO_ERROR:
            break;

        default:
            sprintf(errMsg, "Unknown error @ file %s line %d\n",  file, line);
            break;
    }

    if(gl_error != GL_NO_ERROR)
    fprintf(stderr, "!!!ERROR BUGURT\n%s", errMsg);
}


GLint ShaderStatus(GLuint shader, GLenum param) {
    GLint status, length;
    GLchar buffer[1024];

    glGetShaderiv(shader, param, &status);

    if (status != GL_TRUE) {
        glGetShaderInfoLog(shader, 1024, &length, buffer);
        fprintf(stderr, "Shader: %s\n", (const char*)buffer);
    }
    OPENGL_CHECK_FOR_ERRORS();
    return status;
}

GLint ShaderProgramStatus(GLuint program, GLenum param) {
    GLint status, length;
    GLchar buffer[1024];
    glGetProgramiv(program, param, &status);

    if (status != GL_TRUE)
    {
        glGetProgramInfoLog(program, 1024, &length, buffer);
        fprintf(stderr, "Shader program: %s\n", (const char*)buffer);
    }

    OPENGL_CHECK_FOR_ERRORS();
    return status;
}

}
