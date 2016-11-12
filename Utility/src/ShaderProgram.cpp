#include "ShaderProgram.h"

namespace GL {

void CompileShader(const std::string &name, GLuint &shader, GLenum shaderType) {
    //Initialization of shader
    shader = glCreateShader(shaderType);                                         CHECK_GL_ERRORS

    std::string source = LoadSource(name);

    //Compile vertex shader
    char *src = new char[source.size()];
    sprintf(src, "%s", source.c_str());
    int sourceLength = source.size();

    glShaderSource(shader, 1, (const GLchar**)&src,
                (const GLint*)&sourceLength);                                   CHECK_GL_ERRORS
    glCompileShader(shader);                                                    CHECK_GL_ERRORS

    //Check whether the compilation is successful
    if (ShaderStatus(shader, GL_COMPILE_STATUS) != GL_TRUE) {
        std::cerr << "COMPILATION ERROR | Line: " << __LINE__ << " File: " << name << std::endl;
        exit(1);
    }
}

GLuint CompileShaderProgram(const std::string& shadername) {
    GLuint ID = glCreateProgram();
    GLuint vertSh, fragSh;
    CompileShader("shaders/" + shadername + ".vert", vertSh, GL_VERTEX_SHADER);
    CompileShader("shaders/" + shadername + ".frag", fragSh, GL_FRAGMENT_SHADER);

    glAttachShader(ID, vertSh);                                                  CHECK_GL_ERRORS
    glAttachShader(ID, fragSh);                                                  CHECK_GL_ERRORS

    glLinkProgram(ID);                                                           CHECK_GL_ERRORS

    if (ShaderProgramStatus(ID, GL_LINK_STATUS) != GL_TRUE) {
        std::cerr << "LINKING ERROR | Line: " <<  __LINE__ << std::endl;
        exit(1);
    }
    return ID;
}

}
