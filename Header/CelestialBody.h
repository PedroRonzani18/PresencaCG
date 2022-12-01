#ifndef _CELESTIALBODY_H
#define _CELESTIALBODY_H

#include <GL/freeglut.h>

class CelestialBody
{
    protected:
        GLuint texture;
        double coreRadius; // raio do planeta
        double rotationRadius; // radio do movimento de rotação
        double rotationPeriod;
        double translationPeriod;
        double conversionConst;



        double angle; // angulo do movimento de rotação
        double translationAngularSpeed; // velocidade angular do movimento de rotação ao redor do sol (movimento de translação)
        double rotationAngularSpeed; // velocidade angular de rotação no proprio eixo ( movimento de rotação )
        bool dependsOnLight;

    public:
        CelestialBody(){}

        GLuint getTexture(){return this->texture;}
        void setTexture(GLuint texture){this->texture = texture;}

        double getCoreRadius(){return this->coreRadius;}
        void setCoreRadius(double coreRadius){this->coreRadius = coreRadius;}

        double getRotationRadius(){return this->rotationRadius;}
        void setRotationRadius(double rotationRadius){this->rotationRadius = rotationRadius;}

        double getRotationPeriod(){return this->rotationPeriod;}
        void setRotationPeriod(double rotationPeriod){this->rotationPeriod = rotationPeriod;}

        double getTranslationPeriod(){return this->translationPeriod;}
        void setTranslationPeriod(double translationPeriod){this->translationPeriod = translationPeriod;}

        double getConversionConst(){return this->conversionConst;}
        void setConversionConst(double conversionConst){this->conversionConst = conversionConst;}

        double getAngle(){return this->angle;}
        void setAngle(double angle){this->angle = angle;}

        double getTranslationAngularSpeed(){return this->translationAngularSpeed;}
        void setTranslationAngularSpeed(double translationAngularSpeed){this->translationAngularSpeed = translationAngularSpeed;}

        double getRotationAngularSpeed(){return this->rotationAngularSpeed;}
        void setRotationAngularSpeed(double rotationAngularSpeed){this->rotationAngularSpeed = rotationAngularSpeed;}

        bool doesDependsOnLight(){return this->dependsOnLight;}
        void setDependsOnLight(bool dependsOnLight){this->dependsOnLight = dependsOnLight;}
};

#endif