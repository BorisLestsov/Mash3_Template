#version 330

in vec4 point;

uniform mat4 camera;

void main() {
    gl_Position = camera * point;
}
