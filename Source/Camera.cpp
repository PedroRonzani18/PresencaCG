#include "../Header/Camera.h"
#include "../Header/globalParameters.h"
#include <cmath>

#define radGr(radianos) (radianos * (180.0 / M_PI))
#define grRad(graus) ((graus * M_PI) / 180.0)

Camera::Camera()
{
    midPoint.x = -4.7;
    midPoint.y = 9.9;
    midPoint.z = 16.3;

    moveSpeed.x = 0.1;
    moveSpeed.y = 0.1;
    moveSpeed.z = 0.1;
}

void Camera::move()
{
    midPoint.x += (keys->d - keys->a) * moveSpeed.x;
    midPoint.y += (keys->space - keys->f) * moveSpeed.y;
    midPoint.z += (keys->s - keys->w) * moveSpeed.z;
}

void Camera::setupCamera()
{
    gluLookAt(midPoint.x, midPoint.y, midPoint.z,
              midPoint.x, midPoint.y - 3, midPoint.z - 5,
              0, 1, 0);
}