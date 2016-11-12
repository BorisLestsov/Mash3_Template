#include "Camera.h"

using namespace VM;

namespace GL {

Camera::Camera()
{
    //ctor
}

Camera::Camera(const vec3& position,
       const vec3& direction,
       const vec3& up,
       const float angle,
       const float screenRatio,
       const float znear,
       const float zfar
    ) {
       this->position = position;
       this->direction = direction;
       this->up = up;
       this->angle = angle;
       this->screenRatio = screenRatio;
       this->znear = znear;
       this->zfar = zfar;
    }

mat4 Camera::getMatrix() {
    vec3 z = normalize(direction);
    vec3 x = normalize(cross(up, z));
    vec3 y = normalize(cross(z, x));
    mat4 Minv(1);
    mat4 Tr(1);
    Minv[0] = vec4(x, 0);
    Minv[1] = vec4(y, 0);
    Minv[2] = vec4(z, 0);
    Tr[3] = vec4(-position, 1);
    Tr = transpose(Tr);
    Minv = transpose(Minv);
    Minv = Minv.unmatrixN3();
    float f = 1 / tan(angle / 2);
    float A = (zfar + znear) / (znear - zfar);
    float B = (2 * zfar * znear) / (znear - zfar);

    mat4 projection(0.0f);
    projection[0][0] = f / screenRatio;
    projection[1][1] = f;
    projection[2][2] = A;
    projection[2][3] = B;
    projection[3][2] = -1;
    return projection * Minv * Tr;
}

void Camera::rotateLeft(const float angle) {
    direction = normalize(direction * cosf(angle)
                + normalize(cross(up, direction)) * sinf(angle));
}

void Camera::rotateY(const float angle) {
    mat4 rot(1);
    rot[0][0] = rot[2][2] = cosf(angle);
    rot[0][2] = -sinf(angle);
    rot[2][0] = sinf(angle);
    direction = normalize((rot * vec4(direction, 0)).xyz());
    up = normalize((rot * vec4(up, 0)).xyz());
}

void Camera::rotateTop(const float angle) {
    vec3 left = cross(up, direction);
    direction = normalize(direction * cosf(angle) + up * sinf(angle));
    up = normalize(cross(direction, left));
}

}
