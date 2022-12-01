#ifndef _MOON_H
#define _MOON_H

#include "CelestialBody.h"

class Moon : public CelestialBody
{
    public:
        Moon(){}
        Moon(double angle, double coreRadius, double rotationRadius, double translationAngularSpeed, double rotationAngularSpeed);
};

#endif