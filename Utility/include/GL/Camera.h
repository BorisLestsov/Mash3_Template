#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>

#include "vec3.h"
#include "mat4.h"

namespace GL {

class Camera
{
    public:
        Camera();
        Camera(const VM::vec3& position,
               const VM::vec3& direction,
               const VM::vec3& up,
               const float angle,
               const float screenRatio,
               const float znear,
               const float zfar);

        VM::mat4 getMatrix();

        void rotateLeft(const float angle=0.05f);
        void rotateTop(const float angle=0.05f);
        void rotateY(const float angle=0.05f);
        inline void goForward(const float step=0.01f) {position += -direction * step;}
        inline void goBack(const float step=0.01f) {position -= -direction * step;}
        inline void rotateRight(const float angle=0.05f) {rotateLeft(-angle);}

        VM::vec3 position;
        VM::vec3 direction;
        VM::vec3 up;
        float screenRatio;
        float znear;
        float zfar;
        float angle;
    protected:
    private:
};

}

#endif // CAMERA_H
