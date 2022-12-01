#ifndef _CAMERA_H
#define _CAMERA_H

#include "Coord.h"

class Camera{
    private:
        Coord midPoint;
        Coord moveSpeed;

    public:
        Camera();

        Coord getMidPoint(){return this->midPoint;}
        void setMidPoint(Coord midPoint){this->midPoint = midPoint;}

        void move();
        void setupCamera();
};

#endif