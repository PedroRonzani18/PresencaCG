#include "../Header/Planet.h"
#include "../Header/drawings.h"
#include <stdio.h>

Planet::Planet(GLuint texture, bool dependsOnLight, int numberOfMoons, double coreRadius, double rotationRadius, double translationPeriod, double rotationPeriod)
{
    this->texture = texture;
    this->dependsOnLight = dependsOnLight;
    this->coreRadius = coreRadius/113.0;
    this->rotationRadius = 1.7 * rotationRadius;
    this->translationPeriod = translationPeriod;
    this->rotationPeriod = rotationPeriod;

    double translationSpeed, angularSpeed;

    if(translationPeriod != 0)
        translationSpeed = 30600.0 / translationPeriod;
    else
        translationSpeed = 0;

    if(rotationPeriod != 0)
        angularSpeed = 30/ rotationPeriod;
    else
        angularSpeed = 0;

    this->translationAngularSpeed = translationSpeed;
    this->rotationAngularSpeed = angularSpeed;

    std::shared_ptr<Moon> moon1 = std::make_shared<Moon>(0,0.3, this->coreRadius * 1.1 + 0.15, 60, 50);
    std::shared_ptr<Moon> moon2 = std::make_shared<Moon>(0,0.3, this->coreRadius * 1.1 + 0.15, 60, 50);
    std::shared_ptr<Moon> moon3 = std::make_shared<Moon>(0,0.3, this->coreRadius * 1.1 + 0.15, 60, 50);

    switch(numberOfMoons)
    {
        case 3:
            moon3->setAngle(240);
            addMooon(moon3);
        case 2:
            moon2->setAngle(360/numberOfMoons);
            addMooon(moon2);
        case 1:
            moon1->setAngle(0);
            addMooon(moon1);
            break;
    }
}