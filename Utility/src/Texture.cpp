#include "Texture.h"

using namespace std;

namespace GL {

void bindTexture(GLuint program, const string& name, GLuint texture, GLint unit) {
    glActiveTexture(GL_TEXTURE0 + unit);                                         CHECK_GL_ERRORS;
    glBindTexture(GL_TEXTURE_2D, texture);                                       CHECK_GL_ERRORS;

    GLint location = glGetUniformLocation(program, name.c_str());                CHECK_GL_ERRORS;
    if(location >=0 ) {
        glUniform1i(location, unit);                                             CHECK_GL_ERRORS;
    }
}

}
